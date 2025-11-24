class Solution {
public:

    void possibleValidCombinations(string& currStr, vector<string>& combinations,
                                   int totalSize, int countOpening, int countClosing,
                                   stack<char> st)   // pass stack by value to avoid corruption
    {
        if(countOpening > (totalSize/2) || countClosing > (totalSize/2)) {
            return;
        }

        if(totalSize <= (countOpening + countClosing)) {
            if(totalSize < (countOpening + countClosing)) {
                return;
            }

            // check if valid
            for(char ch : currStr) {
                if(ch == '(') {
                    st.push(ch);
                } else {
                    if(!st.empty()) st.pop();
                }
            }

            if(st.empty()) {
                combinations.push_back(currStr);
            }
            return;
        }

        if((countOpening + countClosing) != (totalSize - 1)) {
            currStr.push_back('(');
            possibleValidCombinations(currStr, combinations, totalSize, countOpening + 1, countClosing, st);
            currStr.pop_back();
        }

        if((countOpening + countClosing) != 0) {
            currStr.push_back(')');
            possibleValidCombinations(currStr, combinations, totalSize, countOpening, countClosing + 1, st);
            currStr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {

        if(n == 1) {
            return {"()"};
        }

        vector<string> combinations;
        string currStr = "";
        stack<char> st;

        possibleValidCombinations(currStr, combinations, n * 2, 0, 0, st);

        return combinations;
    }
};
