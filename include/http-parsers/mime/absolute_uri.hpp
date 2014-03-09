/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef HTTP_PARSERS_MIME_ABSOLUTE_URI_HPP
#define HTTP_PARSERS_MIME_ABSOLUTE_URI_HPP

#include <boost/spirit/home/qi.hpp>

namespace http_parsers { namespace mime {

namespace qi = boost::spirit::qi;

template <typename Iterator, typename Attribute>
struct absolute_uri : qi::grammar<Iterator, Attribute()>
{
  absolute_uri();

  qi::rule<Iterator, Attribute()> start;
  qi::rule<Iterator> scheme, userinfo, password, host, port, query, domain_part;
  qi::rule<Iterator> path;
};

} }

#endif
