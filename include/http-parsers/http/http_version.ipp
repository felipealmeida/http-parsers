/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/http/http_version.hpp>

namespace http_parsers { namespace http {

template <typename Domain, typename Iterator, typename Attribute>
http_version<Domain, Iterator, Attribute>::http_version()
  : http_version::base_type(start)
{
  start %= "HTTP/" && qi::int_ && '.' && qi::int_;

  start.name("http_version"); debug(start);
}

} }
