#pragma once

#include <functional>
namespace shunoros
{

template <typename F, typename... Args>
auto delay_invoke(F&& f, Args&&... args) {
  return [f=std::forward<F>(f), ...args=std::forward<Args>(args)]() mutable-> decltype(auto) {
    return std::invoke(std::forward<F>(f), std::forward<Args>(args)...);
  };
}

} // shunoros