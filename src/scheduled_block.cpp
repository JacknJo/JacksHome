#include "scheduled_block.hpp"

#include <iostream>

namespace jhm
{
    scheduled_block::scheduled_block(std::string_view instance_name, std::string_view block_name,
                                     clock::duration scheduling_period) :
        block(instance_name, block_name),
        cyclic_schedulable(scheduling_period)
    {
    }

    scheduled_block::~scheduled_block() = default;

    void scheduled_block::tick(scheduler& scheduler, const clock::time_point& now, const double dt)
    {
        std::cout << __PRETTY_FUNCTION__ << " " << dt << '\n';
    }

}  // namespace jhm.