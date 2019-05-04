/* PROFANITY IS THE ONLY LANGUAGE A PROGRAMMER UNDERSTANDS */
/* Maxx Is Nuts */
/* So is Julius */
/* Melissa thinks we have no life *///This was written by Maxx she meant he has no life
/* It's 3:03am...I think Melissa is right...*///About Max

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h> /* Contains prototype for sleep() function */
#include "prototypes.h"
#include "structures.h"
#define ITERATE 90
#define ARRAY_SIZE 4

int main(int argc, char *argv[])
{
/*-----------------------------------------------------------------------------------------------*/
    int bet_amount=0, bet_horse,hchoice;
    
    if (argc>1)//If this test is true it means that the command line was used.
    {
        if((atoi(argv[1]))==0)//If this is true it means that the argument is not a number
        {
            printf("Argument is not a number.");
            exit(1);
        }
        else if (argc>2)//If this is true it means that there are more than one arguments
        {
            printf("Too Many Arguments.");
            exit(1);
        }
    }    
            
    bet_amount=atoi(argv[1]);//Converts string to an integer and assigns it to bet_amount    
/*-----------------------------------------------------------------------------------------------*/    
    system("color f");
    system("mode con: cols=100 lines=35"); /* set default height and width of screen*/
    srand(time(NULL));
    /***************************VARIABLES**************************************/
    /*counters*/      
    int i;  
    int movecounter;
    int rand_generated[3];
    /*variables for choosing horses*/
    int finish, select[ARRAY_SIZE], select_horse1[ARRAY_SIZE];
    int select_horse2[ARRAY_SIZE], choose_horse1[2], choose_horse2[2];
    int choosen1, choosen2;
    
    /*variable for random numbers generated*/
    int random_num[3];
    
    /*variables for horse's movement*/
    int move1[2]; 
    int move2[2];
    int movementtotal[4];
    /*variables for positional tests and comentry*/
    int done, ldr_result,win_result=0;
    int commentry_select, commentry_selectHorse;
    char commentry_hname[8];
    
     /*Variable initialisation*/
     for(i = 0; i < 4; i++)
    {
        move1[i] = 0;
        move2[i] = 0;
        movementtotal[i] = 0;
    }    
       
    
    /*Function calls to initialise stables and display*/
    horsey1();
    horsey2();

    displayStables();
    

/*******************************************************************************************/
    char option;
        
    printf("Replace horses in one of our stables with 5 of yours?\n");
    printf("Enter [Y] for yes...any other key to continue\n");
    option = getch();
    
    if(option == 'y' || option == 'Y')
    {
    system("cls");
    file_input();    
    system("cls");
    displayStables();
    printf("Stable was successfully replaced\n");
    system("pause");
    system("cls");
    }
        
/*******************************************************************************************/

    

    system("cls");
    system("color f");
    printf("Horses selected for this race: \n\n");
    
    font_color();
    printf("Turkeyen Speedsters\n");
   /* The following two for loops randomly select two horses from each stable */
   /* Randomly Select from stable 1 */
    for(i = 0; i < 2; i++)
    {
    do{
           choose_horse1[i] = rand()%5;
           choosen1 = choose_horse1[i]; 
      select_horse1[i] = random_select_stable1(&horse[choosen1]);
      }while(select_horse1[i] == 1);
    }
   
    printf("\n");
    font_color();
    printf("Berbice Quicksters\n"); 
    
    /* Randomly select from stable 2 */
    for(i = 0; i < 2; i++)
    {
    do{
            choose_horse2[i] = rand()%5;
            choosen2 = choose_horse2[i];
       select_horse2[i] = random_select_stable2(&horse2[choosen2]);
       }while(select_horse2[i] == 1);
    }
    font_color();
    
    /* Function to calculate odds of selected horses */
    printf(" \n");
    calculate_odds(&horse[choose_horse1[0]], &horse[choose_horse1[1]], &horse2[choose_horse2[0]], &horse2[choose_horse2[1]]);
    
    /*Checks if Command Line Arguments were used in executing the program*/
    if (argc>1)
    {
        
        while((hchoice>4)||(hchoice<0))//Validates input.
        {    
            printf("Select the number of the horse you want to place your bet on:");
            scanf("%d", &hchoice);
            
            switch (hchoice)
            {
                case 1: 
                    bet_horse=hchoice;
                    break;
                case 2:
                    bet_horse=hchoice;
                    break;
                case 3:
                    bet_horse=hchoice;
                    break;
                case 4:
                    bet_horse=hchoice;
                    break;
                default:
                    printf("Invalid Number\n");
                    break;
            }        
        }
        
            printf("\nYou Collect your ticket from the teller and cross your fingers.\n");    
                
                  
    }  
    
    printf("\nPress any key to start race ");
    getch();
    
     countdown();//Race Countdown
        
    horse_color();//Function Call to change color
    
    system("cls");
    int h_breed[3];
    
    
    /* Gets breed of horses */
    h_breed[0] = return_breed1(&horse[ choose_horse1[0] ]);
    h_breed[1] = return_breed1(&horse[ choose_horse1[1] ]);
    h_breed[2] = return_breed2(&horse2[ choose_horse2[0] ]);
    h_breed[3] = return_breed2(&horse2[ choose_horse2[1] ]);

        
   for(i = 0; i < ITERATE; i++)
  {         
  
          rand_generated[0] = 1+rand()%20;
          move1[0]=unitsforward1(rand_generated[0],h_breed[0]);
          movementtotal[0]=movementtotal[0]+move1[0];
       
          rand_generated[1] = 1+rand()%20;
          move1[1]=unitsforward1(rand_generated[1],h_breed[1]);
          movementtotal[1]=movementtotal[1]+move1[1];
              
          rand_generated[2] = 1+rand()%20;
          move2[0]=unitsforward2(rand_generated[2],h_breed[2]);
          movementtotal[2]=movementtotal[2]+move2[0];
      
          rand_generated[3] = 1+rand()%20;
          move2[1]=unitsforward2(rand_generated[3],h_breed[1]);
          movementtotal[3]=movementtotal[3]+move2[1];
              

          
           if (i == 0)
          {
              movementtotal[0] = 0;
              movementtotal[1] = 0;
              movementtotal[2] = 0;
              movementtotal[3] = 0;
              animate(0, 0, 0, 0,i); //Function called to set horses to start position
              system("cls");
          }
 
              animate(move1[0], move1[1], move2[0], move2[1],i);
                      
              /* prints horses selected from each stable */ 
              print_selected1(&horse[ choose_horse1[0] ], &horse[ choose_horse1[1] ]);
              print_selected2(&horse2[ choose_horse2[0] ], &horse2[ choose_horse2[1] ]);
              printf(" \n");  
            
   
          //Functuon called to check if all horses have finished the race 
          done=finishtest(movementtotal[0],movementtotal[1],movementtotal[2],movementtotal[3]);
         
          
          
          ldr_result=leader(movementtotal[0],movementtotal[1],movementtotal[2],movementtotal[3]);
          
          
          /**********************************************************************************/
          /*If win_resuly is anything other than 0 that means that the race has already been*/
          /*won and therefore there is no need to run this function again since the winner  */ 
          /*has already been declared                                                       */
          /**********************************************************************************/  
         
          if (win_result==0)
          {
              win_result=winner(movementtotal[0],movementtotal[1],movementtotal[2],movementtotal[3]);
              
              if (win_result==0)
              {
                  commentry_select=1+rand ()%2;
                  switch(commentry_select)
                  {
                      case 1:
                          {
                              commentry_leader(ldr_result, i);//Function called to do commentry--state position
                              break;
                          }    
                      case 2:
                          {
                              if (i>0)
                              {
                                  commentry_selectHorse=1+rand ()%4;
                                  switch(commentry_selectHorse)
                                  {
                                      case 1:
                                          {
                                              strcpy(commentry_hname, "Horse 1" );
                                              commentry_event(move1[0],commentry_hname);
                                              break;
                                          }
                                      case 2:
                                          {
                                              strcpy(commentry_hname, "Horse 2" );
                                              commentry_event(move1[1], commentry_hname);
                                              break;
                                          }
                                      case 3:
                                          {
                                              strcpy(commentry_hname, "Horse 3" );
                                              commentry_event(move2[0], commentry_hname);
                                              break;
                                          }
                                      case 4:
                                          {
                                              strcpy(commentry_hname, "Horse 4" );
                                              commentry_event(move2[1], commentry_hname);
                                              break;
                                          }
                                  }
                                                      
                                  break;
                              }
                          }    
                  }
                          
              }
          }    

          else
          {
              commentry_winner(win_result);
          } 
          //getch();
     
          sleep(900);   //suspends program for 0.9 seconds
             
          if (done == 1)/* Used to stop the last clearing of the screen */
              break;
          
          else   
              system("cls"); 

                       
  }/* End for */

  if (argc>1)
  bet1(bet_horse,win_result,bet_amount,h_breed[win_result-1]);

  printf("The Race is over.\n");
  system("pause");
  
 
  return 0;
}/* End main */
