#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void add(vector<vector<int>>&l, int u, int v)
{
    l[u].push_back(v);
    l[v].push_back(u);
}

void bfs(vector<vector<int>>&l, int V, int str, int end)
{
    queue<int>q;
    vector<bool>dis(V,false);

    q.push(str);
    dis[str]=true;

    while(q.size()>0)
    {
        int u=q.front();
        q.pop();

        cout<<u<<" ";

        if(u==end)
        {
            cout<<"\n End of vertex";
            return ;
        }
        for(int v : l[u])
        {
            if(!dis[v])
            {
                dis[v]=true;
                q.push(v);
            }
        }
    }

}


void dfs(int u, int end,vector<bool>&dis, vector<vector<int>>&l, int V )
{

    dis[u]=true;
    cout<<u<<" ";

    if(u == end)
    {
        cout << "\nEnd vertex found";
        return;
    }
    for(int v : l[u])
    {
        if(!dis[v])
        {
            dfs(v,end,dis,l,V);
        }
    }
}


void dfs1(vector<vector<int>>&l, int V, int str, int end)
{
    vector<bool>dis(V,false);
    // int u=0;
    dfs(str,end,dis, l, V);
}




int main()
{

    int e,V;

    cout<<"enter the vertices :";
    cin>>V;

    cout<<"enter the edges";
    cin>>e;

    vector<vector<int>>l(V);

    cout<<"enter the edges :";
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin >> u >> v;
        add(l,u,v);
    }
    int str, end;

    cout<<"enter the str no.";
    cin>>str;
    cout<<endl;
    cout<<" enter the end no.";
    cin>>end;
    cout<<endl;

    cout<<"1.bfs";
    cout<<"2.dfs";

    int choice;

    cin >> choice;

    if(choice == 1)
    {
        cout << "BFS Traversal: ";

        bfs(l, V, str, end);
    }
    else if(choice == 2)
    {
        cout << "DFS Traversal: ";

        dfs1(l, V, str, end);
    }
    else
    {
        cout << "Invalid Choice";
    }
    


}
