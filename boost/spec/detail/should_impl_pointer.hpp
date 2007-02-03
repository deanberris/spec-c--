// Copyright 2006, 2007 Dean Michael Berris.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt )

#ifndef __SPEC_SHOULD_IMPL_POINTER_HPP__
#define __SPEC_SHOULD_IMPL_POINTER_HPP__

namespace boost { namespace spec { namespace detail {

    template <typename T>
        struct should_impl_ptr {
            T * _ptr;

            explicit should_impl_ptr(T * const & ptr) : _ptr(ptr) { };

            bool be_null() const {
                if (NULL != _ptr)
                    throw is_not_null<T *>(_ptr);
                return true;
            };

            bool not_be_null() const {
                if (NULL == _ptr)
                    throw is_null<T *>(_ptr);
                return true;
            };

        };

}; // detail

}; // spec

}; // boost

#endif

