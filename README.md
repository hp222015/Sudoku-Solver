


# Sudoku 

Sudoku is one of the most popular classic games. The playing grid of sudoku consists of the 9*9 squares space. The game initially has 9 squares combining rows and columns. Out of these 9 squares, every square is a separate grid of 3*3 square spaces. Every row and column has 9 squares. It can be either one player or a two-player game where the competitors try to fill the boxes faster than their opponents. The game’s primary purpose is to fill boxes in every square with numbers ranging from 1 to 9. The exciting thing about the Sudoku game is that no column, row, or square allows repeating a number.

## Requirements and Conditions of the Game
- The game board should be of 9*9 squares space.
- The game should display the grid with some of the boxes already filled with random numbers ranging from 1 to 9.
- The game should allow the player to fill in empty boxes.
- The game should not allow the player to repeat any number in any row, column, or square.
- If the player fills all the boxes with correct numbers and without any repetition, he wins the game.


## Steps 

### 1. Display Game Board

 In this C++ example, the user pre-defines a board with some initial values and stores them in a 2D array. This two-dimensional array is the game board. The developer can then define the showGame() function to print the sudoku board on the console screen.


### 2. Checking for number repetition 
- ***Checking Columns*** : According to the game’s requirements explained above, the game cannot allow the player to repeat any number in any row, column or square. Therefore, the checkColumn() function takes the column number and the input number or value as its arguments and check if the number already exists in the specified column or not. After it has checked the column for repetitive values, it returns the boolean variables based on its findings.
  - ***Checking rows*** : Similarly, the checkRow() function matches the input number with every number in the specified row and returns true or false after verifying its presence.
    - ***Checking small squares*** :
Furthermore, another function for checking, the checkBox() function takes the starting number of row and column of a specific square, and the user input to match it with the 3 by 3 square to check if the number exists in the entire square or not.

### 3. Placing values in boxes
As all the above conditions need to be false, to place a number in a specific box, the function canEnter() takes the input and calls these above functions inside its body. It checks the output they return. For example, if all of them are false, it returns “true” to confirm that the user can write the input number in that box.
### 4.Making Final Decision
Moreover, the findBox() function looks for an empty box on the entire game board to see if the user has completed the game or not. After that, it can make a winning decision based on this analysis. In this example, the user does not give the input, but the game generates the input itself in the function finalSolution(), the game’s primary function. The function first checks that the board has any empty boxes or not. If yes, it returns true otherwise, it moves on to the “for” loop, which generates the values of numbers from 1 to 9 and calls the above functions to check if it can place these values in the grid or not. Additionally, the findBox() function calls itself recursively until it fills all the positions or else returns false to confirm that no solution exists for that particularly given sudoku board.
### 5. Main Function
Finally, in the main() function, the user only calls the finalSolution(), which is the primary function that solves the sudoku game. If this function returns true, the user calls the showGame() function to display the completed game board. Otherwise, it prints that “This game can not be solved” because there may be situations where there is no solution to this board game. In that case, the user needs to change the board’s initial values.





## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.
