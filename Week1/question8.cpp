//DECODING MESSAGES

//CODE:

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	    long long mod=1e9+7;
		int CountWays(string str){
		    // Code here
		    if(str[0]=='0')
		        return 0;
		    int n=str.length();
		    vector<long long int> dp(n,0);
		    dp[0]=1;
		    
		    for(int i=1;i<n;i++){
		        if(str[i-1]=='0' && str[i]=='0'){
		            dp[i]=0;
		        }
		        else if(str[i-1]=='0' && str[i]!='0'){
		            dp[i]=dp[i-1]%mod;
		        }
		        else if(str[i-1]!='0' && str[i]=='0'){
		            if(str[i-1]=='2' || str[i-1]=='1')
		                dp[i]=(i>=2 ? dp[i-2]%mod:1);
		            else
		                dp[i]=0;
		            
		        }
		        else if(str[i-1]!='0' && str[i]!='0'){
		            if(stoi(str.substr(i-1,2)) <= 26)
		                dp[i]=dp[i-1]%mod + (i>=2 ? dp[i-2]%mod:1);
		            else
		                dp[i]=dp[i-1]%mod;
		        }
		    }
		    /*for(auto i: dp)
		        cout<<i<<" ";*/
		    return dp[n-1]%mod;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends