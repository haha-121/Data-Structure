#include "Person.h"
#include "Employee.h"
#include<stdio.h>
int main()
{
    printf("person object:\n");
    struct Person *person=new_Person("cruise","Tom");
    person->show(person);

    printf("\nperson object modify name:\n");
    person->write(&person,"hanks");
    person->show(person);

    printf("\n\nempolyee object(inherient person):\n");

    struct Employee *employee=new_Employee("cena","John","HR","Google",50000);
    employee->show(employee);

    printf("\nempolyee object modify name:\n");
    employee->write(&employee,"wick");
    employee->show(employee);



    return 0;
}