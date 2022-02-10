#pragma once

#include "data.hpp"

namespace jhm
{
    class data_register_interface
    {
     public:
        virtual data& register_source(data&& d) = 0;
        virtual data& register_sink(data&& d) = 0;
        virtual data& register_fed_source(data&& d) = 0;
        virtual data& register_final_sink(data&& d) = 0;
    };
}  // namespace jhm.