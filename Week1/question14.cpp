//Minimum Size Subarray Sum

//CODE:

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,s=0,ans=INT_MAX;
        while(j<nums.size()){
            s+=nums[j++];
            while(s>=target){
                ans=min(ans,j-i);
                s-=nums[i++];
            }
        }
        return (ans==INT_MAX)?0:ans;
    }
};