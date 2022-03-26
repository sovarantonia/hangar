//
// Created by sovar on 01/05/2021.
//

#ifndef HANGAR_PROIECT_AIRPLANE_H
#define HANGAR_PROIECT_AIRPLANE_H
#include "Vehicle.h"

class Airplane: public Vehicle{
public:
    Airplane(const char*, const char*, const char*, const char*, int);
    ~Airplane();
    string toString();

    char* getType();
    char* getRegistrationNo();
    char* getCompanyName();
    char* getPurpose();
    int getAutonomy();

    void setType(const char* );
    void setRegistrationNo(const char* );
    void setCompanyName(const char* );
    void setPurpose(const char* );
    void setAutonomy(int );

    Airplane &operator=(const Airplane &);
    bool operator==(const Airplane &);

};


#endif //HANGAR_PROIECT_AIRPLANE_H
