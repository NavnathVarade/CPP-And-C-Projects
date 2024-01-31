#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <conio.h>
#include <direct.h>
#include <process.h>
#include <windows.h>


// Structure to store student information
struct Student {
    char ID[15];        // Student ID
    char fullName[30];  // Student's full name
    char class[10];     // Class of the student
    char branch[35];    // Branch of the class
    char address[50];   // Address of the student
    char email[30];     // Email of the student
    char rollNo[15];    // Roll No. of the student
    char phoneNumber[15]; // Phone number of the student
};
struct Student s;

// Function prototypes
void displayDate();
void displayTitle();
void displayMainPage();
int authenticate();
void displayMenu();
void addRecord();
void modifyRecord();
void deleteRecord();
void searchRecord();
void displayRecord(const struct Student *student);
void clearInputBuffer();
void delay(unsigned int milliseconds);

// Global file pointer for data storage
FILE *filePointer;

int main(){
    system("cls");
    displayMainPage();
    if (authenticate()) {
        displayMenu();
    }
    return 0;
}

// Function to display current date
void displayDate() {
    time_t currentTime = time(NULL);
    struct tm *localTime = localtime(&currentTime);
    printf("\n\n\n");
    printf("\t\t\t\t\t\t\t   Date: %02d/%02d/%04d\n", localTime->tm_mday, localTime->tm_mon + 1, localTime->tm_year + 1900);
}

// Function to display the title
void displayTitle() {
    printf("\n\n\n");
    printf("\t\t\t\t\t\t\t");
    printf("\n");
    printf("\t\t\t\t\t\t     ---------------------------\n");
    printf("\t\t\t\t\t\t      |   STUDENT MANAGEMENT   |\n");
    printf("\t\t\t\t\t\t     ---------------------------\n");
    printf("\n\n");
    printf("\t\t\t\t");
}

// Function to display the main page
void displayMainPage() {
    system("cls");
    displayDate();
    printf("\n");
    displayTitle();
    printf("\t\t     Prepared By    :   Navnath Varade\n");
    printf("\t\t\t\t\t\t     Mini Project   :   Student Management System\n\n");
    printf("\t\t\t\t\t\t     Press Enter to continue...\n\n");
    getchar();
    printf("\t\t\t\t\t\t     Loading");
    for (int i = 0; i < 25; i++) {
        delay(150);
        printf(".");
    }
}


// Function for user authentication
int authenticate() {
    char username[30];
    char password[30];
    int attempts = 0;
    do {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\tEnter your username: ");
        scanf("%s", username);
        printf("\t\t\t\t\t\tEnter your password: ");
        scanf("%s", password);
        if (strcmp(username, "admin") == 0 && strcmp(password, "pass") == 0) {
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\tYou have successfully logged in!\n\n");
            printf("\t\t\t\t\t\tPress Enter to continue...");
            fflush(stdin);
            getchar();
            return 1;
        } else {
            attempts++;
            printf("\n\n\n\n\n\n\n\t\t\t\t\t\tInvalid credentials! Attempts remaining: %d", 3 - attempts);
            fflush(stdin);
            getchar();
            if (attempts >= 3) {
                printf("\n\n\n\n\n\n\n\t\t\t\t\t\tYou have exceeded the maximum number of attempts.\n");
                printf("\t\t\t\t\t\tNo permission to enter the system. Please contact the administrator.\n");
                getchar();
                exit(0);
            }
        }
    } while (1);
}

// Function to display the main menu
void displayMenu() {
    int choice;
    do {
        system("cls");
        displayTitle();
        printf("\t\t\t  1. Enter new Record\n\n");
        printf("\t\t\t\t\t\t\t  2. Modify Record\n\n");
        printf("\t\t\t\t\t\t\t  3. Delete Record\n\n");
        printf("\t\t\t\t\t\t\t  4. Search and View Record\n\n");
        printf("\t\t\t\t\t\t\t  5. Exit\n\n");
        printf("\t\t\t\t\t\t\t  Choose an option: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                modifyRecord();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                searchRecord();
                break;
            case 5:
                printf("\n\n\t\t\t\t\t\t\t  Exiting...\n\n\n");
                exit(0);
            default:
                printf("\n\n\t\t\t\t\t\tInvalid input! Press Enter to choose again...\n");
                clearInputBuffer();
                getchar();
        }
    } while (1);
}


// Function to add a new record
void addRecord() {
    char moreRecords;
    do {
        system("cls");
        displayTitle();
        printf("\n\n");
        printf("\t\t\t\t\t\t\tEnter The Information Below: \n\n");
        printf("\t\t\t\t\t\t\tEnter ID        :  ");
        scanf("%s", s.ID);
        printf("\n\t\t\t\t\t\t\tFull Name       :  ");
        scanf(" %[^\n]s", s.fullName);
        printf("\n\t\t\t\t\t\t\tClass           :  ");
        scanf(" %[^\n]s", s.class);
        printf("\n\t\t\t\t\t\t\tBranch          :  ");
        scanf(" %[^\n]s", s.branch);
        printf("\n\t\t\t\t\t\t\tAddress         :  ");
        scanf(" %[^\n]s", s.address);
        printf("\n\t\t\t\t\t\t\tEmail Address   :  ");
        scanf(" %[^\n]s", s.email);
        printf("\n\t\t\t\t\t\t\tRoll No.        :  ");
        scanf("%s", s.rollNo);
        printf("\n\t\t\t\t\t\t\tPhone No.       :  ");
        scanf("%s", s.phoneNumber);
        
        filePointer = fopen("data.txt", "a");
        fwrite(&s, sizeof(s), 1, filePointer);
        fclose(filePointer);
        
        printf("\n\n\t\t\t\t\t\t\tRecord added successfully!!");
        printf("\n\n\t\t\t\t\t\t\tDo you want to add more records? (Y/N): ");
        scanf(" %c", &moreRecords);
    } while (moreRecords == 'Y' || moreRecords == 'y');
    
        displayMenu(); // Return to the main menu
}

// Function to modify an existing record
void modifyRecord() {
    char fullName[30];
    int found = 0;
    
    system("cls");
    displayTitle();
    printf("\n\n");
    printf("\t\t\t\t\t\t  Enter Full Name to Modify Record: ");
    scanf(" %[^\n]s", fullName);

    filePointer = fopen("data.txt", "r+");
    while (fread(&s, sizeof(s), 1, filePointer) == 1) {
        if (strcmp(fullName, s.fullName) == 0) {
            found = 1;
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n");
            printf("\t\t\t\t\t\t\t<<<=======Old Record=======>>>\n");
            displayRecord(&s);
            printf("\n\n\t\t\t\t\t\t\tPress Enter to modify the record...");
            clearInputBuffer();
            getchar();
            system("cls");
            printf("\n\n\n\n\n");
            printf("\t\t\t\t\t\t\t<<<=======New Record=======>>>\n\n");
            printf("\t\t\t\t\t\t\tEnter ID        :  ");
            scanf("%s", s.ID);
            printf("\n\t\t\t\t\t\t\tFull Name       :  ");
            scanf(" %[^\n]s", s.fullName);
            printf("\n\t\t\t\t\t\t\tClass           :  ");
            scanf(" %[^\n]s", s.class);
            printf("\n\t\t\t\t\t\t\tBranch          :  ");
            scanf(" %[^\n]s", s.branch);
            printf("\n\t\t\t\t\t\t\tAddress         :  ");
            scanf(" %[^\n]s", s.address);
            printf("\n\t\t\t\t\t\t\tEmail Address   :  ");
            scanf(" %[^\n]s", s.email);
            printf("\n\t\t\t\t\t\t\tRoll No.        :  ");
            scanf("%s", s.rollNo);
            printf("\n\t\t\t\t\t\t\tPhone No.       :  ");
            scanf("%s", s.phoneNumber);
            fseek(filePointer, -sizeof(s), SEEK_CUR);
            fwrite(&s, sizeof(s), 1, filePointer);
            printf("\n\n\t\t\t\t\t\t\tRecord modified successfully!!");
            break;
        }
    }
    fclose(filePointer);
    if (!found) {
        printf("\n\n\t\t\t\t\t\t\tRecord not found!");
    }
    printf("\n\n\t\t\t\t\t\t\tPress Enter to continue...");
    clearInputBuffer();
    getchar();
}

// Function to delete a record
void deleteRecord() {
    FILE *fpt, *temp;
    char fullName[30];
    int found = 0;

    system("cls");
    displayTitle();
    printf("\n\n");
    printf("\t\t\t\t\t\t  Enter Full Name to Delete Record: ");
    scanf(" %[^\n]s", fullName);

    fpt = fopen("data.txt", "r");
    temp = fopen("temp.txt", "w");
    while (fread(&s, sizeof(s), 1, fpt) == 1) {
        if (strcmp(fullName, s.fullName) != 0) {
            fwrite(&s, sizeof(s), 1, temp);
        } else {
            found = 1;
        }
    }
    fclose(fpt);
    fclose(temp);
    remove("data.txt");
    rename("temp.txt", "data.txt");

    if (found) {
        printf("\n\n\t\t\t\t\t\t\tRecord deleted successfully!");
    } else {
        printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t<<=======Record Not Found=======>>");
    }
    printf("\n\n\t\t\t\t\t\t\tPress Enter to continue...");
    clearInputBuffer();
    getchar();
}

// Function to search for a record
void searchRecord() {
    FILE *fpt;
    int found = 0;
    char fullName[30];

    system("cls");
    displayTitle();
    printf("\n\n");
    printf("\t\t\t\t\t\tEnter Full Name to Search Record: ");
    scanf(" %[^\n]s", fullName);

    fpt = fopen("data.txt", "r");
    while (fread(&s, sizeof(s), 1, fpt) == 1) {
        if (strcmp(fullName, s.fullName) == 0) {
            found = 1;
            break;
        }
    }
    fclose(fpt);

    if (found) {
        system("cls");
        printf("\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t  <<=======Search Successful=======>>\n");
        printf("\n");
        displayRecord(&s); // Display the record
    } else {
        system("cls");
        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\t\t\t<<=======Record Not Found=======>>\n");
    }
    printf("\n\n");
    printf("\t\t\t\t\t\t\tPress Enter to return to Main Menu...");
    clearInputBuffer();
    getchar();
}

// Function to display a record
void displayRecord(const struct Student *student) {
    printf(" ");
    printf("\n");
    printf("\t\t\t\t");
    printf("\t\t\t\t");
    printf("\n");
    printf("\t\t\t\t");
    printf("\n");
    printf("\t\t\t\t");

    printf("\t\t\t\tID      :  %s\n\n", student->ID);
    printf("\t\t\t\t\t\t\t");
    printf("Full Name       : %s  ", student->fullName);

    printf("\n\n");
    printf("\t\t\t\t\t\t\t");
    printf("Class           : %s  ", student->class);

    printf("\n\n");
    printf("\t\t\t\t\t\t\t");
    printf("Branch          : %s  ", student->branch);

    printf("\n\n");
    printf("\t\t\t\t\t\t\t");
    printf("Address         : %s  ", student->address);

    printf("\n\n");
    printf("\t\t\t\t\t\t\t");
    printf("Email Address   : %s  ", student->email);

    printf("\n\n");
    printf("\t\t\t\t\t\t\t");
    printf("Roll No.        : %s  ", student->rollNo);

    printf("\n\n");
    printf("\t\t\t\t\t\t\t");
    printf("Phone No.       : %s  ", student->phoneNumber);
}

// Function to clear the input buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}

// Delay function
void delay(unsigned int milliseconds) {
    clock_t goal = milliseconds + clock();
    while (goal > clock());
}