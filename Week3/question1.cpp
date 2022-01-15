// MINIMUM SUM PARTITION

//CODE

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int s=0;
	    for(int i=0;i<n;i++){
	        s+=arr[i];
	    }
	    bool dp[n+1][s+1];
	    
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=s;j++){
	            if(j==0)
	                dp[i][j] = true;
	            else if(i==0)
	                dp[i][j] = false;
	            else if(arr[i-1]<=j)
	                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
	            else 
	                dp[i][j] = dp[i-1][j];
	        }
	    }
	    int diff = INT_MAX;
	    for(int i=0;i<=s/2;i++){
	        if(dp[n][i]==true)
	            diff = min(diff, s-2*i);
	    }
	    return diff;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends