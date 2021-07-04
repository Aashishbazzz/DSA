//By Aashish Saxena
//Graph BFS implementation



#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<vector<int> &adj, int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<vector<int> adj, int V)
{
	for (int v = 0; v < V; ++v)
	{
      cout << "\n Adjacency list of vertex "<< v << "\n head ";
      for (auto x : adj[v])
        cout << "-> " << x;
      cout<<"\n;
    }
}

//Helper function for DFS
void solve(vector<vector<int>> adj, vector<int> &ans, vector<bool> &vis,int cur)
	{
	    for(int i=0;i<adj[cur].size();i++)
	    {
	        if(!vis[adj[cur][i]])
	        {
	            ans.push_back(adj[cur][i]);
	            vis[adj[cur][i]]=true;
	            solve(adj,ans,vis,adj[cur][i]);
	        }
	    }
	}
	
	vector<int> dfsOfGraph(int V, vector<vector<int> adj)
	{
	    vector<int> ans;
	    vector<bool> vis(V,false);
	    
	    ans.push_back(0);
	    vis[0]=true;
	    solve(adj,ans,vis,0);
	    
	    return ans;
	}

int main()
{
	int V,E,a,b,i;
  
  cin>>V>>E;
  
	vector<vector<int> adj(V);
  vector<int> dfs_Path;
  
  for(i=0;i<E;i++)
  {
    cin>>a>>b;
    addEdge(adj,a,b);
  }
  
	printGraph(adj, V);
  
  dfs_Path= dfsOfGraph(V,adj);
  
	return 0;
}
