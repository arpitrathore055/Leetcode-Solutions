class Solution {
public:
    long long wonderfulSubstrings(string word) {
        
        unordered_map<int,int> prefix;
        prefix[0]=1;

        int mask=0;
        long long count=0;

        for(int j=0;j<word.length();j++){

            char ch=word[j];
            mask^= (1<<(ch-'a'));

            count+=prefix[mask];

            for(int i=0;i<10;i++){

                int requiredMask=mask^(1<<i);

                count+=prefix[requiredMask];

            }

            prefix[mask]++;

        }

        return count;

    }
};