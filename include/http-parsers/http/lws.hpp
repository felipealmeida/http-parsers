/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef HTTP_PARSERS_HTTP_LWS_HPP
#define HTTP_PARSERS_HTTP_LWS_HPP

#include <http-parsers/nonterminal.hpp>

namespace http_parsers { namespace http {

namespace qi = boost::spirit::qi;
namespace fusion = boost::fusion;

template <typename Domain, typename Iterator, typename Attribute>
struct lws : http_parsers::grammar<Domain, Iterator, Attribute()>::type
{
  lws();

  // typedef typename attribute_at_c<Attribute, 0u>::type version_attribute_type;
  // typedef typename attribute_at_c<Attribute, 1u>::type code_attribute_type;
  // typedef typename attribute_at_c<Attribute, 2u>::type message_attribute_type;
  typename http_parsers::rule<Domain, Iterator, Attribute()>::type start;
};

} }

#endif
