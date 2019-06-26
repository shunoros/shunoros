#pragma once

#include <string_view>
namespace shunoros
{

template <typename T>
constexpr auto
type_name()
{
  using namespace std::string_view_literals;
#ifdef __clang__
  constexpr auto prefix = "auto shunoros::type_name() [T = "sv;
  constexpr auto suffix = "]"sv;
  std::string_view name = __PRETTY_FUNCTION__;
#elif defined(__GNUC__)
  constexpr auto prefix = "constexpr shunoros::auto type_name() [with T = "sv;
  constexpr auto suffix = "]"sv;
  std::string_view name = __PRETTY_FUNCTION__;
#elif defined(_MSC_VER)
  constexpr auto prefix = "auto __cdecl shunoros::type_name<"sv;
  constexpr auto suffix = ">(void)"sv;
  std::string_view name = __FUNCSIG__;
#endif
  name.remove_prefix(prefix.size());
  name.remove_suffix(suffix.size());
  return name;
}

} // shunoros