class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        map<int,int>ma;
        int cnt =0;
        for(int i=0;i<nums.size();i++){
            
            ma[nums[i]]++;
            if(ma[nums[i]]>1){
                cnt+=ma[nums[i]]-1;
            }
        }
        return cnt;
    }
};