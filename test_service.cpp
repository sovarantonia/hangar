//
// Created by sovar on 15/05/2021.
//
#include <iostream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <map>
#include "test_service.h"
#include "Vehicle.h"
#include "Repository.h"
#include "Service.h"
#include "ServiceException.h"

void test_file_service()
{
    Repository repo("test_service.txt");
    ifstream f(repo.getFileName());
    assert(f.good());
}

void test_add_service()
{
    Repository repo("test_service.txt");
    Service s(repo);

    s.addVehicle("boeing", "abg888", "BB", "commercial", 3, 1);
    assert(s.getSize() == 1);
    assert(strcmp(s.getAll()[0]->getType(), "boeing") == 0);
    assert(strcmp(s.getAll()[0]->getRegistrationNo(), "abg888") == 0);
    assert(strcmp(s.getAll()[0]->getCompanyName(), "BB") == 0);
    assert(strcmp(s.getAll()[0]->getPurpose(), "commercial") == 0);
    assert(s.getAll()[0]->getAutonomy() == 3);

    s.addVehicle("boeing" , "acg457", "DD", "cargo", 3, 1);
    assert(s.getSize() == 2);
    assert(strcmp(s.getAll()[1]->getType(), "boeing") == 0);
    assert(strcmp(s.getAll()[1]->getRegistrationNo(), "acg457") == 0);
    assert(strcmp(s.getAll()[1]->getCompanyName(), "DD") == 0);
    assert(strcmp(s.getAll()[1]->getPurpose(), "cargo") == 0);
    assert(s.getAll()[1]->getAutonomy() == 3);

    try
    {
        s.addVehicle("boeing", "abg888", "as", "cargo", 4, 1);
        assert(false);
    }
    catch(ServiceException &se)
    {
        assert(true);
    }
}


void test_average_autonomy()
{
    Repository repo("test_service.txt");
    Service s(repo);

    s.addVehicle("boeing747", "abg888", "BB", "commercial", 3, 1);
    s.addVehicle("hp", "hip555", "DDa", "cargo", 2, -1);
    s.addVehicle("boeing747", "ayr110", "Fg", "cargo", 5, 1);
    s.addVehicle("hp", "hse648", "BB", "mission", 3, -1);
    s.addVehicle("airbusA350", "acc777", "GGG", "commercial", 6, 1);

    map<string, int> result = s.averageAutonomy();

    assert(result.find("boeing747")->second == 4);
    assert(result.find("hp")->second == 2);
    assert(result.find("airbusA350")->second == 6);

}

void test_vehicles_company()
{
    Repository repo("test_service.txt");
    Service s(repo);

    s.addVehicle("boeing747", "abg888", "BB", "commercial", 3, 1);
    s.addVehicle("hp", "hip555", "DDa", "cargo", 2, -1);
    s.addVehicle("boeing747", "ayr110", "Fg", "cargo", 5, 1);
    s.addVehicle("hp", "hse648", "BB", "mission", 3, -1);
    s.addVehicle("airbusA350", "acc777", "GGG", "commercial", 6, 1);

   vector <Vehicle*> result = s.getAllVehiclesCompany("BB");
   assert(result.size() == 2);
   assert(strcmp(result.at(0)->getRegistrationNo(), "abg888") == 0);
   assert(strcmp(result.at(1)->getRegistrationNo(), "hse648") == 0);
}


void test_group_vehicles_by_purpose()
{
    Repository repo("test_service.txt");
    Service s(repo);

    s.addVehicle("boeing747", "abg888", "BB", "commercial", 3, 1);
    s.addVehicle("hp", "hip555", "DDa", "cargo", 2, -1);
    s.addVehicle("boeing747", "ayr110", "Fg", "cargo", 5, 1);
    s.addVehicle("hp", "hse648", "BB", "mission", 3, -1);
    s.addVehicle("airbusA350", "acc777", "GGG", "commercial", 6, 1);

    map <string, vector<Vehicle*> > result = s.groupVehiclesByPurpose();
    assert(result.find("cargo")->second.size() == 2);
    assert(result.find("commercial")->second.size() == 2);
    assert(result.find("mission")->second.size() == 1);
    assert(strcmp(result.find("cargo")->second.at(0)->getRegistrationNo(), "hip555") == 0);
    assert(strcmp(result.find("cargo")->second.at(1)->getRegistrationNo(), "ayr110") == 0);
    assert(strcmp(result.find("commercial")->second.at(0)->getRegistrationNo(), "abg888") == 0);
    assert(strcmp(result.find("commercial")->second.at(1)->getRegistrationNo(), "acc777") == 0);
    assert(strcmp(result.find("mission")->second.at(0)->getRegistrationNo(), "hse648") == 0);
}

void test_sort_vehicles()
{
    Repository repo("test_service.txt");
    Service s(repo);

    s.addVehicle("boeing747", "abg888", "BB", "commercial", 3, 1);
    s.addVehicle("hp", "hip555", "DDa", "cargo", 2, -1);
    s.addVehicle("boeing747", "ayr110", "Fg", "cargo", 5, 1);
    s.addVehicle("hp", "hse648", "BB", "mission", 3, -1);
    s.addVehicle("airbusA350", "acc777", "GGG", "commercial", 6, 1);

    vector <Vehicle*> result = s.sortVehicles();
    assert(result.size() == 5);
    assert(strcmp(result.at(0)->getRegistrationNo(), "acc777") == 0);
    assert(strcmp(result.at(2)->getRegistrationNo(), "abg888") == 0);
    assert(strcmp(result.at(1)->getRegistrationNo(), "ayr110") == 0);
    assert(strcmp(result.at(4)->getRegistrationNo(), "hip555") == 0);
    assert(strcmp(result.at(3)->getRegistrationNo(), "hse648") == 0);
}


void test_remove_service()
{
    Repository repo("test_service.txt");
    Service s(repo);

    s.addVehicle("boeing747", "abg888", "BB", "commercial", 3, 1);
    s.addVehicle("hp", "hip555", "DDa", "cargo", 2, -1);
    s.addVehicle("boeing747", "ayr110", "Fg", "cargo", 5, 1);
    s.addVehicle("hp", "hse648", "BB", "mission", 3, -1);
    s.addVehicle("airbusA350", "acc777", "GGG", "commercial", 6, 1);

    s.removeVehicle("ayr110");
    assert(s.getSize() == 4);
    assert(repo.findRegNo("ayr110") == false);
    assert(strcmp(s.getAll()[2]->getRegistrationNo(), "hse648") == 0);
    assert(strcmp(s.getAll()[3]->getRegistrationNo(), "acc777") == 0);

    try
    {
        s.removeVehicle("m888");
        assert(false);
    }
    catch(ServiceException &se)
    {
        assert(true);
    }

}

void test_update_service()
{
    Repository repo("test_service.txt");
    Service s(repo);

    s.addVehicle("boeing747", "abg888", "BB", "commercial", 3, 1);
    s.addVehicle("hp", "hip555", "DDa", "cargo", 2, -1);
    s.addVehicle("boeing747", "ayr110", "Fg", "cargo", 5, 1);
    s.addVehicle("hp", "hse648", "BB", "mission", 3, -1);
    s.addVehicle("airbusA350", "acc777", "GGG", "commercial", 6, 1);

    s.updateVehicle("hip555", "hp1", "hip556", "AAAA", "mission", 3);
    assert(s.getSize() == 5);
    assert(repo.findRegNo("hip555") == false);
    assert(strcmp(s.getAll()[1]->getRegistrationNo(), "hip556") == 0);
    assert(strcmp(s.getAll()[1]->getType(), "hp1") == 0);
    assert(strcmp(s.getAll()[1]->getCompanyName(), "AAAA") == 0);
    assert(strcmp(s.getAll()[1]->getPurpose(), "mission") == 0);
    assert(s.getAll()[1]->getAutonomy() == 3);
}


void test_service()
{
    test_file_service();
    test_add_service();
    test_remove_service();
    test_update_service();
    test_average_autonomy();
    test_vehicles_company();
    test_group_vehicles_by_purpose();
    test_sort_vehicles();
}
