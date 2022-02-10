#pragma once

#include <chrono>

#include "scheduler.hpp"

namespace jhm
{
    class schedulable
    {
     public:
        using clock = scheduler::clock;
        schedulable(bool immediate_tick);
        virtual ~schedulable();

        void tick_invoker(scheduler& scheduler, const clock::time_point& now);
        clock::time_point next_tick_at_invoker();
        bool active() const;
        bool finished() const;

     protected:
        virtual void tick(scheduler& scheduler, const clock::time_point& now, const double dt) = 0;
        virtual clock::time_point next_tick_at() = 0;

        clock::time_point _last_tick = clock::now();
        bool _immediate_tick = false;
        bool _active = true;
        bool _finished = false;
    };
}  // namespace jhm.