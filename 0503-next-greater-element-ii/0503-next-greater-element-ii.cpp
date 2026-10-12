class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        //Since asking for next greater element therefore, Use monotonic decreasing stack, only allow smaller values to push and remove all those which are greater than current element's value
        int n=nums.size();
        if(nums.size() == 1){
            return {-1};
        }
        
        vector<int> nextGreater(n,-1);
        stack<int> st;
        
        for(int times=2;times>0;times--){
            
            for(int i=n-1;i>=0;i--){
            
                int value=nums[i];
                while(!st.empty() && st.top() <= value){
                    st.pop();
                }
                
                if(!st.empty()){
                    nextGreater[i]=st.top();
                }
                st.push(value);
            
            }
            
        }
        
        return nextGreater;
        
    }
};