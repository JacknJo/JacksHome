#pragma once

#include <cstdint>

#include "value_type.hpp"

namespace jhm
{
    class data_provider_meta;
    class data
    {
     public:
        data(value_type initial_value, const data_provider_meta& created_by);
        virtual ~data();

        value_type raw() const;
        uint32_t id() const;

        template <typename T>
        const T& get_as()
        {
            return std::get<T>(get());
        }

        virtual const value_type& get();

        template <typename T>
        const bool is_of_type() const
        {
            return std::holds_alternative<T>(_value);
        }

        const data_provider_meta& created_by() const;

     protected:
        value_type _value;

     private:
        const data_provider_meta& _created_by;
        const uint32_t _id;
        static uint32_t _id_cnt;
    };
}  // namespace jhm.