#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isSafe(vector<string>&board, int row, int col,int n)
{
    for(int j=0;j<n;j++)
    {
        if(board[row][j]=='Q')
        {
            return false;
        }
    }
     for(int i=0;i<n;i++)
    {
        if(board[i][col]=='Q')
        {
            return false;
        }
    }
    for(int i=row, j=col;j>=0 && i>=0;i--,j--)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }

    for(int i=row, j=col;j<n && i>=0;i--,j++)
    {
        if(board[i][j]=='Q')
        {
            return false;
        }
    }

    return true;
}

void nqueen(vector<string>&board,int row, int n, vector<vector<string>>& ans)
{
    if(row==n)
    {
        ans.push_back(board);
        return ;
    }

    for(int j=0;j<n;j++)
    {
        if(isSafe(board, row, j,n))
        {
            board[row][j]='Q';
            nqueen(board,row+1,n,ans);
            board[row][j]='.';
        }
    }
}

vector<vector<string>>solveque(int n)
{
    vector<string>board(n,string(n,'.'));
    vector<vector<string>>ans;

    nqueen(board,0,n,ans);

    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<string>> result = solveque(n);

      for(int k=0; k<result.size(); k++)
    {
        cout << "\nSolution " << k+1 << ":\n";

        for(string row : result[k])
        {
            cout << row << endl;
        }
    }

    return 0;
}


// N-Queen Problem Using Backtracking

// This program solves the N-Queen problem using Backtracking.

// Goal:

// Place N queens so that no queens attack each other.

// Board Representation
// vector<string> board

// Stores chess board.

// Example:

// .Q..
// ...Q
// Q...
// ..Q.
// isSafe Function
// isSafe(board,row,col,n)

// Checks whether queen can be placed safely.

// Checks Performed
// Same Row
// board[row][j]=='Q'
// Same Column
// board[i][col]=='Q'
// Left Diagonal
// i-- , j--

// Checks upper-left diagonal.

// Right Diagonal
// i-- , j++

// Checks upper-right diagonal.

// nqueen Function
// nqueen(board,row,n,ans)

// Main recursive backtracking function.

// Base Condition
// if(row==n)

// All queens placed successfully.

// Store solution in ans.

// Loop
// for(int j=0;j<n;j++)

// Tries every column in current row.

// Place Queen
// board[row][j]='Q';
// Recursive Call
// nqueen(board,row+1,n,ans);

// Moves to next row.

// Backtracking
// board[row][j]='.';

// Removes queen and tries next possibility.

// solveque Function
// solveque(n)

// Creates empty board and starts recursion.

// Time Complexity

// Worst Case:

// O(N!)

// Because many queen arrangements are checked.

// Important Points
// Uses Backtracking
// Recursive solution
// One queen per row
// Checks safe positions only
// Short Viva Explanation

// “This program solves the N-Queen problem using backtracking. It places queens row by row and checks safe positions using row, column, and diagonal checking.”
