//
// Created by sovar on 18/05/2021.
//

#include "VehicleException.h"
VehicleException::VehicleException(string &m) : message(m)
{

}


string VehicleException::get_message()
{
    return message;
}