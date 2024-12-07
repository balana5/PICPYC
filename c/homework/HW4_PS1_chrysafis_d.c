/****************************************************/
/* Name : Dimitri Chrysafis */
/* Student ID : 1277192 */
/* Homework 4 Program Set 1 */
/* Date : 12/5/24 */
/* Salary Business */
/* */
/****************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 6

struct Employee {
    char name[50];
    float sal;
    float rate;
    float raise;
    float newSal;
};

// Function prototypes
void load(struct Employee e[], int n);
void ARate(struct Employee e[], int n);
void calcRaise(struct Employee e[], int n);
void sort(struct Employee e[], int n);
void total(struct Employee e[], int n, float *ts, float *tr, float *tn);
void title();
void print(struct Employee e[], int n);
void printTotals(float ts, float tr, float tn);
void savetext(struct Employee e[], int n);
void gettext(struct Employee e[], int n);
void savebn(struct Employee e[], int n);
void getbn(struct Employee e[], int n);

int main() {
    struct Employee e[SIZE];
    float ts = 0, tr = 0, tn = 0;

    // Load data into the struct and calculate initial values
    load(e, SIZE);
    ARate(e, SIZE);
    calcRaise(e, SIZE);
    total(e, SIZE, &ts, &tr, &tn);

    // Print original array of structures
    printf("Original Array of Structure before Sorting\n\n");
    title();
    print(e, SIZE);
    printTotals(ts, tr, tn);

    // Sort and print sorted array
    sort(e, SIZE);
    total(e, SIZE, &ts, &tr, &tn);
    printf("Array of Structure after Sorting\n\n");
    title();
    print(e, SIZE);
    printTotals(ts, tr, tn);

    // Text file operations
    printf("\n\nFrom Save Text file\n\n");
    title();
    savetext(e, SIZE);
    gettext(e, SIZE);
    print(e, SIZE);
    printTotals(ts, tr, tn);

    // Binary file operations
    printf("\n\nFrom Save Binary file\n\n");
    title();
    savebn(e, SIZE);
    getbn(e, SIZE);
    print(e, SIZE);
    printTotals(ts, tr, tn);

    return 0;
}

void load(struct Employee e[], int n) {
    const char *names[] = {"Susan", "Jim", "Gloria", "Ros", "Ben", "Tim"};
    const float salaries[] = {25000, 30000, 35000, 40000, 40001, 45000};
    for (int i = 0; i < n; i++) {
        strcpy(e[i].name, names[i]);
        e[i].sal = salaries[i];
    }
}

void ARate(struct Employee e[], int n) {
    for (int i = 0; i < n; i++) {
        if (e[i].sal > 0 && e[i].sal < 30000)
            e[i].rate = 7.0;
        else if (e[i].sal >= 30000 && e[i].sal <= 40000)
            e[i].rate = 5.5;
        else
            e[i].rate = 4.0;
    }
}

void calcRaise(struct Employee e[], int n) {
    for (int i = 0; i < n; i++) {
        e[i].raise = e[i].sal * e[i].rate / 100;
        e[i].newSal = e[i].sal + e[i].raise;
    }
}

void sort(struct Employee e[], int n) {
    struct Employee temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(e[i].name, e[j].name) > 0) {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
        }
    }
}

void total(struct Employee e[], int n, float *ts, float *tr, float *tn) {
    *ts = *tr = *tn = 0;
    for (int i = 0; i < n; i++) {
        *ts += e[i].sal;
        *tr += e[i].raise;
        *tn += e[i].newSal;
    }
}

void title() {
    printf("\t\t\tCalculation of Salary Raises\n\n");
    printf("Employee\tSalary\t\tRate %%\tRaise\t\tNew Salary\n\n");
}

void print(struct Employee e[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\t\t%10.2f\t%4.2f\t%8.2f\t%8.2f\n",
               e[i].name, e[i].sal, e[i].rate, e[i].raise, e[i].newSal);
    }
}

void printTotals(float ts, float tr, float tn) {
    printf("Total\t\t%10.2f\t\t%8.2f\t%8.2f\n\n", ts, tr, tn);
}

void savetext(struct Employee e[], int n) {
    FILE *file = fopen("employees.txt", "w");
    if (file) {
        for (int i = 0; i < n; i++) {
            fprintf(file, "%s %.2f %.2f %.2f %.2f\n",
                    e[i].name, e[i].sal, e[i].rate, e[i].raise, e[i].newSal);
        }
        fclose(file);
    }
}

void gettext(struct Employee e[], int n) {
    FILE *file = fopen("employees.txt", "r");
    if (file) {
        for (int i = 0; i < n; i++) {
            fscanf(file, "%s %f %f %f %f",
                   e[i].name, &e[i].sal, &e[i].rate, &e[i].raise, &e[i].newSal);
        }
        fclose(file);
    }
}

void savebn(struct Employee e[], int n) {
    FILE *file = fopen("employees.bin", "wb");
    if (file) {
        fwrite(e, sizeof(struct Employee), n, file);
        fclose(file);
    }
}

void getbn(struct Employee e[], int n) {
    FILE *file = fopen("employees.bin", "rb");
    if (file) {
        fread(e, sizeof(struct Employee), n, file);
        fclose(file);
    }
}

/*
Sample Output:
Enter the employee's name: Susan
Enter salary: 25000
Enter the employee's name: Jim
Enter salary: 30000
Enter the employee's name: Gloria
Enter salary: 35000
Enter the employee's name: Ros
Enter salary: 40000
Enter the employee's name: Ben
Enter salary: 40001
Enter the employee's name: Tim
Enter salary: 45000

Original Array of Structure before Sorting

            Calculation of Salary Raises

Employee        Salary          Rate %   Raise           New Salary

Susan           25000.00        7.00    1750.00         26750.00
Jim             30000.00        5.50    1650.00         31650.00
Gloria          35000.00        5.50    1925.00         36925.00
Ros             40000.00        5.50    2200.00         42200.00
Ben             40001.00        4.00    1600.04         41601.04
Tim             45000.00        4.00    1800.00         46800.00
Total           215001.00       10925.04                225926.03

Array of Structure after Sorting

            Calculation of Salary Raises

Employee        Salary          Rate %   Raise           New Salary

Ben             40001.00        4.00    1600.04         41601.04
Gloria          35000.00        5.50    1925.00         36925.00
Jim             30000.00        5.50    1650.00         31650.00
Ros             40000.00        5.50    2200.00         42200.00
Susan           25000.00        7.00    1750.00         26750.00
Tim             45000.00        4.00    1800.00         46800.00
Total           215001.00       10925.04                225926.03


From Save Text file

            Calculation of Salary Raises

Employee        Salary          Rate %   Raise           New Salary

Ben             40001.00        4.00    1600.04         41601.04
Gloria          35000.00        5.50    1925.00         36925.00
Jim             30000.00        5.50    1650.00         31650.00
Ros             40000.00        5.50    2200.00         42200.00
Susan           25000.00        7.00    1750.00         26750.00
Tim             45000.00        4.00    1800.00         46800.00
Total           215001.00       10925.04                225926.03


From Save Binary file

            Calculation of Salary Raises

Employee        Salary          Rate %   Raise           New Salary

Ben             40001.00        4.00    1600.04         41601.04
Gloria          35000.00        5.50    1925.00         36925.00
Jim             30000.00        5.50    1650.00         31650.00
Ros             40000.00        5.50    2200.00         42200.00
Susan           25000.00        7.00    1750.00         26750.00
Tim             45000.00        4.00    1800.00         46800.00
Total           215001.00       10925.04                225926.03
*/
