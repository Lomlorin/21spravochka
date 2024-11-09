#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_WORK_LENGTH 50
#define MAX_POSITION_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50
#define MAX_SOCIAL_LENGTH 100

typedef struct {
    char first_name[MAX_NAME_LENGTH];
    char surname[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    char work[MAX_WORK_LENGTH];
    char position[MAX_POSITION_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char social[MAX_SOCIAL_LENGTH];
} Contact;

Contact contacts[MAX_CONTACTS];
int contact_count = 0;

void add_contact() {

    if (contact_count >= MAX_CONTACTS) {
        printf("The phone book is full.\n");
        return;
    }

    Contact new_contact;
    printf("Enter name: \n");
    scanf("%s", new_contact.first_name);
    printf("Enter surname: \n");
    scanf("%s", new_contact.surname);

    printf("Enter last name (leave it blank if not needed): \n");
    getchar(); // очищаем буфер
    fgets(new_contact.last_name, MAX_NAME_LENGTH, stdin);

    printf("Enter your place of work (leave it blank if not needed): \n");
    fgets(new_contact.work, MAX_WORK_LENGTH, stdin);

    printf("Enter the position (leave it blank if not needed): \n");
    fgets(new_contact.position, MAX_POSITION_LENGTH, stdin);

    printf("Enter the phone number (leave it blank if not needed): \n");
    fgets(new_contact.phone, MAX_PHONE_LENGTH, stdin);

    printf("Enter the email address (leave it blank if not needed): \n");
    fgets(new_contact.email, MAX_EMAIL_LENGTH, stdin);

    printf("Enter the link to the social network (leave it blank if not needed): \n");
    fgets(new_contact.social, MAX_SOCIAL_LENGTH, stdin);

    contacts[contact_count++] = new_contact;
    printf("Contact added.\n");
}

void edit_contact( char first_name[MAX_NAME_LENGTH], char surname[MAX_NAME_LENGTH]) {
    

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].first_name, first_name) == 0 && strcmp(contacts[i].surname, surname) == 0) {
            printf("Editing a contact: %s %s \n", contacts[i].first_name, contacts[i].surname );
            printf("Enter a new place of work (leave it empty to save): \n");
            getchar();
            fgets(contacts[i].work, MAX_WORK_LENGTH, stdin);

            printf("Enter a new position (leave it empty to save): \n");
            fgets(contacts[i].position, MAX_POSITION_LENGTH, stdin);

            printf("Enter a new phone number (leave it blank to save): \n");
            fgets(contacts[i].phone, MAX_PHONE_LENGTH, stdin);

            printf("Enter a new email address (leave it blank to save): \n");
            fgets(contacts[i].email, MAX_EMAIL_LENGTH, stdin);

            printf("Enter a new link to the social network (leave it blank to save): \n");
            fgets(contacts[i].social, MAX_SOCIAL_LENGTH, stdin);

            printf("The contact has been updated.\n");
            return;
        }
    }
    
    printf("The contact was not found.\n");
}

void delete_contact(char first_name[MAX_NAME_LENGTH], char surname[MAX_NAME_LENGTH]) {

    for (int i = 0; i < contact_count; i++) {
        if (strcmp(contacts[i].first_name, first_name) == 0 && strcmp(contacts[i].surname, surname) == 0) {
            for (int j = i; j < contact_count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            contact_count--;
            printf("The contact has been deleted.\n");
            return;
        }
    }

    printf("The contact was not found.\n");
}

void list_contacts() {
    if (contact_count == 0) {
        printf("The phone book is empty.\n");
        return;
    }

    for (int i = 0; i < contact_count; i++) {
        printf("Contact %d:\n", i + 1);
        printf("Name: %s\n", contacts[i].first_name);
        printf("Surname: %s\n", contacts[i].surname);
        printf("Last name: %s\n", contacts[i].last_name);

        if (strlen(contacts[i].work) > 0) {
            printf("Place of work: %s\n", contacts[i].work);
        }
        if (strlen(contacts[i].position) > 0) {
            printf("Post: %s\n", contacts[i].position);
        }
        if (strlen(contacts[i].phone) > 0) {
            printf("Telephone: %s\n", contacts[i].phone);
        }
        if (strlen(contacts[i].email) > 0) {
            printf("Email: %s\n", contacts[i].email);
        }
        if (strlen(contacts[i].social) > 0) {
            printf("Social network: %s\n", contacts[i].social);
        }
    }
}

int main() {
    int choice;

    while (1) {
        printf ("Phone book:\n");
        printf("1. Add a contact\n");
        printf("2. Edit the contact\n");
        printf("3. Delete the contact\n");
        printf("4. Show all contacts\n");
        printf("5. Exit\n");
        printf ("Select an action: \n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                char first_name2[MAX_NAME_LENGTH], surname2[MAX_NAME_LENGTH];
                printf("Enter the name of the contact to edit: \n");
                scanf("%s", first_name2);
                printf("Enter the  surname of the contact to edit: \n");
                scanf("%s", surname2);
                edit_contact(first_name2, surname2);
                break;
            case 3:
                char first_name3[MAX_NAME_LENGTH], surname3[MAX_NAME_LENGTH];
                printf("Enter the name of the contact to delete: \n");
                scanf("%s", first_name3);
                printf("Enter the surname of the contact to delete: \n");
                scanf("%s", surname3);
                delete_contact(first_name3, surname3);
                break;
            case 4:
                list_contacts();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice. Try again.\n");
        }
    }

    return 0;
}
