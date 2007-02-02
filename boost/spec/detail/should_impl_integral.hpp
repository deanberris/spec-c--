// Copyright 2006, 2007 Dean Michael Berris.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt )

#ifndef __SPEC_SHOULD_IMPL_INTEGRAL_HPP__
#define __SPEC_SHOULD_IMPL_INTEGRAL_HPP__

namespace boost { namespace spec { namespace detail {

    template <typename T>
    struct between_impl {

        explicit between_impl(T const & value) : _value(value) { };

        template <typename _T>
        bool and_(const _T & upper_bound) {
            if (_value < upper_bound)
                return true;
            throw more_than_upper_bound_exception<T, _T>(_value, upper_bound);
        };

        T const & _value;
    };

    template <typename T>
    struct should_impl {
        explicit should_impl(T const & value) : _value(value) { };

        template <typename _T>
        bool equal(const _T & expected) const {
            if (_value == expected)
                return true;
            throw are_not_equal_exception<T, _T>(_value, expected) ;
        };

        template <typename _T>
        bool not_equal(const _T & expected) const {
            if (_value != expected)
                return true;
            throw are_equal_exception<T, _T>(_value, expected) ;
        };

        template <typename _T>
        bool be_less_than(const _T & upper_bound) const {
            if (_value < upper_bound)
                return true;
            throw more_than_upper_bound_exception<T, _T>(_value, upper_bound);
        };

        template <typename _T>
        bool be_more_than(const _T & lower_bound) const {
            if (_value > lower_bound)
                return true;
            throw less_than_lower_bound_exception<T, _T>(_value, lower_bound);
        };

        template <typename _T>
        between_impl<_T> be_between(const _T & lower_bound) const {
            if (_value < lower_bound)
                throw less_than_lower_bound_exception<T, _T>(_value, lower_bound);
            return between_impl<_T>(_value);
        };

        template <typename _T>
            bool be_divisible_by(const _T & divisor) const {
                if (_value % divisor)
                    throw is_not_divisible_by<T, _T>(_value, divisor);

                return true;
            };

        template <typename _T>
            bool not_be_divisible_by(const _T & divisor) const {
                if (!(_value % divisor))
                    throw is_divisible_by<T, _T>(_value, divisor);

                return true;
            };

        bool be_even() const {
            if (_value % 2)
                throw is_odd<T>(_value);

            return true;
        };

        bool be_odd() const {
            if (!(_value % 2))
                throw is_even<T>(_value);

            return true;
        };

        T const & _value;
    };

}; // detail

}; // spec

}; // boost

#endif

