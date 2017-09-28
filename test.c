#include <stdio.h>
#include <stdlib.h>

typedef struct myStruct {
    char *a;
    char *b;
} myStruct;

int main() {
    int maxlength = 60 + 1;
    int arraySize = 2;

    myStruct *myArray = malloc(sizeof(myStruct) * arraySize);
    int runningIndex = 0;
    while (1) {
        char *aline = malloc(maxlength);
        int status = getline(&aline, &maxlength, stdin);
        if (status == -1)
            break;
        char *bline = malloc(maxlength);
        getline(&bline, &maxlength, stdin);
        if (runningIndex == arraySize) {
            arraySize *= 2;
            myArray = realloc(myArray, sizeof(myStruct) * arraySize);
        }
        myArray[runningIndex].a = aline;//&aline is address of local variable.
        myArray[runningIndex].b = bline;//And content is rewritten in each loop.
        runningIndex++;
    }
    for (int i = 0; i < runningIndex; i++) {
        printf("outside the loop at index %d, a is %s and b is %s", i, myArray[i].a, myArray[i].b);
    }
    //deallocate
    return 0;
}