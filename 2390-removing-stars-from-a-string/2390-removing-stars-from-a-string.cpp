class Solution {
public:
    string removeStars(string s) {
        
        string ans="";
        stack<char>st;
        for(char ch:s){
            if(ch != '*'){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};