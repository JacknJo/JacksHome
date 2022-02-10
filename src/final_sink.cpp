#include "final_sink.hpp"

namespace jhm
{
    final_sink::final_sink(value_type v, callable&& c, const data_provider_meta& cb) :
        sink(v, cb),
        notifiable(std::move(c))
    {
    }

    value_type& final_sink::get()
    {
        feedable::get();
        _notifiable(*this);
        return _value;
    }
}  // namespace jhm.