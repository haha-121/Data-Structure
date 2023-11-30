#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"

struct Employee
{
    struct Person *name;
    char *Department;
    char *Company;
    int Salary;
    void (*show)(const struct Employee*);
    void (*write)(struct Employee**,const char *);
};

struct Employee* new_Employee(const char *F,const char *L,char *D,const char *C,const int S);
void display_E(const struct Employee *self);
void write_file_E(struct Employee **self,const char *F);


#endif