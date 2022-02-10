#include "pulse_generator.hpp"

#include <iostream>

namespace jhm
{
    pulse_generator::pulse_generator(std::string_view instance_name, clock::duration scheduling_period) :
        scheduled_block(instance_name, __PRETTY_FUNCTION__, scheduling_period),
        _pulse(register_source("pulse", { static_cast<int>(5), *this }))
    {
        // auto& s = register_final_sink("notify",
        //                               { static_cast<int>(1), [](data&) { std::cout << "Callback!\n"; }, *this });
        // s.feed_from(p);
    }

    source& pulse_generator::pulse()
    {
        return _pulse;
    }

    pulse_generator::~pulse_generator() = default;

    void pulse_generator::tick(scheduler& scheduler, const clock::time_point& now, const double dt)
    {
        auto o = static_cast<source*>(_outputs["pulse"]);
        o->set<int>(o->get_as<int>() ? 0 : 1);
    }
}  // namespace jhm.