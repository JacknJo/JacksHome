#include "feedable.hpp"

#include "data_store.hpp"
#include "fed_source.hpp"
#include "source.hpp"

namespace jhm
{
    // feedable::feedable() = default;
    feedable::~feedable() = default;

    bool feedable::dirty() const
    {
        return _dirty;
    }

    void feedable::feed_from(source& s)
    {
        s.add_connection(*this);
        _fed_by = &s;
    }

    void feedable::feed_from(fed_source& s)
    {
        s.add_connection(*this);
        _fed_by = &s;
    }

    const value_type& feedable::get()
    {
        if (dirty())
        {
            if (_fed_by) _value = _fed_by->get();
            _dirty = false;
            data_store::get()->decrement_dirty_cnt();
        }

        return _value;
    }

    void feedable::mark_dirty()
    {
        if (_dirty) return;

        _dirty = true;
        data_store::get()->increment_dirty_cnt();

        for (auto c : _connections)
        {
            auto f = static_cast<feedable*>(c);
            if (!f) throw std::bad_alloc();
            f->mark_dirty();
        }
    }

}  // namespace jhm.