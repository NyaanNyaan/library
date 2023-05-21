#pragma once

#include <type_traits>
using namespace std;

namespace internal {
template <typename T>
using is_broadly_integral =
    typename conditional_t<is_integral_v<T> || is_same_v<T, __int128_t> ||
                               is_same_v<T, __uint128_t>,
                           true_type, false_type>::type;

template <typename T>
using is_broadly_signed =
    typename conditional_t<is_signed_v<T> || is_same_v<T, __int128_t>,
                           true_type, false_type>::type;

template <typename T>
using is_broadly_unsigned =
    typename conditional_t<is_unsigned_v<T> || is_same_v<T, __uint128_t>,
                           true_type, false_type>::type;

#define ENABLE_VALUE(x) \
  template <typename T> \
  constexpr bool x##_v = x<T>::value;

ENABLE_VALUE(is_broadly_integral);
ENABLE_VALUE(is_broadly_signed);
ENABLE_VALUE(is_broadly_unsigned);
#undef ENABLE_VALUE

#define ENABLE_HAS_TYPE(var)                                              \
  template <class, class = void>                                         \
  struct has_##var : std::false_type {};                                 \
  template <class T>                                                     \
  struct has_##var<T, std::void_t<typename T::var>> : std::true_type {}; \
  template <class T>                                                     \
  constexpr auto has_##var##_v = has_##var<T>::value;

}  // namespace internal
