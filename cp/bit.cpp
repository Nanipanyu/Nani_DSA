#include<iostream>
#include<string>
using namespace std;
int update(int arr[]){
    int n = sizeof(arr)/sizeof(arr[0]);
    int x=0;
    for(int i=0;i<n;i++){
        if(arr[i]='++x'){
            x++;
        }
        if(arr[i]='x++'){
            x++;
        }
        if(arr[i]='--x'){
            x--;
        }
        if(arr[i]='x--'){
            x--;
        }
    }
    return x;
}
int main(){
    int x;
    cout<<"Enter your x"<<endl;
    cin>>x;
    int statement[4]={'x++','--x','--x','x++'};
    update(statement);

}