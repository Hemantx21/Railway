#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BOLD "\033[1m"

typedef struct
{
    int n;
    char Name[50];
    int age;
    char g;
    char emailid[100];
} pd;

typedef struct newtrain
{
    int tnum;
    char tname[50];
    char tsrc[50];
    char tdes[50];
} newtrain;

newtrain nt[10];
pd passdetails[10];

int loginadmin();
void profilesettings();
void displayadmins();
void addadmin();
void del(char *arr);
int ran();
void railwaydatabase();
void addtrain();
void deltrain();

void reservation();
void classify_age(int);
void printticket(int, char Name[50], int, char g, char em[50]);
void cancel();

void train_details();
void train_details2();
float fare();
int random_number(int lower, int upper, int count);
void dtrain_details();

void saveAdmins();
void loadAdmins();
void saveTrains();
void loadTrains();
void savePassengers();
void loadPassengers();
void saveTicket(pd ticket);
void viewTickets();

char username1[20] = "hemant", password1[15] = "pass1";
char username2[20] = "rupesh", password2[15] = "pass2";
char username3[20] = "atul", password3[15] = "pass3";
char username4[20] = {-1}, password4[15];
char username5[20] = {-1}, password5[15];
char username6[20] = {-1}, password6[15];

char newtrain1[10][100];
char newtrain2[10][100];

char name1[20], pass1[20];

int i, temp = 0;
char ch, choice1, choice2[10], choice3[10] = "y", choice5[10], choice4, choice7[10];
int choice6;

int trainnumb;
static int n;
float f;

int main()
{
    loadAdmins();
    loadTrains();
    loadPassengers();

    printf("\n\n\n\n");
    printf("\n|----------------------------------------------------------------------------|\n");
    printf("|                                                                            |\n|");
    printf(RED);

    printf(BOLD "                   Welcome to Railway Reservation System                   ");
    printf(RESET " |\n");

    printf("|                                                                            |\n");
    printf("|                                                                            |\n");
    printf("|  * . · * . · * . · * . · * . · *                                          |\n");
    printf("|  · * . · * . · * . · * . · *                                              |\n");
    printf("|             ( ) ( )                                                        |\n");
    printf("|            ( )( )                                                          |\n");
    printf("|           ( ~ ~ )                                                          |\n");
    printf("|        ____|||_______________________________|||___________                |\n");
    printf("|       | __ | [=] [=] [=] | [=] [=] [=] [=] |                             |\n");
    printf("|       |/##\\|    RAILWAY EXPRESS    |  PASSENGER CAR 01   |                |\n");
    printf("|  _____|\\__/| [=] [=] [=] |______________| [=] [=] [=] [=] |              |\n");
    printf("| /oo___________________________________________oo__________oo\\              |\n");
    printf("|  ( O )   ( O )                    ( O )              ( O )  |             |\n");
    printf("| \\_\\_/     \\_/____________________________\\_/______________\\_/_/          |\n");
    printf("|====+====+====+====+====+====+====+====+====+====+====+====+====+          |\n");
    printf("|    |    |    |    |    |    |    |    |    |    |    |    |    |           |\n");
    printf("|====+====+====+====+====+====+====+====+====+====+====+====+====+          |\n"); printf("|                                                                            |\n");
    printf("|                                                                            |\n");
    printf("|----------------------------------------------------------------------------|\n");
    printf("|                                                                            |\n");
    printf("|\tLog in as:                                                           |\n");
    printf("|                                                                            |\n");

    printf("|           1. ADMIN                                                         | \n");
    printf("|                                                                            |\n");
    printf("|           2. USER                                                          | \n");
    printf("|                                                                            |\n");
    printf("|           0. EXIT                                                          | \n");
    printf("|                                                                            |\n");

    printf("|----------------------------------------------------------------------------|\n");
    printf("|                                                                            |\n");
    printf("|----------------------------------------------------------------------------|\n");
    printf("\n\tChoice:\t\t");
    scanf(" %d", &ch);

    switch (ch)
    {
    case 1:
        system("cls");

        printf("\n----------------------------------------------------------------------------\n");
        printf("                     Welcome ADMIN");
        printf("\n----------------------------------------------------------------------------\n");
        printf("                                                                           \n");

        if (loginadmin() == 0)
        {
            printf(RED);
            printf(BOLD);
            printf("\n\n\n\t!! INVALID CREDENTIALS ...... Enter Correct Username And Password !!\n\n");
            printf(RESET);
        }

        else
        {
            printf("\n\nlogin successful");

            do
            {
                system("CLS");
                printf("\n---------------------------------------------\n");
                printf("                   Menu        (admin)              ");
                printf("\n---------------------------------------------\n");
                printf("\n\t1. Calculate Fare \n\t");
                printf("2. Check availability\n\t3. Book ticket/s and Display of booked ticket/s ");
                printf("\n\t4. Cancel ticket \n\t5. Profile Settings\n\t6. Railway database\n\t7. View Booked Tickets\n\t0. EXIT \n\n\t");
                printf("Choice:\t");
                scanf("%d", &choice1);

                switch (choice1)
                {
                case 0:
                    saveAdmins();
                    saveTrains();
                    savePassengers();
                    exit(0);
                    break;
                case 3:
                    system("CLS");
                    printf("\n----------------------------------------------------------------------------\n");
                    printf("                     Ticket Booking");
                    printf("\n----------------------------------------------------------------------------\n");
                    reservation();

                    break;

                case 1:

                    printf("\n----------------------------------------------------------------------------\n");
                    printf("                              FARE DETAILS");
                    printf("\n----------------------------------------------------------------------------\n");
                    dtrain_details();
                    int temptn, tp;
                    printf("\n\n\nenter the train number : ");
                    scanf("%d", &temptn);
                    printf("\nenter number of passengers:");
                    scanf("%d", &tp);

                    f = fare(temptn, tp);
                    printf(GREEN);
                    printf("\n\nTotal amount that need to be paid is : %.2f Rs ", f);

                    printf(RESET);
                    break;

                case 6:
                    system("CLS");
                    railwaydatabase();
                    break;
                case 2:
                    system("CLS");
                    dtrain_details();
                    int r;
                    printf("\n\nenter the train number\n\n ");
                    scanf("%d", &r);

                    int n2 = ran();
                    if (n2 > 0 && n2 < 25)
                    {
                        printf(RED);
                        printf("\nTHERE ARE NO SEATS AVAILABLE\n");
                        printf(RESET);
                    }
                    else
                    {
                        printf(GREEN);
                        printf("AVAILABLE SEATS : %d", n2);
                        printf(RESET);
                    }
                    break;

                case 4:
                    system("CLS");
                    cancel();
                    break;
                case 5:
                    system("CLS");
                    profilesettings();
                    break;
                case 7:
                    system("CLS");
                    viewTickets();
                    break;
                }
                printf("\n----------------------------------------------------------------------------\n");
                printf("\n\tWant to Continue[Main Menu] (y/n):\t");
                scanf("%s", choice2);
                if (strcmp(choice2, "n") == 0)
                {
                    saveAdmins();
                    saveTrains();
                    savePassengers();
                    exit(0);
                }
                strlwr(choice2);

            } while ((strcmp(choice3, choice2)) == 0);
        }
        break;

    case 2:
        do
        {
            system("CLS");

            printf("\n----------------------------------------------------------------------------\n");
            printf("                     Welcome user");
            printf("\n----------------------------------------------------------------------------\n");
            printf("                                                                           \n");
            printf("\n---------------------------------------------\n");
            printf("                   Menu                    ");
            printf("\n---------------------------------------------\n");
            printf("\n\t1. Book ticket/s and Display of booked ticket/s \n\t");
            printf("2. Fare details\n\t");
            printf("3. Check availability\n\t4. Cancel ticket\n\t5. View Booked Tickets\n\t0. EXIT \n\n\t");
            printf("Choice:\t");
            scanf("%d", &choice1);
            switch (choice1)
            {

            case 1:
                system("CLS");
                printf("\n----------------------------------------------------------------------------\n");
                printf("                     Ticket Booking and display booked ticket/s              ");
                printf("\n----------------------------------------------------------------------------\n");
                reservation();

                break;

            case 2:
                system("CLS");
                printf("\n----------------------------------------------------------------------------\n");
                printf("                              FARE DETAILS");
                printf("\n----------------------------------------------------------------------------\n");
                dtrain_details();
                int temptn, tp;
                printf("\n\n\nenter the train number : ");
                scanf("%d", &temptn);
                printf("\nenter number of passengers:");
                scanf("%d", &tp);

                f = fare(temptn, tp);
                printf(GREEN);

                printf("\n\nTotal amount that need to be paid is : %.2f Rs ", f);
                printf(RESET);
                break;

            case 3:
                system("CLS");
                dtrain_details();
                int r;
                printf("\n\nenter the train number\n\n ");
                scanf("%d", &r);

                int n2 = ran();
                if (n2 > 0 && n2 < 25)
                {
                    printf(RED);
                    printf("\nTHERE ARE NO SEATS AVAILABLE\n");
                    printf(RESET);
                }
                else
                {
                    printf(GREEN);
                    printf("AVAILABLE SEATS : %d", n2);
                    printf(RESET);
                }

                break;

            case 4:
                system("CLS");
                cancel();
                break;
            case 5:
                system("CLS");
                viewTickets();
                break;
            case 0:
                saveAdmins();
                saveTrains();
                savePassengers();
                system("CLS");
                exit(0);
                break;
            }
            printf("\n----------------------------------------------------------------------------\n");
            printf("\n\tWant to Continue[Main Menu] (y/n):\t");
            scanf("%s", choice2);

            strlwr(choice2);
        } while ((strcmp(choice3, choice2)) == 0);

        break;

    default:
        printf(RED);
        printf("\t\t\tINVALID CHOICE");
        printf(RESET);
    }
    return 0;
}

int loginadmin()
{
    printf("\t\tEnter the user name : ");
    scanf("%s", name1);

    printf("\n\t\tenter password : ");

    char c;
    i = 0;
    while (i <= 20)
    {
        pass1[i] = getch();
        if (pass1[i] == 13)
            break;
        else
            printf("*");
        i++;
    }
    pass1[i] = '\0';

    if (strcmp(username1, name1) == 0 && strcmp(password1, pass1) == 0 || strcmp(username2, name1) == 0 && strcmp(password2, pass1) == 0 || strcmp(username3, name1) == 0 && strcmp(password3, pass1) == 0 || strcmp(username4, name1) == 0 && strcmp(password4, pass1) == 0 || strcmp(username5, name1) == 0 && strcmp(password5, pass1) == 0 || strcmp(username6, name1) == 0 && strcmp(password6, pass1) == 0)
    {
        temp = 1;
    }

    return temp;
}

void profilesettings()
{
    do
    {
        system("CLS");
        printf("\n---------------------------------------------\n");
        printf("              PROFILE SETTINGS                   ");
        printf("\n---------------------------------------------\n");
        printf("\n\t1. Display Admins and Passwords \n\t");
        printf("2. Add Admins ");
        printf("\n\t3. Delete Admin\n\t0. EXIT \n\n\t");
        printf("Choice:\t");
        scanf("%d", &choice4);
        switch (choice4)
        {
        case 1:
            system("CLS");
            displayadmins();
            break;
        case 2:
            system("CLS");
            addadmin();
            displayadmins();
            break;

        case 3:
            system("CLS");
            int n;
            printf("Enter the admin number that you need to delete : ");
            scanf("%d", &n);

            if (n == 1)
                del(username1);
            if (n == 2)
                del(username2);
            if (n == 3)
                del(username3);
            if (n == 4)
                del(username4);
            if (n == 5)
                del(username5);
            if (n == 6)
                del(username6);

            displayadmins();
            break;
        case 0:
            system("CLS");
            exit(0);
            break;
        }
        printf("\n----------------------------------------------------------------------------\n");
        printf("\n\tWant to Continue[Profile Setting] (y/n):\t");
        scanf("%s", choice5);
        if (strcmp(choice5, "n") == 0)
        {
            exit(0);
        }
    } while ((strcmp(choice3, choice5)) == 0);
}

void displayadmins()
{
    int count = 0;
    printf(RED);
    printf("\nCURRENT ADMINS AND THEIR PASSWORDS ARE :\n");

    printf(RESET);
    if (username1[0] != -1)
    {
        printf("\nADMIN NAME: %s\n", username1);
        printf("PASSWORD :%s\n", password1);
        printf("---------------\n\n");
        count++;
    }
    if (username2[0] != -1)
    {
        printf("ADMIN NAME: %s\n", username2);
        printf("PASSWORD :%s\n", password2);
        printf("---------------\n\n");
        count++;
    }
    if (username3[0] != -1)
    {
        printf("ADMIN NAME: %s\n", username3);
        printf("PASSWORD: %s\n", password3);
        printf("---------------\n\n");
        count++;
    }
    if (username4[0] != -1)
    {
        printf("ADMIN NAME: %s\n", username4);
        printf("PASSWORD: %s\n", password4);
        printf("---------------\n\n");
        count++;
    }
    if (username5[0] != -1)
    {
        printf("ADMIN NAME:%s\n", username5);
        printf("PASSWORD :%s\n", password5);
        printf("---------------\n\n");
        count++;
    }
    if (username6[0] != -1)
    {
        printf(" ADMIN NAME:%s\n", username6);
        printf("PASSWORD :%s\n", password6);
        printf("---------------\n\n");
        count++;
    }
    printf(GREEN);
    printf("\n\t\tNumber of admins is %d\n", count);
    printf(RESET);
    printf("-----------------------------------------------------------\n\n");
}

void addadmin()
{
    int i = 0;

    printf("\n Enter New Admin Name:\t");
    scanf("%s", username4);
    printf("\n Enter New Admin Password:\t");
    while (i <= 9)
    {
        password4[i] = getch();
        if (password4[i] == 13)
            break;
        else
            printf("*");
        i++;
    }
}

void del(char *arr)
{
    arr[0] = -1;
    printf("-------------------------------------------\n\n");
    printf(RED);
    printf("successfully deleted\n");
    printf(RESET);
    printf("--------------------------------------------\n\n");
}

void reservation()
{
    int k;
    printf("Enter the number of passengers : ");
    scanf("%d", &n);

    train_details();
    printf(RED);
    printf("\n\n\nenter the train number :\n");
    printf(RESET);
    scanf("%d", &trainnumb);

    pd passdetails[10];
    pd passdetails1;

    for (k = 0; k < n; ++k)
    {
        passdetails[k].n = k + 1;
        printf("\n Passenger No. %d \n", passdetails[k].n);
        fflush(stdin);
        printf("Enter the name of the Passenger : ");
        gets(passdetails[k].Name);
        printf("Enter the age of the Passenger : ");
        scanf("%d", &passdetails[k].age);
        fflush(stdin);
        printf("Enter the gender ('F' for Female and 'M' for Male) : ");
        scanf("%c", &passdetails[k].g);
        fflush(stdin);
        printf("\n\n\n");
    }

    printf("Enter the valid Email ID : ");
    scanf("%s", passdetails1.emailid);

    system("cls");

    for (i = 0; i < n; i++)
    {
        strcpy(passdetails[i].emailid, passdetails1.emailid);
        printticket(passdetails[i].n, passdetails[i].Name, passdetails[i].age, passdetails[i].g, passdetails[i].emailid);
        saveTicket(passdetails[i]);
    }

    f = fare(trainnumb, n);

    printf("\n\nTotal amount that need to be paid is : %.2f Rs ", f);
}

void classify_age(int age)
{
    if (age <= 12)
    {
        printf("Child\n");
    }
    else
    {
        printf("Adult\n");
    }
}

void printticket(int n, char Name[50], int age, char g, char em[50])
{
    printf("\n\n Passenger No. %d \n", n);
    printf("-------------------\n");
    printf("\tTICKET\n");
    printf("-------------------\n\n");
    printf("\nName of the Passenger:\t%s", Name);
    printf("\nAge of the Passenger:\t%d\nChild/Adult:\t\t", age);
    classify_age(age);
    printf("Gender:\t\t\t%c", g);
    printf("\nEmail id : %s\n", em);
}

void cancel()
{
    char nameToCancel[50];
    int found = 0;
    
    printf("Enter the name of the passenger to cancel the booked ticket: ");
    scanf("%s", nameToCancel);

    FILE *file = fopen("tickets.dat", "rb");
    FILE *tempFile = fopen("temp.dat", "wb");

    if (file == NULL || tempFile == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    pd ticket;

    while (fread(&ticket, sizeof(pd), 1, file))
    {
        if (strcmp(ticket.Name, nameToCancel) != 0)
        {
            fwrite(&ticket, sizeof(pd), 1, tempFile);
        }
        else
        {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove("tickets.dat");
    rename("temp.dat", "tickets.dat");

    if (found)
    {
        printf("\nThe booked ticket for %s has been canceled successfully.\n", nameToCancel);
    }
    else
    {
        printf("\nNo ticket found for the name %s.\n", nameToCancel);
    }
}

void train_details()
{
    system("cls");
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Tr.No\tName\t\t\tDestinations\t\t\tCharges\t\tTime\t\tNumber of seats\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("1.\tGorakhpur Express\tGorakhpur to Lucknow\t\tRs.350\t\t06:00\t\t%d\n", random_number(0, 100, 1));
    printf("2.\tGorakhpur Express\tLucknow to Gorakhpur\t\tRs.350\t\t14:00\t\t%d\n", random_number(0, 100, 2));
    printf("3.\tSapt Kranti Express\tGorakhpur to New Delhi\t\tRs.1200\t\t20:00\t\t%d\n", random_number(0, 100, 3));
    printf("4.\tSapt Kranti Express\tNew Delhi to Gorakhpur\t\tRs.1200\t\t07:45\t\t%d\n", random_number(0, 100, 4));
    printf("5.\tGorakhpur-Mumbai Exp\tGorakhpur to Mumbai\t\tRs.2200\t\t13:30\t\t%d\n", random_number(0, 50, 2));
    printf("6.\tGorakhpur-Mumbai Exp\tMumbai to Gorakhpur\t\tRs.2200\t\t09:15\t\t%d\n", random_number(25, 100, 7));
    printf("7.\tKashi Vishwanath Exp\tGorakhpur to Varanasi\t\tRs.280\t\t08:30\t\t%d\n", random_number(9, 68, 1));
    printf("8.\tKashi Vishwanath Exp\tVaranasi to Gorakhpur\t\tRs.280\t\t17:00\t\t%d\n", random_number(2, 58, 3));
    printf("9.\tNautanwa Express\tGorakhpur to Kolkata\t\tRs.1800\t\t22:15\t\t%d\n", random_number(19, 67, 5));
    printf("10.\tNautanwa Express\tKolkata to Gorakhpur\t\tRs.1800\t\t05:30\t\t%d\n", random_number(0, 100, 1));
    getchar();
}

void train_details2()
{
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Tr.No\tName\t\t\tDestinations\t\t\tCharges\t\tTime\t\tNumber of seats\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("1.\tGorakhpur Express\tGorakhpur to Lucknow\t\tRs.350\t\t06:00\t\t%d\n", random_number(0, 100, 1));
    printf("2.\tGorakhpur Express\tLucknow to Gorakhpur\t\tRs.350\t\t14:00\t\t%d\n", random_number(0, 100, 2));
    printf("3.\tSapt Kranti Express\tGorakhpur to New Delhi\t\tRs.1200\t\t20:00\t\t%d\n", random_number(0, 100, 3));
    printf("4.\tSapt Kranti Express\tNew Delhi to Gorakhpur\t\tRs.1200\t\t07:45\t\t%d\n", random_number(0, 100, 4));
    printf("5.\tGorakhpur-Mumbai Exp\tGorakhpur to Mumbai\t\tRs.2200\t\t13:30\t\t%d\n", random_number(0, 50, 2));
    printf("6.\tGorakhpur-Mumbai Exp\tMumbai to Gorakhpur\t\tRs.2200\t\t09:15\t\t%d\n", random_number(25, 100, 7));
    printf("7.\tKashi Vishwanath Exp\tGorakhpur to Varanasi\t\tRs.280\t\t08:30\t\t%d\n", random_number(9, 68, 1));
    printf("8.\tKashi Vishwanath Exp\tVaranasi to Gorakhpur\t\tRs.280\t\t17:00\t\t%d\n", random_number(2, 58, 3));
    printf("9.\tNautanwa Express\tGorakhpur to Kolkata\t\tRs.1800\t\t22:15\t\t%d\n", random_number(19, 67, 5));
    printf("10.\tNautanwa Express\tKolkata to Gorakhpur\t\tRs.1800\t\t05:30\t\t%d\n", random_number(0, 100, 1));
}

int random_number(int lower, int upper, int count)
{
    int i, num;
    srand(time(0));
    for (i = 0; i < count; i++)
    {
        num = (rand() % (upper - lower + 1)) + lower;
    }
    return num;
}

float fare(int train_number, int passengers)
{
    switch (train_number)
    {
    case 1:
        return (350.0 * passengers);   // Gorakhpur to Lucknow
    case 2:
        return (350.0 * passengers);   // Lucknow to Gorakhpur
    case 3:
        return (1200.0 * passengers);  // Gorakhpur to New Delhi
    case 4:
        return (1200.0 * passengers);  // New Delhi to Gorakhpur
    case 5:
        return (2200.0 * passengers);  // Gorakhpur to Mumbai
    case 6:
        return (2200.0 * passengers);  // Mumbai to Gorakhpur
    case 7:
        return (280.0 * passengers);   // Gorakhpur to Varanasi
    case 8:
        return (280.0 * passengers);   // Varanasi to Gorakhpur
    case 9:
        return (1800.0 * passengers);  // Gorakhpur to Kolkata
    case 10:
        return (1800.0 * passengers);  // Kolkata to Gorakhpur
    default:
        printf(RED);
        printf("\n\n\t\tInvalid train number!\n\n");
        printf(RESET);
        return 0;
    }
}

void dtrain_details()
{
    system("cls");
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("Tr.No\tName\t\t\tDestinations\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("1.\tGorakhpur Express\tGorakhpur to Lucknow\n");
    printf("2.\tGorakhpur Express\tLucknow to Gorakhpur\n");
    printf("3.\tSapt Kranti Express\tGorakhpur to New Delhi\n");
    printf("4.\tSapt Kranti Express\tNew Delhi to Gorakhpur\n");
    printf("5.\tGorakhpur-Mumbai Exp\tGorakhpur to Mumbai\n");
    printf("6.\tGorakhpur-Mumbai Exp\tMumbai to Gorakhpur\n");
    printf("7.\tKashi Vishwanath Exp\tGorakhpur to Varanasi\n");
    printf("8.\tKashi Vishwanath Exp\tVaranasi to Gorakhpur\n");
    printf("9.\tNautanwa Express\tGorakhpur to Kolkata\n");
    printf("10.\tNautanwa Express\tKolkata to Gorakhpur\n");
    getchar();
}

int ran()
{
    int number;
    srand(time(0));
    number = rand() % 100 + 1;
    return number;
}

void railwaydatabase()
{
    do
    {
        system("CLS");
        printf("\n--------------------------------------------------------\n");
        printf("                        MENU                      ");
        printf("\n--------------------------------------------------------\n\n");
        printf("\t1. Display the trains \n");
        printf("\t2. Add trains\n");
        printf("\t3. Delete the added trains\n");
        printf("\t0. EXIT\n");
        printf("\n--------------------------------------------------------\n");
        printf("Choice:\t");
        scanf("%d", &choice6);
        switch (choice6)
        {

        case 0:
            exit(0);
        case 1:
            system("CLS");
            train_details();

            printf("\n\t\tPress Any Key to Continue ....!!!!!!!\n");
            getch();
            break;
        case 2:
            system("CLS");
            addtrain();
            printf("\n\t\tPress Any Key to Continue ....!!!!!!!\n");
            getchar();
            break;

        case 3:
            system("CLS");
            deltrain();
            break;
        }
        printf("\n----------------------------------------------------------------------------\n");
        printf("\n\tWant to Continue[Main Menu] (y/n):\t");
        scanf("%s", choice7);

    } while ((strcmp(choice3, choice7)) == 0);
}

void addtrain()
{
    int n;
    char buffer[30];

    printf("How many train you want to add : ");
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("\n\n\nenter new train %d \n", i + 1);
        printf("--------------------------------\n");
        printf("enter new train number : ");
        scanf("%d", &nt[i].tnum);

        printf("\nenter new train name : ");
        scanf("%s", buffer);
        strcpy(nt[i].tname, buffer);

        printf("\nenter new train source : ");
        scanf("%s", buffer);
        strcpy(nt[i].tsrc, buffer);

        printf("\nenter new train destination   : ");
        scanf("%s", buffer);
        strcpy(nt[i].tdes, buffer);
    }
    printf(GREEN);
    printf("\n\ntrain successfully added\n\n");
    printf(RESET);
    train_details2();
    for (i = 0; i < n; i++)
    {
        printf("\n%d ", nt[i].tnum);
        printf("\t%s\t\t\t", nt[i].tname);
        printf("%s to ", nt[i].tsrc);
        printf("%s", nt[i].tdes);
    }
}

void deltrain()
{
    nt[0].tnum = -1;
    printf(GREEN);
    printf("\n\n\t\t\t NEWLY ADDED TRAIN DELETED SUCCESSFULLY \n");
    printf(RESET);
    train_details2();
}

void saveAdmins()
{
    FILE *file = fopen("admins.dat", "wb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fwrite(username1, sizeof(username1), 1, file);
    fwrite(password1, sizeof(password1), 1, file);
    fwrite(username2, sizeof(username2), 1, file);
    fwrite(password2, sizeof(password2), 1, file);
    fwrite(username3, sizeof(username3), 1, file);
    fwrite(password3, sizeof(password3), 1, file);
    fwrite(username4, sizeof(username4), 1, file);
    fwrite(password4, sizeof(password4), 1, file);
    fwrite(username5, sizeof(username5), 1, file);
    fwrite(password5, sizeof(password5), 1, file);
    fwrite(username6, sizeof(username6), 1, file);
    fwrite(password6, sizeof(password6), 1, file);
    fclose(file);
}

void loadAdmins()
{
    FILE *file = fopen("admins.dat", "rb");
    if (file == NULL)
    {
        printf("No admin data found.\n");
        return;
    }
    fread(username1, sizeof(username1), 1, file);
    fread(password1, sizeof(password1), 1, file);
    fread(username2, sizeof(username2), 1, file);
    fread(password2, sizeof(password2), 1, file);
    fread(username3, sizeof(username3), 1, file);
    fread(password3, sizeof(password3), 1, file);
    fread(username4, sizeof(username4), 1, file);
    fread(password4, sizeof(password4), 1, file);
    fread(username5, sizeof(username5), 1, file);
    fread(password5, sizeof(password5), 1, file);
    fread(username6, sizeof(username6), 1, file);
    fread(password6, sizeof(password6), 1, file);
    fclose(file);
}

void saveTrains()
{
    FILE *file = fopen("trains.dat", "wb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fwrite(nt, sizeof(nt), 1, file);
    fclose(file);
}

void loadTrains()
{
    FILE *file = fopen("trains.dat", "rb");
    if (file == NULL)
    {
        printf("No train data found.\n");
        return;
    }
    fread(nt, sizeof(nt), 1, file);
    fclose(file);
}

void savePassengers()
{
    FILE *file = fopen("passengers.dat", "wb");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fwrite(passdetails, sizeof(passdetails), 1, file);
    fclose(file);
}

void loadPassengers()
{
    FILE *file = fopen("passengers.dat", "rb");
    if (file == NULL)
    {
        printf("No passenger data found.\n");
        return;
    }
    fread(passdetails, sizeof(passdetails), 1, file);
    fclose(file);
}

void saveTicket(pd ticket)
{
    FILE *file = fopen("tickets.dat", "ab");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
    fwrite(&ticket, sizeof(pd), 1, file);
    fclose(file);
}

void viewTickets()
{
    FILE *file = fopen("tickets.dat", "rb");
    if (file == NULL)
    {
        printf("No tickets found.\n");
        return;
    }

    pd ticket;
    printf("\n----------------------------------------------------------------------------\n");
    printf("                     Booked Tickets");
    printf("\n----------------------------------------------------------------------------\n");

    while (fread(&ticket, sizeof(pd), 1, file))
    {
        printticket(ticket.n, ticket.Name, ticket.age, ticket.g, ticket.emailid);
    }

    fclose(file);
}
