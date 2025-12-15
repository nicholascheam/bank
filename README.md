BANKING SYSTEM USER MANUAL:

The system supports the following functions:
1) Creating a new bank account
2) Deleting an existing bank account
3) Deposit money
4) Withdraw money
5) Remit money between accounts
All accounts data will be stored within text files in "database" folder.

System Requirements:

Operating System: Windows

Compiler: Any standard C compiler

Console / Terminal Access



Upon opening, you will be shown this text menu and a folder named "database" is created automatically within the directory of the .exe file,
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
-------------------------------------------
Please choose an option (1-6):
1. Create New Bank Account
2. Delete Bank Account
3. Deposit
4. Withdrawal
5. Remittance
6. Exit
-------------------------------------------

Select Option:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Function creating account could be accessed with words: 1, create, new, make, open, add

Function deleting account could be accessed with words: 2, delete, del, remove, close, rm

Function depositing in account could be accessed with words: 3, deposit, addfund, addfunds, addmoney, add money, topup, top up, fund, funds

Function withdrawing from account could be accessed with words: 4, withdraw, withdrawal, takeout, take out, removefund, removefunds, remove money, removemoney

Function remitting from accounts to accounts could be accessed with words: 5, remit, remittance, transfer, sendmoney, send money, pay, payment, pay money, paymoney

Function exiting the program could be accessed with words: 6, exit, quit, closeapp, close app, bye, goodbye

**FOR ALL FUNCTIONS, PRESSING ENTER ON A BLANK INPUT RETURNS TO THE OPTION MENU

*ACCOUNT TYPES [1, Savings, savings, save] [2, Current, current, curr] ARE VALID

*ALL ACTIONS WILL BE LOGGED IN "database/transactions.log"

CREATING BANK ACCOUNT:

Step 1: Select option 1 from the menu

Step 2: Enter your full name

Step 3: Enter your Identification Number (ID)

Step 4: Select account type (Savings or Current)

Step 5: Enter a 4-Digit PIN

Output
1) A unique account number (7-9 digits) is generated automatically.
2) A new account file is created in the "database" folder.
3) Account details are logged in "accounts.txt"

Example account file with filename "12345678_Savings.txt":

~~~~~~~~~~~~~~~~~~~~~~~~~~~
Name: john smith
ID: 1234-56-7890
Account Type: Savings
Account Number: 12345678
PIN: 1234
Balance: RM 3032.50
~~~~~~~~~~~~~~~~~~~~~~~~~~~

DELETING BANK ACCOUNT:

**ANY DELETED ACCOUNTS ARE NOT RECOVERABLE

Step 1: Select option 2 from the menu

Step 2: Enter the account number

Step 3: Enter the account type (Savings or Current)

Step 4: Confirm your FULL name

Step 5: Enter the last 4 digits of your ID

Step 6: Enter your PIN

Information must match with the database for deletion to occur.

DEPOSITING MONEY:

Step 1: Select option 3 from the menu

Step 2: Enter account number

Step 3: Enter account type (Savings or Current)

Step 4: Enter your PIN

Step 5: Enter your deposit amount (MUST BE GREATER THAN 0 AND LESS THAN 50000 PER TRANSACTION)

Result:
Balance for specific accounts in the "database" folder will be updated immediately

WITHDRAWING MONEY:

Step 1: Select option 4 from the menu

Step 2: Enter account number

Step 3: Enter account type (Savings or Current)

Step 4: Enter your PIN

Step 5: Enter your withdrawal amount (CANNOT EXCEED CURRENT BALANCE)

Result:
Balance for specific accounts in the "database" folder will be updated immediately

REMITTANCE:

Step 1: Select option 5 from the menu

Step 2: Enter sender account details

Step 3: Enter receiver account details

Step 4: Enter sender's PIN

Step 5: Enter transfer amount

Fees (deducted from sender's account):

Savings TO Current is 2% fee

Current TO Savings is 3% fee

Savings TO Savings, Current TO Current is 0% fee

*Note: Sender must have sufficient funds including fees to transfer.

EXITING THE PROGRAM:

Select option 6 from the menu

Exiting the program will have a 3 second timer before the program successfully quits.

LOGGING:

All transactions are logged in "database/transactions.log"

Example entries:
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Deposited 500.00 to account 12345678 of type Savings
Withdrew 200.00 to account 12345678 of type Savings
Remitted 100.00 from account 12345678 of type Savings to account 87654321 of type Current, fee 2.00
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Error handling:

The system checks for
1) Invalid Input
2) Incorrect PIN
3) Insufficient Balance
4) Non-existent accounts
Error messages are shown and the operation will always be safely cancelled



