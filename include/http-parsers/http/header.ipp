/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/http/header.hpp>

#include <boost/spirit/home/support/char_class.hpp>
#include <boost/spirit/home/support/common_terminals.hpp>

namespace http_parsers { namespace http {

namespace spirit = boost::spirit;

template <typename Domain, typename Iterator, typename Attribute>
header<Domain, Iterator, Attribute>::header()
  : header::base_type(start)
{
  namespace spirit = boost::spirit;

  start %=
    token
    && spirit::omit[':']
    && field_value
    && spirit::omit["\r\n"]
    ;

  field_value = *(spirit::omit[lws] | field_content)
    ;

  field_content = +(spirit::ascii::char_ - (spirit::ascii::cntrl | '\r' | '\n'));

  // start.name("header"); debug(start);
  // field_value.name("field_value"); debug(field_value);
  // field_content.name("field_content"); debug(field_content);
}

} }
