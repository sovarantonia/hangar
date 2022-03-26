//
// Created by sovar on 21/05/2021.
//

#ifndef PRJ_UI_H
#define PRJ_UI_H
#include "Service.h"

class UI {
private:
    Service service;
public:
    UI();
    UI(Service &);
    ~UI();

    void print_options();
    void run_menu();

    void adaugare_vehicul();
    void stergere_vehicul();
    void modificare_vehicul();
    void afisare_vehicule();

    void grupare_vehicule_dupa_scop();
    void autonomie_medie();
    void sortare_vehicule_tip();
    void afisare_flota_companie();
};


#endif //PRJ_UI_H
