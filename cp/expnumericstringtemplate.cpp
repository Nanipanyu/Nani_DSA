#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

int main(){
    cout<<"Enter no. of test case"<<" ";
    int t;
    cin >> t;
    while (t--) {
        cout<<"Enter length of numeric array"<<" ";
        int n;
        cin >> n;
        vector<int> vec(n);
        for (int i = 0; i < n; ++i) {
            cout<<"Enter arr values"<<" ";
            cin >> vec[i];
        }
        cout<<"Enter no. of string you want"<<" ";
        int m;
        cin >> m;
        vector<string> strings(m);
        for (int i = 0; i < m; ++i) {
            cout<<"Enter string "<<" ";
            cin >> strings[i];
        }
        
        for (const string& s : strings) {
            if (s.size() != vec.size()) { //well if the string size does not  match with  vector(vec) size it is not its template
                cout << "NO" << endl;
                continue;
            }
            
            map<int, char> numToChar; //map to store the unique int values of vector and map it with corresponding char present at same index in string
            map<char, int> charToNum;//map to store the unique char values of string and map it with corresponding int present at same index in vector
            bool isMatch = true;
            
            for (int i = 0; i < n; ++i) {
                int num = vec[i];
                char ch = s[i];
                
                if (numToChar.count(num) == 0 && charToNum.count(ch) == 0) { //if the num is not in numtochar map & if the char is not in chartonum map, than map the num to corresponding ch in numtochar nad map the ch to corresponding num in chartonum map.
                    numToChar[num] = ch;
                    charToNum[ch] = num;
                } else if (numToChar.count(num) > 0 && charToNum.count(ch) > 0) { //if the num is already map to some char and ch is already map to some int then
                    if (numToChar[num] != ch || charToNum[ch] != num) {// check if the ch mapped to the num is = ch(s[i]) or if the num mapped to ch is= num(vec[i])
                        isMatch = false; //if not ismatch =false
                        break;
                    }
                } else {  // if we have a num that is mapped to char , but ch is not mapped to a int i.e(we have repetition in one(vec or string(s)) and no repition in one (vec or string(s)) or vice versa , then the string cannot be a template
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
