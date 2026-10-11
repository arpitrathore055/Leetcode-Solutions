#include<bits/stdc++.h>

class Solution {
public:
    int maximumGap(vector<int>& nums) {
  
        if(nums.size() == 0 || nums.size() < 2){
            return 0;
        }

        int minele=*min_element(nums.begin(),nums.end());
        int maxele=*max_element(nums.begin(),nums.end());
        
        if(minele == maxele){
            return 0;
        }
        
        int n=nums.size();
        int bucketWidth=max(1,(maxele-minele)/(n-1));
        int bucketCount=(maxele-minele)/bucketWidth+1;
        
        vector<int> bucketMin(bucketCount,INT_MAX);
        vector<int> bucketMax(bucketCount,INT_MIN);
        
        for(auto& ele:nums){
            
            int index=((ele-minele)/bucketWidth);
            bucketMin[index]=min(bucketMin[index],ele);
            bucketMax[index]=max(bucketMax[index],ele);
            
        }
        
        int maxGap=0;
        int prevmax=minele;
        
        for(int i=0;i<bucketCount;i++){
            
            if(bucketMin[i] == INT_MAX){
                continue;
            }
            
            maxGap=max(maxGap,bucketMin[i]-prevmax);
            prevmax=bucketMax[i];
            
        }
        
        return maxGap;
        
    }
};