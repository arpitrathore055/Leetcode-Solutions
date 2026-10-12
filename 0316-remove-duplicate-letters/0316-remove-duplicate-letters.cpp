class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n=s.length();
        
        if(n == 1 || n==2 && s[0]!=s[1]){
            return s;
        }
        
        string distinctCharString="";
        
        set<char> presence;
        vector<int> characters(26,0);
        stack<char> st;
            
        for(auto& ch:s){
            characters[ch-'a']++;
        }
        
        for(int i=0;i<n;i++){
            
            char ch=s[i];
            characters[ch-'a']--;
            //element already exists in stack, no need to include/process again
            if(presence.find(ch) != presence.end()){
                continue;
            }
            
            while(!st.empty() && st.top() > ch && characters[st.top()-'a']!=0){
                presence.erase(st.top());
                // characters[st.top()-'a']--;
                st.pop();
            }
            
            st.push(ch);
            presence.insert(ch);
        }
        
        while(!st.empty()){
            distinctCharString.push_back(st.top());
            st.pop();
        }
        
        reverse(distinctCharString.begin(),distinctCharString.end());
        
        return distinctCharString;
        
    }
};