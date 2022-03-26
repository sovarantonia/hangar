//
// Created by sovar on 16/05/2021.
//

#include <cstring>
#include "Vehicle.h"

/// General constructor
/// \param typ const char*: the type of the vehicle
/// \param registration_no, const char*: the registration number
/// \param co_name const char*: the company name which ordered the vehicle
/// \param auton int: the vehicle autonomy (in km)
/// \param prpse: const char*: the purpose of the vehicle( cargo, commercial, mission)
Vehicle::Vehicle(const char *typ, const char *registration_no, const char* co_name, const char* prpse, int auton)
{
    type = new char[strlen(typ) + 1];
    strcpy_s(type, strlen(typ) + 1, typ);
    registrationNo = new char[strlen(registration_no) + 1];
    strcpy_s(registrationNo, strlen(registration_no) + 1, registration_no);
    companyName = new char[strlen(co_name) + 1];
    strcpy_s(companyName, strlen(co_name) + 1, co_name);
    autonomy = auton;
    purpose = new char[strlen(prpse) + 1];
    strcpy_s(purpose, strlen(prpse) + 1, prpse);
}


///destructor
Vehicle::~Vehicle()
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

/// Print a vehicle
/// \return a string
string Vehicle::toString()
{
    return "Description: ";
}


/// Type of current vehicle
/// \return the type
char * Vehicle::getType()
{
    return type;
}

/// Registration number of current vehicle
/// \return the reg no
char * Vehicle::getRegistrationNo()
{
    return registrationNo;
}

/// Company name which ordered the current vehicle
/// \return the company name
char * Vehicle::getCompanyName()
{
    return companyName;
}

/// Purpose of the current vehicle
/// \return the purpose
char * Vehicle::getPurpose()
{
    return purpose;
}

/// Current vehicle autonomy
/// \return the autonomy
int Vehicle::getAutonomy()
{
    return autonomy;
}


/// Sets the current vehicle type to tip
/// \param tip the new type
void Vehicle::setType(const char *tip)
{
    if(type)
        delete[] type;
    type = new char[strlen(tip) + 1];
    strcpy_s(type, strlen(tip) + 1, tip);
}


/// Sets the current vehicle reg no to inreg
/// \param inreg the new reg no
void Vehicle::setRegistrationNo(const char *inreg)
{
    if(registrationNo)
        delete[] registrationNo;
    registrationNo = new char[strlen(inreg) + 1];
    strcpy_s(registrationNo, strlen(inreg) + 1, inreg);
}


/// Sets the company name which ordered the current vehicle to company
/// \param company the new company name
void Vehicle::setCompanyName(const char *company)
{
    if(companyName)
        delete[] companyName;
    companyName = new char[strlen(company) + 1];
    strcpy_s(companyName, strlen(company) + 1, company);
}


/// Sets the current vehicle purpose to scop
/// \param scop the new purpose
void Vehicle::setPurpose(const char *scop)
{
    if(purpose)
        delete[] purpose;
    purpose = new char[strlen(scop) + 1];
    strcpy_s(purpose, strlen(scop) + 1, scop);
}


/// Sets the current vehicle autonomy to auton
/// \param auton the new autonomy
void Vehicle::setAutonomy(int auton)
{
    autonomy = auton;
}


