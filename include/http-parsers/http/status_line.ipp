/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/http/status_line.hpp>

#include <boost/spirit/home/support/char_class.hpp>

namespace http_parsers { namespace http {

namespace spirit = boost::spirit;

template <typename Domain, typename Iterator, typename Attribute>
status_line<Domain, Iterator, Attribute>::status_line()
  : status_line::base_type(start)
{
  start %= 
    http_version
    && spirit::omit[' ']
    && spirit::repeat(3u)[spirit::ascii::digit]
    && *
    (
     spirit::ascii::char_
     - ( 
         spirit::ascii::cntrl | '\r' | '\n'
       )
    )
    && spirit::omit["\r\n"]
    ;

  // start.name("request_line"); debug(start);
}

} }
