//
// Created by sovar on 18/05/2021.
//

#ifndef PRJ_VEHICLEVALIDATOR_H
#define PRJ_VEHICLEVALIDATOR_H
#include "Vehicle.h"
#include "VehicleException.h"
class VehicleValidator {
public:
    VehicleValidator();
    ~VehicleValidator();
    void validate(Vehicle* v);
};


#endif //PRJ_VEHICLEVALIDATOR_H
