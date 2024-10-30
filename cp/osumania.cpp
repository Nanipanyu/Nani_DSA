#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int rows;
        cin >> rows;
        vector<string> v(rows);
        for(int i=0;i<rows;i++) {
            string x;
            cin>> x;
            v[i]=x;
        }
        for(int i=rows-1;i>=0;i--) {
            for(int j=0;j<v[i].size();j++){
                if(v[i][j]=='#'){
                    cout<<j+1<<" ";
                }
            }
        }
        cout<<endl;

    }
    return 0;
}