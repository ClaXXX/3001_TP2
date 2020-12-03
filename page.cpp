#include "page.hpp"

#include <algorithm>
#include <assert.h>
#include <stdlib.h>

void effaceMoi(const std::vector<Resultat> resultats) {
  // Cette fonction a deux utilites:
  //  1) Vous prouver qu'on peut declarer et implementer de nouvelles
  //  	 fonctions dans un .cpp sans les declarer dans le fichier .hpp
  //  	 (que vous ne devez pas modifier)
  //  2) Vous faire réaliser que cette fonction qui ne semble rien faire
  //     s'exécute en fait en Theta(n) puisque le vecteur est copie
  //     (il n'est pas passe par reference)
  //  Maintenant que vous le savez, vous pouvez effacer cette fonction.
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

  // Inserez votre code ici.
  //  - Vous ne pouvez pas modifier le vecteur resultats_non_tries, mais rien ne vous empeche de modifier une copie.
  //  - N'hesitez pas a definir d'autres fonctions (mais ne les declarez pas le .hpp)

  effaceMoi(resultats_non_tries);
}
