
#include <concepts>
#include <iostream>

template <std::floating_point T> auto compute(std::size_t N) {
  auto result = T{0};
  for (auto i = 0u; i < N; ++i) {
    result += T(0.1);
  }

  return result;
}

int main(int argc, char** argv) {
  const auto N = std::stoul(argv[1]);
  std::cout << "result: " << compute<float>(N) << " truth: " << static_cast<double>(N) / 10.
            << std::endl;
  std::cout << "result: " << compute<double>(N) << " truth: " << static_cast<double>(N) / 10.
            << std::endl;
}
