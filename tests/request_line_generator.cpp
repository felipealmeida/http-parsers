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

#include <http-parsers/nonterminal_karma.hpp>
#include <boost/spirit/home/karma.hpp>

#define BOOST_TEST_MODULE request_line
#include <boost/test/included/unit_test.hpp>

const char google_uri[] = "http://www.google.com/index.html";
const char request_line_get_abs_path[] = "GET /index.html HTTP/1.1\r\n";
const char request_line_get_abs_uri[] = "GET http://www.google.com/index.html HTTP/1.1\r\n";

BOOST_AUTO_TEST_CASE(test1)
{
  using boost::fusion::at_c;

  typedef boost::fusion::vector3<std::string
                                 , std::string
                                 , http_parsers::http::version
                                >
    attribute_type;
  typedef std::back_insert_iterator<std::vector<char> > iterator;
  http_parsers::http::request_line
    <boost::spirit::karma::domain, iterator, attribute_type> request_line;

  attribute_type attribute("GET", "/", http_parsers::http::version(1, 1));
  bool b;
  std::vector<char> buffer;
  b = boost::spirit::karma::generate(std::back_inserter(buffer), request_line, attribute);
  BOOST_REQUIRE(b);
  std::cout << "buffer ";
  std::copy(buffer.begin(), buffer.end(), std::ostream_iterator<char>(std::cout));
  std::endl(std::cout);
  BOOST_REQUIRE_EQUAL(buffer.size(), 16u);
  BOOST_CHECK(std::equal(buffer.begin(), buffer.end(), "GET / HTTP/1.1\r\n"));

  buffer.clear();

  at_c<1u>(attribute) = "http://www.google.com/index.html";

  b = boost::spirit::karma::generate(std::back_inserter(buffer), request_line, attribute);
  BOOST_REQUIRE(b);
  std::cout << "buffer ";
  std::copy(buffer.begin(), buffer.end(), std::ostream_iterator<char>(std::cout));
  std::endl(std::cout);
  BOOST_REQUIRE_EQUAL(buffer.size(), 47u);
  BOOST_CHECK(std::equal(buffer.begin(), buffer.end(), "GET http://www.google.com/index.html HTTP/1.1\r\n"));
}
