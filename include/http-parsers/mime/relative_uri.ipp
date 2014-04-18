/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#include <http-parsers/mime/relative_uri.hpp>

#include <boost/spirit/home/qi/domain.hpp>
#include <boost/spirit/home/karma/domain.hpp>

#include <boost/spirit/home/support/common_terminals.hpp>
#include <boost/spirit/home/support/char_class.hpp>

namespace http_parsers { namespace mime {

namespace spirit = boost::spirit;

namespace {

template <typename Iterator, typename Attribute>
void init_relative_uri(spirit::qi::domain
                       , relative_uri<spirit::qi::domain, Iterator, Attribute>& self)
{
  using spirit::raw;
  using spirit::lit;
  using spirit::ascii::char_;
  using spirit::ascii::cntrl;
  self.start %= raw[self.path >> -('?' >> self.query) >> -('#' >> self.fragment)];
  self.path %= -char_('/') >> (+(char_ - (cntrl | ' ' | '\t'))) % '/';
}

template <typename Iterator, typename Attribute>
void init_relative_uri(spirit::karma::domain
                       , relative_uri<spirit::karma::domain, Iterator, Attribute>& self)
{
  using spirit::lit;
  self.start %=
    self.path
    // && -('?' && self.query)
    // && -('#' && self.fragment)
    ;
  self.path %= spirit::ascii::string;
}

}

template <typename Domain, typename Iterator, typename Attribute>
relative_uri<Domain, Iterator, Attribute>::relative_uri()
  : relative_uri::base_type(start)
{
  using boost::spirit::eps;
  using boost::spirit::ascii::char_;
  using boost::spirit::ascii::cntrl;

  mime::init_relative_uri(Domain(), *this);
  query = eps(false);
  fragment = eps(false);

  start.name("relative_uri"); debug(start);
  BOOST_SPIRIT_DEBUG_NODE(path);
  BOOST_SPIRIT_DEBUG_NODE(query);
  BOOST_SPIRIT_DEBUG_NODE(fragment);
};

} }
