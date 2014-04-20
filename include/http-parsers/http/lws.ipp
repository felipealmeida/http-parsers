/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/http/lws.hpp>

#include <boost/spirit/home/support/char_class.hpp>

namespace http_parsers { namespace http {

namespace spirit = boost::spirit;

template <typename Domain, typename Iterator, typename Attribute>
lws<Domain, Iterator, Attribute>::lws()
  : lws::base_type(start)
{
  namespace spirit = boost::spirit;

  start %=
    -spirit::lit("\r\n")
    && +(spirit::ascii::char_(' ') | '\t')
    ;

  // start.name("lws"); debug(start);
}

} }
