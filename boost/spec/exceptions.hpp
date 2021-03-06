// Copyright 2006, 2007 Dean Michael Berris.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt )

#ifndef __SPEC_EXCEPTIONS_HPP__
#define __SPEC_EXCEPTIONS_HPP__

#include <sstream>

namespace boost { namespace spec {

    template <typename T, typename _T>
    struct are_not_equal_exception : std::exception {

        are_not_equal_exception(const T & value, const _T & expected)
            : _value(value) , _expected(expected) 
        { 
            std::ostringstream message("");
            message << "spec:: value supplied ("
                << _value 
                << ") and expected value ("
                << _expected
                << ") are not equal.";

            _message = message.str();
        };

        const char * what() const throw (){
            return _message.c_str();
        };

        ~are_not_equal_exception() throw () { };
        
        T _value;
        _T _expected;
        std::string _message;
    };

    template <typename T, typename _T>
    struct are_equal_exception : std::exception {

        are_equal_exception(const T & value, const _T & expected)
            : _value(value) , _expected(expected) 
        { 
            std::ostringstream message("");
            message << "spec:: value supplied ("
                << _value 
                << ") and expected value ("
                << _expected
                << ") are equal.";

            _message = message.str();
        };

        const char * what() const throw (){
            return _message.c_str() ;
        };

        ~are_equal_exception() throw () { };
        
        T _value;
        _T _expected;
        std::string _message;
    };

    template <typename T, typename _T>
    struct less_than_lower_bound_exception : std::exception {

        less_than_lower_bound_exception (const T & value, const _T & lower_bound)
            : _value(value) , _lower_bound(lower_bound) 
        { 
            std::ostringstream message("");
            message << "spec:: value supplied ("
                << _value 
                << ") is less than the lower bound ("
                << _lower_bound
                << ")";

            _message = message.str();
        };

        const char * what() const throw (){
            return _message.c_str() ;
        };

        ~less_than_lower_bound_exception() throw () { };
        
        T _value;
        _T _lower_bound;
        std::string _message;
    };

    template <typename T, typename _T>
    struct more_than_upper_bound_exception : std::exception {

        more_than_upper_bound_exception(const T & value, const _T & upper_bound)
            : _value(value) , _upper_bound(upper_bound) 
        { 
            std::ostringstream message("");
            message << "spec:: value supplied ("
                << _value 
                << ") is more than the upper bound ("
                << _upper_bound
                << ")";

            _message = message.str();
        };

        const char * what() const throw (){
            return _message.c_str() ;
        };

        ~more_than_upper_bound_exception() throw () { };
        
        T _value;
        _T _upper_bound;
        std::string _message;
    };

    template <typename T, typename _T>
    struct is_not_divisible_by : std::exception {

        is_not_divisible_by(const T & value, const _T & divisor)
            : _value(value) , _divisor(divisor) 
        { 
            std::ostringstream message("");
            message << "spec:: value supplied ("
                << _value 
                << ") is not divisible by ("
                << _divisor
                << ")";

            _message = message.str();
        };

        const char * what() const throw (){
            return _message.c_str() ;
        };

        ~is_not_divisible_by() throw () { };
        
        T _value;
        _T _divisor;
        std::string _message;
    };

    template <typename T, typename _T>
    struct is_divisible_by : std::exception {

        is_divisible_by(const T & value, const _T & divisor)
            : _value(value) , _divisor(divisor) 
        { 
            std::ostringstream message("");
            message << "spec:: value supplied ("
                << _value 
                << ") is divisible by ("
                << _divisor
                << ")";

            _message = message.str();
        };

        const char * what() const throw (){
            return _message.c_str() ;
        };

        ~is_divisible_by() throw () { };
        
        T _value;
        _T _divisor;
        std::string _message;
    };

    template <typename T, typename _T>
    struct does_not_match_exception : std::exception {

        does_not_match_exception(const T & value, const _T & pattern)
            : _value(value) , _pattern(pattern) 
        { 
            std::ostringstream message("");
            message << "spec:: value supplied ("
                << _value 
                << ") does not match pattern '"
                << _pattern
                << "'";

            _message = message.str();
        };

        const char * what() const throw (){
            return _message.c_str() ;
        };

        ~does_not_match_exception() throw () { };
        
        T _value;
        _T _pattern;
        std::string _message;
    };

    template <typename T>
        struct is_odd : std::exception {
            explicit is_odd(T const & value)
                : _value(value) {
                    std::ostringstream message("");
                    message << "spec:: value supplied ("
                        << _value
                        << ") is odd.";

                    _message = message.str();
                };

            const char * what() const throw () {
                return _message.c_str();
            };

            ~is_odd() throw () { };

            T _value;
            std::string _message;
        };

    template <typename T>
        struct is_even : std::exception {
            explicit is_even(T const & value)
                : _value(value) {
                    std::ostringstream message("");
                    message << "spec:: value supplied ("
                        << _value
                        << ") is even.";

                    _message = message.str();
                };

            const char * what() const throw () {
                return _message.c_str();
            };

            ~is_even() throw () { };

            T _value;
            std::string _message;
        };

    template <typename T>
        struct container_does_not_contain : std::exception {
            explicit container_does_not_contain (T const & value)
                : _value(value) {
                    std::ostringstream message("");
                    message << "spec:: container supplied does not contain value ("
                        << _value
                        << ").";

                    _message = message.str();
                };

            const char * what() const throw () {
                return _message.c_str();
            };

            ~container_does_not_contain() throw () { };

            T _value;
            std::string _message;
        };

    template <typename T>
        struct container_contains : std::exception {
            explicit container_contains (T const & value)
                : _value(value) {
                    std::ostringstream message("");
                    message << "spec:: container supplied contains value ("
                        << _value
                        << ").";

                    _message = message.str();
                };

            const char * what() const throw () {
                return _message.c_str();
            };

            ~container_contains() throw () { };

            T _value;
            std::string _message;
        };

    template <typename T>
        struct is_null : std::exception {
            explicit is_null(T const & value)
                : _value(value) {
                    std::ostringstream message("");
                    message << "spec:: value supplied ("
                        << _value
                        << ") is NULL.";

                    _message = message.str();
                };

            const char * what() const throw () {
                return _message.c_str();
            };

            ~is_null() throw () { };

            T _value;
            std::string _message;
        };

    template <typename T>
        struct is_not_null : std::exception {
            explicit is_not_null(T const & value)
                : _value(value) {
                    std::ostringstream message("");
                    message << "spec:: value supplied ("
                        << _value
                        << ") is not NULL.";

                    _message = message.str();
                };

            const char * what() const throw () {
                return _message.c_str();
            };

            ~is_not_null() throw () { };

            T _value;
            std::string _message;
        };

    template <typename T>
        struct container_not_empty : std::exception {
            typedef T type;
            explicit container_not_empty()
                {
                    std::ostringstream message("");
                    message << "spec:: container supplied is not empty.";

                    _message = message.str();
                };

            const char * what() const throw () {
                return _message.c_str();
            };

            ~container_not_empty() throw () { };

            std::string _message;
        };

    template <typename T>
        struct container_empty : std::exception {
            typedef T type;
            explicit container_empty()
                {
                    std::ostringstream message("");
                    message << "spec:: container supplied is empty.";

                    _message = message.str();
                };

            const char * what() const throw () {
                return _message.c_str();
            };

            ~container_empty() throw () { };

            std::string _message;
        };
}; // namespace spec

}; // namespace boost

#endif

