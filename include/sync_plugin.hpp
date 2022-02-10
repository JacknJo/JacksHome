#pragma once

#include "cyclic_schedulable.hpp"

namespace jhm
{
    class sync_plugin : public cyclic_schedulable
    {
     public:
        using cyclic_schedulable::cyclic_schedulable;
        // sync_plugin();
        virtual ~sync_plugin();

        void tick(scheduler& scheduler, const clock::time_point& now, const double dt) override;
    };
}  // namespace jhm.