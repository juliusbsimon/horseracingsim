/* Contains function prototypes for functions used */

void animate(int horse1, int horse2, int horse3, int horse4,int counter);

void initial_position(int position[]);

void control_update(int calc_space[], int add_array[]);

int generate();
void horsey1();
void horsey2();
void file_input();
int finishtest(int mov1, int mov2,int mov3,int mov4);
int winner(int mov1, int mov2,int mov3,int mov4);
void race_stable(int choice);
void race_stable2();
void bet1(int chosen, int winner, int money, int breed);
void displayStables();
 
/* COLORS*/
void horse_color();
void commentrycolor();
void track_color();
void font_color();
void countdown();
void countcolor1();
void countcolor2();
void countcolor3();
void meter_color();

/*Commentry Functions*/
int leader(int h_pos1, int h_pos2, int h_pos3, int h_pos4);
void commentry_leader(int frnt_runner,int loopcount);
void commentry_event(int event,char hname[8]);
void commentry_winner (int win);
