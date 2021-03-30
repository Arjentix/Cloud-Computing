#include <iostream>
#include <vector>
#include <iterator>
#include <numeric>

template <typename Iter>
int RecursiveSum(Iter first, Iter last) {
  if (first == last) {
    return 0;
  }

  return *first + RecursiveSum(std::next(first), last);
}

int main() {
  std::vector<int> a(10);
  std::iota(a.begin(), a.end(), 1); // Заполнение числами 1, 2, 3, ...

  std::cout << RecursiveSum(a.begin(), a.end()) << std::endl;

  return 0;
}
