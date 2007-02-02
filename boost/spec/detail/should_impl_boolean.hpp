// Copyright 2006, 2007 Dean Michael Berris.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt )

#ifndef __SPEC_SHOULD_IMPL_BOOLEAN_HPP__
#define __SPEC_SHOULD_IMPL_BOOLEAN_HPP__

namespace boost { namespace spec { namespace detail {

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

}; // detail

}; // spec

}; // boost

#endif
