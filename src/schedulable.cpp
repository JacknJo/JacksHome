#include "schedulable.hpp"

#include <iostream>

#include "scheduler.hpp"

namespace jhm
{
    schedulable::schedulable(bool immediate_tick) :
        _last_tick(clock::now()),
        _immediate_tick(immediate_tick),
        _active(true)
    {
    }

    schedulable::~schedulable() = default;

    void schedulable::tick_invoker(scheduler& scheduler, const clock::time_point& now)
    {
        const auto dt = std::chrono::duration<double>(now - _last_tick).count();
        this->tick(scheduler, now, dt);
        _last_tick = now;
    }

    schedulable::clock::time_point schedulable::next_tick_at_invoker()
    {
        if (_immediate_tick)
        {
            _immediate_tick = false;
            const auto now = clock::now();
            _last_tick = now;
            return now;
        }

        return next_tick_at();
    }

    bool schedulable::active() const
    {
        return _active;
    }

    bool schedulable::finished() const
    {
        return _finished;
    }
}  // namespace jhm.