/****************************************************/
/* Name : Dimitri Chrysafis */
/* Student ID : 1277192 */
/* Homework 4 Program Set 1 */
/* Date : 12/5/24 */
/* Salary Business */
/* */
/****************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 6

// struct to tore the employee information
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
    float ts,tr,tn;
    ts = 0;
    tr = 0;
    tn = 0;

    // Load data, calculate raises, and print original array
    load(e, SIZE);
    ARate(e, SIZE);
    calcRaise(e, SIZE);
    total(e, SIZE, &ts, &tr, &tn);

    printf("Original Array of Structure before Sorting\n\n");
    title();
    print(e, SIZE);
    printTotals(ts, tr, tn);

    // Sort and print the sorted array
    sort(e, SIZE);
    total(e, SIZE, &ts, &tr, &tn);

    printf("Array of Structure after Sorting\n\n");
    title();
    print(e, SIZE);
    printTotals(ts, tr, tn);

    //**************Section for text files*****************
    printf("\n\nFrom Save Text file\n\n");
    title();
    savetext(e, SIZE);
    gettext(e, SIZE);
    print(e, SIZE);
    total(e, SIZE, &ts, &tr, &tn);
    printTotals(ts, tr, tn);

    //**************Section for binary files*****************
    
    printf("\n\nFrom Save Binary file\n\n");
    title();
    savebn(e, SIZE);
    //retrieve data from binary file and print the data
    getbn(e, SIZE);
    print(e, SIZE);
    total(e, SIZE, &ts, &tr, &tn);
    printTotals(ts, tr, tn);

    return 0;
}


// allow to enter employee information (name/salary)
void load(struct Employee e[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("Enter the employee's name: ");
        scanf("%s", e[i].name);
        printf("Enter salary: ");
        scanf("%f", &e[i].sal);
    }
}


// computations for the rate 
void ARate(struct Employee e[], int n)
{
    for (int i = 0; i < n; i++) {
        if (e[i].sal < 30000.0) {
            e[i].rate = 7.0;
        } else if (e[i].sal <= 40000.0) {
            e[i].rate = 5.5;
        } else {
            e[i].rate = 4.0;
        }
    }
}


// calculate the amount of raise for every employee
void calcRaise(struct Employee e[], int n)
{
    for (int i = 0; i < n; i++) {
        e[i].raise = e[i].sal * e[i].rate / 100;
        e[i].newSal = e[i].sal + e[i].raise;
    }
}


// sort the given information about the employees
void sort(struct Employee e[], int n)
{
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


// give everything back for the total
void total(struct Employee e[], int n, float *ts, float *tr, float *tn)
{
    *ts = 0;
    *tr = 0;
    *tn = 0;
    for (int i = 0; i < n; i++) {
        *ts += e[i].sal;
        *tr += e[i].raise;
        *tn += e[i].newSal;
    }
}


// print the title to make it look nice
void title()
{
    printf("\t\t\tCalculation of Salary Raises\n\n");
    printf("Employee\t"); printf("Salary\t\t"); printf("Rate %\t"); printf(" Raise\t\t");
    printf("New Salary\n\n");
}


// print all of the critical information already generated
void print(struct Employee e[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%s\t\t", e[i].name); printf("%10.2f\t", e[i].sal); printf("%4.2f\t", e[i].rate);
        printf("%8.2f\t", e[i].raise); printf("%8.2f\t\n", e[i].newSal);
    }
}

// print whatever totals have already been given
void printTotals(float ts, float tr, float tn)
{
    printf("Total\t\t"); printf("%10.2f\t\t", ts); printf("%8.2f\t", tr); printf("%8.2f\n\n",
                                                                                 tn);
}


// file operations for saving to file
void savetext(struct Employee e[], int n)
{
    FILE *fp = fopen("employees.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%s %.2f %.2f %.2f %.2f\n", e[i].name, e[i].sal, e[i].rate, e[i].raise, e[i].newSal);
    }
    fclose(fp);
}


// get the text for the file operations as well
void gettext(struct Employee e[], int n)
{
    FILE *fp = fopen("employees.txt", "r");
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%s %f %f %f %f", e[i].name, &e[i].sal, &e[i].rate, &e[i].raise, &e[i].newSal);
    }
    fclose(fp);
}


// save the binary file to it
void savebn(struct Employee e[], int n)
{
    FILE *fp = fopen("employees.bin", "wb");
    fwrite(e, sizeof(struct Employee), n, fp);
    fclose(fp);
}


// read the binary file
void getbn(struct Employee e[], int n)
{
    FILE *fp = fopen("employees.bin", "rb");
    fread(e, sizeof(struct Employee), n, fp);
    fclose(fp);
}


/*
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

Employee        Salary          Rate     Raise          New Salary

Susan             25000.00      7.00     1750.00        26750.00        
Jim               30000.00      5.50     1650.00        31650.00        
Gloria            35000.00      5.50     1925.00        36925.00        
Ros               40000.00      5.50     2200.00        42200.00        
Ben               40001.00      4.00     1600.04        41601.04        
Tim               45000.00      4.00     1800.00        46800.00        
Total            215001.00              10925.04        225926.03

Array of Structure after Sorting

                        Calculation of Salary Raises

Employee        Salary          Rate     Raise          New Salary

Ben               40001.00      4.00     1600.04        41601.04        
Gloria            35000.00      5.50     1925.00        36925.00        
Jim               30000.00      5.50     1650.00        31650.00        
Ros               40000.00      5.50     2200.00        42200.00        
Susan             25000.00      7.00     1750.00        26750.00        
Tim               45000.00      4.00     1800.00        46800.00        
Total            215001.00              10925.04        225926.03



From Save Text file

                        Calculation of Salary Raises

Employee        Salary          Rate     Raise          New Salary

Ben               40001.00      4.00     1600.04        41601.04        
Gloria            35000.00      5.50     1925.00        36925.00        
Jim               30000.00      5.50     1650.00        31650.00        
Ros               40000.00      5.50     2200.00        42200.00        
Susan             25000.00      7.00     1750.00        26750.00        
Tim               45000.00      4.00     1800.00        46800.00        
Total            215001.00              10925.04        225926.03



From Save Binary file

                        Calculation of Salary Raises

Employee        Salary          Rate     Raise          New Salary

Ben               40001.00      4.00     1600.04        41601.04        
Gloria            35000.00      5.50     1925.00        36925.00        
Jim               30000.00      5.50     1650.00        31650.00        
Ros               40000.00      5.50     2200.00        42200.00        
Susan             25000.00      7.00     1750.00        26750.00        
Tim               45000.00      4.00     1800.00        46800.00        
Total            215001.00              10925.04        225926.03

*/
