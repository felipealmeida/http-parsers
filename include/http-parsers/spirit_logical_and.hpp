/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef HTTP_PARSERS_HTTP_SPIRIT_LOGICAL_AND_HPP
#define HTTP_PARSERS_HTTP_SPIRIT_LOGICAL_AND_HPP

#include <boost/spirit/home/support.hpp>
#include <boost/spirit/home/karma/domain.hpp>
#include <boost/spirit/home/qi/domain.hpp>
#include <boost/spirit/home/qi/meta_compiler.hpp>
#include <boost/spirit/home/karma/meta_compiler.hpp>
#include <boost/spirit/home/qi/operator/sequence.hpp>
#include <boost/spirit/home/karma/operator/sequence.hpp>

namespace boost { namespace spirit {

///////////////////////////////////////////////////////////////////////////
// Enablers
///////////////////////////////////////////////////////////////////////////
template <>
struct use_operator<karma::domain, proto::tag::logical_and> // enables <<
  : mpl::true_ {};

template <>
struct flatten_tree<karma::domain, proto::tag::logical_and> // flattens <<
  : mpl::true_ {};

///////////////////////////////////////////////////////////////////////////
// Enablers
///////////////////////////////////////////////////////////////////////////
template <>
struct use_operator<qi::domain, proto::tag::logical_and> // enables >>
  : mpl::true_ {};

template <>
struct flatten_tree<qi::domain, proto::tag::logical_and> // flattens >>
  : mpl::true_ {};

namespace karma {

template <typename Elements, typename Modifiers>
struct make_composite<proto::tag::logical_and, Elements, Modifiers>
  : detail::make_sequence<Elements, detail::get_stricttag<Modifiers>::value>
{};

}

namespace qi {

///////////////////////////////////////////////////////////////////////////
// Parser generators: make_xxx function (objects)
///////////////////////////////////////////////////////////////////////////
template <typename Elements, typename Modifiers>
struct make_composite<proto::tag::logical_and, Elements, Modifiers>
  : make_nary_composite<Elements, sequence>
{};

} } }

#endif
