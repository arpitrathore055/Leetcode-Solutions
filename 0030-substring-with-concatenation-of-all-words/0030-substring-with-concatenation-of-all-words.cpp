class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        int wordLen = words[0].length();
        int wordsSize = words.size();

        // Required frequency of each word
        unordered_map<string, int> required;
        for (string word : words) {
            required[word]++;
        }

        // We need wordLen different sliding windows
        // Example: wordLen = 3 -> offsets 0, 1, 2
        for (int offset = 0; offset < wordLen; offset++) {

            int start = offset;
            int end = offset;
            int wordsInWindow = 0;

            unordered_map<string, int> current;

            while (end + wordLen <= s.length()) {

                string word = s.substr(end, wordLen);
                end += wordLen;

                // Invalid word -> reset window
                if (required.find(word) == required.end()) {
                    current.clear();
                    wordsInWindow = 0;
                    start = end;
                    continue;
                }

                // Add word to current window
                current[word]++;
                wordsInWindow++;

                // Too many occurrences of this word
                while (current[word] > required[word]) {

                    string leftWord = s.substr(start, wordLen);

                    current[leftWord]--;
                    wordsInWindow--;
                    start += wordLen;
                }

                // Exactly the required number of words
                if (wordsInWindow == wordsSize) {

                    ans.push_back(start);

                    // Remove leftmost word to search for
                    // the next possible overlapping window
                    string leftWord = s.substr(start, wordLen);

                    current[leftWord]--;
                    wordsInWindow--;
                    start += wordLen;
                }
            }
        }

        return ans;
    }
};