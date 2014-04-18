/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef HTTP_PARSERS_HTTP_NONTERMINAL_QI_HPP
#define HTTP_PARSERS_HTTP_NONTERMINAL_QI_HPP

#include <http-parsers/nonterminal.hpp>

#include <boost/spirit/home/qi/nonterminal.hpp>

namespace http_parsers {

namespace qi = boost::spirit::qi;

template <typename Iterator, typename A1, typename A2, typename A3, typename A4>
struct grammar<qi::domain, Iterator, A1, A2, A3, A4>
{
  typedef qi::grammar<Iterator, A1, A2, A3, A4> type;
};

template <typename Iterator, typename A1, typename A2, typename A3, typename A4>
struct rule<qi::domain, Iterator, A1, A2, A3, A4>
{
  typedef qi::rule<Iterator, A1, A2, A3, A4> type;
};

}

#endif
