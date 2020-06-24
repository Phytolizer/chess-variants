/**
 * @file util.hh
 * @author your name (you@domain.com)
 * @brief Contains miscellaneous abstractions for coding convenience.
 * @date 2020-06-23
 */

#ifndef UTIL_UTIL_HH
#define UTIL_UTIL_HH

#include <sstream>
#include <string>

namespace util
{
namespace _internal
{
template <typename T, typename... Ts> std::string concat_r(std::stringstream &ss, T first, Ts... rest)
{
    ss << first;
    return concat_r(ss, rest...);
}

template <typename T> std::string concat_r(std::stringstream &ss, T it)
{
    ss << it;
    return ss.str();
}
} // namespace _internal

template <typename T, typename... Ts> std::string concat(T first, Ts... rest)
{
    std::stringstream ss;
    ss << first;
    return _internal::concat_r(ss, rest...);
}
template <typename T> std::string concat(T it)
{
    std::stringstream ss;
    ss << it;
    return ss.str();
}
} // namespace util

#endif // UTIL_UTIL_HH