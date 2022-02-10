#pragma once

#include <functional>

#include "event.hpp"

namespace jhm
{
    class event_callable : public event
    {
     public:
        using e_callable = std::function<void()>;

        event_callable(e_callable&& callable, clock::duration schedule_from_now);
        event_callable(e_callable&& callable, clock::time_point schedule_at);

        ~event_callable();

        void tick(scheduler& scheduler, const clock::time_point& now, double dt) override;

     private:
        e_callable _callable;
    };
}  // namespace jhm