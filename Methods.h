#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#include "Classes.h"

using namespace std;

enum Klasa {
    k_A = 1, k_B, k_C, k_F, k_G, k_I,
    k_D = 21, k_E, k_J, k_K, k_L, k_M, //liscie sa powyzej 20 
};

int determine_Class(string klasa) {
    if(klasa == "A") return k_A;
    else if(klasa == "B") return k_B;
    else if(klasa == "C") return k_C;
    else if(klasa == "D") return k_D;
    else if(klasa == "E") return k_E;
    else if(klasa == "F") return k_F;
    else if(klasa == "G") return k_G;
    else if(klasa == "I") return k_I;
    else if(klasa == "J") return k_J;
    else if(klasa == "K") return k_K;
    else if(klasa == "L") return k_L;
    else if(klasa == "M") return k_M;
    else return 0;
};

class Metaklasa {
    Metaklasa() { 
        this->m_A = new A();
        this->m_B = new B();
        this->m_C = new C();
        this->m_D = new D();
        this->m_E = new E();
        this->m_F = new F();
        this->m_G = new G();
        this->m_I = new I();
        this->m_J = new J();
        this->m_K = new K();
        this->m_L = new L();
        this->m_M = new M();
    };
    static Metaklasa instance;
    public:
    Metaklasa(const Metaklasa&) = delete;
    static Metaklasa& get_Instance() {
        return instance;
    };
    class A* m_A;
    class B* m_B;
    class C* m_C;
    class D* m_D;
    class E* m_E;
    class F* m_F;
    class G* m_G;
    class I* m_I;
    class J* m_J;
    class K* m_K;
    class L* m_L;
    class M* m_M;
    ~Metaklasa() {
        delete m_A;
        delete m_B;
        delete m_C;
        delete m_D;
        delete m_E;
        delete m_F;
        delete m_G;
        delete m_I;
        delete m_J;
        delete m_K;
        delete m_L;
        delete m_M;
    };
};
Metaklasa Metaklasa::instance;

void save_list_to_file(Metaklasa& meta) {
    ofstream data;
    data.open("data.dat");

    Leaf<D>* obj_D_ptr = meta.m_D->get_Leaf()->get_head();
    
    while(obj_D_ptr != NULL){
        data << obj_D_ptr->get_class_name() << "#" << obj_D_ptr->get_Data()<< "\n"; 
        obj_D_ptr = obj_D_ptr->get_next();
    }

    Leaf<E> *obj_E_ptr = meta.m_E->get_Leaf()->get_head();
    while(obj_E_ptr != NULL){
        data << obj_E_ptr->get_class_name() << "#" << obj_E_ptr->get_Data() << "\n"; 
        obj_E_ptr = obj_E_ptr->get_next();
    }

    Leaf<J> *obj_J_ptr = meta.m_J->get_Leaf()->get_head();
    while(obj_J_ptr != NULL){
        data << obj_J_ptr->get_class_name() << "#" << obj_J_ptr->get_Data() << "\n"; 
        obj_J_ptr = obj_J_ptr->get_next();
    }

    Leaf<K> *obj_K_ptr = meta.m_K->get_Leaf()->get_head();
    while(obj_K_ptr != NULL){
        data << obj_K_ptr->get_class_name() << "#" << obj_K_ptr->get_Data() << "\n"; 
        obj_K_ptr = obj_K_ptr->get_next();
    }

    Leaf<L> *obj_L_ptr = meta.m_L->get_Leaf()->get_head();
    while(obj_L_ptr != NULL){
        data << obj_L_ptr->get_class_name() << "#" << obj_L_ptr->get_Data() << "\n"; 
        obj_L_ptr = obj_L_ptr->get_next();
    }

    Leaf<M> *obj_M_ptr = meta.m_M->get_Leaf()->get_head();
    while(obj_M_ptr != NULL){
        data << obj_M_ptr->get_class_name() << "#" << obj_M_ptr->get_Data() << "\n"; 
        obj_M_ptr = obj_M_ptr->get_next();
    }
    data.close();
};

void read_list_from_file(Metaklasa& meta){
    ifstream data;
    data.open("data.dat");
    string line_from_file;
    while(getline(data, line_from_file)){
        string myText(line_from_file);
        istringstream iss(myText);
        string segment;
        vector<string> seglist;
        while (getline(iss, segment, '#')){
            seglist.push_back(segment);
        }
        string klasa = seglist[0];
        
        if(klasa == "D"){
            meta.m_D->get_Leaf()->create_obj(stoi(seglist[1]));
        }
        else if(klasa == "E"){
            meta.m_E->get_Leaf()->create_obj(stoi(seglist[1]));
        }
        else if(klasa == "J"){
            meta.m_J->get_Leaf()->create_obj(stoi(seglist[1]));
        }
        else if(klasa == "K"){
            meta.m_K->get_Leaf()->create_obj(stoi(seglist[1]));
        }
        else if(klasa == "L"){
            meta.m_L->get_Leaf()->create_obj(stoi(seglist[1]));
        }
        else if(klasa == "M"){
            meta.m_M->get_Leaf()->create_obj(stoi(seglist[1]));
        }
    }
};

template<class X>
void determined_MO(X* obj, string data_do_wpisania) {
    int data = stoi(data_do_wpisania);
    obj->create_obj(data);
    return;
};

void MO(string klasa, string data_do_wpisania, Metaklasa& metaObject) {
    int chosen_class = determine_Class(klasa);
    switch (chosen_class)
    {
    case k_D:
        determined_MO( metaObject.m_D->get_Leaf(), data_do_wpisania );
        break;
    case k_E:
        determined_MO( metaObject.m_E->get_Leaf(), data_do_wpisania );
        break;
    case k_J:
        determined_MO( metaObject.m_J->get_Leaf(), data_do_wpisania );
        break;
    case k_K:
        determined_MO( metaObject.m_K->get_Leaf(), data_do_wpisania );
        break;
    case k_L:
        determined_MO( metaObject.m_L->get_Leaf(), data_do_wpisania );
        break;
    case k_M:
        determined_MO( metaObject.m_M->get_Leaf(), data_do_wpisania );
        break;
    default:
        cout << "Ta klasa nie ma zadnych obiektow - nie jest lisciem" << endl;
        break;
    };
};

template<typename X>
void determined_DO(X* obj, string do_wyrzucenia) {
    int data = stoi(do_wyrzucenia);
    if(obj->get_head() == NULL) {
        cout << "Nie ma zadnych obiektow tej klasy!" << endl;
        return;
    };
    obj->destroy_obj(data);
        return;
};

void DO(string klasa, string do_wyrzucenia, Metaklasa& metaObject) {
    int chosen_class = determine_Class(klasa);
    switch (chosen_class)
    {
    case k_D:
        determined_DO( metaObject.m_D->get_Leaf(), do_wyrzucenia );
        break;
    case k_E:
        determined_DO( metaObject.m_E->get_Leaf(), do_wyrzucenia );
        break;
    case k_J:
        determined_DO( metaObject.m_J->get_Leaf(), do_wyrzucenia );
        break;
    case k_K:
        determined_DO( metaObject.m_K->get_Leaf(), do_wyrzucenia );
        break;
    case k_L:
        determined_DO( metaObject.m_L->get_Leaf(), do_wyrzucenia );
        break;
    case k_M:
        determined_DO( metaObject.m_M->get_Leaf(), do_wyrzucenia );
        break;
    default:
        cout << "Ta klasa nie ma zadnych obiektow - nie jest lisciem" << endl;
        break;
    };
};

template<typename X>
void determined_MDO(X* obj, string ktory) {
    if(obj->get_head() == NULL) {
        cout << "Nie ma zadnych obiektow tej klasy!" << endl;
        return;
    }
    int z_czego = stoi(ktory);
    int na_co;
    cout << "Jaka bedzie nowa wartosc?" << endl;
        cin >> na_co;
        cin.clear();
        fflush(stdin);
        obj->modify_obj(z_czego, na_co);
        return;
};

void MDO(string klasa, string ktory, Metaklasa& metaObejct) {
    int chosen_class = determine_Class(klasa);
    switch (chosen_class)
    {
    case k_D:
        determined_MDO( metaObejct.m_D->get_Leaf(), ktory );
        break;
    case k_E:
        determined_MDO( metaObejct.m_E->get_Leaf(), ktory );
        break;
    case k_J:
        determined_MDO( metaObejct.m_J->get_Leaf(), ktory );
        break;
    case k_K:
        determined_MDO( metaObejct.m_K->get_Leaf(), ktory );
        break;
    case k_L:
        determined_MDO( metaObejct.m_L->get_Leaf(), ktory );
        break;
    case k_M:
        determined_MDO( metaObejct.m_M->get_Leaf(), ktory );
        break;
    default:
        break;
    };
}

vector<string> determined_DIR(A& obj) {
    return obj.get_Children();
};

void DIR(string klasa, Metaklasa& metaObject) {
    // pokaz wszystkie dzieci metoda DFS
    vector<string> recur = {"0", "0"};
    int chosen_class = determine_Class(klasa);
    switch (chosen_class)
        {
        case k_A:
            recur = determined_DIR( *metaObject.m_A);
            break;
        case k_B:
            recur = determined_DIR( *metaObject.m_B);
            break;
        case k_C:
            recur = determined_DIR( *metaObject.m_C);
            break;
        case k_D:
            recur = determined_DIR( *metaObject.m_D);
            return;
        case k_E:
            recur = determined_DIR( *metaObject.m_E);
            return;
        case k_F:
            recur = determined_DIR( *metaObject.m_F);
            break;
        case k_G:
            recur = determined_DIR( *metaObject.m_G);
            break;
        case k_I:
            recur = determined_DIR( *metaObject.m_I);
            break;
        case k_J:
            recur = determined_DIR( *metaObject.m_J);
            return;
        case k_K:
            recur = determined_DIR( *metaObject.m_K);
            return;
        case k_L:
            recur = determined_DIR( *metaObject.m_L);
            return;
        case k_M:
            recur = determined_DIR( *metaObject.m_M);
            return;
        default:
            break;
        };
    if(recur[0] != "To jest lisc" && isalpha(recur[0][0]) ){
        DIR(recur[0], metaObject);
        if(recur.size() == 2){
            DIR(recur[1], metaObject);
        }
        return;
    }
};

void determined_SHOW(A& obj) {
    obj.print_Parent();
    obj.get_Children();
};

void SHOW(string klasa, Metaklasa& metaObject) {
    int chosen_class = determine_Class(klasa);
    switch (chosen_class)
        {
        case k_A:
            determined_SHOW( *metaObject.m_A);
            break;
        case k_B:
            determined_SHOW( *metaObject.m_B);
            break;
        case k_C:
            determined_SHOW( *metaObject.m_C);
            break;
        case k_D:
            determined_SHOW( *metaObject.m_D);
            break;
        case k_E:
            determined_SHOW( *metaObject.m_E);
            break;
        case k_F:
            determined_SHOW( *metaObject.m_F);
            break;
        case k_G:
            determined_SHOW( *metaObject.m_G);
            break;
        case k_I:
            determined_SHOW( *metaObject.m_I);
            break;
        case k_J:
            determined_SHOW( *metaObject.m_J);
            break;
        case k_K:
            determined_SHOW( *metaObject.m_K);
            break;
        case k_L:
            determined_SHOW( *metaObject.m_L);
            break;
        case k_M:
            determined_SHOW( *metaObject.m_M);
            break;
        default:
            cout << "Nie znaleziono klasy" << endl;
            break;
        };
    return;
};