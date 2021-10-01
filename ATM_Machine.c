/*So this C Programme Project Is About The Concept of Working Of The ATM Machine
Programme Written By -Anand Pratap Tiwari
The Entire Code Is Divided In To Sets Of Functions

                 Sample Output

******************Hello User!*******************
**********Welcome to Anands ATM Banking***********

****Please choose The options Given below****
< 1 >  Check Balance
< 2 >  Deposit
< 3 >  Withdraw
< 4 >  Exit

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Your Selection:	1
You Choose to See your Balance
****Your Total Available Balance is:   20000.00 Rupees

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Would you like to do another transaction:
< 1 > Yes
< 2 > No
1
******************Hello User!*******************
**********Welcome to Anands ATM Banking***********

****Please choose one of the options below****
< 1 >  Check Balance
< 2 >  Deposit
< 3 >  Withdraw
< 4 >  Exit

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Your Selection:	2
You choose to Deposit a money
****Your Current Balance is: 20000.00 Rupees

****Enter The amount You Want to Deposit
5000
****Your New  Updated Balance is:   25000.00 Rupees

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Would you like to do another transaction:
< 1 > Yes
< 2 > No
1
******************Hello User!*******************
**********Welcome to Anands ATM Banking***********

****Please choose one of the options below****
< 1 >  Check Balance
< 2 >  Deposit
< 3 >  Withdraw
< 4 >  Exit

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Your Selection:	3
You choose to Withdraw a money
****Your Balance is: 25000.00 Rupees

Enter The amount You Want to withdraw:
600000
+++Hey User You don't have enough money!+++
If You Think Its a Error Please contact to Your Bank Customer Services
****Your Balance is:   25000.00 Rupees

Enter your amount to withdraw:
14000
****Your withdrawing money is:  15000.00 Rupees
****Your New Balance is:   10000.00 Rupees

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
Would you like to do another transaction:
< 1 > Yes
< 2 > No
1
******************Hello User!*******************
**********Welcome to Anands ATM Banking***********

****Please choose one of the options below****
< 1 >  Check Balance
< 2 >  Deposit
< 3 >  Withdraw
< 4 >  Exit

=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
Your Selection:	4
--------------Please Take your receipt!!!------------------
-----Thank you for using ATM Banking Machine!!!-----
-----Prrgrammed By Anand Pratap Tiwari!!!-----
Program ended with exit code: 0

*/




#include<windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

//Declarations Of The Functions
void login();
void mainMenu();
void checkBalance(float balance);
float moneyDeposit(float balance);
float moneyWithdraw(float balance);
void menuExit();
void errorMessage();


//Main Code
int main() {
    //Local Declarations
    int option;
    float balance = 20000.00;
    int choose;

    bool again = true;

    // insert code here...

    while (again) {
    mainMenu();

   
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("Enter Your Selection:\t");
    scanf("%d", &option);


        switch (option) {
            case 1:
            	system("CLS");
                checkBalance(balance);
                break;
            case 2:
            	system("CLS");
                balance = moneyDeposit(balance);
                break;
            case 3:
            	system("CLS");
                balance = moneyWithdraw(balance);
                break;

            case 4:
            	system("CLS");
                menuExit();
                return 0;

            default:
                errorMessage();
                break;
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("Would you like to do another transaction:\n");
        printf("< 1 > Yes\n");
        printf("< 2 > No\n");
        scanf("%d", &choose);

        system("CLS");



        if (choose == 2) {
            again = false;
            menuExit();

        }

}


    return 0;
}//main code



//Functions

void mainMenu() {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_RED);
    printf("******************Hello User!*******************\n");
    printf("**********Welcome to Anands ATM Banking***********\n\n");
    printf("****Please choose one of the options Given below****\n\n");
    printf("< 1 >  Check Balance\n");
    printf("< 2 >  Deposit\n");
    printf("< 3 >  Withdraw\n");
    printf("< 4 >  Exit\n\n");

}//Main Menu

void checkBalance(float balance) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN);
    printf("You Choose to See your Balance\n");
    printf("\n\n****Your Available Current Balance is Rupees:-   %.2f\n\n", balance);
    

}//Check Balance

float moneyDeposit(float balance) {
    float deposit;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE);
    printf("You choose to Deposit a money\n");
    printf("****Your Balance is Rupees:- %.2f\n\n", balance);
    printf("****Enter The amount You Want to Deposit\n");
    scanf("%f", &deposit);


    balance += deposit;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN);
    printf("\n****Your New Updated Balance is Rupees :-   %.2f\n\n", balance);
    return balance;

}//money deposit

float moneyWithdraw(float balance) {
    float withdraw;
    bool back = true;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN);
    printf("You choose to Withdraw a money\n");
    printf("****Your Current Available Balance is Rupees:- %.2f\n\n", balance);
   

    while (back) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);   
    printf("Enter your amount to withdraw:\n");
    scanf("%f", &withdraw);


    if (withdraw < balance) {
        back = false;
        balance -= withdraw;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
        printf("\n****Your withdrawing money is Rupees:-  %.2f\n", withdraw);
        printf("****Your New Balance is Rupees:-   %.2f\n\n", balance);


    }

        else  {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED);
        printf("+++Hey User You don't have enough money to Withdraw!+++\n");
        printf("If You Think Its Our Fault Please contact to your Bank Customer Services\n");
        printf("****Your New Updated Balance is Rupees :-   %.2f\n\n", balance);
       

    }
    }
    return balance;


}//money withdraw

void menuExit() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    printf("--------------Take your receipt!!!------------------\n");
    printf("-----Thank you for using Anands ATM Banking Machine!!!-----\n");
    printf("-----Programmed By -Anand Pratap Tiwari-----\n");


}//exit menu

void errorMessage() {;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    printf("+++!!!You selected invalid number!!!+++\n");
}//error message


