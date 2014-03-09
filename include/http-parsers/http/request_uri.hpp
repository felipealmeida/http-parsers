/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef HTTP_PARSERS_HTTP_REQUEST_URI_HPP
#define HTTP_PARSERS_HTTP_REQUEST_URI_HPP

#include <http-parsers/mime/absolute_uri.hpp>

#include <boost/spirit/home/qi.hpp>

namespace http_parsers { namespace http {

namespace qi = boost::spirit::qi;

template <typename Iterator, typename Attribute>
struct request_uri : qi::grammar<Iterator, Attribute()>
{
  request_uri();

  //typedef typename attribute_at_c<Attribute, 0u>::type 
  qi::rule<Iterator, Attribute()> start;
  mime::absolute_uri<Iterator, Attribute> absolute_uri;
};

} }

#endif
