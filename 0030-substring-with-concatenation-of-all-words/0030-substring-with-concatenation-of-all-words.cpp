class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> subtringStartIndexes;

        int wordLen = words[0].length();
        int wordsSize = words.size();
        int windowSize = wordLen * wordsSize;

        if (s.length() < windowSize) {
            return subtringStartIndexes;
        }

        unordered_map<string, int> required;

        for (string word : words) {
            required[word]++;
        }

        for (int offset = 0; offset < wordLen; ++offset) {

            int start = offset;
            int end = offset;
            int wordsInWindow = 0;
            unordered_map<string, int> available;

            // Starting with sliding window
            while(end + wordLen <= s.length()){

                // Getting the word
                string substr = s.substr(end, wordLen);
                end += wordLen;

                // Checking if the new word belongs to required and if not clear
                // all progress made till now
                if (required.find(substr) == required.end()) {
                    available.clear();
                    start = end;
                    wordsInWindow = 0;
                    continue;
                }

                available[substr]++;
                wordsInWindow++;

                // Checking if the freq exceeds whats required, if yes then
                // start trimming from left
                while (available[substr] > required[substr]) {
                    string leftWord = s.substr(start, wordLen);
                    available[leftWord]--;
                    start += wordLen;
                    wordsInWindow--;
                }

                // When the window contains all the words
                while (wordsInWindow == wordsSize) {
                    subtringStartIndexes.push_back(start);
                    string leftWord = s.substr(start, wordLen);
                    available[leftWord]--;
                    start += wordLen;
                    wordsInWindow--;
                }
            }
        }

        return subtringStartIndexes;
    }
};