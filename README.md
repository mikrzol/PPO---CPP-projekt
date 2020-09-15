Grupa projektu: 6

Projekt zawiera implementację wszystkich wymaganych funkcjonalności:
1. Odczyt z pliku.
2. Zapis do pliku.
3. Komendy CD, DO, MO, MDO, DIR, SHOW, TREE - każda wg wytycznych widocznych w pliku pdf.
4. Zaimplementowana została wymagana hierarchia klas.
5. Klasy posiadają pola służące do przechowywania danych całoliczbowych - typu int.
6. Funkcjonalność liścia została zaimplementowana w postaci szablonu, do instancji którego wskaźniki posiadają klasy-liście. Zmniejszyło to drastycznie długość kodu poprzez eliminację powtórzeń deklaracji dokładnie takich samych funkcjonalności z różnymi typami.
7. Poruszanie się po menu zaimplementowane jest w formie tekstowej i oparte jest na zapamiętywaniu przez program poprzednich komend i nazw klas oraz danych, jednak zachowane są wszytkie ww. funkcjonalności.
8. Obiekt Metaklasa został zaimplementowany w formie singletona, w którym świadomie postanowiłem umożliwić korzystanie z operatora przypisywania (=) w celu zwiększenia czytelności kodu w funkcji main().
9. Większość metod typu DO, MO itp. zostały zaimplementowane w oparciu o polimorfizm klas, jednak ze względu na to, że operacje wykonywane są na obiektach, do których wskaźniki znajdują się w obiekcie Metaklasa, potrzebne było napisanie metod pomocniczych, umożliwiających odwołanie się do konkretnych pól (np. jeśli użytkownk chce zmodyfikować obiekt klasy D gdy znajduje się już w tej klasie, należy odwołać się po pola meta.m_D, a gdy chce zmienić obiekt klasy E - do pola meta.m_E). Funkcje te nazwane są DO, MO itp. i wywołują właściwe funkcje wykonujące chciane operacje. Taka implementacja była spowodowana chęcią zwiększenia przejrzystości kodu w funkcji main(). 
10. Program automatycznie zwalnia pamięć po zamknięciu dzięki wykorzystaniu scope - destruktor obiektu klasy Metaklasa zostaje wywołany w momencie wybrania komendy EXIT. Następnie wywoływany jest destruktor każdej z klas po kolei - destruktor szablonu liścia ostatecznie zwalnia listę obiektów liści z pamięci dla każdego typu liścia.
11. Projekt był tworzony w programie Visual Studio Code i sposób działania kompilatora gcc był powodem, dla którego pliki Methods oraz Classes mają rozszerzenie .h, a nie .cpp (pliki te są kopiowane bezpośrednio do pliku main.cpp w momencie kompilacji). W moim zrozumieniu nie jest to preferowana praktyka programistyczna (pliki .h powinny rzekomo być niewielkie i zawierać deklaracje zmiennych, a nie pełne implementacje metod i klas), jednak postanowiłem skorzystać z tego rozwiązania, gdyż wydaje mi się ono bardziej uniwersalne: mniej zależne od platformy oraz ustawień użytego kompilatora.
12. W celu wytworzenia pliku .exe wystarczy zbudować projekt na aktywnym pliku Main.cpp.