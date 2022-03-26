//
// Created by sovar on 16/05/2021.
//

#ifndef PRJ_VEHICLE_H
#define PRJ_VEHICLE_H
#include <string>
using std::string;
class Vehicle {
protected:
    char* type;
    char* registrationNo;
    char* companyName;
    char* purpose;
    int autonomy;

public:
    Vehicle(const char*, const char*, const char*, const char*, int );
    virtual ~Vehicle();
    virtual string toString();

    virtual char* getType();
    virtual char* getRegistrationNo();
    virtual char* getCompanyName();
    virtual char* getPurpose();
    virtual int getAutonomy();

    virtual void setType(const char* );
    virtual void setRegistrationNo(const char* );
    virtual void setCompanyName(const char* );
    virtual void setPurpose(const char* );
    virtual void setAutonomy(int );
};

#endif //PRJ_VEHICLE_H
