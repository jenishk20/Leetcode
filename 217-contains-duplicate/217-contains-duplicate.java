
class Solution {
    public boolean containsDuplicate(int[] nums) {
         HashMap<Integer, Integer> tp
            = new HashMap<Integer, Integer>();
        boolean flag=false;
        for(int i=0;i<nums.length;i++)
        {
            if(tp.containsKey(nums[i]))
            {
                flag=true;
            }
            else
            {
                tp.put(nums[i],1);
            }
        }
        
        return flag;
        
    }
}