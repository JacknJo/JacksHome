#pragma once

#include <functional>

#include "data.hpp"

namespace jhm
{
    class notifiable
    {
     public:
        using callable = std::function<void(data&)>;
        notifiable(callable&& c) : _notifiable(std::move(c)) {}

     protected:
        callable _notifiable;
    };
}  // namespace jhm