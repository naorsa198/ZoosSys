#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
#include <exception>
using namespace std;

class IDException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "id doesn't exists";
    }
};

class StudentPermissions : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "this student don't have permission";
    }
};

class SplitBefore : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "This room was split before";
    }
};

class InvalidDetails : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Please enter valid details";
    }
};
#endif //WORK5_EXCEPTION_H