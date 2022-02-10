#pragma once
#include <variant>

namespace jhm
{
    using value_type = std::variant<int, bool, double>;
}
