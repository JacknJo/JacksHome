#include "event.hpp"

#include <iostream>

namespace jhm
{
    // event::event() : oneshot_schedulable(std::chrono::milliseconds(5000)) {}
    // event::~event() = default;

    void event::tick(scheduler& scheduler, const clock::time_point& now, const double dt)
    {
        oneshot_schedulable::tick(scheduler, now, dt);
        // std::cout << __PRETTY_FUNCTION__ << " " << dt << '\n';
        _finished = true;
    }
}  // namespace jhm.