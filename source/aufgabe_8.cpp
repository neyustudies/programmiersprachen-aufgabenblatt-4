#include <cstdlib>    // std::rand()
#include <vector>     // std::vector<>
#include <list>       // std::list<>
#include <iostream>   // std::cout
#include <iterator>   // std::ostream_iterator<>
#include <algorithm>  // std::reverse, std::generate

int main() {

  /* erstellt Vector namens v_0, 
  container kann 10 ints aufnehmen */
  std::vector<int>v_0(10);
  
  /* generiert 10 ints und speichert sie in v_0 */
  for(auto& v : v_0) {
    v=std::rand();
  }

  /* mittels const iterator werden alle Elemente aus v_0 in den 
  ostream_iterator kopiert und der Reihe nach pro Zeile ausgegeben */
  std::copy(std::cbegin(v_0), std::cend(v_0), 
  std::ostream_iterator<int>(std::cout, "\n"));

  /* die Elemente aus v_0 werden in einer Liste namens l_0 gespeichert */
  std::list<int> l_0(std::cbegin(v_0), std::cend(v_0));

  /* die Elemente aus l_0 werden in einer Liste namens l_1 gespeichert */
  std::list<int> l_1(std::cbegin(l_0), std::cend(l_0));

  /* die Reihenfolge der Elemente in l_1 wird 
  umgedreht und (wie oben) ausgegeben */
  std::reverse(std::begin(l_1), std::end(l_1));
  std::copy(std::cbegin(l_1), std::cend(l_1), 
  std::ostream_iterator<int>(std::cout, "\n"));

  /* die Elemente von l_1 werden mittels der 
  Memberfunktion list::sort() sortiert und ausgegeben */
  l_1.sort();
  std::copy(l_1.cbegin(), l_1.cend(), 
  std::ostream_iterator<int>(std::cout, "\n"));

  /* mittels std::generate wird der vector v_0 mit Zufallszahlen gefüllt,
  die die vorherigen Zahlen überschrieben, dann wieder ausgegeben */
  std::generate(std::begin(v_0), std::end(v_0), std::rand);
  std::copy(v_0.crbegin(), v_0.crend(), std::ostream_iterator<int>(std::cout, "\n"));

  return 0;
} 


/* Output :
===========================================
VECTOR v_0
----------------- generiert von std::rand()
16807
282475249
1622650073
984943658
1144108930
470211272
101027544
1457850878
1458777923
2007237709
===========================================
LISTE l_1
------------ umgedreht durch std::reverse()
2007237709
1458777923
1457850878
101027544
470211272
1144108930
984943658
1622650073
282475249
16807
===========================================
LISTE l_1
---------------- sortiert durch std::sort()
16807
101027544
282475249
470211272
984943658
1144108930
1457850878
1458777923
1622650073
2007237709
===========================================
VECTOR v_0
----------- generiert durch std::generate()
143542612
823378840
16531729
1441282327
1137522503
114807987
74243042
1784484492
1115438165
823564440 */

