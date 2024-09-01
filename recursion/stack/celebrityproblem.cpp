#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution 
{
  private:
    //function to check if a(person) knows b(person)
    bool knows(vector<vector<int> >& mat, int a, int b){
        if(mat[a][b]==1){ // a knows b
            return true;
        }
        else{
            return false; 
        }
    }
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {  //Given a 2d array(vector of vector)A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.  A square matrix mat(row) is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.
        // code here
        int n=mat.size(); //No . of people

        //Trick is celebrity will have all its rows zero because he knows no one and all the columns=1 except him because everybody knows him

        //we push all the people in a stack and compare two of them at a time if(A knows B(i.e= matrix[a][b]=1) A is not a celebrity A is discarded)
        stack<int> s;
        for(int i=0;i<n;i++){
            s.push(i);
        }
        while(s.size()>1){ //comparing two people in stack unless there is only one person left(i.e the celebrity)
            int a=s.top(); //a=1st person
            s.pop();
            int b=s.top(); //b=2nd person
            s.pop();
            if(knows(mat,a,b)){ //if a knows b (b can be a celeb) so push b Back inside
                s.push(b);
            }
            if(knows(mat,b,a)){
                s.push(a); //vice versa
            }
        }
        int ans=s.top(); //potential celebrity left in stack;
        int zerocount=0;
        // bool rowcheck=false;
        //checking if all its rows value=0, i.e he does not know anyone
        for(int i=0;i<n;i++){
            if(mat[ans][i]==0){
                zerocount++;
            }
        }
        if(zerocount!=n){ //if all its rows value!=0, it aint a celeb , therefore no potential cnadidate
            return -1;
        }
        
        int onecount=0;
        // bool colcheck=false;
        //checking if all its col value=1, except itself i.e everybody knows him

        for(int i=0;i<n;i++){
            if(mat[i][ans]==1){
                onecount++;
            }
        }
        if(onecount!=n-1){
            return -1;
        }
        
       
        return ans;
       
    }
};
int main(){
    vector<vector<int> > mat = {{0, 0, 1, 0},{0,0,1,0},{0,0,0,0},{0,0,1,0}};
    Solution solution;
    int result=solution.celebrity(mat);
    cout<<result<<endl;
}