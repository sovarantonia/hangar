//
// Created by sovar on 01/05/2021.
//
#include <cstring>
#include "Helicopter.h"
using std::to_string;
/// General constructor for the helicopter
/// \param type const char*: helicopter type
/// \param reg_no cost char*: registration number
/// \param company const char*: company name
/// \param purp: helicopter purpose
/// \param auton int: helicopter autonomy(* 100)
Helicopter::Helicopter(const char *type, const char *reg_no, const char* company, const char* purp, int auton) : Vehicle(type, reg_no, company, purp, auton)
{

}


///destructor
Helicopter::~Helicopter()
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
/// \return a string consisting of type, reg no, company name, purpose, autonomy and engine no
string Helicopter::toString()
{
    return  Vehicle::toString() + "Helicopter -> type: " +  type + ", registration no: " + registrationNo +
            ", company name: " + companyName + ", purpose: " + purpose + ", autonomy (in km): " + to_string(autonomy * 100);
}



char * Helicopter::getType()
{
    return Vehicle::getType();
}


char * Helicopter::getRegistrationNo()
{
    return Vehicle::getRegistrationNo();
}


char * Helicopter::getCompanyName()
{
    return Vehicle::getCompanyName();
}


char * Helicopter::getPurpose()
{
    return Vehicle::getPurpose();
}


int Helicopter::getAutonomy()
{
    return Vehicle::getAutonomy();
}


void Helicopter::setType(const char *t)
{
    Vehicle::setType(t);
}


void Helicopter::setRegistrationNo(const char *rn)
{
    Vehicle::setRegistrationNo(rn);
}


void Helicopter::setCompanyName(const char *company)
{
    Vehicle::setCompanyName(company);
}


void Helicopter::setPurpose(const char *purp)
{
    Vehicle::setPurpose(purp);
}


void Helicopter::setAutonomy(int auton)
{
    Vehicle::setAutonomy(auton);
}


/// assign operator
/// \return ~a ref. to current item~
Helicopter & Helicopter::operator=(const Helicopter &a)
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
bool Helicopter::operator==(const Helicopter &h)
{
    if(strcmp(this->registrationNo, h.registrationNo) == 0) return true;
    return false;
}


