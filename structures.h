#include "prototypes.h"

struct Stable1
{
    char name[11];   
    int stamina;
    int breed;
    int trainer;
    int select;
    int total;
    int age;
  
};  

struct Stable2
{
    char name[11];   
    int stamina;
    int breed;
    int trainer;
    int select;
    int total;
    int age;
};
struct Stable1 horse[5];
struct Stable2 horse2[5];

/* Function Prototypes */
int random_select_stable1(struct Stable1 *ptr);
int random_select_stable2(struct Stable2 *ptr);
void calculate_odds(struct Stable1 *ptr1, struct Stable1 *ptr2, struct Stable2 *ptr3, struct Stable2 *ptr4);
void print_selected1(struct Stable1 *ptr1, struct Stable1 *ptr2);
void print_selected2(struct Stable2 *ptr3, struct Stable2 *ptr4);
int breed_selected1(struct Stable1 *ptr);
int breed_selected2(struct Stable2 *ptr);
int return_breed1(struct Stable1 *ptr);
int return_breed2(struct Stable2 *ptr);
