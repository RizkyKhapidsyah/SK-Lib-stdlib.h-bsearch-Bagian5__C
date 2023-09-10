#include <search.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

/*
    Source by Microsoft (https://docs.microsoft.com/en-us/cpp)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int compare(char** arg1, char** arg2) {
    return _strcmpi(*arg1, *arg2);
}

int main(void) {
    char* arr[] = { "dog", "pig", "horse", "cat", "human", "rat", "cow", "goat" };
    char** result;
    char* key = "cat";
    int i;

    /* Sort using Quicksort algorithm: */
    qsort((void*)arr, sizeof(arr) / sizeof(arr[0]), sizeof(char*), (int (*)(const void*, const void*))compare);

    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {    /* Output sorted list */
        printf("%s ", arr[i]);
    }

    /* Find the word "cat" using a binary search algorithm: */
    result = (char**)bsearch((char*)&key, (char*)arr, sizeof(arr) / sizeof(arr[0]), sizeof(char*), (int (*)(const void*, const void*))compare);
    
    if (result) {
        printf("\n%s found at %Fp\n", *result, result);
    } else {
        printf("\nCat not found!\n");
    }
        
    _getch();
    return 0;
}