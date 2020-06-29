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
- sequenzieller Container (deque)
- effizientes Einfügen am Anfang + Ende
- adaptiver Container queue auch möglich

b) Zuordnung Farbname zu ensprechenden RGB-Werten
- assoziativer Container (map)
- map<String, Color> sinnvoll
- direkte Zuordnung von String zu Werten

c) Speichern der Punkte eines Polygons:
- sequenzieller Container (vector)
- keine spezielle Zuordnung nötig
- sollte gut iterierbar sein

