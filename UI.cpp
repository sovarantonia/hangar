//
// Created by sovar on 21/05/2021.
//
#include <iostream>
#include "UI.h"
#include "ServiceException.h"
#include "VehicleException.h"
using namespace std;


UI::UI() {}
UI::UI(Service &service)
{
    this->service = service;
}

UI::~UI() {}

void UI::print_options()
{
    cout << "1.Adaugare vehicul \n" << "2.Stergere vehicul \n" << "3.Modificare vehicul \n" << "a.Afisare vehicule \n";
    cout << "4.Autonomie medie \n" << "5.Sortare dupa tip \n" << "6.Grupare vehicule dupa scop \n" << "7.Afisare flota companie \n";
    cout << "x.Iesire \n";
}

void UI::run_menu()
{
    string option;
    while(true)
    {
        print_options();
        cout << "Dati optiunea \n";
        cin >> option;
        if(option == "1")
            adaugare_vehicul();
        else if(option == "2")
            stergere_vehicul();
        else if(option == "3")
            modificare_vehicul();
        else if(option == "a")
            afisare_vehicule();
        else if(option == "4")
            autonomie_medie();
        else if(option == "5")
            sortare_vehicule_tip();
        else if(option == "6")
            grupare_vehicule_dupa_scop();
        else if(option == "7")
            afisare_flota_companie();
        else if(option == "x")
            break;
        else cout << "Optiune invalida \n";
    }
}


void UI::adaugare_vehicul()
{
    char* type = new char[10];
    char* regNo = new char[8];
    char* companyName = new char[20];
    char* purpose = new char[11];
    int autonomy;
    int ok;
    try
    {
        cout << "Dati tipul vehiculului \n";
        cin >> type;
        cout << "Dati numarul de inregistrare \n";
        cin >> regNo;
        cout << "Dati numele companiei de care apartine \n";
        cin >> companyName;
        cout << "Dati scopul vehiculului : cargo, commercial sau mission \n";
        cin >> purpose;
        cout << "Dati autonomia vehiculului ( > 0) (*100) \n";
        cin >> autonomy;
        cout << "Pentru avion scrieti 1 si pentru elicopter scrieti -1 \n";
        cin >> ok;
        if(ok == 1 || ok == -1)
        {
            service.addVehicle(type, regNo, companyName, purpose, autonomy, ok);
            cout << "S-a adaugat vehiculul \n";
        }
        delete[] purpose;
        delete[] companyName;
        delete[] regNo;
        delete[] type;
    }
    catch(VehicleException &ve)
    {
       cout << ve.get_message();
    }
    catch(RegNoNotValid &notValid)
    {
        cout << notValid.get_message();
    }
    catch(...)
    {
        cout << ".......";
    }

}


void UI::afisare_vehicule()
{
    vector <Vehicle*> result = service.getAll();
    cout << "In fabrica exista " << service.getSize() << " vehicule \n";
    for(Vehicle* v : result)
        cout << v->toString() << "\n";
}


void UI::afisare_flota_companie()
{
    char* companyName = new char[20];
    try
    {
        cout << "Dati numele companiei a carei flota trebuie afisata \n";
        cin >> companyName;
        vector<Vehicle*> result = service.getAllVehiclesCompany(companyName);
        for(Vehicle* v : result)
            cout << v->toString() << "\n";

        delete[] companyName;
    }
    catch(CompanyNameNotValid &notValid)
    {
        cout << notValid.get_message();
    }
    catch(...)
    {
        cout << "....";
    }
}

void UI::grupare_vehicule_dupa_scop()
{
    map <string, vector <Vehicle*> > result = service.groupVehiclesByPurpose();
    map <string, vector <Vehicle*> > :: iterator it;
    int ok;
    cout << "Pentru toate vehiculele scrieti 0, pentru cele cargo scrieti 1, pentru cele comerciale scrieti 2 "
            "si pentru cele pentru misiuni scrieti 3 \n";
    cin >> ok;

    for(it = result.begin(); it != result.end(); it ++)
    {
        if (ok == 0)
        {
            cout << it->first << ": \n";
            for (int i = 0; i < it->second.size(); i++)
                cout << it->second.at(i)->toString() << "\n";
        }
    }
    if(ok == 1)
    {
        cout << result.find("cargo")->first;
        for(int i = 0; i < result.find("cargo")->second.size(); i ++)
            cout << result.find("cargo")->second.at(i)->toString() << "\n";
    }
    else if(ok == 2)
    {
        cout << result.find("commercial")->first;
        for(int i = 0; i < result.find("commercial")->second.size(); i ++)
            cout << result.find("commercial")->second.at(i)->toString() << "\n";
    }
    else if(ok == 3)
    {
        cout << result.find("mission")->first;
        for(int i = 0; i < result.find("mission")->second.size(); i ++)
            cout << result.find("mission")->second.at(i)->toString() << "\n";
    }

}


void UI::autonomie_medie()
{
    map <string, int > result = service.averageAutonomy();
    map <string, int> :: iterator it;
    cout << "Tip vehicul " << "autonomie medie \n";
    for(it = result.begin(); it != result.end(); it ++)
        cout << it->first << " " << it->second << "\n";
}


void UI::sortare_vehicule_tip()
{
    vector <Vehicle*> result = service.sortVehicles();
    for(Vehicle* v: result)
        cout << v->toString() << "\n";
}


void UI::stergere_vehicul()
{
    char* regNo = new char[8];
    cout << "Dati numarul de inregistrare al vehiculului de sters \n";
    cin >> regNo;
    try
    {
        service.removeVehicle(regNo);
        cout << "S-a sters vehiculul \n";
    }
    catch(RegNoNotValid &notValid)
    {
        cout << notValid.get_message();
    }
    delete[] regNo;
}


void UI::modificare_vehicul()
{
    char* oldRegNo = new char[8];
    char* newType = new char[10];
    char* newRegNo = new char[8];
    char* newCompanyName = new char[20];
    char* newPurpose = new char[11];
    int newAutonomy;
    try
    {
        cout << "Dati numarul de inregistrare vechi \n";
        cin >> oldRegNo;
        cout << "Dati tipul vehiculului \n";
        cin >> newType;
        cout << "Dati numarul de inregistrare \n";
        cin >> newRegNo;
        cout << "Dati numele companiei de care apartine \n";
        cin >> newCompanyName;
        cout << "Dati scopul vehiculului : cargo, commercial sau mission \n";
        cin >> newPurpose;
        cout << "Dati autonomia vehiculului ( > 0) (*100) \n";
        cin >> newAutonomy;
        service.updateVehicle(oldRegNo, newType, newRegNo, newCompanyName, newPurpose, newAutonomy);
        cout << "S-a modificat vehiculul \n";
    }
    catch(RegNoNotValid &notValid)
    {
        cout << notValid.get_message();
    }
    catch(VehicleException &vehicleException)
    {
        cout << vehicleException.get_message();
    }
    catch(...)
    {
        cout << ".....";
    }
}
