#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 20
void inputContacts(char **names, char **phones, int count) 
{
    for (int i = 0; i < count; i++)
    {
        printf("Enter name %d: ", i + 1);
        fgets(names[i], MAX_NAME_LENGTH, stdin);
        names[i][strcspn(names[i], "\n")] = 0;
        printf("Enter phone number %d: ", i + 1);
        fgets(phones[i], MAX_PHONE_LENGTH, stdin);
        phones[i][strcspn(phones[i], "\n")] = 0;
    }
}
void displayContacts(char **names, char **phones, int count)
{
    printf("\nStored Contacts:\n");
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s, Phone: %s\n", names[i], phones[i]);
    }
}
int main()
{
    int count;
    printf("Enter the number of contacts: ");
    scanf("%d", &count);
    getchar();
    char **names = (char **)malloc(count * sizeof(char *));
    char **phones = (char **)malloc(count * sizeof(char *));
    for (int i = 0; i < count; i++) 
    {
        names[i] = (char *)malloc(MAX_NAME_LENGTH * sizeof(char));
        phones[i] = (char *)malloc(MAX_PHONE_LENGTH * sizeof(char));
    }
    inputContacts(names, phones, count);
    displayContacts(names, phones, count);
    for (int i = 0; i < count; i++) 
    {
        free(names[i]);
        free(phones[i]);
    }
    free(names);
    free(phones);
    return 0;
}