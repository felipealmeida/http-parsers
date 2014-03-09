/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/http/token.hpp>

namespace http_parsers { namespace http {

template <typename Iterator, typename Attribute>
token<Iterator, Attribute>::token()
  : token::base_type(start)
{
  start %= 
    +(
    qi::char_ - (qi::cntrl
                 | '(' | ')' | '<' | '>' | '@'
                 | ',' | ';' | ':' | '\\'| '"'
                 | '/' | '[' | ']' | '?' | '='
                 | '{' | '}' | ' ' | '\t')
     )
    ;
}

} }
