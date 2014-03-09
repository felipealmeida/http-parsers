/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/http/request_uri.hpp>

namespace http_parsers { namespace http {

template <typename Iterator, typename Attribute>
request_uri<Iterator, Attribute>::request_uri()
  : request_uri::base_type(start)
{
  start %= absolute_uri /*| relative_uri*/;
  
  start.name("request_uri"); debug(start);
}

} }

