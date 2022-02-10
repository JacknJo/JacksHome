#include "sync_plugin.hpp"

#include <iostream>

namespace jhm
{
    // sync_plugin::sync_plugin() : cyclic_schedulable();
    sync_plugin::~sync_plugin() = default;

    void sync_plugin::tick(scheduler& scheduler, const clock::time_point& now, const double dt)
    {
        // std::cout << __PRETTY_FUNCTION__ << " " << dt << '\n';
    }

}  // namespace jhm.