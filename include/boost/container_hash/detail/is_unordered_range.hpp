// Copyright 2017 Peter Dimov.
// Distributed under the Boost Software License, Version 1.0.
// https://www.boost.org/LICENSE_1_0.txt

#ifndef BOOST_HASH_DETAIL_IS_UNORDERED_RANGE_HPP_INCLUDED
#define BOOST_HASH_DETAIL_IS_UNORDERED_RANGE_HPP_INCLUDED

#include <boost/container_hash/detail/is_range.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/is_same.hpp>

namespace boost
{
namespace hash_detail
{

template<class T, class E = true_type> struct has_hasher_: false_type
{
};

template<class T> struct has_hasher_< T, integral_constant< bool,
        is_same<typename T::hasher, typename T::hasher>::value
    > >: true_type
{
};

template<class T> struct is_unordered_range: integral_constant< bool, is_range<T>::value && has_hasher_<T>::value >
{
};

} // namespace hash_detail
} // namespace boost

#endif // #ifndef BOOST_HASH_DETAIL_IS_UNORDERED_RANGE_HPP_INCLUDED
