//
// Created by sovar on 07/05/2021.
//

#include "Service.h"
#include "Airplane.h"
#include "Helicopter.h"
#include "ServiceException.h"
#include "VehicleValidator.h"
#include <cstring>
#include <algorithm>
using namespace std;

Service::Service()
{

}

Service::Service(Repository &repo)
{
    this->repo = repo;
}

Service::~Service()
{
    for(Vehicle* v : repo.getAll())
        if(v != nullptr)
            delete v;

}

/// All the vehicles
/// \return a vector with all the vehicles
vector<Vehicle *> Service::getAll()
{
    return repo.getAll();
}


/// Adds a plane or helicopter
/// \param type const char*: type of vehicle
/// \param regNo const char*: the registration no
/// \param companyName const char* : company name
/// \param purpose const char*: purpose
/// \param autonomy int: autonomy
/// \param ok int: 1 if a plane is added or -1 if a helicopter is added
void Service::addVehicle(const char *type, const char *regNo, const char* companyName, const char* purpose, int autonomy, int ok)
{
    VehicleValidator v;
    if(!repo.findRegNo(regNo))
    {
        if(ok == 1)
        {
            Vehicle* p = new Airplane(type, regNo, companyName, purpose, autonomy);
            v.validate(p);
            repo.addVehicle(new Airplane(type, regNo, companyName, purpose, autonomy));
            delete p;
        }
        else
            if(ok == -1)
        {
            Vehicle* h = new Helicopter(type, regNo, companyName, purpose, autonomy);
            v.validate(h);
            repo.addVehicle(new Helicopter(type, regNo, companyName, purpose, autonomy));
            delete h;
        }
    }
    else throw(RegNoNotValid("Exista deja numarul de inregistrare \n"));

}


///Updates a vehicle
/// \param oldRegNo const char*: old reg no
/// \param newRegNo const char*: new reg no
/// \param newType const char*: new type

void Service::updateVehicle(const char* oldRegNo, const char* newType, const char* newRegNo, const char* newCompany, const char* newPurpose, int newAutonomy)
{
    VehicleValidator vv;
    if(!repo.findRegNo(oldRegNo))
        throw(RegNoNotValid("Nu exista vehicul cu acest nr de inregistrare \n"));
    if(repo.findRegNo(newRegNo))
        throw(RegNoNotValid("Exista deja acest nr de inregistrare \n"));

    Vehicle* newVehicle = new Vehicle(newType, newRegNo, newCompany, newPurpose, newAutonomy);
    vv.validate(newVehicle);
    for(Vehicle* v : repo.getAll())
        if(strcmp(v->getRegistrationNo(), oldRegNo) == 0)
            repo.updateVehicle(v, newVehicle);

    delete newVehicle;
}


/// Removes a vehicle from the vector
/// \param regNo const char*, the vehicle's registration number
void Service::removeVehicle(const char *regNo)
{
    if(!repo.findRegNo(regNo))
        throw(RegNoNotValid("Nu exista numarul de inregistrare citit \n"));
    for(Vehicle* v : repo.getAll())
        if(strcmp(v->getRegistrationNo(), regNo) == 0)
            repo.removeVehicle(v);
}


/// The current size
/// \return int: the vector size
int Service::getSize()
{
    return repo.getSize();
}


/// Determines the average autonomy for every type of vehicle
/// \return a map consisting of the type and its average autonomy
map<string, int> Service::averageAutonomy()
{
    vector <char*> types;
    types.reserve(repo.getSize());
    map <string, int> result;
    int sum = 0, count = 0;

    for(Vehicle* v : repo.getAll())
    {
        if(find(types.begin(), types.end(), v->getType()) == types.end()) //daca nu se afla in vector
        {
            types.push_back(v->getType());
            result.insert(pair<string, int> (v->getType(), 0));
        }
    }

    for(char* type : types)
    {
        sum = 0; count = 0;
        for(Vehicle* v : repo.getAll())
            if(strcmp(type, v->getType()) == 0)
            {
                sum += v->getAutonomy();
                count ++;
            }
        result.find(type)->second = sum / count;
    }

    types.clear();
    return result;
}


/// companyName's fleet
/// \param companyName const char*: the company name
/// \return a vector with the vehicles which have the company name companyName
vector<Vehicle *> Service::getAllVehiclesCompany(const char *companyName)
{
    vector <Vehicle*> result;
    for(Vehicle* v: repo.getAll())
        if(strcmp(companyName, v->getCompanyName()) == 0)
            result.push_back(v);

   if(result.empty())
       throw(CompanyNameNotValid("Compania nu are aeronave /nu apare in lista \n"));
   return result;
}


map<string, vector <Vehicle*> > Service::groupVehiclesByPurpose()
{
    map <string, vector<Vehicle*> > result;
    vector <Vehicle*> cargos; // vectorul cu vehicule cargo
    vector <Vehicle*> commercials; // vectorul cu vehicule comerciale
    vector <Vehicle*> missions; // vectorul cu vehicule pt misiuni
    for(Vehicle* v: repo.getAll())
    {
        if(strcmp(v->getPurpose(), "cargo") == 0)
            cargos.push_back(v);
        else if(strcmp(v->getPurpose(), "commercial") == 0)
            commercials.push_back(v);
        else missions.push_back(v);
    }

    result.insert(pair <string, vector <Vehicle*> > ("cargo", cargos));
    result.insert(pair <string, vector <Vehicle*> > ("commercial", commercials));
    result.insert(pair <string, vector <Vehicle*> > ("mission", missions));

    return result;
}


bool Service::typeCmp(Vehicle *v1, Vehicle *v2)
{
    return strcmp(v1->getType(), v2->getType()) <= 0;
}


/// Sorts the vehicles alphabetically bu type
/// \return a sorted vector
vector<Vehicle *> Service::sortVehicles()
{
    vector <Vehicle*> result = repo.getAll();
    sort(result.begin(), result.end(), typeCmp);
    return result;
}
