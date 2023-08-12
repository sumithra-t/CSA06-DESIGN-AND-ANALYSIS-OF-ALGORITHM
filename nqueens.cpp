#include <stdio.h>
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(board[i][j])
                printf("Q ");
            else
                printf(". ");
        }
        printf("\n");
    }
}
 
bool isSafe(int board[N][N], int row, int col)
{
    int i, j;
 
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
 
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
 
    return true;
}
 
bool solveNQUtil(int board[N][N], int col)
{
    if (col >= N)
        return true;
 
    
    for (int i = 0; i < N; i++) {
         
        
        if (isSafe(board, i, col)) {
             
            // Place this queen in board[i][col]
            board[i][col] = 1;
 
            // Recur to place rest of the queens
            if (solveNQUtil(board, col + 1))
                return true;
 
            // If placing queen in board[i][col]
            // doesn't lead to a solution, then
            // remove queen from board[i][col]
            board[i][col] = 0; // BACKTRACK
        }
    }
 
    // If the queen cannot be placed in any row in
    // this column col  then return false
    return false;
}
 
// This function solves the N Queen problem using
// Backtracking. It mainly uses solveNQUtil() to
// solve the problem. It returns false if queens
// cannot be placed, otherwise, return true and
// prints placement of queens in the form of 1s.
// Please note that there may be more than one
// solutions, this function prints one  of the
// feasible solutions.
bool solveNQ()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
 
    if (solveNQUtil(board, 0) == false) {
        printf("Solution does not exist");
        return false;
    }
 
    printSolution(board);
    return true;
}
 
// Driver program to test above function
int main()
{
    solveNQ();
    return 0;
}
