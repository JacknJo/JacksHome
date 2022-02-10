#include "delay.hpp"

#include "event_callable.hpp"
#include "scheduler.hpp"

namespace jhm
{
    delay::delay(event::clock::duration delay, std::string_view instance_name) :
        block(instance_name, __PRETTY_FUNCTION__),
        _delay(delay),
        _data_delayed(register_source("data_delayed", { static_cast<int>(0), *this })),
        _data_in(register_final_sink(
            "data_in", { static_cast<int>(1),
                         [this](data& d)
                         {
                             jhm::scheduler::get()->add(std::make_unique<event_callable>(
                                 [this, d]() mutable { _data_delayed.set<int>(d.get_as<int>()); }, _delay));
                         },
                         *this }))
    {
    }

    source& delay::data_delayed()
    {
        return _data_delayed;
    }

    final_sink& delay::data_in()
    {
        return _data_in;
    }
}  // namespace jhm.