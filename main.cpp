#include <cassert>
#include <vector>
#include <random>
#include <iostream>
#include <algorithm>

enum alphabet { A = 0, B = 1, C = 2, D = 3, E = 4, F = 5, G = 6, H = 7, I = 8, J = 9, K = 10, L = 11, M = 12, N = 13, O = 14, P = 15, Q = 16, R = 17, S = 18, T = 19, U = 20, V = 21, W = 22, X = 23, Y = 24, Z = 25, END = 26 };

[[nodiscard]] int to_code(const alphabet a) { return static_cast<int>(a); }
[[nodiscard]] alphabet to_alphabet(const int c) { 
  if (A <= c && c <= Z) return static_cast<alphabet>(c); 
  throw c;
}

using alphabet_vec = std::vector<alphabet>;

void print_alphabet_vec(const alphabet_vec& av) { std::for_each(av.begin(), av.end(), [](auto a){ std::cout << to_code(a) << ' '; }); std::cout << std::endl; }

[[nodiscard]] alphabet_vec make_filled_alphabet_vec(const size_t number_of_random_values){
    std::random_device dev{};
    std::mt19937 rng{dev()};
    std::uniform_int_distribution<int> dist(A, Z);

    alphabet_vec result{};
    result.reserve(Z + number_of_random_values);
    for (int alphabet_code{0}; alphabet_code < END; ++alphabet_code) {
	result.push_back(to_alphabet(alphabet_code));
    }
    for (size_t run{0}; run < number_of_random_values; ++run) {
	const auto random_alphabet_code{dist(rng)};
	result.push_back(to_alphabet(random_alphabet_code));
    }
    // print_alphabet_vec(result);
    return result;
}

void count_alphabet(const alphabet_vec& av){
  using alphabet_count_vec = std::vector<size_t>;
  alphabet_count_vec acv(END);
  for (const auto& a : av) {
    ++acv.at(to_code(a));
  }
  for (size_t idx{0}; idx < acv.size(); ++idx) {
    // std::cout << "Alphabet with code [" << idx << "] was encountered [" << acv[idx] << "] times." << std::endl;
  }

}


int main() {
  try {
    const auto av{make_filled_alphabet_vec(10000)};
    count_alphabet(av);
  } catch (...) {
    std::cerr << "Failure!" << std::endl;
    return EXIT_FAILURE;
  }
  std::cout << "Success!" << std::endl;
  return EXIT_SUCCESS;
}






