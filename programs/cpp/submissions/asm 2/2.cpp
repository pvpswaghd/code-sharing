// use https://www.sudoku-solutions.com/ to generate a board
// this website also supports using particular techniques to solve for a board
// from preferences, choose Naked-Singles only or partial solving
// then click "Solve Partially", you may then cross-check with your progran output

#include <iostream>
using namespace std;

int board[10][10]; //i prefer to use 1-9 to store the board
int allowedNumbers[10][10][10]; //it is to store each pos' allowed numbers
// IMPORTANT:  Do NOT change any of the function headers
//             It means that you will need to use the function headers as is
//             You may add other functions wherever appropriate

// get user input and store the game board in the 2D array b
void ReadBoard( int b[][10] )
{
    for (int i = 1; i <= 9; i++){
        for (int j = 1; j <= 9; j++){
            cin >> b[i][j]; 
        }
    }
}

// display the game board stored in the 2D array b
void PrintBoard( int b[][10] )
{
    for (int i = 1; i <= 9; i++){
        for (int j = 1; j <= 8; j++){
            (b[i][j]!=0) ? cout << b[i][j] : cout << "x";
            ((j)%3!=0) ? cout << " " : cout << " | ";

        }
        (b[i][9]!=0)? cout << b[i][9] << " " << endl : cout << "x " << endl;
        if((i)%3==0 && i!=9)
            cout << "------+-------+-------\n";
    }
    
}


// solve a game board stored in b using the Naked Single technique only
// the (partial) solution is stored in the input array b
void SolveBoard(int b[][10] )
{
    //refresh allowed numbers and naked single
    int count = 0;
    bool found = true; //the allowed numbers identification will restart when a block of single allowed number is found
    int foundX = 0, foundY = 0, number = 0;
    while(found){
        foundX = 0, foundY = 0, number = 0, found = false;
        for (int i = 1; i <= 9; i++){
            for (int j = 1; j <= 9; j++){
                count = 0;
                if (b[i][j]!=0) continue;
                else {
                    for (int k = 1; k <= 9; k++)
                        allowedNumbers[i][j][k] = k;
                    for (int k = 1; k <= 9; k++){ //check row + col
                        if(b[k][j]!=0) allowedNumbers[i][j][b[k][j]] = 0; //identification of allowed number in each block
                        if(b[i][k]!=0) allowedNumbers[i][j][b[i][k]] = 0; 
                    }
                    int x,y; //the following if part is to identify the square the numbers are in.
                    if(i>=1 && i<=3) x=1;
                    if(i>=4 && i<=6) x=4;
                    if(i>=7 && i<=9) x=7;
                    if(j>=1 && j<=3) y=1;
                    if(j>=4 && j<=6) y=4;
                    if(j>=7 && j<=9) y=7;
                    for (int g = 0; g < 3; g++){
                        for (int h = 0; h < 3; h++){
                            if(b[g+x][h+y]!=0) allowedNumbers[i][j][b[g+x][h+y]] = 0;
                        }
                    }
                    //search for how many allowed numbers is in the position (i,j)
                    for (int k = 1; k <= 9; k++){ 
                        if(allowedNumbers[i][j][k] >= 1){
                            count+=1;
                            foundX = i;
                            foundY = j;
                            number = allowedNumbers[i][j][k];
                        }
                    }
                    //if there's one allowed number allowed, we add the allowed number into pos(i,j) and restart the search
                    if (count == 1){
                        b[foundX][foundY] = number;                
                        found = true;
                        break;
                    }
                }
            }
            if (found) break;
        }
    }
}

// You do not need to change anything in the main() function
int main()
{
  ReadBoard( board );

  cout << "Input Sudoku board:" << endl;
  PrintBoard( board );

  // solve the board using the naked single technique only
  SolveBoard( board );

  cout << endl;
  cout << "Final Sudoku board:" << endl;
  PrintBoard( board );

  return 0;
}
