/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef HTTP_PARSERS_HTTP_REQUEST_URI_HPP
#define HTTP_PARSERS_HTTP_REQUEST_URI_HPP

#include <http-parsers/mime/absolute_uri.hpp>
#include <http-parsers/mime/relative_uri.hpp>

#include <http-parsers/nonterminal.hpp>

namespace http_parsers { namespace http {

template <typename Domain, typename Iterator, typename Attribute>
struct request_uri : http_parsers::grammar<Domain, Iterator, Attribute()>::type
{
  request_uri();

  typename http_parsers::rule<Domain, Iterator, Attribute()>::type start;
  mime::absolute_uri<Domain, Iterator, Attribute> absolute_uri;
  mime::relative_uri<Domain, Iterator, Attribute> relative_uri;
};

} }

#endif
