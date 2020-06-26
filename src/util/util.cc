#include "util.hh"

namespace util
{
std::string trim(std::string_view s)
{
    std::string s2 = s.data();
    auto first = std::find_if(s2.begin(), s2.end(), [](char c) { return !std::isspace(c); });
    auto last = std::find_if(s2.rbegin(), s2.rend(), [](char c) { return !std::isspace(c); });
    s2.erase(s2.begin(), first);
    s2.erase(last.base(), s2.end());
    return s2;
}
} // namespace util