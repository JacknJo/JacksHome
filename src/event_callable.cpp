#include "event_callable.hpp"

#include <iostream>

#include "event.hpp"

namespace jhm
{
    // event_callable::event_callable() = default;
    event_callable::~event_callable() = default;

    event_callable::event_callable(e_callable&& callable, clock::duration schedule_from_now) :
        event(schedule_from_now),
        _callable(std::move(callable))
    {
    }

    event_callable::event_callable(e_callable&& callable, clock::time_point schedule_at) :
        event(schedule_at),
        _callable(std::move(callable))
    {
    }

    void event_callable::tick(scheduler& scheduler, const clock::time_point& now, double dt)
    {
        _callable();
        event::tick(scheduler, now, dt);
    }

}  // namespace jhm.