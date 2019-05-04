/* QUITE POSSIBLY THE MOST ABUSED FILE */
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "textcolor.h"
#include "prototypes.h"
#include "structures.h"

#define TRACKLENGTH 90 //defines the length of the virual track
#define ARRAY_SIZE 4  
#define SIZE 80  
    

int finishtest(int mov1, int mov2,int mov3,int mov4)
{
    int returnval;

   //Tests Totals to see whether horse reacehes end of track   
    if (mov1>=TRACKLENGTH && mov2>=TRACKLENGTH && mov3>= TRACKLENGTH && mov4>=TRACKLENGTH)
      {
          returnval = 1;
      }    
    else
          returnval = 0;
 
    return returnval;     
} 

int winner(int mov1, int mov2,int mov3,int mov4)
{
    
    if (mov1>=TRACKLENGTH)
    return 1;
    
    else if (mov2>=TRACKLENGTH)
    return 2;
    
    else if (mov3>=TRACKLENGTH)
    return 3;
    
    else if (mov4>=TRACKLENGTH)
    return 4;
    
    else 
    return 0;
    
        
}   
 
void horsey1 ()
{
        strcpy(horse[0].name, "Gforce");
        horse[0].stamina = 3;
        horse[0].trainer = 5;
        horse[0].select = 0;
        horse[0].breed = 3;
        horse[0].age = 5;
               

        strcpy(horse[1].name, "Speedy");
        horse[1].stamina = 1;
        horse[1].trainer = 3;
        horse[1].select = 0;
        horse[1].breed = 1;
        horse[1].age = 6;
       

        strcpy(horse[2].name, "Lightening");
        horse[2].stamina = 3;
        horse[2].trainer = 3;
        horse[2].select = 0;
        horse[2].breed = 2;
        horse[2].age = 4;
       

        strcpy(horse[3].name, "Daisy");
        horse[3].stamina = 2;
        horse[3].trainer = 3;
        horse[3].select = 0;
        horse[3].breed = 2;
        horse[3].age = 7;
        

        strcpy(horse[4].name, "Malo");
        horse[4].stamina = 2;
        horse[4].trainer = 5;
        horse[4].select = 0;
        horse[4].breed = 2;
        horse[4].age = 9;
        
        int i;
        for(i = 0; i <= ARRAY_SIZE; i++)
        {
            horse[i].total = horse[i].stamina + horse[i].trainer + horse[i].breed;
        }    
            
}

void horsey2()
{    
        
        strcpy(horse2[0].name, "Majestic");
        horse2[0].stamina = 2;
        horse2[0].trainer = 5;
        horse2[0].select = 0;
        horse2[0].breed = 3;
        horse2[0].age = 8;
        

        strcpy(horse2[1].name, "Slowpoke");
        horse2[1].stamina = 2;
        horse2[1].trainer = 3;
        horse2[1].select = 0;
        horse2[1].breed = 1;
        horse2[1].age = 5;
        
        
        strcpy(horse2[2].name, "Flash");
        horse2[2].stamina = 2;
        horse2[2].trainer = 3;
        horse2[2].select = 0;
        horse2[2].breed  = 2;
        horse2[2].age = 7;

        strcpy(horse2[3].name, "Deceiver");
        horse2[3].stamina = 2;
        horse2[3].trainer = 5;
        horse2[3].select = 0;
        horse2[3].breed = 1;
        horse2[3].age = 6;
      
       

        strcpy(horse2[4].name, "Ethernal");
        horse2[4].stamina = 3;
        horse2[4].trainer = 3;
        horse2[4].select = 0;
        horse2[4].breed = 2;
        horse2[4].age = 3;
       
        
        int i;
        for(i = 0; i <= ARRAY_SIZE; i++)
        {
            horse2[i].total = horse2[i].stamina + horse2[i].trainer + horse2[i].breed;
        }    
            
}

 

int random_select_stable1(struct Stable1 *ptr)
{
               textcolor(LIGHTGREEN);
               
              
               if(ptr->select != 1)
                {
                    printf("Name: %s \n", ptr->name);
                    ptr->select = 1;
                    return 0;
                }
                return 1;
}    

int random_select_stable2(struct Stable2 *ptr)
{
              textcolor(LIGHTGREEN);
               
               if(ptr->select != 1)
                {
                    printf("Name: %s \n", ptr->name);
                    ptr->select = 1;
                    return 0;
                }
                return 1;
}   

void calculate_odds(struct Stable1 *ptr1, struct Stable1 *ptr2, struct Stable2 *ptr3, struct Stable2 *ptr4)
{
   
   float probability1, probability2, probability3, probability4;
   float overallTotal = 0; 
   
   probability1 = probability2 = probability3 = probability4 = 0;
     
   overallTotal = ptr1->total + ptr2->total + ptr3->total + ptr4->total;
   probability1 = (ptr1->total / overallTotal) * 100;
   probability2 = (ptr2->total / overallTotal) * 100;
   probability3 = (ptr3->total / overallTotal) * 100;
   probability4 = (ptr4->total / overallTotal) * 100;
   textcolor(WHITE);
   printf("       Two (2) Horses from each stable will now be randomly selected,\n"); 
   printf("          Thereby facilitating the occupation of the 4 racing lanes\n\n"); 
   printf(" *NOTE-  Breed 1: Paint \t Breed 2: Arabian \t Breed 3: Thoroughbred\n"); 
   textcolor(YELLOW);
   printf("----------------------------------------------------------------------------- \n");
   printf("Horse   Prob. of a win   Stable   Breed   Age   Stamina   Trainer   Horse   \n");
   printf("  No.     in this race                                               Name    \n");   
   printf("----------------------------------------------------------------------------- \n");
   textcolor(LIGHTGREEN);
   printf("  1         %.2f%%         1        %d      %d       %d        %d       %s\n",
   probability1, ptr1->breed,ptr1->age, ptr1->stamina, ptr1->trainer, ptr1->name);
   printf("  2         %.2f%%         1        %d      %d       %d        %d       %s\n",
   probability2, ptr2->breed,ptr2->age, ptr2->stamina, ptr2->trainer, ptr2->name);
   printf("  3         %.2f%%         2        %d      %d       %d        %d       %s\n",
   probability3, ptr3->breed,ptr3->age, ptr3->stamina, ptr3->trainer, ptr3->name);
   printf("  4         %.2f%%         2        %d      %d       %d        %d       %s\n",
   probability4, ptr4->breed,ptr4->age,ptr4->stamina, ptr4->trainer, ptr4->name);
   textcolor(YELLOW);
   printf("----------------------------------------------------------------------------- \n");
   textcolor(WHITE);
}  

/* 
   Functions print_selected1 and print_selected2 cycle through
   each horse object and testing their select value. If the value
   is 1 it means the horse was selected and hence it's name is printed.
   print_selected1 checks Stable1 and print_selected2 checks Stable2.
*/
void print_selected1(struct Stable1 *ptr1, struct Stable1 *ptr2)
{
    textcolor(LIGHTRED);
    textbackground(BLACK);

        printf("Breed: %d\t\tLane: 1\t\tName: %s\n",ptr1->breed, ptr1->name);
        printf("Breed: %d\t\tLane: 2\t\tName: %s\n",ptr2->breed, ptr2->name);

}

void print_selected2(struct Stable2 *ptr3, struct Stable2 *ptr4)
{
    textcolor(LIGHTRED);
    textbackground(BLACK);
        printf("Breed: %d\t\tLane: 3\t\tName: %s\n",ptr3->breed, ptr3->name);
        printf("Breed: %d\t\tLane: 4\t\tName: %s\n",ptr4->breed, ptr4->name);
        textcolor(WHITE);
        printf("\nBreed 1: Paint   \t Breed 2: Arabian \t Breed 3: Thoroughbred\n"); 
}

void file_input()
{
    
    
    int stableOption = 0;
    
   
    printf("Choose stable to replace\n");
    printf("1.\tStable 1\n2.\tStable 2\n3.\tQuit\n");
    scanf("%d", &stableOption);
   
   
    switch(stableOption)
    {
        
         case 1:
             {
                 race_stable(1);
                 break;
             }
         case 2:
             {
                 race_stable(2);
                 break;
             }
         case 3:
             {
                 system("pause");
                 exit(1);
             }    
         default:
             {
                 textcolor(LIGHTRED);
                 system("cls");
                 printf("Incorrect choice.\n");
                 textcolor(WHITE);
                 file_input(); /* Recursive function call */
             }
     }                    
            
  
              
} /* end file_input */

  
void race_stable(int choice)
{
    FILE *fp;
    int x , quit;
    
    char data[SIZE], fileName[256];
    
    x = quit = 0; /* Inatialize variables to zero */
    
    while(1)
    {
        printf("Enter file name with extention\n");
        printf("1 to quit: ");
        scanf("%s", fileName);
        
        quit = atoi(fileName);
        
        if(quit == 1)
            exit(1);
        
        fp = fopen(fileName, "r");

        if(fp == NULL)
        {
            textcolor(LIGHTRED);
            system("cls");
            printf("Error opening file!\n");
            textcolor(WHITE);
        }
        
        else
            break; //break out of infinite loop 
    }
    /*NOTE when new horses are scanned into structure the totals of the previous 
    initialized horse are not replaced therefore these totals must also be 
    scanned in from the file*/
    if(choice == 1)
    {
    while( (fgets(data, SIZE, fp)) != NULL ) 
    {
        fscanf(fp, "%s %d %d %d %d %d %d", horse[x].name, &horse[x].stamina, &horse[x].trainer, 
        &horse[x].select, &horse[x].breed, &horse[x].age,&horse[x].total); 
        x++;
    } 
    
    }
    
    else
    {
        while( (fgets(data, SIZE, fp)) != NULL ) 
         {
           fscanf(fp, "%s %d %d %d %d %d %d", horse2[x].name, &horse2[x].stamina, &horse2[x].trainer, 
           &horse2[x].select, &horse2[x].breed, &horse2[x].age, &horse2[x].total); 
           x++;
         } 
    }
    fclose(fp); //close file after reading

}/* end race_stable */

void bet1(int chosen, int winner, int money, int breed)
{
    int winnings = 0,pocket;
    switch (breed)
    {
        case 1:
            winnings=(money*4);
            pocket=winnings-money;
            break;
        case 2:
            winnings=(money*3);
            pocket=winnings-money;
            break;
        case 3:
            winnings=(money*2);
            pocket=winnings-money;
            break;
    }    
    if (chosen==winner)
    {
        switch(winner)
        {
            case 1:
                printf("Horse 1 has earned you $%d,\nYou pocket off the extra $%d.\n", winnings,pocket);
                break;
            case 2:
                printf("Horse 2 has earned you $%d,\nYou pocket off the extra $%d.\n", winnings,pocket);
                break;
            case 3:
                printf("Horse 3 has earned you $%d,\nYou pocket off the extra $%d.\n", winnings,pocket);
                break;
            case 4:
                printf("Horse 4 has earned you $%d,\nYou pocket off the extra $%d.\n", winnings,pocket);
                break;
        }
    }
    else
        printf("You Lost $%d. You Throw Your hands up in the air and head towards \nthe stables to have a word with the jockey who rode the horse you bet on.\n", money);

    
} 

void displayStables()
{
   int i;
   
   
   printf("Stable 1");
   textcolor(YELLOW);
   printf("       \t\t\t\t\t\t| Breed 1: Paint\n");
   printf("  -------------------------------------------------\t| Breed 2: Arabian\n");
   printf("  Breed   Age   Stamina   Trainer     Horse Name   \t| Breed 3: Thoroughbred\n");
   printf("  ------------------------------------------------- \n");
   textcolor(LIGHTGREEN);
   for(i = 0; i < 5; i++)
   { 
     printf("    %d      %d       %d        %d          %s\n", horse[i].breed, 
            horse[i].age, horse[i].stamina, horse[i].trainer, horse[i].name);
   }
   textcolor(YELLOW);
   printf("  ------------------------------------------------- \n\n");
   textcolor(WHITE);
   printf("Stable 2\n");
   textcolor(YELLOW);
   printf("  ------------------------------------------------- \n");
   printf("  Breed   Age   Stamina   Trainer     Horse Name   \n");
   printf("  ------------------------------------------------- \n");
   textcolor(LIGHTGREEN);
   for(i = 0; i < 5; i++)
   { 
     printf("    %d      %d       %d        %d          %s\n", horse2[i].breed, 
            horse2[i].age, horse2[i].stamina, horse2[i].trainer, horse2[i].name);
   }
   textcolor(YELLOW);
   printf("  ------------------------------------------------- \n\n");
}     
                      
/*COLOR FUNCTIONS*/
void commentrycolor()
{
    textcolor(LIGHTMAGENTA);
}    
    
void countcolor1()
{
    textcolor(LIGHTRED);  
}

void countcolor2()
{
    textcolor(YELLOW);  
}

void countcolor3()
{
    textcolor(LIGHTGREEN);   
}

    

void horse_color()
{
     textcolor(YELLOW);
}

void track_color()
{
     textcolor(LIGHTGREEN);
     textbackground(BLACK);
}

void font_color()
{
     textcolor(YELLOW);
}

void meter_color()
{
     textcolor(WHITE);
}
/*END COLOR FUNCTIONS*/

void countdown()
{
  
  
  countcolor1();//Function Call to change color
  
  system("cls");
 printf("\n\t\t\t   33333333333333\n");
   printf("\t\t\t    333333333333 \n"); 
   printf("\t\t\t            333  \n");
   printf("\t\t\t           333   \n");
   printf("\t\t\t        33333    \n");
   printf("\t\t\t      3333333    \n");
   printf("\t\t\t        33333    \n");
   printf("\t\t\t          333    \n");
   printf("\t\t\t           333   \n");
   printf("\t\t\t            333  \n");
   printf("\t\t\t    333333333333 \n");
   printf("\t\t\t   33333333333333\n\n\n\n");
  sleep(1000);
  system("cls");
  
  countcolor2();//Function Call to change color
  
  system("cls");
 printf("\n\t\t\t    222222222222 \n");
   printf("\t\t\t   22222222222222\n"); 
   printf("\t\t\t   22        222 \n");
   printf("\t\t\t            222  \n");
   printf("\t\t\t           222   \n");
   printf("\t\t\t          222    \n");
   printf("\t\t\t         222     \n");
   printf("\t\t\t        222      \n");
   printf("\t\t\t       222       \n");
   printf("\t\t\t      2222      \n");
   printf("\t\t\t    2222222222222\n");
   printf("\t\t\t   22222222222222\n\n\n\n"); 
  sleep(1000);
  system("cls");
  
  countcolor3();//Function Call to change color
  
  system("cls");  
 printf("\n\t\t\t       111111    \n");
   printf("\t\t\t     11111111    \n"); 
   printf("\t\t\t   1111   111    \n");
   printf("\t\t\t   111    111    \n");
   printf("\t\t\t          111    \n");
   printf("\t\t\t          111    \n");
   printf("\t\t\t          111    \n");
   printf("\t\t\t          111    \n");
   printf("\t\t\t          111    \n");
   printf("\t\t\t          111    \n");
   printf("\t\t\t      1111111111 \n");
   printf("\t\t\t   111111111111111\n\n\n\n");
  sleep(1000);
  
  system("cls");
 printf("\n\t\t    GGGGGGGGGG          OOOOOOOOOOO           !!!            \n");
   printf("\t\t   GGGGGGGGGGG         OOOOOOOOOOOOO          !!!            \n"); 
   printf("\t\t   GGG                 OOO       OOO          !!!            \n");
   printf("\t\t   GGG                 OOO       OOO          !!!            \n");
   printf("\t\t   GGG                 OOO       OOO          !!!            \n");
   printf("\t\t   GGG                 OOO       OOO          !!!            \n");
   printf("\t\t   GGG     GGGGGGGG    OOO       OOO          !!!            \n");
   printf("\t\t   GGG      GGGGGG     OOO       OOO          !!!            \n");
   printf("\t\t   GGG       GGG       OOO       OOO          !!!            \n");
   printf("\t\t   GGG       GGG       OOO       OOO                         \n");
   printf("\t\t   GGGGGGGGGGGGG       OOOOOOOOOOOOO          !!!            \n");
   printf("\t\t    GGGGGGGGGGG         OOOOOOOOOOO           !!!            \n\n\n\n");
  sleep(1000);
  system("cls");
  
}


int return_breed1(struct Stable1 *ptr)
{
    return ptr->breed;
}   

int return_breed2(struct Stable2 *ptr)
{
    return ptr->breed;
}      

