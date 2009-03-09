// Copyright 2006, 2007 Dean Michael Berris.
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt )

#ifndef __SPEC_DETAIL_CONTAINER_SHOULD_IMPL_HPP__
#define __SPEC_DETAIL_CONTAINER_SHOULD_IMPL_HPP__

#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <algorithm>

namespace boost { namespace spec { namespace detail {

    template <typename T>
    struct should_container_impl {
        T & _container;
        explicit should_container_impl (T & container) : _container(container) { };

        template <typename _T>
            bool contain(_T const & element) const {
                BOOST_STATIC_ASSERT((boost::is_same<typename T::value_type, _T>::value));
                if (std::find(_container.begin(), _container.end(), element) == _container.end())
                    throw container_does_not_contain<_T>(element);
                return true;
            };

        template <typename _T>
            bool not_contain(_T const & element) const {
                BOOST_STATIC_ASSERT((boost::is_same<typename T::value_type, _T>::value));
                if (std::find(_container.begin(), _container.end(), element) != _container.end())
                    throw container_contains<_T>(element);
                return true;
            };

        bool be_empty() const {
            if (!_container.empty())
                throw container_not_empty<T>();
            return true;
        };

        bool not_be_empty() const {
            if (_container.empty())
                throw container_empty<T>();
            return true;
        };

        bool be_not_empty() const {
            return not_be_empty();
        };

        bool have_size(typename T::size_type size) const {
            return (_container.size() == size);
        };
    };

}; // namespace detail

}; // namespace spec

}; // namespace boost

#endif
