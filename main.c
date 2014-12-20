#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
void screen(void);
int main()
{

screen();
return 0;
}

void screen()
{
int i, j, x, y, x1, y1,x2,y2,x3,y3, score, z;
char m[20][20] = {" "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "," "};
char s = '*' ;
char a = '*';
char b = '*';

char f = '8';
char prevchoice='6';
char choice='6';
x=0;
y=0;
x1=5;
y1=5;
x2 = 0;
y2 = 0;
z=250;

score=0;
while(1)
{
x3 = x2; y3 = y2;
x2 = x; y2 = y;

Sleep(z);
if (_kbhit()){
prevchoice = choice;
choice = _getch();

if (choice != '8' && choice != '6' && choice != '4' && choice != '2') choice = prevchoice;
if (choice == '6') { if (y == 19) y = 0; else y++; }
else if (choice == '4') { if (y == 0) y = 19; else y--; }
else if (choice == '8') { if (x == 0) x = 19; else x--; }
else if (choice == '2') { if (x == 19) x = 0; else x++; }
}
else{
if (choice == '6') { if (y == 19) y = 0; else y++; }
else if (choice == '4') { if (y == 0) y = 19; else y--; }
else if (choice == '8') { if (x == 0) x = 19; else x--; }
else if (choice == '2') { if (x == 19) x = 0; else x++; }
}

m[x3][y3] = b;
m[x2][y2] = a;
m[x][y]=s;
m[x1][y1]=f;
system("cls");
printf("\t**********\n\t*SCORE:%d*\n\t**********\n", score);
printf("#----------------------------------------#\n");
for (i = 0; i < 20; i++)
{ printf("|");

for (j = 0; j < 20; j++)
{

printf("%c ", m[i][j]);
}
printf("|\n");
}
printf("#----------------------------------------#\n");
m[x][y]=' ';
m[x2][y2] = ' ';
m[x3][y3] = ' ';
if (x==x1 && y==y1) {z--;score++;m[x][y]=' '; x1=rand()%20; y1=rand()%20;}

}



}
