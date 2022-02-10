#pragma once

#include <string>
#include <string_view>

#include "data_provider_meta.hpp"

namespace jhm
{
    class named_data_provider : public data_provider_meta
    {
     public:
        named_data_provider(std::string_view instance_name, std::string_view block_name);
        virtual ~named_data_provider();

        std::string_view instance_name() const;
        std::string_view block_name() const;

     protected:
        const std::string _instance_name;
        const std::string _block_name;
    };
}  // namespace jhm.