//
// Created by sovar on 07/05/2021.
//

#include "Repository.h"
#include <cstring>
#include <fstream>

Repository::Repository()
{

}

Repository::~Repository()
{
    if(filename)
        delete[] filename;
    elements.clear();
}

Repository::Repository(const char *filename)
{
    if(filename)
    {
        this->elements.clear();
        this->filename = new char[strlen(filename) + 1];
        strcpy_s(this->filename, strlen(filename) + 1, filename);
        this->loadFromFile();
    }

}


void Repository::loadFromFile()
{
    if(filename)
    {
        ifstream f(filename);
        char *type = new char[10];
        char* regNo = new char[6];
        char* companyName = new char[20];
        char* purpose = new char[11];
        char* letter = new char[2];
        int autonomy;
        while(f >> type >> regNo >> companyName >> purpose >> autonomy >> letter)
        {
            if(strcmp(letter, "a") == 0)
            {
                Vehicle* v = new Airplane(type, regNo, companyName, purpose, autonomy);
                elements.push_back(v);
            }
            else if(strcmp(letter, "h") == 0)
            {
                Vehicle* v = new Helicopter(type, regNo, companyName, purpose, autonomy);
                elements.push_back(v);
            }
            else
            {
                Vehicle* v = new Vehicle(type, regNo, companyName, purpose, autonomy);
                elements.push_back(v);
            }
        }
        delete[] letter;
        delete[] purpose;
        delete[] companyName;
        delete[] regNo;
        delete[] type;
        f.close();
    }
}


void Repository::saveToFile()
{
    ofstream g(filename);
    for(int i = 0; i < elements.size(); i ++)
        g << elements[i]->getType() << elements[i]->getRegistrationNo() << elements[i]->getCompanyName()
        << elements[i]->getPurpose() << elements[i]->getAutonomy()<< "\n";
    g.close();
}


/// Adds a vehicle in vector of vehicles
/// \param v - a vehicle
void Repository::addVehicle(Vehicle *v)
{
    elements.push_back(v);
    this->saveToFile();
}


/// Removes a vehicle from the vector
/// \param v - the vehicle to remove
void Repository::removeVehicle(Vehicle *v)
{
    for(int i = 0; i < elements.size(); i ++)
        if(strcmp(elements[i]->getRegistrationNo(), v->getRegistrationNo()) == 0)
        {
            elements.erase(elements.begin() + i);
            this->saveToFile();
        }

}


/// Updates a vehicle
/// \param oldv the old vehicle
/// \param newv the new vehicle
void Repository::updateVehicle(Vehicle* oldv, Vehicle* newv)
{
    for(Vehicle* v: elements)
        if(strcmp(v->getRegistrationNo(), oldv->getRegistrationNo()) == 0)
        {
            oldv->setType(newv->getType());
            oldv->setRegistrationNo(newv->getRegistrationNo());
            oldv->setCompanyName(newv->getCompanyName());
            oldv->setPurpose(newv->getPurpose());
            oldv->setAutonomy(newv->getAutonomy());
        }
    this->saveToFile();
}


/// All the vehicles
/// \return a vector whith all the vehicles
vector<Vehicle *> Repository::getAll()
{
    return elements;
}


/// Find the vehicle with a given regNo
/// \param rn const char* : the regNo
/// \return true if it is in the vector and false otherwise
bool Repository::findRegNo(const char *rn)
{
    for(Vehicle* v : elements)
        if(strcmp(v->getRegistrationNo(), rn) == 0)
            return true;
    return false;
}


/// The vector size / no of elements
/// \return int: the vector size
int Repository::getSize()
{
    return elements.size();
}

char * Repository::getFileName()
{
    return this->filename;
}
