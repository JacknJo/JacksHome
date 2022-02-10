#pragma once

#include "connectable.hpp"

namespace jhm
{
    class fed_source;
    class source;
    class feedable : public connectable
    {
     public:
        using connectable::connectable;
        ~feedable();

        bool dirty() const;
        void mark_dirty();

        void feed_from(source& s);
        void feed_from(fed_source& s);

        const value_type& get();

     private:
        data* _fed_by = nullptr;
        bool _dirty = false;
    };
}  // namespace jhm.