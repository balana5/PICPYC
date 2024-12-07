#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 6


struct Employee
{
	//declare your struct data members here

};


//function prototype here


int main()
{
	//declaration of variables
	struct Employee e[SIZE];
	float ts,tr,tn;
	
	//load data into struct, calculate raises, salaries and new salaries and print the //original array of struct
	load(e,SIZE);
	ARate(e,SIZE);
	calcRaise(e,SIZE);
    total(e,SIZE,&ts,&tr,&tn);
	printf("Original Array of Structure before Sorting\n\n");
	title();
	print(e,SIZE);
	printTotals(ts,tr,tn);

	//sort the struct of array and print the sorted struct of array
	sort(e,SIZE);
	total(e,SIZE,&ts,&tr,&tn);
	printf("Array of Structure after Sorting\n\n");
	title();
	print(e,SIZE);
	printTotals(ts,tr,tn);

	//**************Section for text files***************** 
	printf("\n\n");
	printf("From Save Text file\n\n");
	title();
	
	//save the struct of array to a text file
	savetext(e,SIZE);
	
	//retrieve the text file and print the data
	gettext(e,SIZE);
	print(e,SIZE);
	total(e,SIZE,&ts,&tr,&tn);
	printTotals(ts,tr,tn);
	
	//**************Section for binary files*****************
	printf("\n\n");
	printf("From Save Binary file\n\n");
	title();
	
	//save struct of array to a binary file
	savebn(e,SIZE);
	
	//retrieve data from binary file and print the data
	getbn(e,SIZE);
	print(e,SIZE);
	total(e,SIZE,&ts,&tr,&tn);
	printTotals(ts,tr,tn);
	
	return 0;
}


void load (struct Employee e[], int n)
{
	//write the codes to let user enter employee’s name and salary

}


void ARate(struct Employee e[], int n)

{
	//assign each employee rate to the struct’s rate data member here by checking salary range	
	//for example
	//        if(e[i].sal >= 0.00 && e[i].sal < 30000.00)
	//		e[i].rate = 7.00;
}


void calcRaise(struct Employee e[], int n)
{   
	//calculate the raise and new salary for each employee and store into the
	//struct’s raise and new salary data members
	//	raise = salary * rate/100
	//	new salary = salary + raise
}


void sort(struct Employee e[], int n)
{
	//sort the struct in ascending order
}



void total(struct Employee e[], int n,float *ts,float *tr,float *tn )

{
	//ts = total salary(sum the salaries of all 6 employees)
	//tr = total raise(sum the raises of all 6 employees)
	//tn = total new salary(sum of new salaries of all 6 employees)

}

void title()
{
	printf("\t\t\tCalculation of Salary Raises\n\n");

	printf("Employee\t");     printf("Salary\t\t"); printf("Rate %\t"); printf("  Raise\t\t"); printf("New Salary\n\n");
}


void print(struct Employee e[], int n)
{
	int i;

	for(i = 0; i < n; i++)
	{
		printf("%s\t\t", e[i].name); printf("%10.2f\t", e[i].sal); printf("%4.2f\t", e[i].rate);
		printf("%8.2f\t", e[i].raise); printf("%8.2f\t\n", e[i].newSal);
	}
}


void printTotals(float ts,float tr, float tn)
{
	printf("Total\t\t"); printf("%10.2f\t\t", ts); printf("%8.2f\t", tr); printf("%8.2f\n\n", tn);
}


void savetext(struct Employee e[], int n)
{
	//save the struct to text file employees.txt
}


void gettext(struct Employee e[], int n)
{
	//retrieve the data from employees.txt file
}


void savebn(struct Employee e[], int n)
{
	//save the struct to a binary file employees.bin
}


void getbn(struct Employee e[], int n)
{
	//retrieve the data from the employees.bin file
}


