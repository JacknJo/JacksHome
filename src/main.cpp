#include <signal.h>

#include <iostream>
#include <memory>

#include "delay.hpp"
#include "event.hpp"
#include "event_callable.hpp"
#include "pulse_generator.hpp"
#include "scheduler.hpp"
#include "sync_plugin.hpp"

static bool stop_requested = false;

void handle_signal(int signal_number)
{
    switch (signal_number)
    {
        case SIGINT:
            stop_requested = true;
            break;
    }
}

int main()
{
    signal(SIGINT, handle_signal);

    jhm::scheduler& scheduler = *jhm::scheduler::get();
    // jhm::event event;

    scheduler.add(std::make_unique<jhm::event>(std::chrono::milliseconds(300)));
    scheduler.add(std::make_unique<jhm::sync_plugin>(std::chrono::milliseconds(30)));
    auto& pulse = scheduler.add(std::make_unique<jhm::pulse_generator>("Testinstance", std::chrono::milliseconds(100)));
    jhm::pulse_generator& p = static_cast<jhm::pulse_generator&>(pulse);

    jhm::delay d1(std::chrono::milliseconds(100), "testdelay");
    jhm::delay d2(std::chrono::milliseconds(200), "testdelay2");
    d1.data_in().feed_from(p.pulse());
    d2.data_in().feed_from(p.pulse());

    scheduler.run(stop_requested, std::chrono::milliseconds(2), std::chrono::milliseconds(20));

    return 0;
}