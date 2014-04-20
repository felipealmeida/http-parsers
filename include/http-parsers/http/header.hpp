/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef HTTP_PARSERS_HTTP_HEADER_HPP
#define HTTP_PARSERS_HTTP_HEADER_HPP

#include <http-parsers/http/token.hpp>
#include <http-parsers/http/lws.hpp>

#include <http-parsers/attribute_at.hpp>

namespace http_parsers { namespace http {

template <typename Domain, typename Iterator, typename Attribute>
struct header : http_parsers::grammar<Domain, Iterator, Attribute()>::type
{
  header();

  typedef typename attribute_at_c<Attribute, 0u>::type name_attribute_type;
  typedef typename attribute_at_c<Attribute, 1u>::type content_attribute_type;
  typename http_parsers::rule<Domain, Iterator, Attribute()>::type start;
  http::token<Domain, Iterator, name_attribute_type> token;
  http::lws<Domain, Iterator, typename content_attribute_type::value_type> lws;
  typename http_parsers::rule<Domain, Iterator, content_attribute_type()>::type field_value;
  typename http_parsers::rule
  <Domain, Iterator, typename content_attribute_type::value_type()>::type
  field_content;
};

} }

#endif

