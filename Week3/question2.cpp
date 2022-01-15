//Prerequisite Tasks

//CODE

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool iscycle(vector<vector<int>>& adj, vector<int> vis, vector<int> dvis, int i){
        vis[i]=1;
        dvis[i]=1;
        
        for(auto k: adj[i]){
            if(!vis[k]){
                if(iscycle(adj,vis,dvis,k))
                    return true;
            }
            else if(dvis[k]==1)
                return true;
        }
        
        dvis[i]=0;
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>> adj(N);
	    for(auto i: prerequisites){
	        adj[i.second].push_back(i.first);
	    }
	    vector<int> vis(N,0);
	    vector<int> dvis(N,0);
	    for(int i=0;i<N;i++){
	        if(!vis[i]){
	            if(iscycle(adj,vis,dvis,i))
	                return false;
	        }
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends