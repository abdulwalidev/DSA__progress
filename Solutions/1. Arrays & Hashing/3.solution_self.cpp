#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isAnagram(string s, string t) {
    if (s.length() != t.length()) 
        return false;

    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    return s == t;
}

int main() {
    string s, t;
    cin >> s >> t;

    if (isAnagram(s, t))
        cout << "Anagram" << endl;
    else
        cout << "Not an Anagram" << endl;

    return 0;
}
