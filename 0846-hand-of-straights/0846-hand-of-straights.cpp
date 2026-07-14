class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if((hand.size() % groupSize) != 0){
            return false;
        }

        unordered_map<int,int> freq;
        for(auto ele:hand){
            freq[ele]++;
        }

        sort(begin(hand),end(hand));

        for(auto ele:hand){

            if(freq[ele] == 0){
                continue;
            }

            for(int num=ele;num < ele + groupSize;num++){

                if(freq[num] == 0){
                    return false;
                }
                freq[num]--;
            }

        }
        return true;

    }
};