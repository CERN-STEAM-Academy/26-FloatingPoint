
#include <bit>
#include <cmath>
#include <cstdint>
#include <iostream>

inline constexpr float ln2 = std::log(2.f);

namespace detail {
template <std::size_t Order> auto exp_taylor(float x) {
  if constexpr (Order == 1) {
    return 1 + x;
  } else if constexpr (Order == 2) {
    return 1 + x + .5f * x * x;
  } else if constexpr (Order == 3) {
    return 1 + x + .5f * x * x + x * x * x / 6.f;
  } else if constexpr (Order == 4) {
    return 1 + x + .5f * x * x + x * x * x / 6.f + x * x * x * x / 24.f;
  } else if constexpr (Order == 5) {
    return 1 + x + .5f * x * x + x * x * x / 6.f + x * x * x * x / 24.f +
           x * x * x * x * x / 120.f;
  }
}
} // namespace detail

template <std::size_t Order> auto exp_taylor(float number) {
  const auto k = std::round(number / ln2);
  const auto y = number - k * ln2;

  auto expy = detail::exp_taylor<Order>(y);
  auto expx = std::bit_cast<std::uint32_t>(expy) +
              (static_cast<std::uint32_t>(k) << 23);
  return std::bit_cast<float>(expx);
}

int main() {
  std::cout << "1 order, exp 10 = " << exp_taylor<1u>(10.f) << " with error = "
            << std::abs(exp_taylor<1u>(10.f) - std::exp(10.f)) * 100 /
                   std::exp(10.f)
            << "%" << std::endl;
  std::cout << "2 order, exp 10 = " << exp_taylor<2u>(10.f) << " with error = "
            << std::abs(exp_taylor<2u>(10.f) - std::exp(10.f)) * 100 /
                   std::exp(10.f)
            << "%" << std::endl;
  std::cout << "3 order, exp 10 = " << exp_taylor<3u>(10.f) << " with error = "
            << std::abs(exp_taylor<3u>(10.f) - std::exp(10.f)) * 100 /
                   std::exp(10.f)
            << "%" << std::endl;
  std::cout << "4 order, exp 10 = " << exp_taylor<4u>(10.f) << " with error = "
            << std::abs(exp_taylor<4u>(10.f) - std::exp(10.f)) * 100 /
                   std::exp(10.f)
            << "%" << std::endl;
  std::cout << "5 order, exp 10 = " << exp_taylor<5u>(10.f) << " with error = "
            << std::abs(exp_taylor<5u>(10.f) - std::exp(10.f)) * 100 /
                   std::exp(10.f)
            << "%" << std::endl;
}
