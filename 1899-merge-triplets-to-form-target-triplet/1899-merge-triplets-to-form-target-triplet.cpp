#include<bits/stdc++.h>
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        vector<int> achievedTarget(3,0);

        for(auto triplet:triplets){

            int a=triplet[0];
            int b=triplet[1];
            int c=triplet[2];

            if(a > target[0] || b > target[1] || c > target[2]){
                continue;
            }
            achievedTarget[0]=max(a,achievedTarget[0]);
            achievedTarget[1]=max(b,achievedTarget[1]);
            achievedTarget[2]=max(c,achievedTarget[2]);

        }

        return (achievedTarget[0] == target[0] && achievedTarget[1] == target[1] && achievedTarget[2] == target[2]);

    }
};
