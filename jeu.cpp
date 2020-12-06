#include "jeu.hpp"

#include "tableau.hpp"

#define MONSTRES 0
#define ROUGE 1
#define BLEU 2

template<typename T>
T max(T a, T b) {
  if (a > b)
    return a;
  return b;
}

void init(Tableau<unsigned int>& D, std::vector<unsigned int> sizes) {
  for (unsigned int j = 0; j < sizes.at(ROUGE); ++j)
    for (unsigned int k = 0; k < sizes.at(BLEU); ++k)
      D.at(0,j,k) = 0;
}

void fillDynamicTab(Tableau<unsigned int>& D, const std::vector<Monstre>& monstres, unsigned int magie_rouge, unsigned int magie_bleue) {
  for (unsigned int i = 0; i < monstres.size(); ++i) {
    const Monstre& monstre = monstres.at(i);

    for (unsigned int j = 1; j <= magie_rouge; ++j) {
      for (unsigned int k = 1; k <= magie_bleue; ++k) {
        if (j >= monstre.magieRouge() && k >= monstre.magieBleue()) {
          D.at(i+1,j,k) = max(D.at(i,j,k),
                              monstre.degat() + D.at(i, j-monstre.magieRouge(), k-monstre.magieBleue()));
        } else {
          D.at(i+1,j,k) = D.at(i,j,k);
        }
      }
    }
  }
}

std::vector<Monstre> programmationDynamique(const std::vector<Monstre>& monstres, unsigned int magie_rouge, unsigned int magie_bleue) {
  std::vector<unsigned int> sizes(3);
  sizes[MONSTRES] = monstres.size() + 1;
  sizes[ROUGE] = magie_rouge + 1;
  sizes[BLEU] = magie_bleue + 1;

  Tableau<unsigned int> D(sizes);
  std::vector<Monstre> L{};

  init(D, sizes);
  fillDynamicTab(D, monstres, magie_rouge, magie_bleue);
  for (int i = monstres.size(); i > 0; --i) {
    if (D.at(i,magie_rouge,magie_bleue) > D.at(i-1,magie_rouge,magie_bleue)) {
      L.push_back(monstres.at(i-1));
      magie_rouge-=monstres.at(i-1).magieRouge();
      magie_bleue-=monstres.at(i-1).magieBleue();
    }
  }
  return L;
}
