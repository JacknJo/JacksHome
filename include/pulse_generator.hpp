#pragma once

#include "scheduled_block.hpp"

namespace jhm
{
    class pulse_generator : public scheduled_block
    {
     public:
        pulse_generator(std::string_view instance_name, clock::duration scheduling_period);
        ~pulse_generator();

        void tick(scheduler& scheduler, const clock::time_point& now, const double dt);

        source& pulse();

     private:
        source& _pulse;
    };
}  // namespace jhm.