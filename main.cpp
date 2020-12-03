#include <iostream>
#include <vector>
#include "question1.hpp"
#include <matplot/matplot.h>

#define MAX_N 10
#define DEFAULT_VALUE false
#define RADOM_GENERATED true

/**
 * Matplot++ installed only
 * @return
 */
int main(void)
{
  using namespace matplot;
  std::vector<bool> vector(MAX_N, DEFAULT_VALUE);
  std::vector<std::string> colors = {"blue", "red", "magenta"};

  auto x = linspace(10, 100, 10);
  auto c = linspace(1,10,x.size());
  auto y1 = transform(x, [&](double x) { return ((double)AlgorithmeProbabiliste1(std::vector<bool>(x, generate(0,1)))); });
  auto y1Min = transform(x, [&](double x) { return ((double)AlgorithmeProbabiliste1(std::vector<bool>(x, false))); });
  auto y1Max = transform(x, [&](double x) { return ((double)AlgorithmeProbabiliste1(std::vector<bool>(x, true))); });

  auto y2 = transform(x, [&](double x) { return ((double)AlgorithmeProbabiliste2(std::vector<bool>(x, generate(0,1)))); });
  auto y2Min = transform(x, [&](double x) { return ((double)AlgorithmeProbabiliste2(std::vector<bool>(x, false))); });
  auto y2Max = transform(x, [&](double x) { return ((double)AlgorithmeProbabiliste2(std::vector<bool>(x, true))); });

  colororder(colors);
  hold(on);
//  scatter(x, y1);
//  scatter(x, y1Max);
//  scatter(x, y1Min);
  scatter(x, y2);
  scatter(x, y2Max);
  scatter(x, y2Min);
  hold(off);

  show();

  // First Algorithme
  std::cout << "AlgorithmeProbabiliste1: "<< std::endl;
  for (unsigned int i = 0; i < MAX_N; i++) {
    std::cout << AlgorithmeProbabiliste1((RADOM_GENERATED ? (std::vector<bool>(MAX_N, generate(0,1))) : vector)) << std::endl;
  }

  // Second Algorithme
  std::cout << "AlgorithmeProbabiliste2: "<< std::endl;
  for (unsigned int i = 0; i < MAX_N; i++) {
    std::cout << AlgorithmeProbabiliste2((RADOM_GENERATED ? (std::vector<bool>(MAX_N, generate(0,1))) : vector)) << std::endl;
  }
  return 0;
}