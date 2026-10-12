class Solution {
public:
    string removeKdigits(string num, int k) {

        int n = num.length();
        stack<int> st;

        string sNum = "";
        for (int i = 0; i < n; i++) {

            int digit = num[i] - '0';
            while (k != 0 && !st.empty() && st.top() > digit) {
                st.pop();
                k--;
            }

            if (st.empty() && digit == 0) {
                continue;
            }

            st.push(digit);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        while (!st.empty()) {
            sNum += to_string(st.top());
            st.pop();
        }
        reverse(sNum.begin(), sNum.end());

        int pos = sNum.find_first_not_of('0');

        if (pos == string::npos) {
            return "0";
        }

        return sNum.substr(pos);
    }
};