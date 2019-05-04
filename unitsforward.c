#include "structures.h"

int unitsforward1(int random_number,int horsebreed)
{
    

        switch(horsebreed)
        {
            case 2:
                {
                    
                    if ((random_number >= 1 )&&( random_number <=9))
                    {
                        return 6;
                    }
                    else if ((random_number >9 )&& (random_number <=14))
                    {
                        return 2;
                    }
                    else if ((random_number >14 )&& (random_number <=18))
                    {
                        return 3;
                    }
                    else
                        return 1;
                        
                    break;
                }
             case 1:
                 {
                     if ((random_number >= 1) && (random_number <=7))
                    {
                        return 6;
                    }
                    else if ((random_number >7) && (random_number <=13))
                    {
                        return 2;
                    }
                    else if ((random_number >13) && (random_number <=17))
                    {
                        return 3;
                    }
                    else
                        return 1;
                    
                    break;
                 }
             case 3:
                 {
                     if ((random_number >= 1 && random_number <=10))
                    {
                        return 6;
                    }
                    else if ((random_number >10 && random_number <=14))
                    {
                        return 2;
                    }
                    else if ((random_number >14 && random_number <=19))
                    {
                        return 3;
                    }
                    else
                        return 1;
                    
                    break;
                 }
             }
           
}            



int unitsforward2(int random_number,int horsebreed)
{
    

      
        switch( horsebreed)
        {
            case 2:
                {
                    
                    if ((random_number >= 1 )&&( random_number <=9))
                    {
                        return 6;
                    }
                    else if ((random_number >9 )&& (random_number <=14))
                    {
                        return 2;
                    }
                    else if ((random_number >14 )&& (random_number <=18))
                    {
                        return 3;
                    }
                    else
                        return 1;
                        
                    break;
                }
             case 1:
                 {
                     if ((random_number >= 1) && (random_number <=7))
                    {
                        return 6;
                    }
                    else if ((random_number >7) && (random_number <=13))
                    {
                        return 2;
                    }
                    else if ((random_number >13) && (random_number <=17))
                    {
                        return 3;
                    }
                    else
                        return 1;
                        
                    break;    
                 }
             case 3:
                 {
                     if ((random_number >= 1) &&( random_number <=10))
                    {
                        return 6;
                    }
                    else if ((random_number >10) &&( random_number <=14))
                    {
                        return 2;
                    }
                    else if ((random_number >14 )&& (random_number <=19))
                    {
                        return 3;
                    }
                    else
                        return 1;
                        
                    break;
                 }
             }
             
} 

