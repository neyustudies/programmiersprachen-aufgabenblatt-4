``` Cpp
#include <cstdlib>    // std::rand()
#include <vector>     // std::vector<>
#include <list>       // std::list<>
#include <iostream>   // std::cout
#include <iterator>   // std::ostream_iterator<>
#include <algorithm>  // std::reverse, std::generate

int main() {

  // erstellt Vector container v_0 mit einer Aufnahmekapazität von 10 integers
  // Aufruf des Standard-Konstruktors, sodass alle Ints mit 0 initialisiert werden
  std::vector<int>v_0(10);
  
  // iteriert über alle Elemente aus v_0
  // füllt den Vector durch std::rand mit pseudo-zufälligen Ganzzahlen zwischen 0 und RAND_MAX
  for(auto& v : v_0) {
    v=std::rand();
  }

  // std::copy kopiert die Elemente, die im Bereich von [first,last] definiert sind
  // cbegin() und cend() sind const-Iteratoren, das heißt sie können die Werte nicht verändern
  // std::ostream_iterator nutzt operator << und schreibt alle Werte in den Output-Stream
  std::copy(std::cbegin(v_0), std::cend(v_0), std::ostream_iterator<int>(std::cout, "\n"));


  // mit const-iteratoren werden alle Elemente aus v_0 in l_0 bzw. aus l_0 in l_1 kopiert
  std::list<int> l_0(std::cbegin(v_0), std::cend(v_0));
  std::list<int> l_1(std::cbegin(l_0), std::cend(l_0));


  // std::list::reverse kehrt die Reihenfolge der Elemente im Container um
  // std::copy kopiert alle Elemente aus l_1 und ruft den ostream iterator (siehe oben)
  std::reverse(std::begin(l_1), std::end(l_1));
  std::copy(std::cbegin(l_1), std::cend(l_1), std::ostream_iterator<int>(std::cout, "\n"));


  // sdt::list::sort() sortiert die Elemente aus l_1 in aufsteigender Reihenfolge mit operator<
  // std::copy siehe oben
  l_1.sort();
  std::copy(l_1.cbegin(), l_1.cend(), std::ostream_iterator<int>(std::cout, "\n"));


  // std::generate füllt den vector v_0 mit Zufallszahlen, die die Elemente überschreiben
  // std::rand generiert dazu erneut pseudo-zufällige Ganzzahlen
  // std::copy siehe oben
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


```