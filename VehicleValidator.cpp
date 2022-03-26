//
// Created by sovar on 18/05/2021.
//

#include "VehicleValidator.h"
#include <cstring>
VehicleValidator::VehicleValidator() {}
VehicleValidator::~VehicleValidator() {}
void VehicleValidator::validate(Vehicle *v)
{
    string errors = "";
    if(v->getType() == nullptr)
        errors += "Tipul trebuie sa aiba o denumire \n";
    if(v->getRegistrationNo() == nullptr)
        errors += "Nr de inregistrare trebuie sa aiba o denumire \n";
    if(v->getCompanyName() == nullptr)
        errors += "Numele companiei trebuie sa aiba o denumire \n";
    if(!(strcmp(v->getPurpose(), "cargo") == 0 || strcmp(v->getPurpose(), "commercial") == 0 || strcmp(v->getPurpose(), "mission") == 0))
        errors += "Scopul trebuie sa fie cargo, commercial sau mission \n";
    if(v->getAutonomy() <= 0)
        errors += "Autonomia trebuie sa fie un nr intreg pozitiv nenul \n";
    if(!errors.empty())
        throw(VehicleException(errors));
}