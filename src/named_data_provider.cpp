#include "named_data_provider.hpp"

namespace jhm
{
    named_data_provider::named_data_provider(std::string_view instance_name, std::string_view block_name) :
        _instance_name(instance_name),
        _block_name(block_name)
    {
    }

    named_data_provider::~named_data_provider() = default;

    std::string_view named_data_provider::instance_name() const
    {
        return _instance_name;
    }

    std::string_view named_data_provider::block_name() const
    {
        return _block_name;
    }

}  // namespace jhm.