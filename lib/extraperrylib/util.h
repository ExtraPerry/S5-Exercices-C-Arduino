#ifndef util_h
#define util_h

//Structures
typedef struct s_person { 
    char* name;
    int age;
} t_person;

//Methodes Ex1-8 (Premier Cours).
int isPositiveNumber(int number);

char* fuzbiz(int number);

void all_evens_to(int number);

int is_prime(int number);

int count_char(char* str, char character);

void draw_rectangle(int height, int width, char border, char corner, char inside);

void show_multiple_tables(int number);

void print_person(t_person s_person);

int count_me();

#endif