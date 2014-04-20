/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/mime/absolute_uri.hpp>

#include <boost/spirit/home/qi/domain.hpp>
#include <boost/spirit/home/karma/domain.hpp>

#include <boost/spirit/home/support/common_terminals.hpp>
#include <boost/spirit/home/support/auxiliary/attr_cast.hpp>
#include <boost/spirit/home/support/char_class.hpp>

#include <boost/spirit/home/karma/numeric.hpp>

#include <boost/spirit/home/phoenix.hpp>

namespace http_parsers { namespace mime {

namespace spirit = boost::spirit;

namespace {

template <typename Iterator, typename Attribute>
void init_absolute_uri(spirit::qi::domain
                       , absolute_uri<spirit::qi::domain, Iterator, Attribute>& self)
{
  using spirit::raw;
  using spirit::lit;
  using spirit::ascii::char_;
  using spirit::ascii::cntrl;
  self.start %=
    raw
    [
     self.scheme
     && ':' && lit("//") && -(self.userinfo && '@') && self.host && -(':' && self.port)
     && self.path && -('?' && self.query) && -('#' && self.fragment)
    ]
    ;
  self.path %= *('/' && +(char_ - (cntrl | ' ' | '\t')));
  self.host %= self.domain_part && *('.' && self.domain_part);
}

template <typename Iterator, typename Attribute>
void init_absolute_uri(spirit::karma::domain
                       , absolute_uri<spirit::karma::domain, Iterator, Attribute>& self)
{
  namespace karma = spirit::karma;
  self.start %=
    *(
      (
       spirit::duplicate
       [
        &spirit::standard::char_(' ')
        << spirit::lit('%')
        << spirit::hex
       ]
      )
      | spirit::ascii::char_
     )
    ;
}

}

template <typename Domain, typename Iterator, typename Attribute>
absolute_uri<Domain, Iterator, Attribute>::absolute_uri()
  : absolute_uri::base_type(start)
{
  using boost::spirit::lit;
  using boost::spirit::ascii::xdigit;
  using boost::spirit::int_;
  using boost::spirit::eps;
  using boost::spirit::ascii::alnum;
  using boost::spirit::ascii::alpha;
  using boost::spirit::ascii::char_;
  using boost::spirit::ascii::cntrl;

  mime::init_absolute_uri(Domain(), *this);
  userinfo = 
    +(
      (
       alnum | '-' | '.' | '_' | '~'
       | '!' | '$' | '&' | '\'' | '(' | ')'
       | '*' | '+' | ',' | ';' | '='
      )
      | ('%' && xdigit && xdigit)
     );
  port = int_;
  query = eps(false);
  fragment = eps(false);
  domain_part %= +alnum;
  scheme %= alpha && *(alnum | '+' | '-' | '.');

  start.name("absolute_uri"); debug(start);
  // BOOST_SPIRIT_DEBUG_NODE(userinfo);
  // BOOST_SPIRIT_DEBUG_NODE(host);
  // BOOST_SPIRIT_DEBUG_NODE(port);
  // BOOST_SPIRIT_DEBUG_NODE(path);
  // BOOST_SPIRIT_DEBUG_NODE(query);
  // BOOST_SPIRIT_DEBUG_NODE(fragment);
  // BOOST_SPIRIT_DEBUG_NODE(domain_part);
};

} }
