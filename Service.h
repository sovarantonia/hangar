//
// Created by sovar on 07/05/2021.
//

#ifndef HANGAR_PROIECT_SERVICE_H
#define HANGAR_PROIECT_SERVICE_H
#include "Repository.h"
#include <map>
class Service {
private:
   Repository repo;
public:
    Service();
    ~Service();
    Service(Repository &repo);

    void addVehicle(const char*, const char*, const char*, const char*, int, int);
    void removeVehicle(const char*);
    void updateVehicle(const char*, const char*, const char*, const char*, const char*, int);

    int getSize();
    vector <Vehicle*> getAll();

    map <string, int> averageAutonomy();
    vector <Vehicle*> getAllVehiclesCompany(const char*);
    map <string, vector <Vehicle*> > groupVehiclesByPurpose();
    vector <Vehicle*> sortVehicles();
    static bool typeCmp(Vehicle* , Vehicle *);

};


#endif //HANGAR_PROIECT_SERVICE_H
