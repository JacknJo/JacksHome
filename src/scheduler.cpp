#include "scheduler.hpp"

#include <iostream>
#include <ranges>
#include <thread>

#include "data_store.hpp"
#include "feedable.hpp"
#include "schedulable.hpp"

namespace jhm
{
    scheduler::scheduler() = default;
    scheduler::~scheduler() = default;

    schedulable& scheduler::add(std::unique_ptr<schedulable>&& s)
    {
        return *_schedulables.emplace_back(std::move(s)).get();
    }

    scheduler* scheduler::get()
    {
        static scheduler s;
        return &s;
    }

    void scheduler::run(bool& stop_requested, clock::duration minimum_scheduling_duration,
                        clock::duration maximum_scheduling_duration)
    {
        while (!stop_requested)
        {
            auto sleep_time = maximum_scheduling_duration;
            const auto tick_start = clock::now();
            for (auto it = _schedulables.begin(); it != _schedulables.end();)
            {
                auto& s = *it;

                if (!s->active())
                {
                    it++;
                    continue;
                }

                auto calc_delta = [&tick_start](std::unique_ptr<schedulable>& s)
                {
                    return s->next_tick_at_invoker() - tick_start;
                };

                const auto delta = calc_delta(s);

                if (delta < minimum_scheduling_duration / 2)
                {
                    s->tick_invoker(*this, tick_start);

                    // Recalculate delta time, as the next_tick output changed by invoking the tick method.
                    sleep_time = std::min(sleep_time, calc_delta(s));
                }
                else
                {
                    sleep_time = std::min(sleep_time, delta);
                }

                if (s->finished())
                {
                    it = _schedulables.erase(it);
                }
                else
                {
                    it++;
                }
            }

            // Remove finished schedulables.

            // std::cout << "dirty_cnt: " << data_store::get()->dirty_cnt() << '\n';
            if (data_store::get()->dirty_cnt())
            {
                for (auto& dirty :
                     data_store::get()->feedables() | std::views::filter([](auto f) { return f->dirty(); }))
                {
                    dirty->get();
                }
            }

            sleep_time -= clock::now() - tick_start;
            sleep_time = std::max(sleep_time, minimum_scheduling_duration);

            // const auto minimum_cycle_time = std::chrono::milliseconds(5);
            std::this_thread::sleep_for(sleep_time);
        }
    }
}  // namespace jhm.