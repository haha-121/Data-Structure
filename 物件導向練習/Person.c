
#include "Person.h"
#include<stdlib.h>
#include<stdio.h>
struct Person* new_Person(const char *F,const char *L)
{
    struct Person *ptr=NULL;
    ptr=malloc(sizeof(struct Person));

    if(ptr==NULL)
        return NULL;

    ptr->F_name=malloc(sizeof(char)*(strlen(F)+1));
    if(ptr->F_name==NULL)
        return NULL;
    strcpy(ptr->F_name,F);

    ptr->L_name=malloc(sizeof(char)*(strlen(L)+1));
    if(ptr->L_name==NULL)
        return NULL;
    strcpy(ptr->L_name,L);

    ptr->show=display;
    ptr->write=write_file;

    return ptr;
}
void _delete(struct Person **self)
{
    if(*self!=NULL)
    {
        free(*self);
        *self=NULL;
    }
}
void display(const struct Person *self)
{
    printf("First name:%s\n",self->F_name);
    printf("Last name:%s\n",self->L_name);
}
void write_file(struct Person **self,const char *F)
{
    (*self)->F_name=malloc(sizeof(char)*(strlen(F)+1));
    if((*self)->F_name==NULL)
        return;
    strcpy((*self)->F_name,F);
}
