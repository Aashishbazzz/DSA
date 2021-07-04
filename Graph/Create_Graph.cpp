// By Aashish Saxena
// Generating graph using adjacency list

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

int main()
{
	int V,E,a,b,i;
  
  cin>>V>>E;
  
	vector<vector<int> adj(V);
  
  for(i=0;i<E;i++)
  {
    cin>>a>>b;
    addEdge(adj,a,b);
  }
  
	printGraph(adj, V);
	return 0;
}
