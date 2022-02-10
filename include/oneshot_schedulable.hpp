#pragma once
#include "schedulable.hpp"

namespace jhm
{
    class oneshot_schedulable : public schedulable
    {
     public:
        oneshot_schedulable(clock::time_point schedule_at);
        oneshot_schedulable(clock::duration schedule_from_now);

        virtual ~oneshot_schedulable();

        schedulable::clock::time_point next_tick_at() override;
        void tick(scheduler& scheduler, const clock::time_point& now, const double dt);

     private:
        schedulable::clock::time_point _next_tick;
    };
}  // namespace jhm.