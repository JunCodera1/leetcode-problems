class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) {
            return false;
        }

        vector<int> freq1(26);
        vector<int> freq2(26);

        for(auto &it : word1) {
            freq1[it - 'a']++;
        }

        for(auto &it : word2) {
            freq2[it - 'a']++;
        }

        for(int i = 0; i<26; i++) {
            if(freq1[i] && !freq2[i])
                return false;

            else if(freq2[i] && !freq1[i])
                return false;
        }
        sort(freq1.begin(), freq1.end(), greater<int>());
        sort(freq2.begin(), freq2.end(), greater<int>());

        for(int i = 0; i<26; i++) {
            if(freq1[i] != freq2[i])
                return false;
        }

        return true;
    }
};
