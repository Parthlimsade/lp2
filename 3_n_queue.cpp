#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N;

void printBoard(vector<int> board)
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

struct Node
{

    vector<int> board;

    int row;
    int g;
    int h;

    int f() const
    {
        return g + h;
    }

    bool operator<(const Node &other) const
    {
        return f() > other.f();
    }
};

int heuristic(vector<int> board)
{

    int attacks = 0;

    for (int i = 0; i < N; i++)
    {

        for (int j = i + 1; j < N; j++)
        {

            if (board[i] == board[j] ||

                abs(board[i] - board[j]) == abs(i - j))
            {

                attacks++;
            }
        }
    }

    return attacks;
}

void solveAStar()
{

    priority_queue<Node> pq;

    vector<int> start(N, -1);

    Node initial;

    initial.board = start;
    initial.row = 0;
    initial.g = 0;
    initial.h = 0;

    pq.push(initial);

    while (!pq.empty())
    {

        Node current = pq.top();
        pq.pop();

        if (current.row == N &&
            heuristic(current.board) == 0)
        {

            cout << "A* Solution Found:\n\n";

            printBoard(current.board);

            return;
        }

        if (current.row >= N)
            continue;

        for (int col = 0; col < N; col++)
        {

            vector<int> newBoard = current.board;

            newBoard[current.row] = col;

            Node next;

            next.board = newBoard;

            next.row = current.row + 1;

            next.g = current.g + 1;

            next.h = heuristic(newBoard);

            pq.push(next);
        }
    }

    cout << "No Solution Found\n";
}

int main()
{

    cout << "Enter size of board : ";
    cin >> N;
    cout << endl;

    // ---------------- A* ----------------

    solveAStar();

    return 0;
}

// notes

// ======================================================
// N-QUEEN PROBLEM
// USING: A* Algorithm
// ======================================================

// ------------------------------------------------------
// BOARD REPRESENTATION
// ------------------------------------------------------
//
// We store board in a 1D vector.
//
// Example:
//
// board[0] = 1
// means:
// Queen in row 0 is placed at column 1
//
// board[1] = 3
// means:
// Queen in row 1 is placed at column 3
//
// Example for N = 4:
//
// board = [1,3,0,2]
//
// Board becomes:
//
// . Q . .
// . . . Q
// Q . . .
// . . Q .
// ------------------------------------------------------

// ======================================================
// PRINT BOARD FUNCTION
// ======================================================
//
// Loops through every row and column.
//
// If board[i] == j
// -> Queen exists there
//
// Else
// -> Empty space
//
// Example:
// board[0] = 2
//
// Means in row 0,
// queen is in column 2
// ------------------------------------------------------

// ======================================================
// isSafe FUNCTION
// ======================================================
//
// Checks whether queen can be placed safely.
//
// Two conditions checked:
//
// 1. SAME COLUMN
//
// Example:
// Q already at column 2
// another queen cannot be at column 2
//
// 2. SAME DIAGONAL
//
// Diagonal condition:
//
// abs(col difference)
// ==
// abs(row difference)
//
// Example:
//
// Q at (0,0)
// another Q at (1,1)
//
// abs(0-1) == abs(0-1)
// 1 == 1
//
// Therefore diagonal attack
// ------------------------------------------------------

// ======================================================
// A* ALGORITHM
// ======================================================
//
// A* is a BEST-FIRST SEARCH algorithm.
//
// Formula:
//
// f(n) = g(n) + h(n)
//
// where:
//
// g(n)
// = cost so far
// = number of queens placed
//
// h(n)
// = heuristic
// = number of attacking queens
//
// Smaller f(n) is better
// ------------------------------------------------------

// ======================================================
// PRIORITY QUEUE
// ======================================================
//
// Priority queue always selects
// state with LOWEST f(n)
//
// Therefore promising boards
// are explored first
// ------------------------------------------------------

// ======================================================
// HEURISTIC FUNCTION
// ======================================================
//
// Counts attacking queens.
//
// Example:
//
// Q . . .
// . Q . .
//
// These queens attack diagonally
//
// Therefore attacks++
//
// Goal:
// heuristic = 0
//
// Means:
// no queens attack each other
// ------------------------------------------------------

// ======================================================
// A* WORKING STEP-BY-STEP
// ======================================================
//
// STEP 1:
// Start with empty board
//
// -1 -1 -1 -1
//
// STEP 2:
// Generate possible states
//
// Put queen in row 0:
//
// [0,-1,-1,-1]
// [1,-1,-1,-1]
// [2,-1,-1,-1]
// [3,-1,-1,-1]
//
// STEP 3:
// Calculate heuristic for each
//
// Less attacking queens
// -> better priority
//
// STEP 4:
// Remove best state from queue
//
// Expand next row
//
// Continue until:
//
// row == N
// AND
// heuristic == 0
//
// Then solution found
// ------------------------------------------------------

// ======================================================
// TIME COMPLEXITY
// ======================================================
//
// Worst case:
//
// O(N!)
//
// Because:
// many queen arrangements checked
// ------------------------------------------------------