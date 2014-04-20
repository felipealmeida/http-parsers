/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef HTTP_PARSERS_HTTP_PARSER_LINE_HPP
#define HTTP_PARSERS_HTTP_PARSER_LINE_HPP

#include <http-parsers/http/token.hpp>
#include <http-parsers/http/request_uri.hpp>
#include <http-parsers/http/http_version.hpp>
#include <http-parsers/attribute_at.hpp>
#include <http-parsers/nonterminal.hpp>

#include <boost/spirit/home/qi.hpp>
#include <boost/fusion/include/at.hpp>

namespace http_parsers { namespace http {

namespace qi = boost::spirit::qi;
namespace fusion = boost::fusion;

template <typename Domain, typename Iterator, typename Attribute>
struct request_line : http_parsers::grammar<Domain, Iterator, Attribute()>::type
{
  request_line();

  typedef typename attribute_at_c<Attribute, 0u>::type token_attribute_type;
  typedef typename attribute_at_c<Attribute, 1u>::type request_uri_attribute_type;
  typedef typename attribute_at_c<Attribute, 2u>::type http_version_attribute_type;
  typename http_parsers::rule<Domain, Iterator, Attribute()>::type start;
  http::token<Domain, Iterator, token_attribute_type> token;
  http::request_uri<Domain, Iterator, request_uri_attribute_type> request_uri;
  http::http_version<Domain, Iterator, http_version_attribute_type> http_version;
};

} }

#endif

