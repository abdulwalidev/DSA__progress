class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (string &word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            mp[sortedWord].push_back(word);
        }
        vector<vector<string>> res;
        for (auto &p : mp) res.push_back(p.second);
        return res;
    }
};
