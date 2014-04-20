/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/spirit_logical_and.hpp>
#include <http-parsers/http/status_line.hpp>
#include <http-parsers/http/status_line.ipp>
#include <http-parsers/http/http_version.ipp>
#include <http-parsers/http/version.hpp>

#include <http-parsers/nonterminal_qi.hpp>
#include <boost/spirit/home/qi.hpp>

#define BOOST_TEST_MODULE status_line
#include <boost/test/included/unit_test.hpp>

const char status_line_test1[] = "HTTP/1.1 200 OK\r\n";
const char status_line_test2[] = "HTTP/1.1 404 Some Error\r\n";

BOOST_AUTO_TEST_CASE(test1)
{
  using boost::fusion::at_c;

  typedef boost::fusion::vector3<http_parsers::http::version
                                , std::string, std::string>
    attribute_type;
  http_parsers::http::status_line
    <boost::spirit::qi::domain, const char*, attribute_type> status_line;

  attribute_type attribute;
  bool b;
  b = boost::spirit::qi::parse
    (&status_line_test1[0], &status_line_test1[sizeof(status_line_test1) - 1]
     , status_line
     , attribute);
  BOOST_REQUIRE(b);
  std::cout << "method " << boost::distance(at_c<1>(attribute)) << std::endl;
  BOOST_REQUIRE(boost::distance(at_c<1>(attribute)) == 3);
  BOOST_CHECK(std::equal(at_c<1>(attribute).begin(), at_c<1>(attribute).end()
                         , "200"));
  std::cout << "status_uri " << boost::distance(at_c<2>(attribute)) << std::endl;
  BOOST_REQUIRE(boost::distance(at_c<2>(attribute)) == 3);
  BOOST_CHECK(std::equal(at_c<2>(attribute).begin(), at_c<2>(attribute).end()
                         , " OK"));

  at_c<1>(attribute).clear(); at_c<2>(attribute).clear();

  b = boost::spirit::qi::parse
    (&status_line_test2[0], &status_line_test2[sizeof(status_line_test2) - 1]
     , status_line
     , attribute);
  BOOST_REQUIRE(b);
  BOOST_REQUIRE(boost::distance(at_c<1>(attribute)) == 3);
  BOOST_CHECK(std::equal(at_c<1>(attribute).begin(), at_c<1>(attribute).end()
                         , "404"));
  BOOST_REQUIRE(boost::distance(at_c<2>(attribute)) == 11);
  BOOST_CHECK(std::equal(at_c<2>(attribute).begin(), at_c<2>(attribute).end()
                         , " Some Error"));
}
