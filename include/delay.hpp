#pragma once

#include "block.hpp"
#include "event.hpp"

namespace jhm
{
    class delay : public block
    {
     public:
        delay(event::clock::duration delay, std::string_view instance_name);

        source& data_delayed();
        final_sink& data_in();

     private:
        event::clock::duration _delay;
        source& _data_delayed;
        final_sink& _data_in;
    };
}  // namespace jhm.