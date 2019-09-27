#ifndef MAINFUNCTIONS_H_INCLUDED
#define MAINFUNCTIONS_H_INCLUDED
#define NSIZE 70
#define MAX_SIZE 500
typedef struct
{
    int day;
    int month;
    int year;
} birth;
typedef struct
{
    char fname[NSIZE];
    char lname[NSIZE];
   // int Naddress;
    birth date;
    char address[NSIZE];
    char mail[NSIZE];
    char Nphone[NSIZE];
} contact;
contact Contacts_array[MAX_SIZE];
int lines=0;
contact*results[MAX_SIZE];
contact keyContact;
contact*multisearchResults[MAX_SIZE];
int searchResultsSize;
char path[MAX_SIZE];
int counter=0;
void LOAD();
void search();
void ADD();
void Delete();
void modify();
void printc(int j);
void save();
void Exit();
#endif // MAINFUNCTIONS_H_INCLUDED
