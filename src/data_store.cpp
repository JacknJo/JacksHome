#include "data_store.hpp"

#include "fed_source.hpp"
#include "feedable.hpp"
#include "final_sink.hpp"
#include "sink.hpp"
#include "source.hpp"

namespace jhm
{
    data_store::data_store() = default;
    data_store::~data_store() = default;

    data_store* data_store::get()
    {
        static data_store ds;
        return &ds;
    }

    std::size_t data_store::dirty_cnt() const
    {
        return _dirty_cnt;
    }

    void data_store::increment_dirty_cnt()
    {
        _dirty_cnt++;
    }

    void data_store::decrement_dirty_cnt()
    {
        _dirty_cnt -= _dirty_cnt > 0;
    }

    source& data_store::register_source(source&& d)
    {
        const auto& up = _data.emplace_back(std::make_unique<source>(std::move(d)));
        auto pt = static_cast<source*>(up.get());
        _sources.push_back(pt);
        return *pt;
    }

    sink& data_store::register_sink(sink&& d)
    {
        const auto& up = _data.emplace_back(std::make_unique<sink>(std::move(d)));
        auto pt = static_cast<sink*>(up.get());
        _sinks.push_back(pt);
        _feedables.push_back(pt);
        return *pt;
    }

    fed_source& data_store::register_fed_source(fed_source&& d)
    {
        const auto& up = _data.emplace_back(std::make_unique<fed_source>(std::move(d)));
        auto pt = static_cast<fed_source*>(up.get());
        _fed_sources.push_back(pt);
        _feedables.push_back(pt);
        return *pt;
    }

    final_sink& data_store::register_final_sink(final_sink&& d)
    {
        const auto& up = _data.emplace_back(std::make_unique<final_sink>(std::move(d)));
        auto pt = static_cast<final_sink*>(up.get());
        _final_sinks.push_back(pt);
        _feedables.push_back(pt);
        return *pt;
    }

}  // namespace jhm.