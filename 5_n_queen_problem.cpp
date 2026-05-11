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