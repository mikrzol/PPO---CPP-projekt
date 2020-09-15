#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#pragma once 

using namespace std;

class A {
private:
    vector<string> m_ChildrenList;
    string m_Parent;
    string m_Name;
    int m_Data;
protected:
    int prot_A;
public:
    A(): A("A", {string("B"), string("C")}, "To jest korzen - nie ma rodzica") {};
    A(const string& name, vector<string> children, const string& parent) 
        : m_Name(name), m_ChildrenList(children), m_Parent(parent) {};

    virtual int get_Data() const {
        return this->m_Data;
    };
    virtual void set_Data(int data) {
        this->m_Data = data;
    };
    virtual vector<string> get_Children() const {
        cout << "\nLista dzieci dla obiektu ("; this->print_Name(); cout << "):" << endl;
        for(int i = 0; i < m_ChildrenList.size(); i++){
            cout << m_ChildrenList[i] << endl;
        }
        return this->m_ChildrenList;
    };
    virtual void print_Name() const {
        cout << this->m_Name;
    };
    virtual string get_Name() const {
        return this->m_Name;
    };
    virtual void print_Parent() const {
        cout << "\nRodzic tego obiektu ("; this->print_Name(); cout << "):" << endl;
        cout << this->m_Parent << endl;
    };
    virtual string get_Parent() const {
        return this->m_Parent;
    };
};

template <class X>
class Leaf : public A {
    class Leaf* next;
    static class Leaf *head;

    public:
    ~Leaf(){
        if(this->head != nullptr) {
            Leaf<X>* ptr= this->head;
            if(ptr->next == nullptr) {
                free(ptr);
                return;
            } else {
                Leaf<X>* prev= this->head;
                ptr = ptr->next;
                while(ptr != nullptr) {
                    free(prev);
                    prev = ptr;
                    ptr = ptr->next;
                }
                free(prev);
            }
        }
    };
    void create_obj(int data){
        Leaf<X>* new_Leaf = new Leaf<X>;
            new_Leaf->set_Data(data);
            new_Leaf->list_insert();
    };
    void list_insert(){
        if(this->head == NULL) {
            this->head = this;
            this->next = NULL;
        } else {
            Leaf<X>* ptr = this->head;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = this;
            this->next = NULL;
        }
    };
    void print_list(){
        Leaf<X> *ptr = this->head;
        if(ptr == nullptr) {
            cout << "Brak obiektow tej klasy" << endl;
            return;
        }
        cout << "Lista obiektow tej klasy: " << endl;
        while(ptr != nullptr){
            cout << ptr->get_Data() << " " << ptr->get_class_name() << endl;
            ptr = ptr->next;
        }
    };
    void modify_obj(int z_ktorego, int na_co){
        Leaf<X>* obj = this->list_search(z_ktorego);
        if(obj) {
            obj->set_Data(na_co);
        }
        else {
            cout << "Nie zmodyfikowano obiektu" << endl;
        }
    };
    Leaf<X>* list_search(int data){
        Leaf<X> *ptr = this->head;
        while(ptr != nullptr && ptr->get_Data() != data){
            ptr = ptr->next;
        }
        if(ptr == nullptr){
            cout << "Nie znaleziono takich danych" << endl;
            return nullptr;
        }
        return ptr;
    };
    void destroy_obj(int key){
        this->list_delete(key);
    };
    // usuwanie po kluczu
    void list_delete(int key){
        Leaf<X>* ptr = this->head;
        if(ptr != NULL && ptr->get_Data() == key){
            this->head = this->head->next;
            delete ptr;
            return;
        }
        Leaf<X>* prev = ptr;
        while(ptr != NULL && ptr->get_Data() != key){
            prev = ptr;
            ptr = ptr->next;
        }
        if(ptr == NULL){
            cout << "Nie znaleziono takich danych" << endl;
            return;
        }
        prev->next = ptr->next;
        delete ptr;
    };

    char get_class_name() const {
        string full_name = typeid(this).name();
        char klasa = full_name.at(9);
        return klasa;
    };

    Leaf<X>* get_head() const {
        return this->head;
    };
    
    Leaf<X>* get_next() const {
        return this->next;
    };

};

template <class X>
class Leaf<X>* Leaf<X>::head = NULL;

class B : public virtual A {
private:
    int priv_B;
protected:
    int prot_B;
public:
    B()
        : A("B", {"D", "E"}, "A") {};
};

class C : public virtual A {
private:
    int priv_C;
protected:
    int prot_C;
public:
    C()
        : A("C", {"F", "G"}, "A") {};
};

class D : public B {
private:
    Leaf<D>* m_Leaf;
protected:
    int prot_D;
public:
    D() 
        : A("D", {"To jest lisc", " "}, "B") {
            m_Leaf = new Leaf<D>;
        };
    ~D(){
        delete m_Leaf;
    }
    Leaf<D>* get_Leaf() const {
        return this->m_Leaf;
    };
    vector<string> get_Children() const {
        vector<string> children = A::get_Children();
        m_Leaf->print_list();
        return children;
    };
};

class E : public B {
private:
    Leaf<E>* m_Leaf;
protected:
    int prot_E;
public:
    E()
        : A("E", {"To jest lisc", ""}, "B") {
            m_Leaf = new Leaf<E>;
        };
    ~E(){
        delete m_Leaf;
    };
    Leaf<E>* get_Leaf() const {
        return this->m_Leaf;
    };
    vector<string> get_Children() const {
        vector<string> children = A::get_Children();
        m_Leaf->print_list();
        return children;
    };
};

class F : public virtual C {
private:
    int priv_F;
protected:
    int prot_F;
public:
    F()
        : A("F", {"I", ""}, "C") {};
};

class G : public virtual C {
private:
    int priv_G;
protected:
    int prot_G;
public:
    G()
        : A("G", {"J", "K"}, "C") {};
};

class I : public virtual F {
private:
    int priv_I;
protected:
    int prot_I;
public:
    I()
        : A("I", {"L", "M"}, "F") {};
};

class J : public G {
private:
    Leaf<J>* m_Leaf;
protected:
    int prot_J;
public:
    J() 
        : A("J", {"To jest lisc", " "}, "G") {
            m_Leaf = new Leaf<J>;
        };
    ~J(){
        delete m_Leaf;
    }
    Leaf<J>* get_Leaf() const {
        return this->m_Leaf;
    };
    vector<string> get_Children() const {
        vector<string> children = A::get_Children();
        m_Leaf->print_list();
        return children;
    };
};

class K : public G {
private:
    Leaf<K>* m_Leaf;
protected:
    int prot_K;
public:
    K() 
        : A("K", {"To jest lisc", " "}, "G") {
            m_Leaf = new Leaf<K>;
        };
    ~K(){
        delete m_Leaf;
    }
    Leaf<K>* get_Leaf() const {
        return this->m_Leaf;
    };
    vector<string> get_Children() const {
        vector<string> children = A::get_Children();
        m_Leaf->print_list();
        return children;
    };
};

class L : public I {
private:
    Leaf<L>* m_Leaf;
protected:
    int prot_L;
public:
    L() 
        : A("L", {"To jest lisc", " "}, "I") {
            m_Leaf = new Leaf<L>;
        };
    ~L(){
        delete m_Leaf;
    }
    Leaf<L>* get_Leaf() const {
        return this->m_Leaf;
    };
    vector<string> get_Children() const {
        vector<string> children = A::get_Children();
        m_Leaf->print_list();
        return children;
    };
};

class M : public I {
private:
    Leaf<M>* m_Leaf;
protected:
    int prot_M;
public:
    M() 
        : A("M", {"To jest lisc", " "}, "I") {
            m_Leaf = new Leaf<M>;
        };
    ~M(){
        delete m_Leaf;
    }
    Leaf<M>* get_Leaf() const {
        return this->m_Leaf;
    };
    vector<string> get_Children() const {
        vector<string> children = A::get_Children();
        m_Leaf->print_list();
        return children;
    };
};
