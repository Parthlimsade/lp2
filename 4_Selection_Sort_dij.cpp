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



