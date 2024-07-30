class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>indices;
        int len=boxes.length();
        vector<int>ans(len,0);
        for(int i=0;i<len;i++){
            if(boxes[i]=='1'){
                indices.push_back(i);
            }
        }
        for(int i=0;i<len;i++){
            for(auto& index:indices){
                if(index == i){
                    continue;
                }
                ans[i]+=abs(i-index);
            }
        }
        return ans;
    }
};