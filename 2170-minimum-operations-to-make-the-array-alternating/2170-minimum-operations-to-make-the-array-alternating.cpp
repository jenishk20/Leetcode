class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int n=nums.size();
        map<int,int>freqEven,freqOdd;
        
        int i;
        int maxi=0;
        for(i=0;i<n;i++)
        {
            if(i&1)
            {
                freqOdd[nums[i]]++;
            }
            else
            {
                freqEven[nums[i]]++;
            }
            maxi=max(maxi,nums[i]);
        }
        
        int firstMaxEven=0,firstMaxEvenFreq=0;
        int firstMaxOdd=0,firstMaxOddFreq=0;
        
        int secondMaxEven=0,secondMaxEvenFreq=0;
        int secondMaxOdd=0,secondMaxOddFreq=0;
        
        for(i=1;i<=maxi;i++)
        {
            if(freqEven[i]>firstMaxEvenFreq)
            {
                secondMaxEvenFreq=firstMaxEvenFreq;
                secondMaxEven=firstMaxEven;
                firstMaxEvenFreq=freqEven[i];
                firstMaxEven=i;
            }
            else if(freqEven[i]>secondMaxEvenFreq)
            {
                secondMaxEvenFreq=freqEven[i];
                secondMaxEven=i;
            }
            if(freqOdd[i]>firstMaxOddFreq)
            {
                secondMaxOddFreq=firstMaxOddFreq;
                secondMaxOdd=firstMaxOdd;
                firstMaxOddFreq=freqOdd[i];
                firstMaxOdd=i;
            }
            else if(freqOdd[i]>secondMaxOddFreq)
            {
                secondMaxOddFreq=freqOdd[i];
                secondMaxOdd=i;
            }
        }
        if(firstMaxEven!=firstMaxOdd)
        {
            return n-firstMaxEvenFreq-firstMaxOddFreq;
        }
        
        return min(n-firstMaxEvenFreq-secondMaxOddFreq,n-secondMaxEvenFreq-firstMaxOddFreq);
        
    }
};