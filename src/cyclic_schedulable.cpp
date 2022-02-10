#include "cyclic_schedulable.hpp"

namespace jhm
{
    cyclic_schedulable::cyclic_schedulable(const clock::duration& scheduling_period) :
        schedulable(true),
        _scheduling_period(scheduling_period)
    {
    }

    cyclic_schedulable::~cyclic_schedulable() = default;

    schedulable::clock::time_point cyclic_schedulable::next_tick_at()
    {
        return _last_tick + _scheduling_period;
    }
}  // namespace jhm.