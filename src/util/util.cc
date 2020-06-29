#include "util.hh"

namespace util
{
std::string trim(std::string_view s)
{
    std::string s2 = s.data();
    auto first = std::find_if(s2.begin(), s2.end(), [](char c) { return !static_cast<bool>(std::isspace(c)); });
    auto last = std::find_if(s2.rbegin(), s2.rend(), [](char c) { return !static_cast<bool>(std::isspace(c)); });
    s2.erase(s2.begin(), first);
    s2.erase(last.base(), s2.end());
    return s2;
}

long parseInt(std::string_view s)
{
    char *end;
    constexpr int BASE = 10;
    long l = std::strtol(s.data(), &end, BASE);
    if (s.length() == 0 || *end != '\0')
    {
        throw std::runtime_error(concat("parsing integer: '", s, "' is not an integer"));
    }
    return l;
}
} // namespace util