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

template <typename Domain, typename Iterator, typename Attribute>
struct lws : http_parsers::grammar<Domain, Iterator, Attribute()>::type
{
  lws();

  typename http_parsers::rule<Domain, Iterator, Attribute()>::type start;
};

} }

#endif
