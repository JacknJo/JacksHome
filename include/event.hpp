#pragma once

#include "oneshot_schedulable.hpp"

namespace jhm
{
    class event : public oneshot_schedulable
    {
     public:
        using oneshot_schedulable::oneshot_schedulable;
        // event();
        // virtual ~event();

        void tick(scheduler& scheduler, const clock::time_point& now, double dt) override;
        // clock::time_point next_tick_at() override;
    };
}  // namespace jhm.