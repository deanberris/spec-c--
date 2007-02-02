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
        struct should_impl;

}; // namespace detail

}; // namespace spec

}; // namespace boost

#include <boost/spec/detail/should_impl_string.hpp>
#include <boost/spec/detail/should_impl_integral.hpp>
#include <boost/spec/detail/should_impl_boolean.hpp>

#endif

