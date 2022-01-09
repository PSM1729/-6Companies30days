// First non-repeating character in a stream

//CODE:

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    string res;
            vector<int> visited(26,0);
            queue<int> q; 
        
            for(int i=0;i<A.size();i++){
           
                if(visited[A[i]-'a']==0){
                    visited[A[i]-'a']=1;
                    q.push(A[i]);
                }
                else
                    visited[A[i]-'a']++;;
    
                
                while(!q.empty()&&visited[q.front()-'a']==2)
                    q.pop();
                    
                if(!q.empty())
                    res.push_back(q.front());
                else
                    res.push_back('#');
            }
            
            return res;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends