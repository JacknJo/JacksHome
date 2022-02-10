#pragma once

#include "schedulable.hpp"

namespace jhm
{
    class cyclic_schedulable : public schedulable
    {
     public:
        cyclic_schedulable(const clock::duration& scheduling_period);
        virtual ~cyclic_schedulable();

        clock::time_point next_tick_at() override;

     private:
        clock::duration _scheduling_period;
    };
}  // namespace jhm.