//IF YOU DONT LIKE IF STATEMENTS DO NOT READ ANY THING ELSE IN THIS FILE

void commentry_leader(int front,int loopcount)
{
    commentrycolor();//Fuction called to change color of commentry
    
    if (!(loopcount))
    {
        printf("AND THEY'RE OFF!!!!\n");
    }
    else
    {
        switch(front)
        {
            case 1:
                printf("Horse 1 is in the lead\n" );
                break;
            case 2:
                printf("Horse 2 is in the lead\n");
                break;
            case 3:
                printf("Horse 3 is in the lead\n");
                break;
            case 4:
                printf("Horse 4 is in the lead\n");
                break;
            case 5:
                printf("The Race is Tied\n");
                break;
            default:
                printf("Too Close to Call");
                break;
        }    
              
    }    
       
}

void commentry_event(int event, char hname[8])
{
    countcolor1();
    switch (event)
    {
        case 6:
            {
                printf("%s has performed a fast plod", hname);
                break;
            }    
        case 2:
            {
                printf("OH NO!!! %s has slipped",hname); 
                break;
            }
        case 3:
            {
                printf("%s seems to be jogging, does he know this is a race??",hname);
                break;
            }
        case 1:
            {
                printf("%s has yielded", hname);
                break;
            }
        //default:
                //printf("JUST WTF IS THIS HORSE DOING!!!???\n"); /* This is funny ha ha */
        
    }        
}    

void commentry_winner(int win)
{
    commentrycolor();
    
    switch(win)
    {
        case 1:
            printf("Horse 1 has Won the race!\n" );
            break;
        case 2:
            printf("Horse 2 has Won the race!\n");
            break;
        case 3:
            printf("Horse 3 has Won the race!\n");
            break;
        case 4:
            printf("Horse 4 has Won the race!\n");
            break;
        default:
            break;
    }
}        
            
             
/*
The first thing we do in this function is test to see which horse has the lead 
position, this part is simple since all we have to do is test all the positions 
and check which is largest. to do this we compare the values of each horse, with 
all the other horses, if the horse 1's position is higher than the others it will
be the front runner, if not we move to horse 2 and so on.

Any other result condition would result in the race being tied.
*/

int leader(int h_pos1, int h_pos2, int h_pos3, int h_pos4)
{
       
    if ((h_pos1 > h_pos2 )&& (h_pos1 > h_pos3) && (h_pos1 > h_pos4))
    {
        return 1;
    }    
    
    else if ((h_pos2 > h_pos1) && (h_pos2 > h_pos3) && (h_pos2 > h_pos4))
    {
        return 2;
    }    
    
    else if ((h_pos3 > h_pos1) && (h_pos3 > h_pos2) && (h_pos3 > h_pos4))
    {
        return 3;
    }    
    
    else if ((h_pos4 > h_pos1) && (h_pos4 > h_pos2) && (h_pos4 > h_pos3))
    {
        return 4; 
    }
     
    else
    {
        return 5;
    }
        

}
