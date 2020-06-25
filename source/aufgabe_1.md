## Aufgabe 4.1

### sequenzielle, assoziative und adaptive Container

----------------------------------------------------------

#### sequenzielle Container:
- array, vector, list, forward_list, deque
- Zuordnung von Index und Wert mit Reihenfolge
- Datenelemente werden gespeichert wie abgelegt

#### assoziative Container:
- map, multiset, set
- unorderded_map, unordered_multimap, unordered_multiset, unordered_set
- Zuordnung von key und value, meist <key, value> Pair
- keinen Einfluss auf Speicherung der Datenelemente

#### Containeradapterklassen:
- priority_queue, queue, stack
- keine C++ STL-Iteratoren

#### Beispiele:
a) FIFO-Warteschlange von Druckaufträgen
- adaptive Container
- am besten Queue

b) Zuordnung Farbname zu ensprechenden RGB-Werten
- assoziativer Container
- map<String, Color> eignet sich zB. gut
- Reihenfolge egal
- Zuordnung von String

c) Speichern der Punkte eines Polygons:
- sequenzieller Container
- keine spezielle Zuordnung
- sollte gut iterierbar sein

