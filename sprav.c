#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_JOB_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 50
#define MAX_SOCIAL_LENGTH 50

typedef struct {
    char FIRST_NAME[MAX_NAME_LENGTH];
    char SURNAME_NAME[MAX_NAME_LENGTH]; 
    char LAST_NAME[MAX_NAME_LENGTH];
    char WORKPLACE[MAX_JOB_LENGTH];
    char POSITION[MAX_JOB_LENGTH];
    char PHONE[MAX_PHONE_LENGTH];
    char EMAIL[MAX_EMAIL_LENGTH];
    char SOCIAL_MEDIA[MAX_SOCIAL_LENGTH];
} Contact;

Contact CONTACTS[MAX_CONTACTS];
int CONTACT_COUNT = 0;

void ADD_CONTACT() {
    if (CONTACT_COUNT >= MAX_CONTACTS) {
        printf("PHONEBOOK IS FULL.n");
        return;
    }
    Contact NEW_CONTACT;
    printf("ENTER FIRST NAME: ");
    scanf("%s", NEW_CONTACT.FIRST_NAME);
    printf("ENTER SURNAME NAME: ");
    scanf("%s", NEW_CONTACT.SURNAME_NAME);
    CONTACTS[CONTACT_COUNT].SURNAME_NAME[strcspn(CONTACTS[CONTACT_COUNT].SURNAME_NAME, "n")] = 0; 

    printf("ENTER LAST NAME (optional): ");
    fgets(CONTACTS[CONTACT_COUNT].LAST_NAME, MAX_NAME_LENGTH, stdin);
    CONTACTS[CONTACT_COUNT].LAST_NAME[strcspn(CONTACTS[CONTACT_COUNT].LAST_NAME, "n")] = 0; 

    printf("ENTER WORKPLACE (optional): ");
    fgets(CONTACTS[CONTACT_COUNT].WORKPLACE, MAX_JOB_LENGTH, stdin);
    CONTACTS[CONTACT_COUNT].WORKPLACE[strcspn(CONTACTS[CONTACT_COUNT].WORKPLACE, "n")] = 0; 

    printf("ENTER POSITION (optional): ");
    fgets(CONTACTS[CONTACT_COUNT].POSITION, MAX_JOB_LENGTH, stdin);
    CONTACTS[CONTACT_COUNT].POSITION[strcspn(CONTACTS[CONTACT_COUNT].POSITION, "n")] = 0; 

    printf("ENTER PHONE (optional): ");
    fgets(CONTACTS[CONTACT_COUNT].PHONE, MAX_PHONE_LENGTH, stdin);
    CONTACTS[CONTACT_COUNT].PHONE[strcspn(CONTACTS[CONTACT_COUNT].PHONE, "n")] = 0; 

    printf("ENTER EMAIL (optional): ");
    fgets(CONTACTS[CONTACT_COUNT].EMAIL, MAX_EMAIL_LENGTH, stdin);
    CONTACTS[CONTACT_COUNT].EMAIL[strcspn(CONTACTS[CONTACT_COUNT].EMAIL, "n")] = 0; 

    printf("ENTER SOCIAL MEDIA (optional): ");
    fgets(CONTACTS[CONTACT_COUNT].SOCIAL_MEDIA, MAX_SOCIAL_LENGTH, stdin);
    CONTACTS[CONTACT_COUNT].SOCIAL_MEDIA[strcspn(CONTACTS[CONTACT_COUNT].SOCIAL_MEDIA, "n")] = 0; 

    CONTACT_COUNT++;
    printf("CONTACT ADDED.n");
}

void EDIT_CONTACT() {
    char LAST_NAME[MAX_NAME_LENGTH];
    printf("ENTER LAST NAME OF CONTACT TO EDIT: ");
    fgets(LAST_NAME, MAX_NAME_LENGTH, stdin);
    LAST_NAME[strcspn(LAST_NAME, "n")] = 0; 
}

void DELETE_CONTACT() {
    char LAST_NAME[MAX_NAME_LENGTH];
    printf("ENTER LAST NAME OF CONTACT TO DELETE: ");
    fgets(LAST_NAME, MAX_NAME_LENGTH, stdin);
    LAST_NAME[strcspn(LAST_NAME, "n")] = 0;
}

void DISPLAY_CONTACTS() {
    if (CONTACT_COUNT == 0) {
        printf("PHONEBOOK IS EMPTY.n");
        return;
    } 
    for (int i = 0; i < CONTACT_COUNT; i++) {
        printf("CONTACT %d:n", i + 1);
        printf("FIRST NAME: %sn", CONTACTS[i].FIRST_NAME);
        printf("SURNAME NAME: %sn", CONTACTS[i].SURNAME_NAME);
        printf("LAST NAME: %sn", CONTACTS[i].LAST_NAME);
        printf("WORKPLACE: %sn", CONTACTS[i].WORKPLACE);
        printf("POSITION: %sn", CONTACTS[i].POSITION);
        printf("PHONE: %sn", CONTACTS[i].PHONE);
        printf("EMAIL: %sn", CONTACTS[i].EMAIL);
        printf("SOCIAL MEDIA: %sn", CONTACTS[i].SOCIAL_MEDIA);
        printf("n");
    }
}

int main() {
    int CHOICE;
    
    while (1) {
        printf("1. ADD CONTACT\n");
        printf("2. EDIT CONTACT\n");
        printf("3. DELETE CONTACT\n");
        printf("4. DISPLAY CONTACTS\n");
        printf("5. EXIT\n");
        scanf("%d", &CHOICE);
        getchar(); // Читаем символ новой строки после scanf
        switch (CHOICE) {
            case 1:
                ADD_CONTACT();
                break;
            case 2:
                EDIT_CONTACT();
                break;
            case 3:
                DELETE_CONTACT();
                break;
            case 4:
                DISPLAY_CONTACTS();
                break;
            case 5:
                exit(0);
            default:
                printf("INVALID CHOICE. PLEASE TRY AGAIN.n");
        }
    }
    
    return 0;
}
