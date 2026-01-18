class Solution {
public:

    string encode(vector<string>& strs) {


	string result = "";
	

        for(string str : strs){
result += to_string(str.length()) + "#" + str;
            
        }
       
        cout << result;
	return result;
}
    



    vector<string> decode(string s) {
vector<string> result;
    int i = 0;
    
    while (i < s.length()) {
        // Find '#'
        int pos = s.find('#', i);
        
        // Get length
        int len = stoi(s.substr(i, pos - i));
        
        // Get string
        string str = s.substr(pos + 1, len);
        result.push_back(str);
        
        // Move forward
        i = pos + 1 + len;
    }
    
    return result;
    }
};
