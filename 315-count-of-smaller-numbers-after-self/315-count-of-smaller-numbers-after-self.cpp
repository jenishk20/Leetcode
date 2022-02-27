class Solution {
public:
    void merge(vector<pair<int,int>>&a,int low,int mid,int high,vector<int>&ans)
    {
        int i=low;
        int j=mid+1;
        vector<pair<int,int>>temp(high-low+1);
        int k=0;
        while(i<=mid and j<=high)
        {
            if(a[i].first<=a[j].first)
            {
                temp[k++]=a[j];
                j++;
            }
            else
            {
                temp[k++]=a[i];
                ans[a[i].second]+=high-j+1;
                i++;
            }
            
            
        }
        while(i<=mid)
        {
            temp[k++]=a[i++];
        }
        while(j<=high)
        {
            temp[k++]=a[j++];
        }
        for(i=low;i<=high;i++)
            a[i]=temp[i-low];
      
    }
    void mergeSort(vector<pair<int,int>>&a,int low,int high,vector<int>&ans)
    {
        if(low<high)
        {
            int mid=(low+high)/2;
            mergeSort(a,low,mid,ans);
            mergeSort(a,mid+1,high,ans);
            merge(a,low,mid,high,ans);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        
        int n=nums.size();
        vector<pair<int,int>>a(n);
        int i;
        for(i=0;i<n;i++)
        {
            a[i]={nums[i],i};
        }
        vector<int>ans(n,0);
        mergeSort(a,0,n-1,ans);
        return ans;
    }
};