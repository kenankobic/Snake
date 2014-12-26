#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

void writeScoreboard(char*, int);
void screen(void);
void menu(void);
void readScoreboard(void);
void deleteScoreboard(void);

int main()
{

    menu();
    return (EXIT_SUCCESS);
}
void writeScoreboard(char* name, int score)
{
    int i;
    FILE *s;
    s = fopen("scoreboard.txt", "a+");
    fprintf(s, "%s ", name);
    fprintf(s, "%d\n", score);
    fclose(s);
    menu();
}

void deleteScoreboard()
{
    system("cls");
    remove("scoreboad.txt");
    FILE *s=fopen("scoreboard.txt", "w");
    printf("Scoreboard successfuly deleted!\n");
    fclose(s);
    system("Pause");
    menu();
}

void readScoreboard()
{
    system("cls");
    char c;
    FILE *sb;
    sb=fopen ("scoreboard.txt" , "r");
    if (sb)
    {
        while ((c = getc(sb)) != EOF)
            putchar(c);
        fclose(sb);
    }
    printf("\nPress any key to return to menu.\n");
    system("Pause");
    menu();
}

void menu()
{
    system("color 0a");
    char choice;
start:
    system("cls");
    printf("Welcome, please choose an option:\n");
    printf("1. Play\n");
    printf("2. View scoreboard\n");
    printf("3. Delete scoreboard\n");
    printf("4. Exit game\n");
    choice=getch();
    switch(choice)
    {
    case '1':
        screen();
        break;
    case '2':
        readScoreboard();
        break;
    case '3':
        deleteScoreboard();
        break;
    case '4':
        printf("\n\tExiting game...\n");
        break;
    default:
        break;
    }
}

void screen()
{
    int i=0, j, x1, y1,w, score, z;
    char m[12][12] = {  " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " " };
    char name[10];
    char ch;
    char s = '*';
    char h='>';
    w = 3;
    char f = '8';
    char prevchoice = '6';
    char choice = '6';
    int x[80];
    int y[80];
    x[0] = 0;
    y[0] = 0;
    x1 = 5;
    y1 = 5;
    z = 250;
    score = 0;
    while (1)
    {
        system("color 0a");
        for (i = w; i > 0; i--)
        {
            x[i] = x[i - 1];
            y[i] = y[i - 1];
            x[1] = x[0];
            y[1] = y[0];
        }
        Sleep(z);
        if (_kbhit())
        {
            prevchoice = choice;
            choice = _getch();
            if(choice=='6' && prevchoice=='4') choice=prevchoice;
            if(choice=='4' && prevchoice=='6') choice=prevchoice;
            if(choice=='8' && prevchoice=='2') choice=prevchoice;
            if(choice=='2' && prevchoice=='8') choice=prevchoice;
            if (choice == '6') h = '>';
            if (choice == '4') h = '<';
            if (choice == '8') h = '^';
            if (choice == '2') h = 'V';
            if (choice != '8' && choice != '6' && choice != '4' && choice != '2') choice = prevchoice;
            if (choice == '6')
            {
                if (y[0] == 11) y[0] = 0;
                else y[0]++;
            }
            else if (choice == '4')
            {
                if (y[0] == 0) y[0] = 11;
                else y[0]--;
            }
            else if (choice == '8')
            {
                if (x[0] == 0) x[0] = 11;
                else x[0]--;
            }
            else if (choice == '2')
            {
                if (x[0] == 11) x[0] = 0;
                else x[0]++;
            }
        }
        else
        {
            if (choice == '6')
            {
                if (y[0] == 11) y[0] = 0;
                else y[0]++;
            }
            else if (choice == '4')
            {
                if (y[0] == 0) y[0] = 11;
                else y[0]--;
            }
            else if (choice == '8')
            {
                if (x[0] == 0) x[0] = 11;
                else x[0]--;
            }
            else if (choice == '2')
            {
                if (x[0] == 11) x[0] = 0;
                else x[0]++;
            }
        }
        m[x1][y1] = f;
        for (i = 0; i < w; i++)
        {
            if(i==0) m[x[i]][y[i]] = h;
            else m[x[i]][y[i]] = s;

        }
        system("cls");
        printf("\t**********\n\t*SCORE:%d*\n\t**********\n", score);
        printf("#------------------------#\n");
        for (i = 0; i < 12; i++)
        {
            printf("|");

            for (j = 0; j < 12; j++)
            {

                printf("%c ", m[i][j]);
            }
            printf("|\n");
        }
        printf("#------------------------#\n");
        if(m[x[0] ][y[0] ] == '*')
        {
            printf("\n\tGAME OVER!\n");
            system("pause");
            system("cls");
            printf("Please enter your name: ");
            for (i = 0; i < 50; i++)
            {
                scanf("%c", &name[i]);
                if(name[i] == '\n')
                {
                    name[i] = '\0';
                    break;
                }
            }
            system("pause");
            writeScoreboard(name, score);
            break;
        }
        for (i = 0; i < w; i++)
        {
            m[x[i]][y[i]] = ' ';

        }
        if (x[0] == x1 && y[0] == y1)
        {
            w++;
            z--;
            score++;
            m[x[0]][y[0]] = ' ';


        for (i=0;i<w;i++)
        {
            while((x1==x[i] && y1==y[i]) || m[x1][y1]=='<' || m[x1][y1]=='>' || m[x1][y1]=='^' || m[x1][y1]=='v')
            {
                x1=rand() % 12;
                y1=rand() % 12;
            }
        }
        }
    }
    menu();
}
