/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/spirit_logical_and.hpp>
#include <http-parsers/http/version.hpp>
#include <http-parsers/http/request_uri.hpp>
#include <http-parsers/http/request_uri.ipp>
#include <http-parsers/mime/absolute_uri.ipp>
#include <http-parsers/mime/relative_uri.ipp>

#include <http-parsers/nonterminal_karma.hpp>
#include <boost/spirit/home/karma.hpp>

#define BOOST_TEST_MODULE request_uri_generator
#include <boost/test/included/unit_test.hpp>

const char* const uri_test_srcs[] = 
  {
    "http://www.google.com/index.html"
    , "http://www.google.com/index .html"
  };
const char* const uri_test_res[] = 
  {
    "http://www.google.com/index.html"
    , "http://www.google.com/index%20.html"
  };

BOOST_AUTO_TEST_CASE(test_success)
{
  using boost::fusion::at_c;

  typedef std::string attribute_type;
  typedef std::back_insert_iterator<std::string> iterator;
  http_parsers::http::request_uri
    <boost::spirit::karma::domain, iterator, attribute_type> request_uri;

  assert(sizeof(uri_test_srcs)/sizeof(uri_test_srcs[0])
         == sizeof(uri_test_res)/sizeof(uri_test_res[0]));

  for(std::size_t i = 0; i != sizeof(uri_test_srcs)/sizeof(uri_test_srcs[0]); ++i)
  {
    std::string buffer;
    attribute_type attribute(uri_test_srcs[i]);
    bool b = boost::spirit::karma::generate(std::back_inserter(buffer), request_uri, attribute);
    BOOST_REQUIRE(b);
    std::cout << "buffer " << buffer << std::endl;
    BOOST_CHECK_EQUAL(buffer, uri_test_res[i]);
  }
}
