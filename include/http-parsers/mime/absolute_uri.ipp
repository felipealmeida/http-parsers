/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/mime/absolute_uri.hpp>

namespace http_parsers { namespace mime {

template <typename Iterator, typename Attribute>
absolute_uri<Iterator, Attribute>::absolute_uri()
  : absolute_uri::base_type(start)
{
  start %= scheme >> ':' >> -qi::lit("//") >> -userinfo >> -password >> -host >> -port
             >> path >> -('?' >> query)
    ;
  userinfo = qi::eps(false);
  password = qi::eps(false);
  port = qi::eps(false);
  domain_part %= +qi::alnum;
  host %= domain_part >> *('.' >> domain_part);
  scheme %= qi::alpha >> *(qi::alpha | qi::digit | '+' | '-' | '.');
  path %= +('/' >> +(qi::char_ - (qi::cntrl | ' ' | '\t')));

  start.name("absolute_uri"); debug(start);
  // BOOST_SPIRIT_DEBUG_NODE(start);
  BOOST_SPIRIT_DEBUG_NODE(userinfo);
  BOOST_SPIRIT_DEBUG_NODE(password);
  BOOST_SPIRIT_DEBUG_NODE(host);
  BOOST_SPIRIT_DEBUG_NODE(port);
  BOOST_SPIRIT_DEBUG_NODE(path);
  BOOST_SPIRIT_DEBUG_NODE(query);
  BOOST_SPIRIT_DEBUG_NODE(domain_part);
};

} }
