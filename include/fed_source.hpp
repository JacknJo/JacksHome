#pragma once

#include "feedable.hpp"
#include "notifiable.hpp"

namespace jhm
{
    class fed_source : public feedable, public notifiable
    {
     public:
        using feedable::feedable;
    };
}  // namespace jhm.