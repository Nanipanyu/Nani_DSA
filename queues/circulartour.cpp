#include<iostream>
#include<vector>
using namespace std;

int tour(vector<vector<int>> p,int n)
    {
       //Your code here
       int rear=0; //to move in the vector p
       int start =0;   //to set pointer at station from where we can start 
       int balance =0;  //to count the balance of petrol ineach station
       int deficit=0;  // if balance<0 to store the deficit so that when we reach the last station and it is still possible to go we do balance - deficit, so that we wont have to traverse the loop again
       while(rear<n){
           balance=balance+p[rear][0]-p[rear][1]; //storing and adding balance at subsequent station
           if(balance<0){ //if balance gets negative
                deficit=balance + deficit;  //store the deficit and add the deficit in previous station if there was so that if later from some front stations if we are able to go till last station, we need to check circularly for the staion behind starting staion, so to not go back & check the vector in the loop we use deficit to calculate if the final balance is able to cover the deficit ;
                start=rear+1; //if balcnce<0 we need to change the starting station from rear+1
                rear=start;  // we can jump the rear to start and start checking for new station
                balance=0;     // after setting the start from new station , we need to have a new balance           
           }
            else{
                rear++; //if balance >0 keep  moving forward
            }
           
       }
       if(balance+deficit>=0){  //after reaching last station if balance can cover the deficit i.e, it is possible to travel circulary to each station 
           return start;
       }
       else{   //not possible to travel circularly
           return -1;
       }
    }
    int main(){
        vector<vector<int>> p = {{4,6}, {6,5}, {7,3},{3,5}};
        int n = p.size();
        int result = tour(p,n);
        cout<<"You can start from"<<" "<<result<<endl;
    }