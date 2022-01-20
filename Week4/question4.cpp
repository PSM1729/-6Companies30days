// Partition equal subset sum

//CODE

// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


// User function Template for C++

class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        long long sum=0;
        for(long long i=0;i<N;i++)
            sum+=arr[i];
            
        if(sum%2!=0)
            return 0;
            
        bool dp[sum/2+1][N+1];
        for(long long i=0;i<=N;i++)
            dp[0][i]= true;
        
        for(long long i=0;i<=sum/2;i++)
            dp[i][0]= false;
            
        for(long long i=1;i<=sum/2;i++)
        {
            for(long long j=1;j<=N;j++)
            {
                dp[i][j]=dp[i][j-1];
                if(i>=arr[j-1])
                    dp[i][j]= dp[i][j]||dp[i-arr[j-1]][j-1];
            }
        }
        if(dp[sum/2][N])
            return 1;
        else
            return 0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends