#ifndef PERSON_H
#define PERSON_H


#include<string.h>
struct Person
{
    char *F_name;
    char *L_name;
    void (*show)(const struct Person*);
    void (*write)(struct Person**,const char *);
};
struct Person* new_Person(const char *F,const char *L);
void _delete(struct Person **self);
void display(const struct Person *self);
void write_file(struct Person **self,const char *F);

#endif


