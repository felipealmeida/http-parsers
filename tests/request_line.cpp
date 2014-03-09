/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/http/request_line.hpp>
#include <http-parsers/http/request_line.ipp>
#include <http-parsers/http/token.ipp>
#include <http-parsers/http/request_uri.ipp>
#include <http-parsers/http/http_version.ipp>
#include <http-parsers/mime/absolute_uri.ipp>

const char request_line_get_abs_path[] = "GET /index.html HTTP/1.1\r\n";
const char request_line_get_abs_uri[] = "GET http://www.google.com/index.html HTTP/1.1\r\n";

int main()
{
  typedef boost::fusion::vector<boost::iterator_range<const char*>
                                , boost::iterator_range<const char*>
                                , boost::fusion::vector<int, int> >
    attribute_type;
  http_parsers::http::request_line<const char*, attribute_type> request_line;

  attribute_type attribute;
  bool b;
  b = boost::spirit::qi::parse
    (&request_line_get_abs_uri[0], &request_line_get_abs_uri[0] + sizeof(request_line_get_abs_uri) - 1
     , request_line
     , attribute);
  assert(b);

  b = boost::spirit::qi::parse
    (&request_line_get_abs_path[0], &request_line_get_abs_path[0] + sizeof(request_line_get_abs_path) - 1
     , request_line
     , attribute);
  assert(b);
}
