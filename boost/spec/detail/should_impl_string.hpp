// Copyright 2006, 2007 Dean Michael Berris.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt )

#ifndef __SPEC_SHOULD_IMPL_STR_HPP__
#define __SPEC_SHOULD_IMPL_STR_HPP__

#include <boost/spec/exceptions.hpp>
#include <string>
#include <boost/regex.hpp>

namespace boost { namespace spec { namespace detail {

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

            bool match(std::string const & pattern) const {
                boost::regex re(pattern);
                if (!regex_match(_value, re))
                    throw does_not_match_exception<std::string, std::string>(_value, pattern);
                return true;
            };
        };

    template <>
        struct should_impl<std::string> : should_impl<char const *> {
            explicit should_impl(std::string const & value)
                : should_impl<char const *>(value)
            { };
        };

}; // detail

}; // spec

}; // boost
#endif
