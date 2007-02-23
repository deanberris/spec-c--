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
#include <boost/spec/detail/container_should_impl.hpp>
#include <boost/type_traits/is_array.hpp>
#include <boost/type_traits/is_pointer.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_pointer.hpp>
#include <boost/type_traits/remove_all_extents.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/logical.hpp>

namespace boost { namespace spec {

    namespace tags {
        template <typename T> struct pointer { typedef T type; };
        template <typename T> struct wrap_ { typedef T type; };
    };

    using namespace boost::mpl;

    template <typename T>
    struct spec {
        typedef typename if_<
            and_<
                boost::is_array<T>, 
                boost::is_same<
                    typename boost::remove_all_extents<T>::type,
                    char
                > 
            >,
            tags::wrap_<std::string> , 
            typename if_<
                boost::is_pointer<T>,
                tags::pointer<typename boost::remove_all_extents<T>::type>,
                tags::wrap_<T>
            >::type
        >::type type;

        typename type::type _value;

        typename if_<
            boost::is_same<
                tags::pointer<typename boost::remove_all_extents<T>::type>,
                type
            >,
            detail::should_impl_ptr<typename boost::remove_pointer<T>::type>,
            detail::should_impl<typename type::type>
        >::type should, & must;

        explicit spec(
                typename if_<
                    boost::is_same<
                        tags::pointer<typename boost::remove_all_extents<T>::type>,
                        type
                    >,
                    typename boost::remove_pointer<T>::type * const,
                    T const
                >::type
                    & v) : _value(v), should(_value), must(should) { };
    };
    
    template <typename T>
    inline spec<T> value (const T & v) {
        return spec<T>(v);
    };

    template <typename T>
    struct container_spec {
        typedef T type;
        T & container;
        detail::should_container_impl<T> should, & must;

        explicit container_spec(T & container_) : container(container_), should(container), must(should) { };
    };

    template <typename T>
    inline container_spec<T> container(T & c) {
        return container_spec<T>(c);
    };

}; // namespace spec

}; // namepsace boost

#endif // __SPEC_HPP_
