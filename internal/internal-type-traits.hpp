#pragma once

#include <type_traits>

using namespace std;

namespace internal {
template <typename T>
using is_broadly_integral =
    typename conditional_t<is_integral_v<T> || is_same_v<T, __int128_t> ||
                               is_same_v<T, __uint128_t>,
                           true_type, false_type>;
template <typename T>
constexpr bool is_broadly_integral_v = is_broadly_integral<T>::value;
}  // namespace internal
