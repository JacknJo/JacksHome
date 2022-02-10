#include "connectable.hpp"

namespace jhm
{
    connectable::~connectable() = default;

    void connectable::add_connection(data& data)
    {
        _connections.push_back(&data);
    }
}  // namespace jhm.