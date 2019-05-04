#include "prototypes.h"
#define LIMIT 90
#define ARRAY_SIZE 4 

int i, first_call = 0;
/*
  This function does not actually cause animation, but merely gives the illusion
  of animation because of the fact that its called rapidly. What this function
  really does is update the screen according to the amount of spaces calculated.
*/

/* Function to simulate animation */
void animate(int horse1, int horse2, int horse3, int horse4, int counter)
{
     /***********************************************************************/
     /* When the static modifier is applied to a local variable,            */ 
     /* permanent storage for the variable is allocated in much             */
     /* the same way that it is for a global variable. This alllows         */
     /* a static variable to maintain its value between function calls.     */
     /***********************************************************************/
     
     static int spaces[ARRAY_SIZE];
            int horse_array[ARRAY_SIZE];
            
            /* Test if function is being called for the first time */
            if(!(first_call))
            {
                for(i = 0; i < ARRAY_SIZE; i++)
                    spaces[i] = 0; /* If function is being called for first time initialize elements in spaces to 0*/
                first_call++;
            }
            
            /* Assign the update value of each horse into horse_array */
            horse_array[0] = horse1;
            horse_array[1] = horse2;
            horse_array[2] = horse3;
            horse_array[3] = horse4;
            
            if (counter==0)
            {
                    
                horse_array[0] = 0;
                horse_array[1] = 0;
                horse_array[2] = 0;
                horse_array[3] = 0;
            }    
                
     
     /* The character variable c is assinged 32 which is the ASCII decimal value for a space */
         
     /*******************************************************************/
     /* The following if test is executed to test if the function       */
     /* is being called for the first time. If the test evaluates to    */
     /* be true then the function initial_position() is called to set   */
     /* horses in starting position before the start of the race.       */  
     /*******************************************************************/
     
     /* 
        If the test evaluates to false (and it will after the function is called 
        the first time), the control_update() function is called to ensure that
        horse's position is not updated after the horse has compeleted the race.
     */     
     
     control_update(spaces, horse_array);
     
     
     printf("\n");
     meter_color();
     printf(" 0m                    100m                 200m                 300m                400m\n");     
                                 
     track_color();
     
     printf("__________________________________________________________________________________________\n\n");
     printf("1");
     /* First the number of spaces are printed followed by the asterix */
     for(i = 0; i <= spaces[0]; i++)
     printf(" ");
     horse_color();
     printf("*\n");
     track_color();
      
     printf("------------------------------------------------------------------------------------------|\n\n");
     printf("2"); 
     for(i = 0; i <= spaces[1]; i++)
     printf(" ");
     horse_color();
     printf("*\n");
     track_color();
     
     printf("------------------------------------------------------------------------------------------|\n\n");
     printf("3");
     for(i = 0; i <= spaces[2]; i++)
     printf(" ");
     
     horse_color();
     printf("*\n");
     track_color();
     
     printf("------------------------------------------------------------------------------------------|\n\n");
     printf("4"); 
     for(i = 0; i <= spaces[3]; i++)
     printf(" ");
     horse_color();
     printf("*\n");
     track_color();
     printf("__________________________________________________________________________________________\n\n");
     
  

}/* End animate */

/* Function to control horse position updating */
void control_update(int calc_space[], int add_array[])
{
   
     for(i = 0; i < ARRAY_SIZE; i++){
          if(calc_space[i] < LIMIT)
           calc_space[i] = calc_space[i] + add_array[i];
         }    
}/* End control_update */    
