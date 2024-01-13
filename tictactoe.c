#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>


char  board[3][3];
const char PLAYER_1 = 'X';
const char PLAYER_2 = 'O';

void resetBoard();
void printBoard();
void player1Move();
void player2Move();
int checkFreeSpaces();
char checkWinner();
void printWinner(char);


void main()
{
  char winner = ' ';
  
resetBoard();
while(winner == ' ' && checkFreeSpaces() != 0){
  printBoard();

  player1Move();
  winner = checkWinner();
  if(winner != ' ' || checkFreeSpaces() == 0){
    break;
  }
  printBoard();

  player2Move();
  winner = checkWinner();
  if(winner != ' ' || checkFreeSpaces() == 0){
    break;
  }
}

 printBoard();
 printWinner(winner);
  


}
   

void printBoard()
{
   printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
   printf("\n---|---|---\n");
   printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
   printf("\n");
}

  void resetBoard(){
   for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
         board[i][j] = ' ';
      }
   }
  }

void player1Move(){
  int x, y;
  printf("PLAYER 1 MOVE (X)");
   do
   {
      printf("\nEnter row : ");
      scanf("%d", &x);
      x--;
      printf("Enter column : ");
      scanf("%d", &y);
      y--;

      if(board[x][y] != ' '){
         printf("INVALID MOVE!\n");
      }
      else{
         board[x][y] = PLAYER_1;
         break;
      }
   } 
   while (board[x][y] != ' ');
   
}



void player2Move(){
  int x, y;
  printf("PLAYER 2 MOVE (O)");
   do{
      printf("\nEnter row : ");
      scanf("%d", &x);
      x--;
      printf("Enter column : ");
      scanf("%d", &y);
      y--;

      if(board[x][y] != ' '){
         printf("INVALID MOVE!\n");
      }
      else{
         board[x][y] = PLAYER_2;
         break;
      }
   } 
   while (board[x][y] != ' ');
}

int checkFreeSpaces(){
  int freeSpaces = 9;

  for(int i = 0; i < 3; ++i){
    for(int j = 0; j < 3; ++j){
       if (board[i][j] != ' '){
        freeSpaces--;
       }
  }
  }

return freeSpaces;  
}

char checkWinner()
{

   for(int i = 0; i < 3; i++){
      if(board[i][0] == board[i][1] && board[i][0] == board[i][2])
      {
         return board[i][0];
      }
   }

   for(int i = 0; i < 3; i++){
      if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
         return board[0][i];
      }
   }

   if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
      return board[0][0];
   }
   if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
      return board[0][2];
   }

   return ' ';
}

void printWinner(char winner)
{
   if(winner == PLAYER_1){
      printf("PLAYER 1 WINS");
   }
   else if(winner == PLAYER_2)
   {
      printf("PLAYER 2 WINS");
   }
   else{
      printf("ITS A TIE!");
   }
}