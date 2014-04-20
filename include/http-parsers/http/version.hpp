/* (c) Copyright 2014 Felipe Magno de Almeida
 *
 * Distributed under the Boost Software License, Version 1.0. (See
 * accompanying file LICENSE_1_0.txt or copy at
 * http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef HTTP_PARSERS_HTTP_PARSERS_VERSION_HPP
#define HTTP_PARSERS_HTTP_PARSERS_VERSION_HPP

#include <boost/fusion/include/adapt_struct.hpp>

namespace http_parsers { namespace http {

#if defined(major) || defined(minor)
#pragma push_macro("major")
#pragma push_macro("minor")
#undef major
#undef minor
#endif

struct version
{
  version() : major(1), minor(1) {}
  version(int (major), int (minor))
    : major(major), minor(minor) {}

  int (major), (minor);
};

} }

BOOST_FUSION_ADAPT_STRUCT( ::http_parsers::http::version
                           , (int, major)
                           (int, minor)
                         )

#if defined(major) || defined(minor)
#pragma pop_macro("major")
#pragma pop_macro("minor")
#endif

#endif
