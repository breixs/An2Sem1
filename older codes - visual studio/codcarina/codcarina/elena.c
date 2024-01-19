#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[35];
    char address[50];
    char father_name[35];
    char mother_name[30];
    char tel_number[15];
    char sex[8];
    char mail[100];
}Contact;

Contact contact_list[101];

void addcontact();
void contactlist();
void searchcontact();
void modifycontact();
void deletecontact();

void exit_prog()
{
    printf("\t\t\t\t Application finished");
    exit(0);
}

void read() {
    FILE* fp;
    fp = fopen("f.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    char current_line[1001];
    while (fgets(current_line, 100, fp)) {
        printf("%s", current_line);
    }
    fclose(fp);
}
void menu() {
    printf("\t\t\t    PHONEBOOK");
    printf("\n\n\t\t\t      MENU\t\t\n\n");
    printf("\t1.Add New Contact   \t\t4.Modify Contact   \n\t2.Contact List  \t\t5.Delete Contact \n\t3.Search Contact \t\t6.Exit\n\n");
    printf("\t\t\t    Enter 1 to 6\n");
    switch (getch())
    {
    case '1': addcontact();
        break;
    case '2': contactlist();
        break;
    case '3': searchcontact();
        break;
    case '4': modifycontact();
        break;
    case '5': deletecontact();
        break;
    case '6':
        exit_prog();
        break;
    default: menu();
    }
}

void addcontact()
{
    printf("\tAdds a contact.\n");
    getch();
    menu();
}

void contactlist()
{
    printf("\tDisplays the contact list \n");
    getch();
    menu();
}
void searchcontact()
{
    printf("\tSearches for a contact.\n");
    getch();
    menu();
}
void modifycontact()
{
    printf("\tModifies a contact.\n");
    getch();
    menu();
}
void deletecontact()
{
    printf("\tDelete a contact.\n");
    getch();
    menu();
}

void start() {
    menu();
}

int main()
{
    system("color 03");
    start();
    FILE* out_file = fopen("contact_list_out", "w"); // write only
    read();
    return 0;
}