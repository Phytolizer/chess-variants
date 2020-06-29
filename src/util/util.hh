/**
 * @file util.hh
 * @author your name (you@domain.com)
 * @brief Contains miscellaneous abstractions for coding convenience.
 * @date 2020-06-23
 */

#ifndef UTIL_UTIL_HH
#define UTIL_UTIL_HH

#include <iostream>
#include <sstream>
#include <string>


/**
 * @namespace util
 * @brief Various utility functions for coding convenience
 *
 */
namespace util
{
namespace _internal
{
/**
 * @brief Internal concatenation base case function, called by util::_internal::concat_r
 *
 * @tparam T the final parameter's type
 * @param ss the stringstream to append to
 * @param it the final parameter
 * @return std::string the string representation of the contents of `ss` concatenated with `it`
 */
template <typename T> std::string concat_r(std::stringstream &ss, T it)
{
    ss << it;
    return ss.str();
}

/**
 * @brief Internal recursive concatenation function, called by util::concat
 *
 * @tparam T the type of the first param
 * @tparam Ts the types of the other params
 * @param ss the stringstream to append to
 * @param first the first param
 * @param rest the other params
 * @return std::string a string representation of all params concatenated together
 */
template <typename T, typename... Ts> std::string concat_r(std::stringstream &ss, T first, Ts... rest)
{
    ss << first;
    return concat_r(ss, rest...);
}
} // namespace _internal

/**
 * @brief The base case of the concat function. Calling this function directly may be useful to quickly
 * convert any parameter to a string.
 *
 * @tparam T the parameter's type
 * @param it the parameter
 * @return std::string a string representation of the parameter
 */
template <typename T> std::string concat(T it)
{
    std::stringstream ss;
    ss << it;
    return ss.str();
}
/**
 * @brief Concatenate all parameters into a single string. Uses stringstreams internally.
 *
 * @tparam T the first parameter's type
 * @tparam Ts the types of other parameters
 * @param first the first parameter
 * @param rest the rest of the parameters
 * @return std::string a string representation of the parameters concatenated together
 */
template <typename T, typename... Ts> std::string concat(T first, Ts... rest)
{
    std::stringstream ss;
    ss << first;
    return _internal::concat_r(ss, rest...);
}

/**
 * @brief Print the parameter using std::cout. This is the base case of print(T, Ts...).
 *
 * @tparam T the parameter's type
 * @param it the parameter to print
 */
template <typename T> void print(T it)
{
    std::cout << it;
}

/**
 * @brief Print the parameters using std::cout. This is purely a syntactic conversion.
 *
 * @tparam T the first parameter's type
 * @tparam Ts the other parameter types
 * @param first the first parameter to print
 * @param rest the rest will be put back in this function recursively
 */
template <typename T, typename... Ts> void print(T first, Ts... rest)
{
    std::cout << first;
    print(rest...);
}

/**
 * @brief Trim whitespace from either end of a string.
 *
 * @param s the string to trim
 * @return std::string the trimmed string
 */
std::string trim(std::string_view s);

/**
 * @brief Parse an integer from a string.
 * 
 * @param s the string
 * @return long the integer
 */
long parseInt(std::string_view s);
} // namespace util

#endif // UTIL_UTIL_HH
