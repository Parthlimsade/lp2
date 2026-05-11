#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

void sel(vector<int>num, int n)
{
    for(int i=0;i<n-1;i++)
    {
     int count=i;
     for(int j=i+1;j<n;j++)
     {
        if(num[j]<num[count])
        {
            count=j;
        }

     }   
     swap(num[i], num[count]);
    }

    for(int i : num)
    {
        cout<<i<<" ";
    }
}


void dij(int src , vector<vector<pair<int,int>>>&g, int v)
{
    vector<int>dis(v,INT_MAX);
    dis[src]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>,  greater<pair<int,int>>>pq;
        pq.push({0,src});

    while(pq.size()>0)
    {
        
        int u=pq.top().second;
        pq.pop();
        for(auto e : g[u])
        {
            int ver=e.first;
            int wt=e.second;
            if(dis[ver]>dis[u]+wt)
            {
                dis[ver]=dis[u]+wt;
                pq.push({dis[ver],ver});
            }
        }
    }

    for(int i=0;i<v;i++)
    {
        cout<<dis[i]<<"  ";
    }

    cout<<endl;
}

int main()
{
  cout<<endl;
    int n;
    cout<<"enter the no. ";
    cin>>n;
    vector<int>num(n);

    cout<<"now enter the number :";
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    } 
    sel(num, n);

    
    int v, e;

    cout << "Enter number of vertices: ";

    cin >> v;

    cout << "Enter number of edges: ";

    cin >> e;

    vector<vector<pair<int,int>>> g(v);

    cout << "Enter source destination weight:" << endl;

    for(int i=0; i<e; i++)
    {
        int u, ver, wt;

        cin >> u >> ver >> wt;

        g[u].push_back({ver, wt});
    }

    int src;

    cout << "Enter source vertex: ";

    cin >> src;

    dij(src, g, v);

    return 0;
}


// Dijkstra Algorithm
// dij(src,g,v);

// Used to find shortest path from source vertex to all other vertices.

// Works on weighted graphs.

// Graph Representation
// vector<vector<pair<int,int>>> g(v);

// Stores:

// destination vertex
// edge weight

// Example:

// 0 → (1,4)

// means:

// edge from 0 to 1 with weight 4
// Distance Array
// vector<int> dis(v,INT_MAX);

// Stores shortest distances.

// Initially all distances are infinity.

// Source Distance
// dis[src]=0;

// Source vertex distance is 0.

// Priority Queue
// priority_queue<...>

// Always selects vertex with minimum distance.

// Push Source
// pq.push({0,src});

// Adds source vertex into queue.

// Main Loop
// while(pq.size()>0)

// Runs until queue becomes empty.

// Get Minimum Distance Vertex
// int u=pq.top().second;
// pq.pop();

// Removes smallest distance vertex.

// Traverse Neighbors
// for(auto e : g[u])

// Visits all adjacent vertices.

// Store Vertex and Weight
// int ver=e.first;
// int wt=e.second;
// ver = neighbor vertex
// wt = edge weight
// Important Condition
// if(dis[ver] > dis[u] + wt)

// Checks if shorter path exists.

// Update Distance
// dis[ver]=dis[u]+wt;

// Updates shortest distance.

// Push Updated Vertex
// pq.push({dis[ver],ver});

// Adds updated distance into queue.

// Final Output
// cout<<dis[i];

// Prints shortest distances from source.

// Time Complexity

// Using Priority Queue:

// O((V+E)logV)

// Where:

// V = number of vertices
// E = number of edges
// Important Points
// Greedy Algorithm
// Uses Priority Queue
// Finds shortest path
// Works for positive weights only
// Short Viva Explanation

// “Dijkstra Algorithm is a greedy algorithm used to find shortest path from source vertex to all other vertices in a weighted graph using priority queue.”
