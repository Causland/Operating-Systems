#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char* firstName;
    char* middleName;
    char* lastName;
    char* fullName;

    printf("What is your first name?\n");
    firstName = malloc(100*sizeof(char));
    scanf("%s", firstName);

    printf("What is your middle name?\n");
    middleName = malloc(100*sizeof(char));
    scanf("%s", middleName);

    printf("What is your last name?\n");
    lastName = malloc(100*sizeof(char));
    scanf("%s", lastName);

    fullName = malloc(strlen(firstName) + strlen(middleName) + strlen(lastName) + 3);
    strcat(fullName, firstName);
    strcat(fullName, " ");
    strcat(fullName, middleName);
    strcat(fullName, " ");
    strcat(fullName, lastName);

    printf("Your full name is %s\n", fullName);

    char* id = malloc(5*sizeof(char));
    strcpy(id, "1234");

    char* fullNameId = realloc(fullName, strlen(fullName)+ strlen(id) + 1);
    strcat(fullNameId, fullName);
    strcat(fullNameId, " ");
    strcat(fullNameId, id);

    printf("Your full name with id is %s\n", fullNameId);

}