// Bridge edge in a graph

//CODE

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    bool isPath(int startNode, int desNode, vector<int> adj[], vector<int> &isVisited){
        if(startNode == desNode)
            return true;
        isVisited[startNode] = true;
        for(int node: adj[startNode]){
            if(!isVisited[node]){
                if(isPath(node, desNode, adj, isVisited)){
                    return true;
                }
            }
        }
        return false;
    }
    int isBridge(int V, vector<int> adj[], int c, int d) {
        vector<int>adj2[V];
        for(int i=0; i<V; i++){
            for(auto j : adj[i]){
                if((i == c and j == d) or (i == d or j == c)){
                    continue;
                }
                else{
                    adj2[i].push_back(j);
                }
            }
        }
        vector<int> isVisited(V, false);
        bool bl = isPath(c, d, adj2, isVisited);
        return !bl;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends