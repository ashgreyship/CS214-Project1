#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Sorter.h"
#include "mergesort.c"


int main(int agrc, char *argv[]) {
    if (agrc != 3) {
        printf("argument are incorrect\n");
        return 1;
    }
    if (strcmp(argv[1], "-c") != 0) {
        printf("first argument is incorrect\n");
        return 1;
    }


    int n = 0;
    char **lines = (char **) malloc(sizeof(char *) * 100000);
    char *oneLine = malloc(sizeof(char) * 50000);
    int totalLines = 0;
    while (fgets(oneLine, 50000, stdin)) {
        oneLine[strcspn(oneLine, "\n")] = 0;
        lines[totalLines] = (char *) malloc(sizeof(char) * 50000);
        strcpy(lines[totalLines], oneLine);
        totalLines++;
        oneLine = realloc(oneLine, sizeof(char) * 50000);
    }
    free(oneLine);



    unsortMovie *unsortMovies = malloc(sizeof(unsortMovie) * totalLines);
    int currLine;
    for (currLine = 0; currLine < totalLines; currLine++) {
        char *curr = malloc(sizeof(char) * 50000);;
        char **oneFilmArray = malloc(sizeof(char *) * 10000);

        int type;
        for (type = 0; type < 28; type++) {
            oneFilmArray[type] = (char *) malloc(sizeof(char) * 100);
        }

        curr = lines[currLine];
        char *token = strtok(curr, ",");
        int i = 0;

        while (token != NULL) {
            oneFilmArray[i] = token;
            token = strtok(NULL, ",");
            i++;
        }

//        unsortMovies[currLine].color = oneFilmArray[0];
//        unsortMovies[currLine].director_name = oneFilmArray[1];
//        unsortMovies[currLine].num_critic_for_reviews = atoi(oneFilmArray[2]);
//        unsortMovies[currLine].duration = atoi(oneFilmArray[3]);
//        unsortMovies[currLine].director_facebook_likes = atoi(oneFilmArray[4]);
//        unsortMovies[currLine].actor_3_facebook_likes = atoi(oneFilmArray[5]);
//        unsortMovies[currLine].actor_2_name = oneFilmArray[6];
//        unsortMovies[currLine].actor_1_facebook_likes = atoi(oneFilmArray[7]);
//        unsortMovies[currLine].gross = atoi(oneFilmArray[8]);
//        unsortMovies[currLine].genres = oneFilmArray[9];
//        unsortMovies[currLine].actor_1_name = oneFilmArray[10];
//        unsortMovies[currLine].movie_title = oneFilmArray[11];
//        unsortMovies[currLine].num_voted_users = atoi(oneFilmArray[12]);
//        unsortMovies[currLine].cast_total_facebook_likes = atoi(oneFilmArray[13]);
//        unsortMovies[currLine].actor_3_name = oneFilmArray[14];
//        unsortMovies[currLine].facenumber_in_poster = atoi(oneFilmArray[15]);
//        unsortMovies[currLine].plot_keywords = oneFilmArray[16];
//        unsortMovies[currLine].movie_imdb_link = oneFilmArray[17];
//        unsortMovies[currLine].num_user_for_reviews = atoi(oneFilmArray[18]);
//        unsortMovies[currLine].language = oneFilmArray[19];
//        unsortMovies[currLine].country = oneFilmArray[20];
//        unsortMovies[currLine].content_rating = oneFilmArray[21];
//        unsortMovies[currLine].budget = atoi(oneFilmArray[22]);
//        unsortMovies[currLine].title_year = atoi(oneFilmArray[23]);
//        unsortMovies[currLine].actor_2_facebook_likes = atoi(oneFilmArray[24]);
//        unsortMovies[currLine].imdb_score = atoi(oneFilmArray[25]);
//        unsortMovies[currLine].aspect_ratio = atoi(oneFilmArray[26]);
//        unsortMovies[currLine].movie_facebook_likes = atoi(oneFilmArray[27]);

        free(curr);
    }


    return 0;
}
