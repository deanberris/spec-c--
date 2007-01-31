// Copyright 2006, 2007 Dean Michael Berris.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt )

#ifndef __SPEC_EXCEPTIONS_HPP__
#define __SPEC_EXCEPTIONS_HPP__

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

}; // namespace spec

}; // namespace boost

#endif

