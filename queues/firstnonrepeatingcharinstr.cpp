#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
string FirstNonRepeating(string A)
{
    // Code here
    int s = A.size();
    map<char, int> lettercount;
    queue<char> q;
    string ans(s, '\0');
    for (int i = 0; i < s; i++)
    {
        lettercount[A[i]]++; //keeping a track of count of each letter
        q.push(A[i]);  //push char of string A
        while (!q.empty())  //to remove the char in queue having more than 1 occurenece in string A
        {
            if (lettercount[q.front()] > 1)  //if the char in queue.front has more than 1 occurence pop it 
            {
                q.pop();
            }
            else
            {
                ans[i] = q.front();  //if you git a char which is not repeated assign it to str s and break the loop as there is an nonrepeating element
                break;
            }
        }
        if (q.empty()) //if queue gets empty that means no nonrepeating words were available all words were repeated so insert # in string s
        {
            ans[i] = '#';
        }
    }
    return ans;
}
int main(){
    string A = "aabbcc";
    cout << FirstNonRepeating(A) << endl;

}