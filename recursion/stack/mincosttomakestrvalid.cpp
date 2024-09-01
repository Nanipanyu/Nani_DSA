#include<iostream>
#include<stack>
using namespace std;
int findMinimumCost(string str) {
  // Write your code here
  stack<char> s;
  int i=0;
  while (str[i] != '\0') {
    if (str[i] != '}'){
      s.push(str[i]);
    } 
    else {
    // if closing bracket found then check if its empty and if not and stack top val has a open bracket pop that
      if (!s.empty() && s.top() == '{') {
        s.pop();
      }  
    //  if no valid str than keep pushing the brackets in stack
      else {
        s.push(str[i]);
      }
    }
    i++;
  }
  // if stack wiith invalid brackets has odd values the making the str valid is impossible  then return -1
  if(s.size()%2!=0){
    return -1;
  }
  
  else{
    //count the no. of '{' and '}'
    int a=0;
    int b=0;
    while(!s.empty()){
      if(s.top()=='{'){
        a++;
      }
      else{
        b++;
      }
      s.pop();
    }
    int ans=(a+1)/2 + (b+1)/2; //eqn for converting the brackets in such a way it gives minimal cost
    return ans;
  }
}

int main(){
    string str="}}}}}{";
    int ans =findMinimumCost(str);
    cout<<ans;
}
