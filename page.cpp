#include "page.hpp"

#include <algorithm>
#include <assert.h>
#include <random>

/**
 * Utils
 */

template<typename T>
void swap(T &a, T &b)
{
  T c = a;
  a = b;
  b = c;
}

template<typename T>
T min(T a, T b)
{
  if (a < b)
    return a;
  return b;
}

/**
 * QuickSort Functions
 */

long generate(const long from, const long to)
{
  static std::default_random_engine generator;
  std::uniform_int_distribution<long> uniform(from, to);

  return uniform(generator);
}

unsigned long Partition(std::vector<Resultat> &A, std::pair<unsigned long, unsigned long> limits)
{
  unsigned long s = generate(limits.first, limits.second);
  unsigned long j = limits.first;
  swap(A[j], A[s]);
  const Resultat p = A.at(j);

  for (unsigned long i = j + 1; i <= limits.second; i++) {
    if (A[i] < p) {
      j++;
      swap(A[i], A[j]);
    }
  }
  swap(A[j], A[limits.first]);
  return j;
}

/**
 * QuickSort
 * @param A : entrée et resultat
 * @param limits : nous permet d'éviter de copier à chaque fois le vector
 * @param from : début de la page
 * @param k : nombre d'éléments par page
 */
void QuickSort(std::vector<Resultat> &A, const std::pair<long, long> limits, const unsigned long from, const unsigned int k)
{
  if (limits.second - limits.first < 1)
    return;
  const unsigned long s = Partition(A, limits);

  if (s < from + k)
    QuickSort(A, std::pair<long, long>(s + 1, limits.second), from, k);
  if (s > from)
    QuickSort(A, std::pair<long, long>(limits.first, s - 1), from, k);
}

// Retourne les resultats d'une page
// Entrees:
//   resultats_non_tries: tous les resultats de recherche non tries
//   nombre_resultats_par_page: le nombre de resultats par page (sauf possiblement sur la derniere page)
//   numero_page: le numero de la page. La premiere page est la page numero 0.
// Sortie:
//   page: les resultats de recherche se trouvant sur la page demandee
void retournePage(const std::vector<Resultat>& resultats_non_tries, unsigned int nombre_resultats_par_page, unsigned int numero_page, std::vector<Resultat>& page) {
  assert(!resultats_non_tries.empty());
  assert(page.empty());
  assert(nombre_resultats_par_page > 0);
  assert(numero_page < (resultats_non_tries.size() + nombre_resultats_par_page - 1) / nombre_resultats_par_page); // (a + b - 1) / b = plafond(a/b)
  unsigned long from = nombre_resultats_par_page * numero_page;
  std::vector<Resultat> A = std::vector<Resultat>(resultats_non_tries);

  QuickSort(A, std::pair<long, long>(0, A.size() - 1), from, nombre_resultats_par_page);
  page = std::vector<Resultat>(A.begin() + min(from, A.size()),
                               A.begin() + min(from + nombre_resultats_par_page, A.size()));
}
