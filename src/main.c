#include <stdio.h>
#include <string.h>

#define KEY 3
#define MAX 100

// function to encrypt password
void encrypt(char password[], char encrypted[]) {
    for (int i = 0; password[i] != '\0'; i++) {
        encrypted[i] = password[i] + KEY;
    }
    encrypted[strlen(password)] = '\0';
}

// function to login
int login(char stored[]) {
    char input[MAX];
    char encrypted_input[MAX];

    printf("Enter password: ");
    scanf("%s", input);

    encrypt(input, encrypted_input);

    if (strcmp(encrypted_input, stored) == 0)
        return 1;
    else
        return 0;
}

int main() {
    char password[MAX];
    char encrypted[MAX];

    printf("=== SIGN UP ===\n");
    printf("Create password: ");
    scanf("%s", password);

    encrypt(password, encrypted);

    printf("Encrypted password stored: %s\n", encrypted);

    printf("\n=== LOGIN ===\n");

    if (login(encrypted))
        printf("Access Granted\n");
    else
        printf("Access Denied\n");

    return 0;
}
