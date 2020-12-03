#include <vector>
#include <random>

int generate(const int from, const int to)
{
  static std::default_random_engine generator;
  std::uniform_int_distribution<int> uniform(from, to);

  return uniform(generator);
}

int AlgorithmeProbabiliste1(const std::vector<bool> A)
{
  const unsigned int n = A.size();
  const unsigned int k = generate(1, n);

  int c = 0;
  if ((unsigned int )A.at(0) == k) {
    for (unsigned int i = k; i <= n; i++) {
      for (unsigned int j = 1; j <= k; j++) {
        c+=1;
      }
    }
  }
  return c;
}

int AlgorithmeProbabiliste2(const std::vector<bool> A)
{
  const unsigned int n = A.size();
  const unsigned int k = generate(1, n);

  int c = 0;
  if (!A.at(0)) {
    for (unsigned int i = 1; i <= k; i++) {
      c+=1;
    }
  }
  return c;
}