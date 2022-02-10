#pragma once

#include "block.hpp"
#include "cyclic_schedulable.hpp"

namespace jhm
{
    class scheduled_block : public cyclic_schedulable, public block
    {
     public:
        scheduled_block(std::string_view instance_name, std::string_view block_name, clock::duration scheduling_period);
        ~scheduled_block();

        void tick(scheduler& scheduler, const clock::time_point& now, const double dt) override;
        // void tick() override;
    };
}  // namespace jhm.