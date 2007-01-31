// Copyright 2006, 2007 Dean Michael Berris.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt )

#ifndef __SPEC_SHOULD_IMPL_HPP__
#define __SPEC_SHOULD_IMPL_HPP__

#include <boost/spec/exceptions.hpp>
#include <string>

namespace boost { namespace spec { namespace detail {

    template <typename T>
    struct between_impl; 

    template <typename T>
    struct should_impl {
        explicit should_impl(T & value) : _value(value) { };

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

        T & _value;
    };

    // Overload for a boolean test
    template <>
        struct should_impl<bool> {
            bool _value ;
            explicit should_impl(bool value) : _value(value) { };

            bool be_true() const {
                return _value ? true : false ;
            };

            bool be_false() const {
                return !_value ? true : false ;
            };
        };

    // Overload for string literals
    template <>
        struct should_impl<const char *> {
            std::string _value;
            explicit should_impl(std::string const & value) : _value(value) { };

            bool equal(std::string const & expected) const {
                if (_value == expected)
                    return true;
                throw are_not_equal_exception<std::string, std::string>(_value, expected) ;
            };

            bool not_equal(std::string const & expected) const {
                if (_value != expected)
                    return true;
                throw are_equal_exception<std::string, std::string>(_value, expected) ;
            };
        };

    template <>
        struct should_impl<std::string> : should_impl<char const *> {
            explicit should_impl(std::string const & value)
                : should_impl<char const *>(value)
            { };
        };

    template <typename T>
    struct between_impl {

        explicit between_impl(T & value) : _value(value) { };

        template <typename _T>
        bool and_(const _T & upper_bound) {
            if (_value < upper_bound)
                return true;
            throw more_than_upper_bound_exception<T, _T>(_value, upper_bound);
        };

        T & _value;
    };

}; // namespace detail

}; // namespace spec

}; // namespace boost

#endif
