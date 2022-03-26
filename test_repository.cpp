//
// Created by sovar on 08/05/2021.
//
#include <cassert>
#include <cstring>
#include <fstream>
#include "Repository.h"
#include "Vehicle.h"
#include "Airplane.h"
#include "Helicopter.h"


void test_file()
{
    Repository r("test_repo.txt");
    ifstream f(r.getFileName());
    assert(f.good());
}

void test_add_repository()
{
   Repository r("test_repo.txt");
   /*assert(r->getSize() == 1);
   assert(strcmp(r->getAll()[0]->getType(), "airbus") == 0);
   assert(strcmp(r->getAll()[0]->getRegistrationNo(), "ayr125") == 0);
   assert(strcmp(r->getAll()[0]->getCompanyName(), "BlueAir") == 0);
   assert(strcmp(r->getAll()[0]->getPurpose(), "commercial") == 0);
   assert(r->getAll()[0]->getAutonomy() == 3);*/

   Vehicle* v = new Helicopter("h", "hyr598", "ABC", "cargo", 3);
   Vehicle* v1 = new Airplane("a", "aww365", "S", "commercial", 1);
   r.addVehicle(v);
   r.addVehicle(v1);
   assert(r.getSize() == 2);
   assert(strcmp(r.getAll()[0]->getType(), "h") == 0);
   assert(strcmp(r.getAll()[0]->getRegistrationNo(), "hyr598") == 0);
   assert(strcmp(r.getAll()[0]->getCompanyName(), "ABC") == 0);
   assert(strcmp(r.getAll()[0]->getPurpose(), "cargo") == 0);
   assert(r.getAll()[0]->getAutonomy() == 3);
   assert(strcmp(v1->getRegistrationNo(), "aww365") == 0);
   assert(v1->getAutonomy() == 1);

   delete v1;
   delete v;
}


void test_update_repository()
{
    Repository r("test_repo.txt");
    Vehicle* v1 = new Airplane("dd", "a125", "AAA", "cargo", 4);
    Vehicle* v2 = new Airplane("bb", "a765", "Point", "commercial", 5);
    r.addVehicle(v1);
    r.updateVehicle(v1, v2);

    assert(r.getSize() == 1);
    assert(strcmp(r.getAll()[0]->getType(), "bb" ) == 0);
    assert(strcmp(r.getAll()[0]->getRegistrationNo(), "a765") == 0);
    assert(strcmp(r.getAll()[0]->getCompanyName(), "Point") == 0);
    assert(strcmp(r.getAll()[0]->getPurpose(), "commercial") == 0);
    assert(r.getAll()[0]->getAutonomy() == 5);

    delete v2;
    delete v1;

}


void test_remove_repository()
{
    Repository r("test_repo.txt");
    Vehicle* v1 = new Airplane("dd", "a125", "AAA", "cargo", 4);
    Vehicle* v2 = new Airplane("bb", "a765", "Point", "commercial", 5);
    r.addVehicle(v1);
    r.addVehicle(v2);
    r.removeVehicle(v1);
    assert(r.getSize() == 1);
    assert(r.findRegNo("a125") == false);
    assert(r.findRegNo("a765") == true);

    delete v2;
    delete v1;
}


void test_findRegNo()
{
    Repository r("test_repo.txt");
    Vehicle* v1 = new Airplane("dd", "a125", "AAA", "cargo", 4);
    Vehicle* v2 = new Airplane("bb", "a765", "Point", "commercial", 5);
    r.addVehicle(v1);
    r.addVehicle(v2);

    assert(r.findRegNo("a125") == true);
    assert(r.findRegNo("a765") == true);
    assert(r.findRegNo("e555") == false);

    delete v2;
    delete v1;
}

void test_repository()
{
    test_add_repository();
    test_update_repository();
    test_remove_repository();
    test_findRegNo();
    test_file();
}
