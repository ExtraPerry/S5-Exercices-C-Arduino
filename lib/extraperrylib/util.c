#include "util.h"

int isPositiveNumber(int number){
    if (number < 0) {
        printf("Error : Number should be positif (bigger than zero).");
        return -1;
    }
    return 0;
}

char* fuzbiz(int number){
    if (isPositiveNumber(number) != 0) {
        return "";
    }

    if (number%7 == 0 && number%13 == 0) {
        return "fuzbiz";
    }
    if (number%7 == 0) {
        return "fuz";
    }
    if (number%11 == 0) {
        return "biz";
    }
    return "none";
}

void all_evens_to(int number){
    if (isPositiveNumber(number) != 0) {
        return;
    }

    printf("Even numbers below %d : \n", number);
    for (int i = 0; i <= number; ++i) {
        if(i%2 == 0) {
            printf(" - %d", i);
        }
    }
    return;
}

int is_prime(int number) {
    if (isPositiveNumber(number) != 0) {
        return -1;
    }

    for (int i = 2; i < number; i++) {
        if (number%i == 0) {
            return i;
        }
    }
    return 0;
}

int count_char(char* str, char character) {
    int count = 0;
    for(int i = 0; str[i] != '\0'; i++) {
        if (str[i] == character) {
            count++;
        }
    }
    return count;
}

void draw_rectangle(int height, int width, char border, char corner, char inside) {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            if (((j == 0 || j == width-1) && (i == 0 || i == height-1))) {
                printf("%c", corner);
            } else if (((j == 0 || j == width-1) && (i != 0 || i != height-1)) || ((j != 0 || j != width-1) && (i == 0 || i == height-1))) {
                printf("%c", border);
            } else {
                printf("%c", inside);
            }
        }
        printf("\n");
    }
    return;
}

void show_multiple_tables(int number) {
    printf("Table of %d", number);
    printf("\n\n");
    for(int i = 1; i < 10; i++){
        printf("%d x %d = %d", number, i, number * i);
        printf("\n");
    }
    printf("\n\n");
    return;
}

void print_person(t_person s_person) {
    printf("Here is the reciet for %s who is %d years old.", s_person.name, s_person.age);
}

int count_me() {
    static int count = 0;
    count++;
    return count;
}