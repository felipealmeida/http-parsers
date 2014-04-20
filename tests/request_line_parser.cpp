/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/spirit_logical_and.hpp>
#include <http-parsers/http/version.hpp>
#include <http-parsers/http/request_line.hpp>
#include <http-parsers/http/request_line.ipp>
#include <http-parsers/http/token.ipp>
#include <http-parsers/http/request_uri.ipp>
#include <http-parsers/http/http_version.ipp>
#include <http-parsers/mime/absolute_uri.ipp>
#include <http-parsers/mime/relative_uri.ipp>

#include <http-parsers/nonterminal_qi.hpp>
#include <boost/spirit/home/qi.hpp>

#define BOOST_TEST_MODULE request_line
#include <boost/test/included/unit_test.hpp>

const char google_uri[] = "http://www.google.com/index.html";
const char request_line_get_abs_path[] = "GET /index.html HTTP/1.1\r\n";
const char request_line_get_abs_uri[] = "GET http://www.google.com/index.html HTTP/1.1\r\n";

BOOST_AUTO_TEST_CASE(test1)
{
  using boost::fusion::at_c;

  typedef boost::fusion::vector<std::string, std::string
                                , http_parsers::http::version>
    attribute_type;
  http_parsers::http::request_line
    <boost::spirit::qi::domain, const char*, attribute_type> request_line;

  attribute_type attribute;
  bool b;
  b = boost::spirit::qi::parse
    (&request_line_get_abs_uri[0], &request_line_get_abs_uri[0] + sizeof(request_line_get_abs_uri) - 1
     , request_line
     , attribute);
  BOOST_REQUIRE(b);
  std::cout << "method " << boost::distance(at_c<0>(attribute)) << std::endl;
  BOOST_REQUIRE(boost::distance(at_c<0>(attribute)) == 3);
  BOOST_CHECK(std::equal(at_c<0>(attribute).begin(), at_c<0>(attribute).end()
                         , "GET"));
  std::cout << "request_uri " << boost::distance(at_c<1>(attribute)) << std::endl;
  BOOST_REQUIRE(boost::distance(at_c<1>(attribute)) == 32);
  BOOST_CHECK(std::equal(at_c<1>(attribute).begin(), at_c<1>(attribute).end()
                         , google_uri));
  BOOST_CHECK(at_c<2>(attribute).major == 1);
  BOOST_CHECK(at_c<2>(attribute).minor == 1);

  at_c<0>(attribute).clear(); at_c<1>(attribute).clear();

  b = boost::spirit::qi::parse
    (&request_line_get_abs_path[0], &request_line_get_abs_path[0] + sizeof(request_line_get_abs_path) - 1
     , request_line
     , attribute);
  BOOST_REQUIRE(b);
  BOOST_REQUIRE(boost::distance(at_c<0>(attribute)) == 3);
  BOOST_CHECK(std::equal(at_c<0>(attribute).begin(), at_c<0>(attribute).end()
                         , "GET"));
  BOOST_REQUIRE(boost::distance(at_c<1>(attribute)) == 11);
  BOOST_CHECK(std::equal(at_c<1>(attribute).begin(), at_c<1>(attribute).end()
                         , "/index.html"));
  BOOST_CHECK(at_c<2>(attribute).major == 1);
  BOOST_CHECK(at_c<2>(attribute).minor == 1);
}
