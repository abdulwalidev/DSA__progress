// adding general valid paranthesis code from uni

#include <iostream>
#include <stack>
using namespace std;
//leetcode function 
bool isValidParentheses(const string& s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c); // push opening brackets
        } else {
            if (st.empty()) return false;

            char top = st.top();
            st.pop();

            // check for matching pair
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }

    return st.empty(); // true if all brackets matched
}

int main() {
    string s1 = "()[]{}";
    string s2 = "([)]";
    string s3 = "{[()]}";

    cout << s1 << ": " << (isValidParentheses(s1) ? "Valid" : "Invalid") << endl;
    cout << s2 << ": " << (isValidParentheses(s2) ? "Valid" : "Invalid") << endl;
    cout << s3 << ": " << (isValidParentheses(s3) ? "Valid" : "Invalid") << endl;

    return 0;
}
