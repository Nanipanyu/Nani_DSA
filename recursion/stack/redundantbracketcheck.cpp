#include<iostream>
#include<stack>
using namespace std;
bool findRedundantBrackets(string &s)
{
    // Write your code here.
    stack<char> ch;
    int i=0;
    // traversing the string
    while(s[i]!='\0'){
        //Keep pushing in a stack unless a cosing bracket is there
        if(s[i]!=')'){
            ch.push(s[i]);
        }
        else if(s[i]==')'){  //when you get a close bracket 
        //if the just previous element is '(' we have a redundant bracket 
            if(ch.top()=='('){
                return true;
            }
            else{
                int count=0; //to check if there is just a single char within the bracket ex-(a+c*b)+(c) ;bracket around c is not needed
                char check; //to check if there is just a single char within the bracket and the char can be a expression not a alphabet ex-(a+c*b)+(c) and ((b*c)*(a/b)) ;bracket around c is not needed
                //start removing elements from stack until you find a opening bracket
                while(ch.top()!='('){
                    count++;  
                    check=ch.top() ;                 
                    ch.pop();
                }
                //well if there is only one char between the bracket and and the char is alphabet then it has a redundant bracket
                if(count==1 && check >= 'a' && check <= 'z'){
                    return true;
                }
                count=0;
                ch.pop();
            }
        }
        i++;
        
    }
    
    return false;
}

// 2nd approach  if you find a closing bracket then check if there is a operator between the opening and closing bracket
bool findRedundantBracket(string &s){
    stack<char> st;
    int i=0;
    while(s[i]!='\0'){
        if(s[i]!=')' ){
            st.push(s[i]);
        }
        else{
            if(s[i]==')'){
                bool isredundant=true;
                while(st.top()!='('){
                    char top=st.top() ;
                    if(top=='+' || top=='-' || top=='/' || top=='*'){
                        isredundant=false;
                    }
                    st.pop();
                }
                if(isredundant){
                    return true;
                }
                st.pop();
            }
        }
        i++;
    }
    return false;
}

int main(){
    string s = "a+b*(c-d)+e";
    string n="(((a+b)))";;
    string k="(a+c*b)+(c)";
    string m="((b*c)*(a/b))";
    if(findRedundantBracket(k)){
        cout<<"It has a redundant bracket"<<endl;
    }
    else{
        cout<<"It does not have a redundant bracket"<<endl;
    }
}