/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef HTTP_PARSERS_HTTP_NONTERMINAL_HPP
#define HTTP_PARSERS_HTTP_NONTERMINAL_HPP

#include <boost/spirit/home/support/unused.hpp>

namespace http_parsers {

namespace spirit = boost::spirit;

template <typename Domain, typename Iterator
          , typename A1 = spirit::unused_type
          , typename A2 = spirit::unused_type
          , typename A3 = spirit::unused_type
          , typename A4 = spirit::unused_type>
struct grammar;

template <typename Domain, typename Iterator
          , typename A1 = spirit::unused_type
          , typename A2 = spirit::unused_type
          , typename A3 = spirit::unused_type
          , typename A4 = spirit::unused_type>
struct rule;

}

#endif
