/*=============================================================================
    Copyright (c) 2012 Paul Fultz II
    first_or_default.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef LINQ_GUARD_EXTENSIONS_FIRST_OR_DEFAULT_H
#define LINQ_GUARD_EXTENSIONS_FIRST_OR_DEFAULT_H

#include <linq/extensions/extension.h>
#include <linq/extensions/detail/always.h>
#include <linq/extensions/first.h>
#include <boost/range.hpp>

namespace linq { 

//
// first_or_default
//
namespace detail {
struct first_or_default_t
{
    template<class Range>
    auto operator()(Range && r) LINQ_RETURNS(r | linq::first(always(), typename boost::range_value<Range>::type()));

    template<class Range, class Predicate>
    auto operator()(Range && r, Predicate p) LINQ_RETURNS(r | linq::first(p, typename boost::range_value<Range>::type()));
};
}
namespace {
range_extension<detail::first_or_default_t> first_or_default = {};
}

}

#endif
