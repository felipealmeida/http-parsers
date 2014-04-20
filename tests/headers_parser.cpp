/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/spirit_logical_and.hpp>
#include <http-parsers/http/header.hpp>
#include <http-parsers/http/header.ipp>
#include <http-parsers/http/lws.ipp>
#include <http-parsers/http/token.ipp>

#include <http-parsers/nonterminal_qi.hpp>
#include <boost/spirit/home/qi.hpp>

#define BOOST_TEST_MODULE header_parser
#include <boost/test/included/unit_test.hpp>

const char header_test1[] = "X: content\r\n";
const char header_test2[] = "X: content\r\n content2\r\n";

const char* const header_errors[] = 
  {
    "X\r\n: content\r\n content2\r\n"
    , "X: content\r\ncontent2\r\n"
  };

BOOST_AUTO_TEST_CASE(test1)
{
  using boost::fusion::at_c;

  typedef boost::fusion::vector2<std::string&, std::vector<std::string>&>
    attribute_type;
  http_parsers::http::header
    <boost::spirit::qi::domain, const char*, attribute_type> header;

  std::string name;
  std::vector<std::string> value;

  attribute_type attribute(name, value);
  bool b;
  {
    b = boost::spirit::qi::parse
      (&header_test1[0], &header_test1[sizeof(header_test1) - 1]
       , header, attribute);
    BOOST_REQUIRE(b);
    std::cout << "field name " << name << std::endl;
    std::cout << "field values ";
    std::copy(value.begin(), value.end(), std::ostream_iterator<std::string>(std::cout));
    std::endl(std::cout);

    BOOST_CHECK_EQUAL(name, "X");

    BOOST_REQUIRE_EQUAL(value.size(), 1);
    BOOST_CHECK_EQUAL(value[0], "content");
  }
  name.clear(); value.clear();
  {
    b = boost::spirit::qi::parse
      (&header_test2[0], &header_test2[sizeof(header_test2) - 1]
       , header, attribute);
    BOOST_REQUIRE(b);
    std::cout << "field name " << name << std::endl;
    std::cout << "field values ";
    std::copy(value.begin(), value.end()
              , std::ostream_iterator<std::string>(std::cout, ", "));
    std::endl(std::cout);

    BOOST_CHECK_EQUAL(name, "X");

    BOOST_REQUIRE_EQUAL(value.size(), 2);
    BOOST_CHECK_EQUAL(value[0], "content");
    BOOST_CHECK_EQUAL(value[1], "content2");
  }






  // To fail
  for(const char*const* first = header_errors
        , *const*last = first + sizeof(header_errors)/sizeof(header_errors[0])
        ;first != last; ++first)
  {
    assert(first != 0);
    assert(*first != 0);
    std::cout << "Testing " << *first << std::endl;
    const char* iterator = *first;
    b = boost::spirit::qi::parse
      (iterator, *first + std::strlen(*first), header, attribute)
      && iterator == (*first + std::strlen(*first));
    BOOST_REQUIRE(!b);
  }



}
