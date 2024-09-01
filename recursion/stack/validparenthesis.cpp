
#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string s) {
    stack<char> st;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } 
        else {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            if ((c == ')' && top == '(') || 
                (c == ']' && top == '[') || 
                (c == '}' && top == '{')) {
                st.pop();
            } 
            else {
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    else{
        return false;
    }
}

int main() {
    string s = "{[(]}";
    if (isValidParenthesis(s)) {
        cout << "The parentheses are valid." << endl;
    } else {
        cout << "The parentheses are not valid." << endl;
    }

    return 0;
}
