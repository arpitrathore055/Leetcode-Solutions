class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> nextWarmerDay(temperatures.size());
        stack<int> st;
        for (int i = 0; i < temperatures.size(); i++) {
            if (st.empty() || temperatures[st.top()] >= temperatures[i]) {
                st.push(i);
            } else {
                while (!st.empty() && temperatures[st.top()] < temperatures[i]) {
                    int index = st.top();
                    st.pop();
                    nextWarmerDay[index] = i - index;
                }
                st.push(i);
            }
        }
        return nextWarmerDay;
    }
};
