//
// Created by sovar on 18/05/2021.
//

#ifndef PRJ_VEHICLEEXCEPTION_H
#define PRJ_VEHICLEEXCEPTION_H
#include <exception>
#include <string>
using namespace std;
class VehicleException : public exception {
protected:
    string message;
public:
    VehicleException(string &m);
    string get_message();
};


#endif //PRJ_VEHICLEEXCEPTION_H
