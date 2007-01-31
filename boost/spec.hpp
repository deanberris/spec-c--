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
#include <boost/type_traits/is_array.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_all_extents.hpp>
#include <boost/mpl/if.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/logical.hpp>

namespace boost { namespace spec {

    using namespace boost::mpl;

    template <typename T>
    struct spec {
        typedef typename if_< 
                and_<
                    boost::is_array<
                        T
                    >, 
                    boost::is_same<
                        typename boost::remove_all_extents<T>::type, 
                        char
                    > 
                >,
                std::string , 
                T 
            >::type type;

        type const & _value;
        detail::should_impl<type> should;

        spec(type const & v) : _value(v), should(_value){ };
    };
    
    template <typename T>
    inline spec <T> value (const T & v) {
        return spec<T>(v);
    };

}; // namespace spec

}; // namepsace boost

#endif // __SPEC_HPP_
