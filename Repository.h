//
// Created by sovar on 07/05/2021.
//

#ifndef HANGAR_PROIECT_REPOSITORY_H
#define HANGAR_PROIECT_REPOSITORY_H
#include <vector>
#include "Vehicle.h"
#include "Airplane.h"
#include "Helicopter.h"
using namespace std;
class Repository {
private:
    vector <Vehicle*> elements;
    char* filename;
public:
    Repository();
    ~Repository();
    Repository(const char* filename);

    char* getFileName();

    void loadFromFile();
    void saveToFile();

    void addVehicle(Vehicle *);
    void removeVehicle(Vehicle *);
    void updateVehicle(Vehicle *, Vehicle *);

    vector <Vehicle*> getAll();
    bool findRegNo(const char*);
    int getSize();

};


#endif //HANGAR_PROIECT_REPOSITORY_H
