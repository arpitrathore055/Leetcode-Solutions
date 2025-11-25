
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
		stack<pair<char,int>>st;
		string validParenthesisStr="";
		
		for(int i=0;i<s.length();i++)
		{
			char ch=s[i];
			if(ch == '(')
			{
				st.push({ch,i});
			}
			else if(ch == ')')
			{
				if(!st.empty() && st.top().first == '(')
				{
					st.pop();
				}
				else
				{
					st.push({ch,i});
				}
			}
			else
			{
			
			}
		}
		
		for(int i=s.length()-1;i>=0;i--)
		{
			if(!st.empty() && st.top().second == i)
			{
				st.pop();
				continue;
			}
			validParenthesisStr.push_back(s[i]);
			
		}
		
		reverse(validParenthesisStr.begin(),validParenthesisStr.end());
		
		return validParenthesisStr;
		
    }
};