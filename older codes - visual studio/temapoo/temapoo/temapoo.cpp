#include<iostream>
#include<conio.h>
#include<string.h>
#include <string>
using namespace std;
class carti {
    char* autor;
    char* titlu;
    int imprumutat;
    carti* head;
    carti* next;
public:
    carti(const char*, const char*, int);
    void adaugare();
    void afisare();
    carti* cautare(carti* head, const char* titluCautat);
    void stergere(const char* titluStergere);

};
carti::carti(const char* a, const char* t, int i)
{
    autor = new char[20];
    titlu = new char[20];
    strcpy(autor, a);
    strcpy(titlu, t);
    imprumutat = i;
    head = NULL;
}
void carti::adaugare() {
    cout << "Adaugarea unui nod la inceputul listei" << endl;
    cout << "Dati autorul: ";
    //fflush(stdin);
    cin.ignore();
    cin.getline(autor, 20);
    cout << "Dati titlul: ";
    //fflush(stdin);
    cin.ignore();
    cin.getline(titlu, 20);
    cout << "Dati starea cartii(imprumutata = 1/ neimprumutata = 0): ";
    cin >> imprumutat;
    carti* c = new carti(autor, titlu, imprumutat);
    c->next = head;
    head = c;
}
void carti::afisare()
{
    carti* c = head;
    while (c != NULL) {
        cout << "--------------" << endl;
        cout << "Autor: " << c->autor << endl;
        cout << "Titlu: " << c->titlu << endl;
        cout << "Imprumutat" << c->imprumutat << endl;
        cout << "--------------" << endl;
        c = c->next;
    }
}

carti* carti::cautare(carti* head, const char* titluCautat) {
    carti* c = head;
    while (c != NULL) {
        if (strcmp(c->titlu, titluCautat) == 0) {
            cout << "--------------" << endl;
            cout << "Autor: " << c->autor << endl;
            cout << "Titlu: " << c->titlu << endl;
            cout << "Imprumutat" << c->imprumutat << endl;
            cout << "--------------" << endl;
            return c;
        }
        c = c->next;
    }
    return NULL;
}

void carti::stergere(const char* titluStergere) {
    carti* curent = head;
    carti* anterior = NULL;
    while (curent != NULL) {
        if (strcmp(curent->titlu, titluStergere) == 0) {
            if (anterior == NULL) {
                head = curent->next;
            }
            else {
                anterior->next = curent->next;
            }
            delete curent;
            cout << "Cartea cu titlul " << titluStergere << " a fost stearsa." << endl;
            return;
        }
        anterior = curent;
        curent = curent->next;
    }
    cout << "Cartea cu titlul " << titluStergere << " nu a fost gasita." << endl;
}

int main() {
    int opt;
    carti* carteGasita;
    carti* c = new carti(" ", " ", 0);
    do {
        cout << "1. Adaugare carte" << endl;
        cout << "2. Afisare carte" << endl;
        cout << "0. Iesire" << endl;
        cout << "Optiune: " << endl;
        cin >> opt;
        switch (opt)
        {
        case 1:
            c->adaugare();
            break;
        case 2:
            c->afisare();
            break;
        case 3:
            char titluCautat[20];
            cout << "Dati titlul cartii pentru cautare: ";
            cin.ignore();
            cin.getline(titluCautat, 20);
            carteGasita = c->cautare(c, titluCautat);
            if (carteGasita) {
                cout << "Cartea a fost gasita!" << endl;
            }
            else {
                cout << "Cartea cu titlul " << titluCautat << " nu a fost gasita." << endl;
            }
            break;
        case 4:

            char titluStergere[20];
            cout << "Dati titlul cartii pentru stergere: ";
            cin.ignore();
            cin.getline(titluStergere, 20);
            c->stergere(titluStergere);
            break;

        }
    } while (opt != 0);
    getch();
}