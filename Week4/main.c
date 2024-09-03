#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CONTACT 50
struct contact {
    char name[50];
    char phone[12];
    char email [20];

};
void AddContact (struct contact Contacts[],int *count);
void SearchContact(struct contact Contacts[],int count);
void DisplayContacts(struct contact Contacts[],int count);
int main()
{
    struct contact Contacts[MAX_CONTACT];
    int count=0,choice;
    while (1)
    {
        printf("\nPhonebook Menu : \n");
        printf("(1) Add Contact : \n");
        printf("(2) Search Contact : \n");
        printf("(3) Display all contacts : \n");
        printf("(4) Exit \n");
        printf("Please enter your choice : ");
        scanf(" %d",&choice);

        switch(choice)
        {
        case 1:
            AddContact(Contacts, &count);
            break;
        case 2:
            SearchContact(Contacts,count);
            break;
        case 3:
            DisplayContacts(Contacts,count);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice ! Please try again \n");

        }
    }

return 0;
}
void AddContact (struct contact Contacts[],int *count)
{
    if (*count >=MAX_CONTACT)
    {
        printf("Phonebook is full!\n Cannot add any more contacts.\n");
        return;
    }
    struct contact newcontact;
    printf("Enter name : ");
    scanf(" %[^\n]",newcontact.name);
    printf("Enter phone number : ");
    scanf("%s",newcontact.phone);
    printf("Enter email : ");
    scanf("%s",newcontact.email);

    Contacts[*count]=newcontact;
    (*count)++;

     printf("Contact Added !\n");
}
void SearchContact(struct contact Contacts[],int count)
{
    char search[50];
    int found=0;

    printf("Please enter the name to be searched : ");
    scanf(" %[^\n]",search);

    for (int i=0;i<count;i++)
    {
        if (strcmp(search,Contacts[i].name)==0)
        {
            printf("\nContact Found ! \n");
            printf("Name : %s\n",Contacts[i].name);
            printf("Phone number : %s\n",Contacts[i].phone);
            printf("Email : %s\n",Contacts[i].email);
            found=1;
            break;
        }
    }
    if (found==0)
    {
        printf("\n Contact not found ! \n");
    }
}
void DisplayContacts(struct contact Contacts[],int count)
{
    if (count==0)
    {
        printf("No contacts to display \n");
        return;
    }
    printf("All contacts : \n");
     for (int i=0;i<count;i++)
     {
        printf("Contact number %d : \n",i+1);
        printf("Name : %s\n",Contacts[i].name);
        printf("Phone number : %s\n",Contacts[i].phone);
        printf("Email : %s\n",Contacts[i].email);
        printf("----------------------\n");
     }
}
