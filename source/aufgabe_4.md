## Aufgabe 4.4

```cpp
std::map<std::string,int> matrikelnummern;
// Hinzufuegen von vielen Studenten 
matrikelnummern["Max Mustermann"] = 12345; 
matrikelnummern["Erika Mustermann"] = 23523; 
// ...
exmatrikulation(matrikelnummern["Fred Fuchs"]);
```
----------------------------------------------------------
#### Problem:
- std::map 'matrikelnummern' speichert Schlüssel(Name) und Wert(Matrikelnummer)
- Schlüssel ist ein const char, Wert ein int -> letzteres modifizierbar!
- operator[ ] kann vorhandene Werte modifizieren, falls Schlüssel schon existiert 
- Methode exmatrikulation( ) greift direkt auf map container zu
- falls "Fred Fuchs" nicht vorhanden ist, wird er mittels operator[ ] mit Wert 0  
  in 'matrikelnummern' eingefügt und dann '0' exmatrikuliert
- falls "Fred Fuchs" mehrmals existiert, kann auch falscher Wert modifiziert werden

#### Lösung:
- [`std::map::insert()`](http://en.cppreference.com/w/cpp/container/map/insert)
  - const& verhindert Modifizierung von Schlüssel/Wert-Paaren
  - gibt std::pair zurück -> first und second Iteratoren verhindern doppelte Eintragung
  - insert(pair<Name,Matr> const& p) ermöglicht Suchabfrage per const& von Wertepaaren p

- [`std::map::find()`](http://en.cppreference.com/w/cpp/container/map/find)
  - Überprüfung mittels Iterator, ob Schlüssel existiert
  - wirft Fehlermeldung, falls Schlüssel nicht gefunden wird