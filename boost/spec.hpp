// Copyright 2006, 2007 Dean Michael Berris.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt )

#ifndef __SPEC_HPP_
#define __SPEC_HPP_

#include <exception>
#include <sstream>
#include <string>

#include <boost/spec/exceptions.hpp>
#include <boost/spec/detail/should_impl.hpp>

namespace boost { namespace spec {

    template <typename T>
    struct spec {
        T _value;
        detail::should_impl<T> should;

        spec(const T & v) : _value(v), should(_value){ };
    };
    
    template <typename T>
    inline spec<T> value (const T & v) {
        return spec<T>(v);
    };

}; // namespace spec

}; // namepsace boost

#endif // __SPEC_HPP_
