#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Classes.h"
#include "Methods.h"

using namespace std;

int main() {

{
    Metaklasa& meta = Metaklasa::get_Instance();
    {
    int tryb = 1;
    string wybor;
    string poprzednia_klasa;
    vector<string> seglist= {"0", "0"};

while(tryb) {
cout << "========================================================" << endl;
if(seglist[1] != "0"){
    cout << "Aktualnie jestes w wezle: " << seglist[1] << endl;
};
cout << "\nWybierz dzialanie:\n\
CD [nazwa wezla] -> przejdz do wezla o danej nazwie" << endl;
if(determine_Class(seglist[1]) > 20){
    cout << "\
\tMO [nazwa]-> stworz obiekt o podanej nazwie dla tego liscia\n\
\tDO [nazwa]-> usun obiekt o danej nazwie dla tego liscia\n\
\tMDO [nazwa]-> zmodyfikuj obiekt o danej nazwie dla tego liscia" << endl;
}
cout << "\
DIR -> wyswietl liste wszystkich obiektow, ktore dziedzicza z danego wezla\n\
SHOW [wezel] -> wyswietl szczegolowe informacje o danym wezle\n\
SAVE -> zapisz zbior do pliku\n\
READ -> wczytaj zbior z pliku\n\
TREE -> pokaz schemat struktury\n\
EXIT -> zakoncz program" << endl;
cout << "========================================================" << endl;

        getline(cin, wybor);
        // string w duze litery
        transform(wybor.begin(), wybor.end(),wybor.begin(), ::toupper);
        cin.clear();
        fflush(stdin);

        string myText(wybor);
        istringstream iss(myText);
        string segment;
        poprzednia_klasa = seglist[1];
        seglist.resize(0);
        while (getline(iss, segment, ' ')){
            seglist.push_back(segment);
        }
        string komenda = seglist[0];
        string klasa = seglist[1];

        if(komenda == "CD") {
            if(!determine_Class(klasa)) {
                cout << "Prosze wybrac klase z listy" << endl;
                seglist[1] = poprzednia_klasa;
            }
        }
        else if(komenda == "MO") {
            if(determine_Class(poprzednia_klasa) > 20) {
                MO(poprzednia_klasa, klasa, meta);
                seglist[1] = poprzednia_klasa;
            } else {
                cout << "Nie mozna tworzyc obiektow tej klasy- nie jest ona lisciem" << endl;
                seglist[1] = poprzednia_klasa;
            } 
        }
        else if(komenda == "DO") {
            if(determine_Class(poprzednia_klasa) > 20) {
                DO(poprzednia_klasa, klasa, meta);
                seglist[1] = poprzednia_klasa;
            } else {
                cout << "Nie mozna niszczyc obiektow tej klasy - nie jest ona lisciem" << endl;
                seglist[1] = poprzednia_klasa;
            }
        }
        else if(komenda == "MDO") {
            if(determine_Class(poprzednia_klasa) > 20) {
                MDO(poprzednia_klasa, klasa, meta);
                seglist[1] = poprzednia_klasa;
            } else {
                cout << "Nie mozna modyfikowac obiektow tej klasy - nie jest ona lisciem" << endl;
                seglist[1] = poprzednia_klasa;
            }
        }
        else if(komenda == "DIR" && poprzednia_klasa != "0") {
            DIR(klasa, meta);
        }
        else if(komenda == "SHOW" && poprzednia_klasa != "0") {
            SHOW(poprzednia_klasa, meta);
            seglist[1] = poprzednia_klasa;
        }
        else if(komenda == "SAVE") {
            save_list_to_file(meta);
        }
        else if(komenda == "READ") {
            read_list_from_file(meta);
        }
        else if(komenda == "TREE") {
            cout << "SCHEMAT STRUKTURY:\n\
\t\t\tA\n\
\t\t/\t      \\\n\
\t  B\t \t\tC\t\t\n\
   /\t\t\\\t   /\t     \\\n\
D\t\tE\t F\t\tG\n\
\t\t\t |\t  /\t     \\\n\
\t\t\t I\tJ\t\tK\n\
\t\t      /    \\\n\
\t\t    L\t    M" << endl;
        }
        else if(komenda == "EXIT") {
            tryb = 0;
        }
    } // koniec while(tryb)
    }
} // koniec scope Metaklasa obj 
    return 0;
};