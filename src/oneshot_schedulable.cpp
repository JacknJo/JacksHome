#include "oneshot_schedulable.hpp"

namespace jhm
{

    oneshot_schedulable::oneshot_schedulable(clock::time_point schedule_at) :
        schedulable(false),
        _next_tick(schedule_at) {};

    oneshot_schedulable::oneshot_schedulable(clock::duration schedule_from_now) :
        oneshot_schedulable(clock::now() + schedule_from_now)
    {
    }

    oneshot_schedulable::~oneshot_schedulable() = default;

    schedulable::clock::time_point oneshot_schedulable::next_tick_at()
    {
        return _next_tick;
    }

    void oneshot_schedulable::tick(scheduler& scheduler, const clock::time_point& now, const double dt)
    {
        _active = false;
    }

}  // namespace jhm.