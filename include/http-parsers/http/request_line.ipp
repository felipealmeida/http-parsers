/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/http/request_line.hpp>

namespace http_parsers { namespace http {

template <typename Domain, typename Iterator, typename Attribute>
request_line<Domain, Iterator, Attribute>::request_line()
  : request_line::base_type(start)
{
  start %= /*raw[*/token//]
    && ' '
    && /*raw[*/request_uri//]
    && ' '
    && http_version
    && "\r\n"
    ;

  // start.name("request_line"); debug(start);
}

} }
