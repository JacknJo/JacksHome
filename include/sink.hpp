#pragma once

#include "feedable.hpp"

namespace jhm
{
    class sink : public feedable
    {
     public:
        using feedable::feedable;
    };
}  // namespace jhm.