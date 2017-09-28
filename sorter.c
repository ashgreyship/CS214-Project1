#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Sorter.h"
#include "mergesort.c"

//typedef struct movie {
//    //char** aRowfieldsArray;
//    char* aRowString;
//}unsortMovie;
int storeRows(unsortMovie *unsortMovies, int *totalRow);

int splitRows(unsortMovie *unsortMovies, int totalRow);

int splitOneRow(unsortMovie *unsortMovies, int currRowNum);

void deleteSpaces(char *oneRow);

void formatQuotesFileds(char *oneRow);

void deleteComma(char *subString);

char **rowIntoFields(char *oneRow);

void checkFirstField(char *tmpString);

void removeFirst(char *str, const char *toRemove);

int main(int agrc, char *argv[]) {
    if (agrc != 3) {
        printf("Format of arguments is incorrect\n");
        return 1;
    }
    if (strcmp(argv[1], "-c") != 0) {
        printf("first argument is incorrect\n");
        return 1;
    }
    char *sortField = argv[2];

    unsortMovie *unsortMovies = malloc(sizeof(unsortMovie) * 100000);
    int totalRow;
    storeRows(unsortMovies, &totalRow);
    splitRows(unsortMovies, totalRow);
    //printf("%s\n",unsortMovies[0].aRowString);
    int i;
    for (i = 0; i < 28; i++) {
        printf("%s\n", unsortMovies[5040].aRowfieldsArray[i]);
    }
//    printf("TotalRows:%d\n", totalRow);
//    int i;
//    for (i = 0; i < totalRow; i++) {
//        printf("%s\n", unsortMovies[i].aRowString);
//    }
//    printf("END");
    free(unsortMovies);

    return 0;
}

int storeRows(unsortMovie *unsortMovies, int *totalRow) {
    *totalRow = 0;
    char *currRow = malloc(sizeof(char) * 50000);
    while (fgets(currRow, 50000, stdin)) {
        currRow[strcspn(currRow, "\n")] = 0;
        unsortMovies[*totalRow].aRowString = malloc(sizeof(char) * 5000);
        strcpy(unsortMovies[*totalRow].aRowString, currRow);
        (*totalRow)++;
    }
    free(currRow);
    return 0;
}

int splitRows(unsortMovie *unsortMovies, int totalRow) {
    int currRowNum;
    for (currRowNum = 0; currRowNum < totalRow; currRowNum++) {
        splitOneRow(unsortMovies, currRowNum);
    }
    return 0;
}

int splitOneRow(unsortMovie *unsortMovies, int currRowNum) {
    char *oneRow = malloc(sizeof(char) * 50000);
    strcpy(oneRow, unsortMovies[currRowNum].aRowString);
    //char* oneRow= unsortMovies[currRowNum].aRowString;
    deleteSpaces(oneRow);
    formatQuotesFileds(oneRow);
    unsortMovies[currRowNum].aRowfieldsArray = rowIntoFields(oneRow);

//    int i;
//    for(i=0;i<28;i++) {
//        printf("%s", unsortMovies[currRowNum].aRowfieldsArray[i]);
//    }
    return 0;
}

void deleteSpaces(char *oneRow) {
    char *i = oneRow;
    char *j = oneRow;
    while (*j != 0) {
        *i = *j++;
        if (*i != ' ')
            i++;
    }
    *i = 0;
}

void formatQuotesFileds(char *oneRow) {
    char *tmpString = malloc(sizeof(char) * 50000);;
    char *token;
    char *beginStr = malloc(sizeof(char) * 50000);
    char *endStr = malloc(sizeof(char) * 50000);
    char *midStr = malloc(sizeof(char) * 50000);

    strcpy(tmpString, oneRow);
    token = strtok(tmpString, "\"");
    strcpy(beginStr, token);
    token = strtok(NULL, "\"");

    if (token) {
        deleteComma(token);
        strcpy(midStr, token);
        token = strtok(NULL, "\"");
        strcpy(endStr, token);

        tmpString[0] = '\0';
        strcat(tmpString, beginStr);
        strcat(tmpString, midStr);
        strcat(tmpString, endStr);
        strcpy(oneRow, tmpString);
    }
    //printf("%s",oneRow);
    free(tmpString);
    free(beginStr);
    free(endStr);
    free(midStr);
}

void deleteComma(char *subString) {
    char *r, *w;
    for (w = r = subString; *r; r++) {
        if (*r != ',') {
            *w++ = *r;
        }
    }
    *w = '\0';
}

char **rowIntoFields(char *oneRow) {
    char **oneRowFields = malloc(sizeof(char *) * 100);
    for (int i = 0; i < 100; i++) {
        oneRowFields[i] = malloc(sizeof(char) * 50000);
    }
    char *tmpString = malloc(sizeof(char) * 5000);
    strcpy(tmpString, oneRow);
    checkFirstField(tmpString);

    char *tmp = malloc(sizeof(char) * 1000);
    char *comma = malloc(sizeof(char) * 100);
    strcpy(comma, ",");
    int i = 0;
    while (sscanf(tmpString, "%[^,],", tmp) != EOF) {
        // printf("OUTPUT:%s\n", tmp);
        removeFirst(tmpString, tmp);
        removeFirst(tmpString, comma);
        checkFirstField(tmpString);
        strcpy(oneRowFields[i], tmp);
        i++;
    }
    free(tmp);
    free(comma);
    free(tmpString);
    return oneRowFields;
}

void checkFirstField(char *tmpString) {
    char firstChar = tmpString[0];
    if (firstChar == ',') {
        char *newRow = malloc(sizeof(char) * 80000);
        strcpy(newRow, "&");
        strcat(newRow, tmpString);
        strcpy(tmpString, newRow);
        free(newRow);
    }

}

void removeFirst(char *str, const char *toRemove) {
    int i, j;
    int len, removeLen;
    int found = 0;

    len = strlen(str);
    removeLen = strlen(toRemove);

    for (i = 0; i < len; i++) {
        found = 1;
        for (j = 0; j < removeLen; j++) {
            if (str[i + j] != toRemove[j]) {
                found = 0;
                break;
            }
        }

        /* If word has been found then remove it by shifting characters  */
        if (found == 1) {
            for (j = i; j <= len - removeLen; j++) {
                str[j] = str[j + removeLen];
            }

            // Terminate from loop so only first occurrence is removed
            break;
        }
    }
}




