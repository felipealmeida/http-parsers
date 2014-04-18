/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/http/token.hpp>

#include <boost/spirit/home/qi/domain.hpp>
#include <boost/spirit/home/karma/domain.hpp>

#include <boost/spirit/home/support/common_terminals.hpp>
#include <boost/spirit/home/support/char_class.hpp>

namespace http_parsers { namespace http {

namespace spirit = boost::spirit;

namespace {

template <typename Rule>
void init_token(spirit::qi::domain, Rule& rule)
{
  rule %=
    +(
      spirit::ascii::char_
      - (spirit::ascii::cntrl
         | '(' | ')' | '<' | '>' | '@'
         | ',' | ';' | ':' | '\\'| '"'
         | '/' | '[' | ']' | '?' | '='
         | '{' | '}' | ' ' | '\t'
        )
     )
    ;
}

template <typename Rule>
void init_token(spirit::karma::domain, Rule& rule)
{
  rule %= spirit::ascii::string;
}

}

template <typename Domain, typename Iterator, typename Attribute>
token<Domain, Iterator, Attribute>::token()
  : token::base_type(start)
{
  http::init_token(Domain(), start);
}

} }
