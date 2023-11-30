#include "Person.h"
#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>


struct Employee* new_Employee(const char *F,const char *L,char *D,const char *C,const int S)
{
    struct Employee *ptr_E=NULL;
    ptr_E=malloc(sizeof(struct Employee));

    if(ptr_E==NULL)
        return NULL;

    ptr_E->name=new_Person(F,L);

    ptr_E->Department=malloc(sizeof(char)*(strlen(D)+1));
    if(ptr_E->Department==NULL)
        return NULL;
    strcpy(ptr_E->Department,D);

    ptr_E->Company=malloc(sizeof(char)*(strlen(C)+1));
    if(ptr_E->Company==NULL)
        return NULL;
    strcpy(ptr_E->Company,C);

    ptr_E->Salary=S;
    ptr_E->show=display_E;
    ptr_E->write=write_file_E;

    return ptr_E;

}
void display_E(const struct Employee *self)
{
    self->name->show(self->name);
    printf("Department:%s\n",self->Department);
    printf("Company:%s\n",self->Company);
    printf("Salary:%d\n",self->Salary);
}
void write_file_E(struct Employee **self,const char *F)
{
    (*self)->name ->F_name=malloc(sizeof(char)*(strlen(F)+1));
    if((*self)->name ->F_name==NULL)
        return;
    strcpy((*self)->name ->F_name,F);
}