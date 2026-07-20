
#include <cmath>
#include <iostream>
#include <random>

int main() {
  std::mt19937 rng(std::random_device{}());
  std::uniform_real_distribution<double> dist(0.0, 90.0);

  auto sum_f = 0.f;
  auto sum_d = 0.;

  const auto population_size = 90'000'000;
  for (auto i = 0; i < population_size; ++i) {
    const auto age = dist(rng);
    sum_f += static_cast<float>(age);
    sum_d += age;
  }

  const auto average_f = sum_f / population_size;
  const auto average_d = sum_d / population_size;

  std::cout << "Average age (float): " << average_f << std::endl;
  std::cout << "Average age (double): " << average_d << std::endl;
  std::cout << "Difference: " << std::abs(average_f - average_d) / average_d
            << " %" << std::endl;
}
