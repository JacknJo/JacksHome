#pragma once

#include "named_data_provider.hpp"

namespace jhm
{
    class block : public named_data_provider
    {
     public:
        using named_data_provider::named_data_provider;
        virtual ~block();

     protected:
    };
}  // namespace jhm.