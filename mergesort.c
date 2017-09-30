#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "Sorter.h"

void initializeMergeSort(unsortMovie **unsortMovies, int sortFieldToInt, int totalRow);

void mergeSort(unsortMovie **unsortMovies, int totalRow, int sortFieldToInt);

void merge(unsortMovie **unsortMovies, unsortMovie **leftUnsortMovies, int leftCount, unsortMovie **rightUnsortMovies,
           int rightCount,
           int sortFieldToInt);

void initializeMergeSort(unsortMovie **unsortMovies, int sortFieldToInt, int totalRow) {
    //printf("int is %d\n",sortFieldToInt);
    mergeSort(unsortMovies, totalRow, sortFieldToInt);
    int i;
    for(i=0;i<totalRow;i++){
        printf("%s",unsortMovies[i]->aRowString);
    }
}

void mergeSort(unsortMovie **unsortMovies, int totalRow, int sortFieldToInt) {
    if(totalRow < 2) return;
    int middle = totalRow / 2;
    //printf("middle: %d\n",middle);

    int row;
    unsortMovie **leftArray = malloc(sizeof( unsortMovie * ) * middle);
    unsortMovie **rightArray = malloc(sizeof( unsortMovie * ) * (totalRow-middle));

    for (row = 0; row < middle; row++) {
        leftArray[row] = malloc(sizeof(unsortMovie) * 100000);
    }
    for (row = 0; row < (totalRow-middle); row++) {
        rightArray[row] = malloc(sizeof(unsortMovie) * 100000);
    }


    int i;
    for (i = 0; i < middle; i++) {
        leftArray[i] = unsortMovies[i];
    }

    for (i = middle; i < totalRow; i++) {
        rightArray[i-middle] = unsortMovies[i];
    }

    mergeSort(leftArray, middle, sortFieldToInt);
    mergeSort(rightArray, totalRow - middle, sortFieldToInt);
    merge(unsortMovies, leftArray, middle, rightArray, totalRow - middle, sortFieldToInt);




//    for (row = 0; row < middle; row++) {
//        free(leftArray[row]);
//    }
//    for (row = 0; row < (totalRow-middle); row++) {
//        free(rightArray[row]);
//    }
    free(leftArray);
    free(rightArray);

}

void merge(unsortMovie **unsortMovies, unsortMovie **leftUnsortMovies, int leftCount, unsortMovie **rightUnsortMovies, int rightCount, int sortFieldToInt) {
    int leftIndex, rightIndex, mergedIndex;
    leftIndex = 0;
    rightIndex = 0;
    mergedIndex = 0;

    while (leftIndex < leftCount && rightIndex < rightCount) {

       // printf("%s\n",leftUnsortMovies[0]->aRowfieldsArray[sortFieldToInt-1]);
       // printf("%s\n",rightUnsortMovies[0]->aRowfieldsArray[sortFieldToInt-1]);

        if (strcmp(leftUnsortMovies[leftIndex]->aRowfieldsArray[sortFieldToInt-1],
                   rightUnsortMovies[rightIndex]->aRowfieldsArray[sortFieldToInt-1]) < 0) {
            unsortMovies[mergedIndex++] = leftUnsortMovies[leftIndex++];
        } else {
            unsortMovies[mergedIndex++] = rightUnsortMovies[rightIndex++];
        }
    }
    while (leftIndex < leftCount) {
        unsortMovies[mergedIndex++] = leftUnsortMovies[leftIndex++];
    }
    while (rightIndex < rightCount) {
        unsortMovies[mergedIndex++] = rightUnsortMovies[rightIndex++];
    }
}



