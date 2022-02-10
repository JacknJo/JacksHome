#include "data_provider_meta.hpp"

#include <stdexcept>

#include "data_store.hpp"

namespace jhm
{
    uint32_t data_provider_meta::_id_cnt = 0;

    data_provider_meta::data_provider_meta() : _id(_id_cnt++)
    {
        _data_store = data_store::get();
        if (_data_store == nullptr) throw std::bad_alloc();
    }

    data_provider_meta::~data_provider_meta() = default;

    // data& data_provider_meta::register_source(std::string_view s, data&& d) {}

    uint32_t data_provider_meta::id() const
    {
        return _id;
    }

    sink& data_provider_meta::register_sink(std::string_view s, sink&& d)
    {
        sink& element = _data_store->register_sink(std::move(d));
        _inputs.insert({ std::string(s), &element });
        return element;
    }

    final_sink& data_provider_meta::register_final_sink(std::string_view s, final_sink&& d)
    {
        final_sink& element = _data_store->register_final_sink(std::move(d));
        _inputs.insert({ std::string(s), &element });
        return element;
    }

    source& data_provider_meta::register_source(std::string_view s, source&& d)
    {
        source& element = _data_store->register_source(std::move(d));
        _outputs.insert({ std::string(s), &element });
        return element;
    }

    fed_source& data_provider_meta::register_fed_source(std::string_view s, fed_source&& d)
    {
        fed_source& element = _data_store->register_fed_source(std::move(d));
        _outputs.insert({ std::string(s), &element });
        return element;
    }

}  // namespace jhm.