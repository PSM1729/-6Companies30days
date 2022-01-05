class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        if(n<3)
            return 0;
        int pre[n],suff[n];
        pre[0]=0;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1])
                pre[i]=pre[i-1]+1;
            else
                pre[i]=0;
        }
        suff[n-1]=0;
        for(int i=n-2;i>=0;i--){
            if(arr[i] > arr[i+1])
                suff[i]=suff[i+1]+1;
            else
                suff[i]=0;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            //cout<<pre[i]<<" "<<suff[i]<<endl;
            if(pre[i]!=0 && suff[i]!=0)
                ans=max(ans, pre[i]+suff[i]);
        }
        
        return (ans==0)? 0 : ans+1;
    }
};