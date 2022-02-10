#pragma once

#include <memory>
#include <vector>

#include "data_register_interface.hpp"

namespace jhm
{
    class fed_source;
    class sink;
    class source;
    class final_sink;
    class feedable;

    class data_store
    {
     public:
        data_store();
        ~data_store();

        source& register_source(source&& d);
        sink& register_sink(sink&& d);
        fed_source& register_fed_source(fed_source&& d);
        final_sink& register_final_sink(final_sink&& d);

        static data_store* get();

        void increment_dirty_cnt();
        void decrement_dirty_cnt();

        inline auto& all() const
        {
            return _data;
        }

        inline auto& sinks() const
        {
            return _sinks;
        }

        inline auto& sources() const
        {
            return _sources;
        }

        inline auto& fed_sources() const
        {
            return _fed_sources;
        }

        inline auto& final_sinks() const
        {
            return _final_sinks;
        }

        inline auto& feedables() const
        {
            return _feedables;
        }

        std::size_t dirty_cnt() const;

     private:
        std::vector<std::unique_ptr<data>> _data;

        std::vector<source*> _sources;
        std::vector<sink*> _sinks;
        std::vector<fed_source*> _fed_sources;
        std::vector<final_sink*> _final_sinks;
        std::vector<feedable*> _feedables;

        std::size_t _dirty_cnt = 0;
    };
}  // namespace jhm.