// smallest range in k lists

//CODE

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
  struct compare{
    bool operator()(pair<int,int> &p1 , pair<int,int> &p2){
        if(p1.first == p2.first)
            return p1.second >= p2.second;
            
        return p1.first >= p2.first;
    }
};
class Solution{
    public:
    bool isvis(vector<int>& pos){
        for(int i=0;i<pos.size();i++){
            if(pos[i]==0)
                return false;
        }
        return true;
    }
    pair<int,int> findSmallestRange(int a[][N], int n, int k){
        vector<pair<int,int>> pq;
        for(int i=0;i<k;i++){
            for(int j=0;j<n;j++){
                pq.push_back({a[i][j],i});
            }
        }
        sort(pq.begin(),pq.end());
        vector<int> pos;
        for(auto k: pq){
            //cout<<k.first<<" "<<k.second<<endl;
            pos.push_back(k.second);
        }
        int su= ((k-1)*k)/2;
        int l=0,r=k-1;
        vector<pair<int,int>> ans;
        while(r<n*k){
            vector<int> vis(k,0);
            for(int i=l;i<=r;i++){
                vis[pos[i]]=1;
            }
            if(isvis(vis)==true)
                ans.push_back({l,r});
                
            l++;r++;
        }
        cout<<ans.size();
        int a1 = 0,b1 = 0;
        /*for(int i=1;i<ans.size();i++){
            if(abs(a1-b1) > abs(pq[ans[i].first].first-pq[ans[i].second].first)){
                a1 = pq[ans[i].first].first;
                b1 = pq[ans[i].second].first;
            }
        }*/
        return {a1,b1};
    }
};


// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends