#include <iostream>
#include <vector>
#include "question1.hpp"
#include <matplot/matplot.h>
using namespace matplot;

#define MAX_N 10

/**
 * Matplot++ installed only
 * @return
 */
int main(void)
{
  std::vector<std::string> colors = {"blue", "red", "magenta"};
  auto x = linspace(10, 100, 10);

  colororder(colors);
  hold(on);
  for (unsigned int i = 0; i < MAX_N; i++)
  {
    auto y2 = transform(x, [&](double x) { return ((double)AlgorithmeProbabiliste2(std::vector<bool>(x, generate(0,1)))); });
    auto y2Min = transform(x, [&](double x) { return ((double)AlgorithmeProbabiliste2(std::vector<bool>(x, false))); });
    auto y2Max = transform(x, [&](double x) { return ((double)AlgorithmeProbabiliste2(std::vector<bool>(x, true))); });
    scatter(x, y2);
    scatter(x, y2Max);
    scatter(x, y2Min);
  }

//  for (unsigned int i = 0; i < MAX_N; i++)
//  {
//    auto y1 = transform(x, [&](double x) { return ((double)AlgorithmeProbabiliste1(std::vector<bool>(x, generate(0,1)))); });
//    auto y1Min = transform(x, [&](double x) { return ((double)AlgorithmeProbabiliste1(std::vector<bool>(x, false))); });
//    auto y1Max = transform(x, [&](double x) { return ((double)AlgorithmeProbabiliste1(std::vector<bool>(x, true))); });
//    scatter(x, y1);
//    scatter(x, y1Max);
//    scatter(x, y1Min);
//  }
  hold(off);

  show();
  return 0;
}