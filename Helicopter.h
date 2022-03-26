//
// Created by sovar on 01/05/2021.
//

#ifndef HANGAR_PROIECT_HELICOPTER_H
#define HANGAR_PROIECT_HELICOPTER_H
#include "Vehicle.h"

class Helicopter: public Vehicle {
public:
    Helicopter(const char*, const char*, const char*, const char*, int);
    ~Helicopter();
    string toString();

    char* getType();
    char* getRegistrationNo();
    char* getCompanyName();
    char* getPurpose();
    int getAutonomy();
    int getNoPropellers();

    void setType(const char* );
    void setRegistrationNo(const char* );
    void setCompanyName(const char* );
    void setPurpose(const char* );
    void setAutonomy(int );
    void setNoPropellers(int );

    Helicopter &operator=(const Helicopter &);
    bool operator==(const Helicopter &);

};


#endif //HANGAR_PROIECT_HELICOPTER_H
