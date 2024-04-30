


// forza 4 (connect 4) with anti-easywin functions
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#define dim 7

typedef struct {
    int righe;
    int colonne;
    char valori[dim][dim];
} tabella;
const char gamer = 'X';
const char compiuter = 'O';
int turno=0;
char risposta;
int  modalita;
char player;


void clrscr();
void turnomio(tabella *tabella1);
void turnomio2(tabella *tabella1);
void posiziona(tabella *tabella1, int colonnaa, char user);
void reset(tabella *tabella1);
void turnocompiuter(tabella *tabella1);
void vincitore(char winner);
char checkwinner(tabella tabella1);
char checkorizz(tabella tabella1);
char checkvertic(tabella tabella1);
char checkdiagonale(tabella tabella1);
int  checkspazi(tabella tabella1);
int  checkwinner2(tabella tabella1);
int  checkorizz2(tabella tabella1);
int  checkvertic2(tabella tabella1);
int  disegno(tabella tabella1);
int  valoriiniziali(tabella *tabella1);


int main(void) {
    tabella tabella1;
    char winner = ' ';
    char risposta;
    turno = 0;
    int aii;
    do {
    turno = 0;
    winner = ' ';
    risposta = ' ';
    valoriiniziali(&tabella1);
    printf("\033[36mWelcum to conect 4!! swag \n");
    disegno(tabella1);
    printf("\n \n \033[36mNow lets get started, type 0 if u against PC, 1 if u against a real player: ");
    scanf("%d", &modalita);
    getchar();
    switch (modalita)   {
        case 0:
        modalita = 0; // against pc
        break;
        case 1:
        modalita = 1; // against player
        break;
        default: 
        printf("\n \033[36mdude tf u typing?? type either 0 or 1 cuh");
        continue;   }
    printf("\n");
    printf("\n \033[0m");
    

    while (winner == ' ' && checkspazi(tabella1) != 0) {
        turno++;
        disegno(tabella1);
        turnomio(&tabella1);
        winner = checkwinner(tabella1);
        if (winner != ' ' || checkspazi(tabella1) == 0) {
            break;          }
        if (modalita == 0) {
            turnocompiuter(&tabella1);
            winner = checkwinner(tabella1);
            if (winner != ' ' || checkspazi(tabella1) == 0) {
                break;          }       }
        else if (modalita == 1) {
            turnomio2(&tabella1);
            winner = checkwinner(tabella1);
            if (winner != ' ' || checkspazi(tabella1) == 0) {
                break;          }       }
    }
    disegno(tabella1);
    vincitore(winner);
    printf("\n\033[36maaa match finished\n");
    reset(&tabella1);
    printf("\n wanna play again? click (S/N) and enter, if u click sometjing else u ded: ");
    scanf("%c", &risposta);
    getchar();
    risposta = toupper(risposta);
    } while (risposta == 'S');
    printf("\n k now frick off\n");
    system("pause");
    return 0;
}

void clrscr() {
    system("@cls||clear");  }

void reset(tabella *tabella1) {
    for (int i=0; i<=7; i++) {
        for (int j=0; j<=7; j++) {
            tabella1->valori[i][j] = ' ';
        }
    }                       }

int disegno(tabella tabella1) {
    int i=0;
    int j=0;
    clrscr();
    printf("\n");//0   1   2   3   4   5   6
    printf("\n \033[31m   CONNECT 4  \033[33m Turn %d - Player: %c \033[0m \n", turno, player);
    printf("     _____________________________  \n");
    printf("    //_A_|_B_|_C_|_D_|_E_|_F_|_G_\\\\ \n");
    printf("  6 || %c | %c | %c | %c | %c | %c | %c || \n", tabella1.valori[6][0], tabella1.valori[6][1], tabella1.valori[6][2], tabella1.valori[6][3], tabella1.valori[6][4], tabella1.valori[6][5], tabella1.valori[6][6]);
    printf("  5 || %c | %c | %c | %c | %c | %c | %c || \n", tabella1.valori[5][0], tabella1.valori[5][1], tabella1.valori[5][2], tabella1.valori[5][3], tabella1.valori[5][4], tabella1.valori[5][5], tabella1.valori[5][6]);
    printf("  4 || %c | %c | %c | %c | %c | %c | %c || \n", tabella1.valori[4][0], tabella1.valori[4][1], tabella1.valori[4][2], tabella1.valori[4][3], tabella1.valori[4][4], tabella1.valori[4][5], tabella1.valori[4][6]);
    printf("  3 || %c | %c | %c | %c | %c | %c | %c || \n", tabella1.valori[3][0], tabella1.valori[3][1], tabella1.valori[3][2], tabella1.valori[3][3], tabella1.valori[3][4], tabella1.valori[3][5], tabella1.valori[3][6]);
    printf("  2 || %c | %c | %c | %c | %c | %c | %c || \n", tabella1.valori[2][0], tabella1.valori[2][1], tabella1.valori[2][2], tabella1.valori[2][3], tabella1.valori[2][4], tabella1.valori[2][5], tabella1.valori[2][6]);
    printf("  1 || %c | %c | %c | %c | %c | %c | %c || \n", tabella1.valori[1][0], tabella1.valori[1][1], tabella1.valori[1][2], tabella1.valori[1][3], tabella1.valori[1][4], tabella1.valori[1][5], tabella1.valori[1][6]);
    printf("  0 ||_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|_%c_|| \n", tabella1.valori[0][0], tabella1.valori[0][1], tabella1.valori[0][2], tabella1.valori[0][3], tabella1.valori[0][4], tabella1.valori[0][5], tabella1.valori[0][6]);
    printf("    || A | B | C | D | E | F | G || \n");
    printf("    \\\\___________________________// \n");
    return 0;                 }


int valoriiniziali(tabella *tabella1) {   // uguale a reset si sn stupid
    int i=0;
    int j=0;
    while (i<7) {
        j=0;
        while (j<7) {
            tabella1->valori[i][j] = ' ';
            j++;
        }
        i++;    }
    return 0;             }


int checkspazi(tabella tabella1) {
    int spazi = 49;
    int i = 0;
    int j = 0;
    for(int i = 0; i < 7; i++)  {
      for(int j = 0; j < 7; j++)  {
         if(tabella1.valori[i][j] != ' ')  {
            spazi--;
         }
       }
    }
    return spazi;            }


char checkwinner(tabella tabella1) {
    int i=0;
    int j=0;
    char winner;
    if (checkorizz(tabella1) != ' ')   {
        return checkorizz(tabella1);  }
    if (checkvertic(tabella1) != ' ')  {
        return checkvertic(tabella1); }
    if (checkdiagonale(tabella1) != ' ') {
        return checkdiagonale(tabella1);}
    return ' ';              }


char checkvertic(tabella tabella1) {
    int i=0;
    int j=0;
    char winner = ' ';
    int puntiPL = 4; // roba inutile
    int puntiPC = 4; // roba inutile
    while (j<7) {
        i=0;
        while (i<7) {
            if (tabella1.valori[i][j] == gamer && tabella1.valori[i+1][j] == gamer && tabella1.valori[i+2][j] == gamer && tabella1.valori[i+3][j] == gamer) {
                puntiPL = 0;
                winner = gamer;
                break;  }
            if (tabella1.valori[i][j] == compiuter && tabella1.valori[i+1][j] == compiuter && tabella1.valori[i+2][j] == compiuter && tabella1.valori[i+3][j] == compiuter) {
                puntiPC = 0;
                winner = compiuter;
                break;  }
            i++;  }
        j++;  }
    return winner;          }


char checkorizz(tabella tabella1) {
    int i=0;
    int j=0;
    char winner = ' ';
    int puntiPL = 4; // roba inutile
    int puntiPC = 4; // roba inutile
    while (i<7) {
        j=0;
        while (j<7) {
            if (tabella1.valori[i][j] == gamer && tabella1.valori[i][j+1] == gamer && tabella1.valori[i][j+2] == gamer && tabella1.valori[i][j+3] == gamer) {
                puntiPL = 0;
                winner = gamer;
                break;  }
            if (tabella1.valori[i][j] == compiuter && tabella1.valori[i][j+1] == compiuter && tabella1.valori[i][j+2] == compiuter && tabella1.valori[i][j+3] == compiuter) {
                puntiPC = 0;
                winner = compiuter;
                break;  }
            j++;  }
        i++;  }
    return winner;         }


char checkdiagonale(tabella tabella1) {
    int i=0;
    int j=0;
    int x=0;
    int y=0;
    int c=7;  // counter, aiuta a far shiftare la diagionale
    char winner = ' ';
    while (x<7 && c>=0) { // cambia diagonale da controllare da A a B e cosi via... |  /////    |
        i=0;                                                    //                  | ///// --> |
        j=0;
        j=(7-c);  // avanza a destra, quindi di colonne
        while (i<7 && j<7) { // partendo dal basso, va più a fondo in alto a destra nella diagonale fino a toccare l'altra estremità della tabella
            if (tabella1.valori[i][j] == gamer && tabella1.valori[i+1][j+1] == gamer && tabella1.valori[i+2][j+2] == gamer && tabella1.valori[i+3][j+3] == gamer) {
                winner = gamer;
                return winner; }
            if (tabella1.valori[i][j] == compiuter && tabella1.valori[i+1][j+1] == compiuter && tabella1.valori[i+2][j+2] == compiuter && tabella1.valori[i+3][j+3] == compiuter) {
                winner = compiuter;
                return winner; }
            i++;
            j++;
        }
        x++;   
        c--;    }
    i=0;
    j=0;
    x=0;
    c=7;
    while (x<7 && c>=0) { 
        i=0;
        j=0;                                    //                          | //    |      /'\ 
        i=(7-c); // avanza in alto, non a destra, quindi di righe           |//     |       |
        while (i<7 && j<7) { 
            if (tabella1.valori[i][j] == gamer && tabella1.valori[i+1][j+1] == gamer && tabella1.valori[i+2][j+2] == gamer && tabella1.valori[i+3][j+3] == gamer) {
                winner = gamer;
                return winner;  }
            if (tabella1.valori[i][j] == compiuter && tabella1.valori[i+1][j+1] == compiuter && tabella1.valori[i+2][j+2] == compiuter && tabella1.valori[i+3][j+3] == compiuter) {
                winner = compiuter;
                return winner;  }
            i++;
            j++;
        }
        x++;
        c--;    }
    i=0;
    j=0;
    x=0;
    c=7;
    while (x<7 && c>=0) { // stessa cosa ma diagonali da alto-sinistra a basso-destra
        i=6;
        j=0;
        j=(7-c);
        while (i>=3 && j<=5) { 
            if (tabella1.valori[i][j] == gamer && tabella1.valori[i-1][j+1] == gamer && tabella1.valori[i-2][j-2] == gamer && tabella1.valori[i-3][j-3] == gamer) {
                winner = gamer;
                return winner;  }
            if (tabella1.valori[i][j] == compiuter && tabella1.valori[i-1][j-1] == compiuter && tabella1.valori[i-2][j-2] == compiuter && tabella1.valori[i-3][j-3] == compiuter) {
                winner = compiuter;
                return winner;  }
            i--;
            j++;
        }
        x++;
        c--;    }
    i=0;
    j=0;
    c=7;
    x=0;
    while (x<7 && c>=0) { 
        i=6;
        j=0;
        i=(7-c); // avanza in alto, non a destra, quindi di righe
        while (i>=3 && j<=5) { 
            if (tabella1.valori[i][j] == gamer && tabella1.valori[i-1][j+1] == gamer && tabella1.valori[i-2][j+2] == gamer && tabella1.valori[i-3][j+3] == gamer) {
                winner = gamer;
                return winner;  }
            if (tabella1.valori[i][j] == compiuter && tabella1.valori[i-1][j+1] == compiuter && tabella1.valori[i-2][j+2] == compiuter && tabella1.valori[i-3][j+3] == compiuter) {
                winner = compiuter;
                return winner;  }
            i--;
            j++;
        }
        x++;
        c--;    }
    return winner;
                  }

void vincitore(char winner) {
    if (winner == gamer) {
        printf("\n \033[36m BRAVO AI VINTP");
    }
    else if (winner == compiuter) {
        printf("\n \033[36m COIONE AI PERSP");
    }
    else {
        printf("\n \033[36m nesuno a vintp...");   }     }

void turnomio(tabella *tabella1) {
    char char_colonna;
    int colonna;
    player = gamer;
    disegno(*tabella1);
   do {
    printf("\n \033[36mChoose the column u wanna put X in: A-B-C-D-E-F-G, (not caps lock if u prefer) and press send\n");
    scanf("%c", &char_colonna);
    getchar();
    switch (char_colonna) {
        case 'A':
        colonna=0;
        break;
        case 'B':
        colonna=1;
        break;
        case 'C':
        colonna=2;
        break;
        case 'D':
        colonna=3;
        break;
        case 'E':
        colonna=4;
        break;
        case 'F':
        colonna=5;
        break;
        case 'G':
        colonna=6;
        break;
        case 'a':
        colonna=0;
        break;
        case 'b':
        colonna=1;
        break;
        case 'c':
        colonna=2;
        break;
        case 'd':
        colonna=3;
        break;
        case 'e':
        colonna=4;
        break;
        case 'f':
        colonna=5;
        break;
        case 'g':
        colonna=6;
        break;
        case '1':
        colonna=0;
        break;
        case '2':
        colonna=1;
        break;
        case '3':
        colonna=2;
        break;
        case '4':
        colonna=3;
        break;
        case '5':
        colonna=4;
        break;
        case '6':
        colonna=5;
        break;
        case '7':
        colonna=6;
        break;
        default:
        printf("\n \033[36mdude tf u typin??, type \"A\" or \"a\" or B/b or C/c or 1/2/3... \n");
        continue;  }
    if (tabella1->valori[6][colonna] != ' ') {
        printf("\n \033[36mdude that spot is already occupied, or it dont even exist cuh\n");  }
    else {
        posiziona(tabella1, colonna, gamer);
        break;
    }
   } while (1); /* (tabella1->valori[riga][colonna] != ' '); */        }



void turnomio2(tabella *tabella1) {
    char char_colonna;
    int colonna;
    player = compiuter;
    disegno(*tabella1);
   do {
    printf("\n \033[36mChoose the column u wanna put X in: A-B-C-D-E-F-G, (not caps lock if u prefer) and press send\n");
    scanf("%c", &char_colonna);
    getchar();
    switch (char_colonna) {
        case 'A':
        colonna=0;
        break;
        case 'B':
        colonna=1;
        break;
        case 'C':
        colonna=2;
        break;
        case 'D':
        colonna=3;
        break;
        case 'E':
        colonna=4;
        break;
        case 'F':
        colonna=5;
        break;
        case 'G':
        colonna=6;
        break;
        case 'a':
        colonna=0;
        break;
        case 'b':
        colonna=1;
        break;
        case 'c':
        colonna=2;
        break;
        case 'd':
        colonna=3;
        break;
        case 'e':
        colonna=4;
        break;
        case 'f':
        colonna=5;
        break;
        case 'g':
        colonna=6;
        break;
        case '1':
        colonna=0;
        break;
        case '2':
        colonna=1;
        break;
        case '3':
        colonna=2;
        break;
        case '4':
        colonna=3;
        break;
        case '5':
        colonna=4;
        break;
        case '6':
        colonna=5;
        break;
        case '7':
        colonna=6;
        break;
        default:
        printf("\n \033[36mdude tf u typin??, type \"A\" or \"a\" or B/b or C/c or 1/2/3... \n");
        continue;  }
    if (tabella1->valori[6][colonna] != ' ') {
        printf("\n \033[36mdude that spot is already occupied, or it dont even exist cuh\n");  }
    else {
        posiziona(tabella1, colonna, compiuter);
        break;
    }
   } while (1); /* (tabella1->valori[riga][colonna] != ' '); */        }


void posiziona(tabella *tabella1, int colonnaa, char user) {
    int i=0;
    int j=0;
    while (i<8) {
        if (tabella1->valori[i][colonnaa] != ' ') {
            i++;    }
        else {
            tabella1->valori[i][colonnaa] = user;
            break;   }
        }       }


void turnocompiuter(tabella *tabella1) {
    int ai;
    srand(time(0));
    int colonne;
    if (checkspazi(*tabella1) > 0) {
        ai=checkwinner2(*tabella1); // controlla se stai per vincere
        if (ai != 10) {
            posiziona(tabella1, ai, compiuter); // ti impedisce di vincere
            return; }
        do {
            colonne = rand() % 6;
        } while (tabella1->valori[6][colonne] != ' ');
        posiziona(tabella1, colonne, compiuter); 
    }
    else {
        vincitore(' ');    }        }


int checkwinner2(tabella tabella1) {  // controllo anti vincita easy
    int i=0;
    int j=0;
    if (checkorizz2(tabella1) != 10)   {
        return checkorizz2(tabella1);  }
    if (checkvertic2(tabella1) != 10)  {
        return checkvertic2(tabella1); }
    return 10;              }
int checkvertic2(tabella tabella1) {
    int i=0;
    int j=0;
    int x=10;
    int y=10;
    while (j<7) {
        i=0;
        while (i<7) {
            if (tabella1.valori[i][j] == gamer && tabella1.valori[i+1][j] == gamer && tabella1.valori[i+2][j] == gamer && tabella1.valori[i+3][j] == ' ') {
                y=j;
                return y;  }
            i++;  }
        j++;  }
    return 10;          }
int checkorizz2(tabella tabella1) {
    int i=0;
    int j=0;
    int x=10;
    int y=10;
    while (i<7) {
        j=0;
        while (j<7) {
            if (tabella1.valori[i][j] == gamer && tabella1.valori[i][j+1] == gamer && tabella1.valori[i][j+2] == gamer && tabella1.valori[i][j+3] == ' ') {
                y=j+3;
                return y;  }
            j++;  }
        i++;  }
    return 10;         }