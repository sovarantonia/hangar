//
// Created by sovar on 18/05/2021.
//

#include "ServiceException.h"
ServiceException::ServiceException(string &m): message(m)
{

}

string ServiceException::get_message()
{
    return message;
}


RegNoNotValid::RegNoNotValid(string message) : ServiceException(message)
{

}


CompanyNameNotValid::CompanyNameNotValid(string message) : ServiceException(message)
{

}