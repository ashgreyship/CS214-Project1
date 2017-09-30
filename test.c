#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include "Sorter.h"

void initializeMergeSort(unsortMovie **unsortMovies, int sortFieldToInt, int totalRow);

void mergeSort(unsortMovie **unsortMovies, int leftIndex, int rightIndex, int sortFieldToInt);

void merge(unsortMovie **unsortMovies, int leftIndex, int middleIndex, int rightIndex, int sortFieldToInt);

void initializeMergeSort(unsortMovie **unsortMovies, int sortFieldToInt, int totalRow) {
    //printf("int is %d",sortFieldToInt);
    mergeSort(unsortMovies, 0, totalRow - 1, sortFieldToInt);
}

void mergeSort(unsortMovie **unsortMovies, int leftIndex, int rightIndex, int sortFieldToInt) {
    if (leftIndex < rightIndex) {
        int middle = leftIndex + (rightIndex - leftIndex) / 2;
        mergeSort(unsortMovies, leftIndex, middle, sortFieldToInt);
        mergeSort(unsortMovies, middle + 1, rightIndex, sortFieldToInt);
        merge(unsortMovies, leftIndex, middle, rightIndex, sortFieldToInt);
    }


}

void merge(unsortMovie **unsortMovies, int leftIndex, int middleIndex, int rightIndex, int sortFieldToInt) {
    int i, j, k;
    int leftArraySize = middleIndex - leftIndex + 1;
    int rightArraySize = rightIndex - middleIndex;

    unsortMovie **leftUnsortMovie = malloc(sizeof(struct unsortMovie *) * leftArraySize);
    unsortMovie **rightUnsortMovie = malloc(sizeof(struct unsortMovie *) * rightArraySize);
    int leftNum, rightNum;
    for (leftNum = 0; leftNum < leftArraySize; leftNum++) {
        leftUnsortMovie[leftNum] = malloc(sizeof(unsortMovie) * 10000);
    }
    for (rightNum = 0; rightNum < rightArraySize; rightNum++) {
        rightUnsortMovie[rightNum] = malloc(sizeof(unsortMovie) * 10000);
    }

    i = 0;
    j = 0;
    k = leftIndex;
    while (i < leftArraySize && j < rightArraySize) {
        if(strcmp(leftUnsortMovie[i]->aRowfieldsArray[sortFieldToInt-1],rightUnsortMovie[j]->aRowfieldsArray[sortFieldToInt-1])<0){
            unsortMovies[k]=leftUnsortMovie[i];
            i++;
        }else{
            unsortMovies[k]=rightUnsortMovie[j];
            j++;
        }
        k++;
    }

    while(i<leftArraySize){
        unsortMovies[k]=leftUnsortMovie[i];
        i++;
        k++;
    }
    while(j<rightArraySize){
        unsortMovies[k]=rightUnsortMovie[j];
        j++;
        k++;
    }

    free(leftUnsortMovie);
    free(rightUnsortMovie);

}