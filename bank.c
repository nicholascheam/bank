#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
char option[30];

void text_menu(){
    printf("-------------------------------------------\n");
    printf("Please choose an option (1-6):\n");
    printf("1. Create New Bank Account\n");
    printf("2. Delete Bank Account\n");
    printf("3. Deposit\n");
    printf("4. Withdrawal\n");
    printf("5. Remittance\n");
    printf("6. Exit\n");
    printf("-------------------------------------------\n");
    printf("\nSelect Option:");
    scanf("%s", &option);
}

void create_account(){
    int *account_type;
    printf("Enter Your Name:");
    char name[50];
    scanf("%s", name);
    printf("Enter Your Identification Number(ID):");
    char id[20];
    scanf("%s", id);
    printf("Enter the Type of Account (1: Savings/2: Checking):");
    scanf("%d", &account_type);
    FILE *fp = fopen("database/accounts.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "%s %s %d\n", name, id, account_type);
    fclose(fp);
    printf("Account Created Successfully!\n");
}

void delete_account(){
    
}

void deposit(){

}

void withdrawal(){

}

void remittance(){

}

void options(){
    if (strcmp(option, "1") == 0 || strcmp(option, "create") == 0 || strcmp(option, "new") == 0 || strcmp(option, "make") == 0) {
        create_account();
    } else if (strcmp(option, "2") == 0 || strcmp(option, "delete") == 0 || strcmp(option, "remove") == 0) {
        delete_account();
    } else if (strcmp(option, "3") == 0 || strcmp(option, "deposit") == 0) {
        deposit();
    } else if (strcmp(option, "4") == 0 || strcmp(option, "withdraw") == 0 || strcmp(option, "withdrawal") == 0) {
        withdrawal();
    } else if (strcmp(option, "5") == 0 || strcmp(option, "remit") == 0 || strcmp(option, "remittance") == 0) {
        remittance();
    } else if (strcmp(option, "6") == 0 || strcmp(option, "exit") == 0 || strcmp(option, "quit") == 0) {
    const char *message = "Program will exit soon";
    for (int i = 0; i < 4; i++) {
        printf("\r%s", message);   // \r returns cursor to start of line
        for (int j = 0; j < i % 4; j++)
            printf(".");
        fflush(stdout);
        Sleep(600);
    }
    exit(0);
    } else {
        printf("Invalid Option. Please try again.\n");
    }
}
int main(){
    while (1){
        text_menu();
        options();
    }
    return 0;
}