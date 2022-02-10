#pragma once

#include <vector>

#include "data.hpp"

namespace jhm
{
    class connectable : public data
    {
     public:
        // connectable();
        using data::data;
        virtual ~connectable();

        void add_connection(data& data);

     public:
        std::vector<data*> _connections;
    };
}  // namespace jhm.