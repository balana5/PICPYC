/**************************************************/
/* Lab 4                                         */
/* Name: Dimitri C                               */
/* Student ID: 1277192                     */
/* Date: Dec 5                         */
/**************************************************/

/**************************************************/
/* Lab 4 Question 1                              */
/* This program interchanges the largest and     */
/* smallest numbers in an array                  */
/**************************************************/

#include<stdio.h>

void read_array(int arr[], int size);
void display_array(int arr[], int size);
void interchange_largest_smallest(int arr[], int size);

int main() {
    int size;

    printf("Enter the desired size of the array: ");
    scanf("%d", &size);

    int arr[size];

    read_array(arr, size);
    printf("\n");
    printf("The elements of the array are:\n");
    display_array(arr, size);

    interchange_largest_smallest(arr, size);
    printf("\nThe elements of the array after the interchange are:\n");
    display_array(arr, size);

    return 0;
}


void read_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter a number for position %d: ", i);
        scanf("%d", &arr[i]);
    }
}


void display_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d]=%d ", i, arr[i]);
    }
    printf("\n");
}


void interchange_largest_smallest(int arr[], int size) {
    int max_idx = 0;
    int min_idx = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[max_idx]){
            max_idx = i;
        }
        if (arr[i] < arr[min_idx]){
            min_idx = i;
        }
    }

    int temp = arr[max_idx];
    arr[max_idx] = arr[min_idx];
    arr[min_idx] = temp;
}


/* Test Runs
Test Run 1:
Enter the desired size of the array: 5
Enter a number for position 0: 3
Enter a number for position 1: 6
Enter a number for position 2: 3
Enter a number for position 3: 7
Enter a number for position 4: 9

The elements of the array are:
arr[0]=3 arr[1]=6 arr[2]=3 arr[3]=7 arr[4]=9

The elements of the array after the interchange are:
arr[0]=9 arr[1]=6 arr[2]=3 arr[3]=7 arr[4]=3

Test Run 2:
Enter the desired size of the array: 4
Enter a number for position 0: 10
Enter a number for position 1: 15
Enter a number for position 2: 2
Enter a number for position 3: 8

The elements of the array are:
arr[0]=10 arr[1]=15 arr[2]=2 arr[3]=8

The elements of the array after the interchange are:
arr[0]=2 arr[1]=15 arr[2]=10 arr[3]=8

Test Run 3:
Enter the desired size of the array: 6
Enter a number for position 0: 5
Enter a number for position 1: 9
Enter a number for position 2: 3
Enter a number for position 3: 6
Enter a number for position 4: 1
Enter a number for position 5: 4

The elements of the array are:
arr[0]=5 arr[1]=9 arr[2]=3 arr[3]=6 arr[4]=1 arr[5]=4

The elements of the array after the interchange are:
arr[0]=1 arr[1]=9 arr[2]=3 arr[3]=6 arr[4]=5 arr[5]=4
*/

/**************************************************/
/* Lab 4 Question 2                              */
/* This program finds the second largest number  */
/* in an array                                   */
/**************************************************/

#include <stdio.h>

void read_array(int arr[], int size);
void display_array(int arr[], int size);
void find_largest_and_second_largest(int arr[], int size, int *largest, int *second);

int main() {
    int size;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    read_array(arr, size);
    printf("\n");
    printf("The numbers you entered are: ");
    display_array(arr, size);

    int largest, second_largest;
    find_largest_and_second_largest(arr, size, &largest, &second_largest);

    printf("The largest of these numbers is: %d\n", largest);
    printf("The second largest of these numbers is: %d\n", second_largest);

    return 0;
}

void read_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Enter the number: ");
        scanf("%d", &arr[i]);
    }
}

void display_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void find_largest_and_second_largest(int arr[], int size, int *largest, int *second) {
    if (size < 2) {
        // Handle the case where there aren't enough elements
        *largest = *second = -1;
        return;
    }

    // Initialize largest and second largest
    *largest = (arr[0] > arr[1]) ? arr[0] : arr[1];
    *second = (arr[0] < arr[1]) ? arr[0] : arr[1];

    // Start iterating from the third element
    for (int i = 2; i < size; i++) {
        if (arr[i] > *largest) {
            *second = *largest;
            *largest = arr[i];
        } else if (arr[i] > *second && arr[i] != *largest) {
            *second = arr[i];
        }
    }
}

/* Test Runs
Test Run 1:
Enter the number of elements in the array: 6
Enter the number: 10
Enter the number: 35
Enter the number: 60
Enter the number: 34
Enter the number: 20
Enter the number: 46

The numbers you entered are:
10 35 60 34 20 46
The largest of these numbers is: 60
The second largest of these numbers is: 46

Test Run 2:
Enter the number of elements in the array: 5
Enter the number: 25
Enter the number: 50
Enter the number: 15
Enter the number: 5
Enter the number: 10

The numbers you entered are:
25 50 15 5 10
The largest of these numbers is: 50
The second largest of these numbers is: 25

Test Run 3:
Enter the number of elements in the array: 4
Enter the number: 100
Enter the number: 90
Enter the number: 80
Enter the number: 70

The numbers you entered are:
100 90 80 70
The largest of these numbers is: 100
The second largest of these numbers is: 90
*/

/**************************************************/
/* Lab 4 Question 3                              */
/* This program checks for duplicate numbers     */
/* in an array                                   */
/**************************************************/

#include<stdio.h>
#include<stdbool.h>

void read_array(int arr[], int size);
void display_array(int arr[], int size);
bool find_duplicates(int arr[], int size);

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    read_array(arr, size);
    printf("The numbers you entered are:\n");
    display_array(arr, size);

    if (!find_duplicates(arr, size)) {
        printf("No duplicate numbers found.\n");
    }

    return 0;
}


void read_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}


void display_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


bool find_duplicates(int arr[], int size) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                printf("Duplicate number %d found at location %d and %d\n", arr[i], i, j);
                found = true;
            }
        }
    }
    return found;
}

/* Test Runs
Test Run 1:
Enter the size of the array: 6
1
2
3
3
4
5
The numbers you entered are:
1 2 3 3 4 5
Duplicate number 3 found at location 2 and 3

Test Run 2:
Enter the size of the array: 5
6
7
8
8
9
The numbers you entered are:
6 7 8 8 9
Duplicate number 8 found at location 2 and 3

Test Run 3:
Enter the size of the array: 4
10
11
12
10
The numbers you entered are:
10 11 12 10
Duplicate number 10 found at location 0 and 3

/**************************************************/
/* Lab 4 Question 4                              */
/* This program reads and prints text until '*'  */
/* is encountered and counts the number of       */
/* characters entered.                           */
/**************************************************/

#include<stdio.h>

void read_and_count_text();

int main() {
    read_and_count_text();
    return 0;
}

void read_and_count_text() {
    char ch;
    int count = 0;
    char text[1000];  // To store the text entered by the user
    int i = 0;

    printf("Enter * to end\n");
    printf("Enter the text: ");

    // Read and store characters, excluding * and newlines
    while ((ch = getchar()) != '*') {
        if (ch != '\n') {  // Ignore newline characters
            text[i++] = ch;  // Store the character
            count++;          // Increment the character count
        }
    }
    text[i] = '\0';  // Null-terminate the string

    // Print the entered text and count
    printf("The text is: %s\n", text);
    printf("The count of the characters is: %d\n", count);
}


/* Test Runs
Test Run 1:
Enter * to end
Enter the text: Hi there*
The text is: Hi there
The count of the characters is: 8

Test Run 2:
Enter * to end
Enter the text: Hello, world!*
The text is: Hello, world!
The count of the characters is: 13

Test Run 3:
Enter * to end
Enter the text: Programming in C is fun*
The text is: Programming in C is fun
The count of the characters is: 24
*/

/**************************************************/
/* Lab 4 Question 5                              */
/* This program reads a sentence and counts the  */
/* number of words in the sentence.              */
/**************************************************/

#include<stdio.h>

int count_words(char sentence[]);

int main() {
    char sentence[100];

    printf("Enter the sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    printf("The total count of words is: %d\n", count_words(sentence));

    return 0;
}


int count_words(char sentence[]) {
    int count = 0, in_word = 0;
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\n') {
            in_word = 0;  // Space or newline, end of a word
        } else if (in_word == 0) {
            in_word = 1;  // Start of a new word
            count++;      // Increment word count
        }
    }
    return count;
}

/* Test Runs
Test Run 1:
Enter the sentence: How are you
The total count of words is: 3

Test Run 2:
Enter the sentence: Programming in C is awesome
The total count of words is: 5

Test Run 3:
Enter the sentence: Hello, my name is Dimitri
The total count of words is: 5
*/

/**************************************************/
/* Lab 4 Question 6                              */
/* This program replaces commas with semi-colons */
/* in the entered text and displays the result.   */
/**************************************************/

#include<stdio.h>

void replace_commas(char text[]);

int main() {
    char text[100];

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    replace_commas(text);

    printf("The copied text is: %s\n", text);
    return 0;
}


void replace_commas(char text[]) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ',') {
            text[i] = ';';
        }
    }
}

/* Test Runs
Test Run 1:
Enter the text: Hello, how are you
The copied text is: Hello; how are you

Test Run 2:
Enter the text: Welcome, to the programming world, enjoy!
The copied text is: Welcome; to the programming world; enjoy!

Test Run 3:
Enter the text: Apples, bananas, and cherries
The copied text is: Apples; bananas; and cherries
*/

/**************************************************/
/* Lab 4 Question 7                              */
/* This program counts how many times a pattern   */
/* is found in the entered text.                  */
/**************************************************/

#include<stdio.h>

int count_pattern_occurrences(char text[], char pattern[]);


int main() {
    char text[100], pattern[100];

    printf("Enter string: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the pattern: ");
    fgets(pattern, sizeof(pattern), stdin);

    int count = count_pattern_occurrences(text, pattern);
    
    if (count > 0) {
        printf("Pattern found %d times\n", count);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}


int count_pattern_occurrences(char text[], char pattern[]) {
    int count = 0, i = 0, j = 0;

    while (text[i] != '\0') {
        if (text[i] == pattern[j]) {
            j++;
            if (pattern[j] == '\0') {  // Pattern found
                count++;
                j = 0;  // Restart matching from the beginning of the pattern
            }
        } else {
            j = 0;  // Reset pattern matching
        }
        i++;
    }

    return count;
}

/* Test Runs
Test Run 1:
Enter string: She sells sea shells on the sea shore
Enter the pattern: sea
Pattern found 2 times

Test Run 2:
Enter string: Hello there! How are you today? I hope you are doing well.
Enter the pattern: you
Pattern found 2 times

Test Run 3:
Enter string: The quick brown fox jumps over the lazy dog
Enter the pattern: dog
Pattern found 1 time
*/

