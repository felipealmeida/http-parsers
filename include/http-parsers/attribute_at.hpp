/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef HTTP_PARSERS_ATTRIBUTE_AT_HPP
#define HTTP_PARSERS_ATTRIBUTE_AT_HPP

#include <boost/type_traits/remove_reference.hpp>

#include <boost/fusion/include/at.hpp>

namespace http_parsers {

template <typename Attribute, unsigned int I>
struct attribute_at_c
{
  typedef typename boost::remove_reference
  <typename boost::fusion::result_of::at_c<Attribute, I>::type>::type type;

};

}

#endif

