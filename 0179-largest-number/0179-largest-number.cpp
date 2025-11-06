class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        int n=nums.size();
        if(n == 0){
            return "";
        }

        string ans="";
        sort(nums.begin(),nums.end(),[](const int& n1,const int& n2){
            string a=to_string(n1);
            string b=to_string(n2);
            return a+b > b+a;
        });

        if(nums[0] == 0){
            return "0";
        }
        for(int n:nums){
            ans+=to_string(n);
        }
        return ans;

    }
};