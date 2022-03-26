//
// Created by sovar on 18/05/2021.
//

#ifndef PRJ_SERVICEEXCEPTION_H
#define PRJ_SERVICEEXCEPTION_H
#include <exception>
#include <string>
using namespace std;
class ServiceException : public exception {
protected:
    string message;
public:
    ServiceException(string &m);

    string get_message();
};


class RegNoNotValid : public ServiceException
{
public:
    RegNoNotValid(string message);
};

class CompanyNameNotValid : public ServiceException
{
public:
    CompanyNameNotValid(string message);
};
#endif //PRJ_SERVICEEXCEPTION_H
