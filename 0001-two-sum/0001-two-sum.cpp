class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<pair<int,int>> indexMapping;
       for(int i=0;i<nums.size();i++){
        indexMapping.push_back({nums[i],i});
       } 
       sort(indexMapping.begin(),indexMapping.end());
       int start=0;
       int end=nums.size()-1;
       while(start<end){
        int value=indexMapping[start].first + indexMapping[end].first;
        if(value == target){
            return {indexMapping[start].second,indexMapping[end].second};
        }
        else if(value < target){
            start++;
        }
        else{
            end--;
        }
       }
       return {-1,-1};
    }
};