// Basic and Easy CPP Sudoku Solver

/* Ready to use Code

can be compiled using online or offline compilers */

#include <iostream>
#include<stdio.h>
using namespace std;

#define N 9 //defining grid dimension, that is 9 by 9
int sudokuboard[N][N];

/*  If you don't want to give the input of 81 numbers, 
you may always use the commented out pre-defined sudoku arrangement in a 2-D array 
or you can edit the code and always pre-define by yourself for your use. 
Thank You! */


/*int sudokuboard[N][N] = 
{
 {0, 0, 6, 5, 0, 8, 4, 0, 0},
 {5, 2, 0, 0, 0, 1, 0, 0, 0},
 {0, 7, 8, 0, 0, 0, 0, 0, 1},
 {0, 0, 4, 0, 1, 0, 0, 8, 0},
 {9, 0, 0, 8, 2, 3, 0, 0, 5},
 {0, 5, 0, 0, 9, 0, 6, 0, 0},
 {1, 3, 0, 0, 0, 0, 2, 5, 0},
 {0, 0, 0, 0, 0, 0, 0, 7, 4},
 {0, 0, 5, 2, 0, 6, 3, 0, 0}
};*/


/* The checkColumn() function takes the column number 
and the input number or value as its arguments 
and check if the number already exists in the specified column or not*/



bool checkColumn(int c, int value)
{ 
 for (int r = 0; r < N; r++)
  if (sudokuboard[r][c] == value)
   return true;
 return false;
}

/*  The checkRow() function matches the input number with every number in the specified row 
and returns true or false after verifying its presence */


bool checkRow(int r, int value)
{ 
for (int c = 0; c < N; c++)
 if (sudokuboard[r][c] == value)
  return true;
 return false;
}

/* */

bool checkBox(int initial_row, int initial_column, int value)
{
for (int r = 0; r < 3; r++)
 for (int c = 0; c < 3; c++)
  if (sudokuboard[r+initial_row][c+initial_column] == value)
   return true;
 return false;
}

/* showGame() function to print the sudoku board on the console screen */


void showGame()
{ 
for (int r = 0; r < N; r++){
 for (int c = 0; c < N; c++)
 {
  if(c == 3 || c == 6)
   cout << " | ";
  cout << sudokuboard[r][c]<<" ";
 }
 if(r == 2 || r == 5)
 {
  cout << endl;
  for(int k = 0; k<N; k++)
   cout << "---";
 }
 cout << endl;
}
}

/* The findBox() function looks for an empty box on the entire game board to see if the user has completed the game or not */



bool findBox(int &r, int &c)
{ 
 for (r = 0; r < N; r++)
  for (c = 0; c < N; c++)
   if (sudokuboard[r][c] == 0) 
    return true;
 return false;
}


/* The function canEnter() takes the input and calls these above functions inside its body. 
It checks the output they return*/




bool canEnter(int r, int c, int value)
{
 return !checkRow(r, value) && !checkColumn(c, value) && !checkBox(r-r%3,c-c%3,value);
}

/* */

bool finalSolution(){
int r, c;
if (!findBox(r, c))
 return true; 
for (int val = 1; val <= 9; val++)
 { 
  if (canEnter(r, c, val))
  { 
   sudokuboard[r][c] = val;
   if (finalSolution()) 
    return true;
   sudokuboard[r][c] = 0; 
  }
 }
return false;
}

/* The main() function, the user only calls the finalSolution(), which is the primary function that solves the sudoku game */


int main(){
    cout<<"Enter your 81 numbers (0 <= Input_Numbers <= 9) :"<<endl;
    int sudokuboard[N][N];
    for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
        cin>>sudokuboard[i][j];
    }
}
if (finalSolution() == true)
 showGame();
else
 cout << "This game can not be solved";
}
