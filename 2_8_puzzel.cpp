#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

struct Node
{

    vector<vector<int>> state;

    int x, y;
    int g, h;

    string path;

    int f() const
    {
        return g + h;
    }

    bool operator<(const Node &other) const
    {
        return f() > other.f();
    }
};

vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}};

void printPuzzle(vector<vector<int>> puzzle)
{

    for (auto row : puzzle)
    {

        for (auto val : row)
        {
            cout << val << " ";
        }

        cout << endl;
    }

    cout << endl;
}

int heuristic(vector<vector<int>> state)
{

    int distance = 0;

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            int value = state[i][j];

            if (value != 0)
            {

                int targetX = (value - 1) / 3;
                int targetY = (value - 1) % 3;

                distance += abs(i - targetX) + abs(j - targetY);
            }
        }
    }

    return distance;
}

string stateToString(vector<vector<int>> state)
{

    string s = "";

    for (auto row : state)
    {

        for (auto val : row)
        {
            s += to_string(val);
        }
    }

    return s;
}

void solvePuzzle(vector<vector<int>> start)
{

    priority_queue<Node> pq;

    set<string> visited;

    int blankX, blankY;

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            if (start[i][j] == 0)
            {
                blankX = i;
                blankY = j;
            }
        }
    }

    Node initial;

    initial.state = start;
    initial.x = blankX;
    initial.y = blankY;
    initial.g = 0;
    initial.h = heuristic(start);
    initial.path = "";

    pq.push(initial);

    // Directions
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    string moves[] = {"Up ", "Down ", "Left ", "Right "};

    while (!pq.empty())
    {

        Node current = pq.top();
        pq.pop();

        if (current.state == goal)
        {

            cout << "Goal State Reached!\n\n";

            printPuzzle(current.state);

            cout << "Moves: " << current.path << endl;

            cout << "Cost: " << current.g << endl;

            return;
        }

        string key = stateToString(current.state);

        if (visited.count(key))
        {
            continue;
        }

        visited.insert(key);

        for (int i = 0; i < 4; i++)
        {

            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (newX >= 0 && newX < 3 &&
                newY >= 0 && newY < 3)
            {

                Node next = current;

                swap(next.state[current.x][current.y],
                     next.state[newX][newY]);

                next.x = newX;
                next.y = newY;

                next.g = current.g + 1;

                next.h = heuristic(next.state);

                next.path = current.path + moves[i];

                pq.push(next);
            }
        }
    }

    cout << "No Solution Found\n";
}

// Sample Input:
// Enter 3x3 puzzle values:
// 1 3 6
// 5 0 2
// 4 7 8

int main()
{

    vector<vector<int>> start(3, vector<int>(3));

    cout << "Enter 3x3 puzzle values:\n";

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            cin >> start[i][j];
        }
    }

    cout << "Initial State:\n\n";

    printPuzzle(start);

    solvePuzzle(start);

    return 0;
}

// Initial Puzzle
// 1 3 6
// 5 0 2
// 4 7 8
//
// 0 represents blank space

// ---------------- MOVE 1 ----------------
// Move: Right
//
// Blank moves RIGHT by swapping with 2

// After:
//
// 1 3 6
// 5 2 0
// 4 7 8

// ---------------- MOVE 2 ----------------
// Move: Up
//
// Blank moves UP by swapping with 6

// After:
//
// 1 3 0
// 5 2 6
// 4 7 8

// ---------------- MOVE 3 ----------------
// Move: Left
//
// Blank moves LEFT by swapping with 3

// After:
//
// 1 0 3
// 5 2 6
// 4 7 8

// ---------------- MOVE 4 ----------------
// Move: Down
//
// Blank moves DOWN by swapping with 2

// After:
//
// 1 2 3
// 5 0 6
// 4 7 8

// ---------------- MOVE 5 ----------------
// Move: Left
//
// Blank moves LEFT by swapping with 5

// After:
//
// 1 2 3
// 0 5 6
// 4 7 8

// ---------------- MOVE 6 ----------------
// Move: Down
//
// Blank moves DOWN by swapping with 4

// After:
//
// 1 2 3
// 4 5 6
// 0 7 8

// ---------------- MOVE 7 ----------------
// Move: Right
//
// Blank moves RIGHT by swapping with 7

// After:
//
// 1 2 3
// 4 5 6
// 7 0 8

// ---------------- MOVE 8 ----------------
// Move: Right
//
// Blank moves RIGHT by swapping with 8

// After (GOAL STATE):
//
// 1 2 3
// 4 5 6
// 7 8 0

// This code solves the 8-puzzle problem using A* algorithm.

// Important Small Explanations
// state → stores puzzle board
// x,y → blank position
// g → cost so far
// h → heuristic value
// f() → total cost = g+h
// Heuristic Function
// heuristic(state)

// Uses Manhattan Distance.

// Calculates how far tiles are from goal position.

// Smaller heuristic = better state.

// Priority Queue
// priority_queue<Node> pq;

// Stores puzzle states.

// Best state comes first.

// Goal State
// 1 2 3
// 4 5 6
// 7 8 0

// 0 represents blank space.

// solvePuzzle()

// Main A* function.

// Steps:

// Find blank space
// Push initial state
// Generate moves
// Calculate heuristic
// Push new states
// Stop at goal
// Moves
// Up
// Down
// Left
// Right

// Blank tile moves in these directions.

// Visited Set
// set<string> visited;

// Prevents revisiting same states.

// Swap Function
// swap(...)

// Moves blank tile with adjacent tile.

// Time Complexity

// Worst Case:

// O(b
// d
// )

// Where:

// b = branching factor
// d = depth of solution

// For 8-puzzle, maximum possible states are:

// 9! = 362880
// Short Viva Answer

// “This program uses A* algorithm with Manhattan Distance heuristic to solve the 8-puzzle problem. Priority queue selects the best puzzle state first until the goal state is reached.”
