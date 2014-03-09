/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef HTTP_PARSERS_HTTP_HTTP_VERSION_HPP
#define HTTP_PARSERS_HTTP_HTTP_VERSION_HPP

#include <boost/spirit/home/qi.hpp>

namespace http_parsers { namespace http {

template <typename Iterator, typename Attribute>
struct http_version : qi::grammar<Iterator, Attribute()>
{
  http_version();

  qi::rule<Iterator, Attribute()> start;
};

} }

#endif
