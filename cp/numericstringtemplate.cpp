#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            cin >> vec[i];
        }
        
        int m;
        cin >> m;
        vector<string> strings(m);
        for (int i = 0; i < m; ++i) {
            cin >> strings[i];
        }
        
        for (const string& s : strings) {
            if (s.size() != vec.size()) {
                cout << "NO" << endl;
                continue;
            }
            
            map<int, char> numToChar;
            map<char, int> charToNum;
            bool isMatch = true;
            
            for (int i = 0; i < n; ++i) {
                int num = vec[i];
                char ch = s[i];
                
                if (numToChar.count(num) == 0 && charToNum.count(ch) == 0) {
                    numToChar[num] = ch;
                    charToNum[ch] = num;
                } else if (numToChar.count(num) > 0 && charToNum.count(ch) > 0) {
                    if (numToChar[num] != ch || charToNum[ch] != num) {
                        isMatch = false;
                        break;
                    }
                } else {
                    isMatch = false;
                    break;
                }
            }
            
            if (isMatch) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
