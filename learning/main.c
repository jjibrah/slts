#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>
#include <windows.h>
#include <unistd.h>
#include "chapters.h"

struct details{
    char fname[20];
    char lname[20];
    char stdno[20];
};


time_t now , endT;

const char *courses[] = {
    "C programming Language"
};


void getdetails(struct details *std);
void showCourse();
int chooseCourse();
int chooseChapter();
int chooseUnit();
void displayChapters(int);
void displayUnits(int);
void displayContent(int, int);
int isValidString(const char *str);
void skip();
void stars();
void displayMenu();
void timer();
void startTime();
void difTime(double now,double end);
void endTime();



int main(){
    //Start by getting the students information
    struct details studentDetails;
    stars();
    printf("\tWELCOME TO THE STUDENT LEARNING TRECKING SYSTEM\n");
    stars();
    getdetails(&studentDetails);
    stars();
    printf(" welcome %s %s,\n %s\n",studentDetails.lname, studentDetails.fname, studentDetails.stdno);
    stars();
    showCourse();
    int course = chooseCourse();
    stars();
    displayChapters(course);
    stars();
    int chapter = chooseChapter();
    stars();
    displayUnits(chapter);
    stars();
    int unit = chooseUnit();
    stars();
    displayContent(chapter,unit);
    skip();
    stars();
    startTime();
    displayMenu();



}

void skip(){
    printf("\n");

}

void stars(){
    printf("********************************************************************\n");
}

void showCourse(){
     printf("Available courses.\n");
     for(int i = 0; i< sizeof(courses)/ sizeof(courses[0]);i++){
        printf("%d : %s\n", i+1, courses[i]);
     }
}

void getdetails(struct details *std){
    printf("Please enter your Details to start.\n");
    do{
        printf("enter first name  :  ");
        scanf("%s",std->fname);
    } while(!isValidString(std->fname));
    do{
        printf("enter last name  :  ");
        scanf("%s",std->lname);
    } while(!isValidString(std->lname));

    printf("enter student number : ");
    scanf("%s",std->stdno);
}

int isValidString(const char *str) {
    while (*str) {
        if (!isalpha(*str) || isspace(*str)) {
            printf("Invalid input! Please enter a valid name without numbers, spaces, or special characters.\n");
            return 0; // Return 0 to indicate invalid input
        }
        str++;
    }
    return 1; // Return 1 to indicate valid input
}

int chooseCourse() {
    int courseNo;

    printf("Enter the number of the course you want to Learn: ");
    scanf("%d", &courseNo);
    while (courseNo < 1 || courseNo > sizeof(courses) / sizeof(courses[0])) {
        printf("Invalid courseNo. Please enter a number > 0 but <= %d: ", sizeof(courses) / sizeof(courses[0]));
        scanf("%d", &courseNo);
    }
    return courseNo;
}

void displayChapters(int courseNumber) {
    FILE *file;

    char chapter[20];
    sprintf(chapter, "chapter.txt", courseNumber);
    file = fopen(chapter, "w");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(1);
    }


 switch (courseNumber) {
        case 1:
            for (int i = 0; i < sizeof(tutorials) / sizeof(tutorials[0]); i++) {
                fprintf(file, "%s\n", tutorials[i]);
            }
            break;
        default:
            printf("Invalid course choice.\n");
            exit(1);
    }

    fclose(file);
    file = fopen(chapter, "r");

    if (file == NULL) {
        printf("Error opening file for reading.\n");
        exit(1);
    }

    printf("The course has the following chapters:\n");
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);

}

int chooseChapter() {
    int chapterNumber;
    printf("Enter the number of the chapter you want to learn: ");
    scanf("%d", &chapterNumber);

    while (chapterNumber < 1 || chapterNumber > sizeof(tutorials) / sizeof(tutorials[0])) {
        printf("Invalid courseNo. Please enter a number <= %d: ", sizeof(tutorials) / sizeof(tutorials[0]));
        scanf("%d", &chapterNumber);
    }

    return chapterNumber;
}

void displayUnits(int chapterNumber) {
    FILE *file;

    char units[20];
    sprintf(units, "units.txt", chapterNumber);

    file = fopen(units, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        exit(1);
    }

    switch (chapterNumber) {
        case 1:
            // Print values from section1 to the file
            for (int i = 0; i < sizeof(section1) / sizeof(section1[0]); i++) {
                fprintf(file, "%s\n", section1[i]);
            }
            break;
        case 2 :
            // Print values from section1 to the file
            for (int i = 0; i < sizeof(section2) / sizeof(section2[0]); i++) {
                fprintf(file, "%s\n", section2[i]);
            }break;
        case 3:
            // Print values from section1 to the file
            for (int i = 0; i < sizeof(section3) / sizeof(section1[0]); i++) {
                fprintf(file, "%s\n", section1[i]);
            }
            break;
        case 4 :
            // Print values from section1 to the file
            for (int i = 0; i < sizeof(section4) / sizeof(section4[0]); i++) {
                fprintf(file, "%s\n", section4[i]);
            }break;
        case 5:
            // Print values from section1 to the file
            for (int i = 0; i < sizeof(section5) / sizeof(section5[0]); i++) {
                fprintf(file, "%s\n", section5[i]);
            }
            break;
        case 6 :
            // Print values from section1 to the file
            for (int i = 0; i < sizeof(section6) / sizeof(section6[0]); i++) {
                fprintf(file, "%s\n", section6[i]);
            }break;
        case 7 :
            // Print values from section1 to the file
            for (int i = 0; i < sizeof(section7) / sizeof(section7[0]); i++) {
                fprintf(file, "%s\n", section7[i]);
            }break;
        // Add more cases for additional courses
        default:
            printf("Invalid course choice.\n");
            exit(1);
    }

    // Close the file
    fclose(file);

    // Reopen the file for reading
    file = fopen(units, "r");

    if (file == NULL) {
        printf("Error opening file for reading.\n");
        exit(1);
    }

    printf("*****************************************\n");
    printf("The chapter has the following units:\n");
    printf("*****************************************\n");


    // Display the contents of the file
    int ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    // Close the file
    fclose(file);

}

int chooseUnit() {
    int unitNumber;

    printf("Enter the number of the Unit you want to Study: ");
    scanf("%d", &unitNumber);

    while (unitNumber < 1 || unitNumber > sizeof(section5) / sizeof(section5[0])) {
        printf("Invalid courseNo. Please enter a number <= %d: ", sizeof(section5) / sizeof(section5[0]));
        scanf("%d", &unitNumber);
    }

    return unitNumber;
}

void displayContent(int chapterNumber, int unitNumber) {
    FILE *file;
    char content[20];
    sprintf(content, "files/%d.%02d.txt", chapterNumber, unitNumber);
    file = fopen(content, "r");

    if (file != NULL) {
        int ch;
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
    }else{
        printf("******************************************************\n");
        printf("Sorry file not available\n");
        printf("******************************************************\n");

    }

    fclose(file);
}

void displayMenu() {
    int choice;
    printf("\nMenu:\n");
    printf("1. Choose Knowledge Units start Learning\n");
    printf("2. Time taken studying\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

 switch (choice) {
        case 1:
            {

                int chosenChapter = chooseChapter();
                int chosenUnit = chooseUnit(chosenChapter);
                displayContent(chosenChapter, chosenUnit);  // Pass chosenCourse here
                stars();
                displayMenu();
            }
            break;

        case 2:
            endTime();
            difTime(endT, now);
            displayMenu();
            break;

        case 3:
            printf("Exiting the program.\n");
            exit(0);
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
            break;
    }

}

void startTime(){
    now = time(NULL);
    char *lc_time = ctime(&now);

    printf("THE STARTING TIME IS \n");
    printf(" %s \n",lc_time);
    stars();


}

void endTime(){
    endT = time(NULL);
    char *lc_time = ctime(&endT);
    stars();
    printf("THE ENDING TIME IS \n");
    printf(" %s \n",lc_time);
    stars();


}

void difTime(double end,double now){

    double diff = difftime(end, now);
    printf("You have Studyied for : %1.0f seconds", diff);
}

/*/ Function to log learning activity
void logLearningActivity(int chapterNumber, int unitNumber, const char *unitName) {


    FILE *logFile;
    logFile = fopen("learninglog.txt", "a");  // Open log file in append mode

    if (logFile == NULL) {
        printf("Error opening log file for writing.\n");
        exit(1);
    }


    // Get the current time
    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);

    fprintf(logFile, "Student ID    : %s\n", stdno);
    fprintf(logFile, "Chapter: %d, Section: %02d\n", chapterNumber, unitNumber);
    fprintf(logFile, "Start Time    : %s", asctime(localTime));
    fprintf(logFile, "End Time      : %s", asctime(localTime));
    fprintf(logFile, "Elapsed Time  : %ld seconds\n", (endTime - startTime));
    fprintf(logFile, "*********************************\n");

    fclose(logFile);
}
*/
