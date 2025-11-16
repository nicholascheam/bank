#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <ctype.h>

char option[30];

void text_menu(){
    printf("\n-------------------------------------------\n");
    printf("Please choose an option (1-6):\n");
    printf("1. Create New Bank Account\n");
    printf("2. Delete Bank Account\n");
    printf("3. Deposit\n");
    printf("4. Withdrawal\n");
    printf("5. Remittance\n");
    printf("6. Exit\n");
    printf("-------------------------------------------\n");
    printf("\nSelect Option: ");
    scanf("%29s", &option);
}

void create_account(){
    int account_type;
    char account_type_name[20];
    char account_file_name[50];
    char name[50];
    char id[20];
    int pin;

    // user input
    printf("Enter Your Name: ");
    scanf("%49s", name);
    printf("Enter Your Identification Number(ID): ");
    scanf("%19s", id);
    printf("Enter the Type of Account (1: Savings/2: Current): ");
    scanf("%d", &account_type);
    if (account_type != 1 && account_type != 2){
        printf("Invalid Account Type Selected. Please try again.\n");
        return;
    }
    printf("Enter a 4 Digit PIN for your Account: ");
    scanf("%d", &pin);
    if (pin < 1000 || pin > 9999){
        printf("Invalid PIN entered. Please try again.\n");
        return;
    }
    // lowercase name
    for (int i = 0; name[i]; i++){
        name[i] = tolower(name[i]);
    }
    // account logging

    if (account_type == 1){
        strcpy(account_type_name, "Savings");
    }
    else if (account_type == 2){
        strcpy(account_type_name, "Current");
    }

    sprintf(account_file_name, "database/%s_%s.txt", id, account_type_name);

    // check if account already exists
    FILE *file_check = fopen(account_file_name, "r");
    if (file_check != NULL) {
        printf("Account already exists!\n");
        fclose(file_check);
        return;
    }

    FILE *account_fp = fopen(account_file_name, "w+");
    if (account_fp == NULL) {
        printf("Error creating account file!\n");
        return;
    }
    fprintf(account_fp, "Name: %s\nID: %s\nAccount Type: %s\nPIN: %d\nBalance: 0\n", name, id, account_type_name, pin);
    fclose(account_fp);

    // general logging, pin is giving garbage value ****
    FILE *fp = fopen("database/accounts.txt", "a");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    fprintf(fp, "%s %s %d %d\n", name, id, account_type, pin);
    fclose(fp);

    FILE *log_fp = fopen("database/transactions.log", "a");
    if (log_fp == NULL) {
        printf("Error opening log file!\n");
        return;
    }
    fprintf(log_fp, "Account created for %s with ID %s and account type %d\n", name, id, account_type);
    fclose(log_fp);

    printf("Account Created Successfully!\n");
}

void delete_account(){
    char name[50], name_check[50];
    char account_type_name[20];
    char account_file_name[50];
    char id[20], id_check[20];
    char account_type[20], account_type_check[20];
    int pin, pin_check;
    char line[100];
    int extracted_pin = 0;

    // user input
    // printf("Enter Your Name: ");
    // scanf("%s", &name);
    printf("Enter Your Identification Number(ID) to Delete Account: ");
    scanf("%19s", &id);
    printf("Enter the Type of Account to Delete (1: Savings/2: Current): ");
    scanf("%19s", &account_type);

    if (strcmp(account_type, "1") == 0 || strcmp(account_type, "Savings") == 0 || strcmp(account_type, "savings") == 0 || strcmp(account_type, "save") == 0){
        strcpy(account_type_name, "Savings");
    }
    else if (strcmp(account_type, "2") == 0 || strcmp(account_type, "Current") == 0 || strcmp(account_type, "current") == 0 || strcmp(account_type, "curr") == 0) {
        strcpy(account_type_name, "Current");
    }

    // check if account exists
    sprintf(account_file_name, "database/%s_%s.txt", id, account_type_name);
    FILE *file_check = fopen(account_file_name, "r");
    if (file_check == NULL) {
        printf("Account doesn't exist!\n");
        fclose(file_check);
        return;
    }
    else {
        printf("Account found!\n");
        fclose(file_check);
    }

    printf("Enter your 4 Digit PIN: ");
    scanf("%d", &pin);

    // retreive name for logging
    FILE *name_fp = fopen(account_file_name, "r");
    while(fgets(line, sizeof(line), name_fp)) {
        if (sscanf(line, "Name: %s", name) == 1) {
            break;
        }
    }
    fclose(name_fp);

    // read PIN from account file
    FILE *pin_fp = fopen(account_file_name, "r");
    if (pin_fp == NULL) {
        printf("Account doesn't exist!\n");
        return;
    }

    while(fgets(line, sizeof(line), pin_fp)) {
        if (sscanf(line, "PIN: %d", &extracted_pin) == 1) {
            break;
        }
    }
    fclose(pin_fp);

    if (extracted_pin == pin){
        remove(account_file_name);
        printf("Account deleted successfully!\n");
    }
    else {
        printf("Incorrect PIN. Account deletion failed.\n");
    }

    // general logging
    FILE *fp = fopen("database/accounts.txt", "r");
    FILE *temp_fp = fopen("database/temp_accounts.txt", "w");
    if (fp == NULL || temp_fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while(fscanf(fp, "%49s %19s %19s %d", name_check, id_check, account_type_check, &pin_check) == 4) {
        if(strcmp(id_check, id) == 0 && strcmp(account_type_check, account_type) == 0) {
            continue; 
    }
        fprintf(temp_fp, "%s %s %s %d\n", name_check, id_check, account_type_check, pin_check);
}
    fclose(fp);
    fclose(temp_fp);
    remove("database/accounts.txt");
    rename("database/temp_accounts.txt", "database/accounts.txt");

    FILE *log_fp = fopen("database/transactions.log", "a");
    if (log_fp == NULL) {
        printf("Error opening log file!\n");
        return;
    }
    fprintf(log_fp, "Account deleted for %s with ID %s and account type %s\n", name, id, account_type);
    fclose(log_fp);

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
    for (int i = 0; i < 3; i++) {
        printf("\r%s", message);
        for (int j = 0; j < i % 4; j++)
            printf(".");
        fflush(stdout);
        sleep(1);
    }
    exit(0);
    } else {
        printf("Invalid Option. Please try again.\n");
    }
}
int main(){
    struct stat st = {0};
    if (stat("database", &st) == -1) {
        system("mkdir database");
    }
    while (1){
        text_menu();
        options();
    }
    return 0;
}