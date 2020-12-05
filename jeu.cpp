#include "jeu.hpp"

#include <math.h>
#include "tableau.hpp"

Tableau<Monstre> Tab(const std::vector<Monstre>& monstres, unsigned int magie_rouge, unsigned int magie_bleue)
{
  std::vector<unsigned int> degats;
  std::vector<unsigned int> rouge;
  std::vector<unsigned int> bleue;
  Tableau<unsigned int> tableau(std::vector<unsigned int>(monstres.size()));

  for (unsigned int i = 0; i < monstres.size(); i++) {
    const Monstre& monstre = monstres.at(i);
    tableau.at(0, i, monstre.degat());
    tableau.at()
    degats.push_back(monstre.degat());
    rouge.push_back(monstre.magieRouge());
    bleue.push_back(monstre.magieBleue());
  }
}

std::vector<Monstre> programmationDynamique(const std::vector<Monstre>& monstres, unsigned int magie_rouge, unsigned int magie_bleue) {
  // Inserez votre code ici
  std::vector<Monstre> D{};
  //Tableau<unsigned int> tableau(std::vector<unsigned int >(3)); // tableau à 3 dimensions

  if (!magie_bleue || !magie_rouge)
    return D;
  for (const Monstre& monstre : monstres) {

  }
  return D;
}
