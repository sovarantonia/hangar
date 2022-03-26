//
// Created by sovar on 03/05/2021.
//
#include "test_domain.h"
#include "Vehicle.h"
#include "Airplane.h"
#include "Helicopter.h"
#include "VehicleValidator.h"
#include "VehicleException.h"
#include <cstring>
#include <cassert>
void test_general_cstr()
{
    VehicleValidator vv;

    Vehicle v("car1", "125d", "aba", "cargo", 10);
    assert(v.getAutonomy() == 10);
    assert(strcmp(v.getType(), "car1") == 0);
    assert(strcmp(v.getRegistrationNo(), "125d") == 0);
    assert(strcmp(v.getCompanyName(), "aba") == 0);
    assert(strcmp(v.getPurpose(), "cargo") == 0);

    Airplane a("airbus", "abc4", "flag", "commercial", 8);
    assert(strcmp(a.getType(), "airbus") == 0);
    assert(strcmp(a.getRegistrationNo(), "abc4") == 0);
    assert(a.getAutonomy() == 8);
    assert(strcmp(a.getCompanyName(), "flag") == 0);
    assert(strcmp(a.getPurpose(), "commercial") == 0);

    Helicopter h("smth", "ro123", "abc", "mission", 2);
    assert(strcmp(h.getType(), "smth") == 0);
    assert(strcmp(h.getRegistrationNo(), "ro123") == 0);
    assert(h.getAutonomy() == 2);
    assert(strcmp(h.getCompanyName(), "abc") == 0);
    assert(strcmp(h.getPurpose(), "mission") == 0);

    try
    {
        Airplane a1("aaaa", "abc4", "wqwq", "ca", 0);
        vv.validate(&a1);
        assert(false);
    }
    catch(VehicleException &ve)
    {
        assert(true);
    }

}


void test_setter()
{
    Vehicle v("car1", "125d", "aba", "cargo", 10);
    Airplane a("airbus", "abc4", "flag", "commercial", 8);
    Helicopter h("smth", "ro123", "abc", "mission", 2);

    v.setAutonomy(5);
    assert(v.getAutonomy() == 5);
    v.setPurpose("commercial");
    assert(strcmp(v.getPurpose(), "commercial") == 0);

    a.setRegistrationNo("ayr457");
    assert(strcmp(a.getRegistrationNo(), "ayr457") == 0);
    a.setCompanyName("better");
    assert(strcmp(a.getCompanyName(), "better") == 0);

    h.setType("another");
    assert(strcmp(h.getType(), "another") == 0);

}


void test_eq_op_airplane()
{
    Airplane a("airbus", "abc4", "flag", "commercial", 8);
    Airplane a1("airbus", "abc4", "flag", "commercial", 8);
    assert(a == a1);
}


void test_eq_op_helicopter()
{
    Helicopter h("smth", "ro123", "abc", "mission", 2);
    Helicopter h1("smth", "ro123", "abc", "mission", 2);
    assert(h == h1);
}



void test_domain()
{
    test_general_cstr();
    test_setter();
    test_eq_op_airplane();
    test_eq_op_helicopter();
}
