#include "data.hpp"

#include "data_provider_meta.hpp"

namespace jhm
{
    uint32_t data::_id_cnt = 0;

    data::data(value_type initial_value, const data_provider_meta& created_by) :
        _value(initial_value),
        _created_by(created_by),
        _id(_id_cnt++)
    {
    }

    data::~data() = default;

    value_type data::raw() const
    {
        return _value;
    }

    uint32_t data::id() const
    {
        return _id;
    }

    const value_type& data::get()
    {
        return _value;
    }

    const data_provider_meta& data::created_by() const
    {
        return _created_by;
    }
}  // namespace jhm.