//
// Created by sovar on 01/05/2021.
//
#include <cstring>
#include "Airplane.h"
using std::to_string;
/// General constructor for the plane
/// \param type const char*: plane type
/// \param reg_no cost char*: registration number
/// \param company const char*: company name
/// \param purp: plane purpose
/// \param auton int: plane autonomy (*100)
Airplane::Airplane(const char *type, const char *reg_no, const char* company, const char* purp, int auton) : Vehicle(type, reg_no, company, purp, auton)
{

}


///destructor
Airplane::~Airplane()
{
    if(type)
        delete[] type;
    if(registrationNo)
        delete[] registrationNo;
    if(companyName)
        delete[] companyName;
    if(purpose)
        delete[] purpose;
    autonomy = 0;
}


/// Airplane description
/// \return a string consisting of type, reg no, company name, purpose and autonomy
string Airplane::toString()
{
    return  Vehicle::toString() + "Airplane -> type: " +  type + ", registration no: " + registrationNo +
    ", company name: " + companyName + ", purpose: " + purpose + ", autonomy (in km): " + to_string(autonomy * 100);
}


char * Airplane::getType()
{
    return Vehicle::getType();
}


char * Airplane::getRegistrationNo()
{
    return Vehicle::getRegistrationNo();
}


char * Airplane::getCompanyName()
{
    return Vehicle::getCompanyName();
}


char * Airplane::getPurpose()
{
    return Vehicle::getPurpose();
}


int Airplane::getAutonomy()
{
    return Vehicle::getAutonomy();
}


void Airplane::setType(const char *t)
{
    Vehicle::setType(t);
}


void Airplane::setRegistrationNo(const char *rn)
{
    Vehicle::setRegistrationNo(rn);
}


void Airplane::setCompanyName(const char *company)
{
    Vehicle::setCompanyName(company);
}


void Airplane::setPurpose(const char *purp)
{
    Vehicle::setPurpose(purp);
}


void Airplane::setAutonomy(int auton)
{
    Vehicle::setAutonomy(auton);
}


/// assign operator
/// \return ~a ref. to current item~
Airplane & Airplane::operator=(const Airplane &a)
{
    if(this != &a)
    {
        this->setType(a.type);
        this->setRegistrationNo(a.registrationNo);
        this->setCompanyName(a.companyName);
        this->setPurpose(a.purpose);
        this->setAutonomy(a.autonomy);
    }
    return *this;
}


/// Compares 2 planes by their reg no
/// \param a Airplane: a plane
/// \return true if they have the same reg no and false otherwise
bool Airplane::operator==(const Airplane &a)
{
    if(strcmp(this->registrationNo, a.registrationNo) == 0) return true;
    return false;
}
