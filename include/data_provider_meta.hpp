#pragma once

#include <cstdint>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

#include "data_register_interface.hpp"
#include "fed_source.hpp"
#include "final_sink.hpp"
#include "sink.hpp"
#include "source.hpp"

namespace jhm
{
    class data_store;
    class data_provider_meta
    {
     public:
        data_provider_meta();
        ~data_provider_meta();

        sink& register_sink(std::string_view s, sink&& d);
        final_sink& register_final_sink(std::string_view s, final_sink&& d);

        source& register_source(std::string_view s, source&& d);
        fed_source& register_fed_source(std::string_view s, fed_source&& d);

        uint32_t id() const;

     protected:
        // std::vector<data*> _inputs;
        // std::vector<data*> _outputs;
        std::unordered_map<std::string, data*> _inputs;
        std::unordered_map<std::string, data*> _outputs;
        data_store* _data_store;  // Quick-access for singleton.
        const uint32_t _id;
        static uint32_t _id_cnt;
    };
}  // namespace jhm.