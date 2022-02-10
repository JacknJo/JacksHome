#pragma once

#include <iostream>

#include "connectable.hpp"
#include "feedable.hpp"

namespace jhm
{
    class source : public connectable
    {
     public:
        using connectable::connectable;
        // source();
        ~source();

        template <typename T>
        void set(T value)
        {
            if (!is_of_type<T>()) throw std::bad_cast();
            _value = value;
            for (auto c : _connections)
            {
                static_cast<feedable*>(c)->mark_dirty();
            }
        }
    };
}  // namespace jhm.