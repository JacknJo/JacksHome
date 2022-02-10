#pragma once

#include <functional>

#include "notifiable.hpp"
#include "sink.hpp"

namespace jhm
{
    class final_sink : public sink, public notifiable
    {
     public:
        final_sink(value_type v, callable&& c, const data_provider_meta& created_by);

        value_type& get() override;
        //  private:
    };
}  // namespace jhm.