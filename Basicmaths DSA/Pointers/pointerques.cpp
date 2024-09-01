#include<iostream>
using namespace std;
int main(){
    int first=8;
    int second=10;
    int *ptr=&second;
    *ptr=9;
    // find the outcome
    cout<<first<<" "<<second<<endl;
     int a=6;
     int *p=&a;
     int *q=p;
     (*q)++;
    // find the outcome
     cout<<a<<endl; 


     int c=8;
     int *PTR=&c;
    // find the outcome important 
     cout<<(*PTR)++<<" ";
     cout<< c<< endl;

     int *P=0;
     int t=1;
     *p=t;
     cout<<*p<<endl;


     int arr[5];
     int *pointer;
     cout<< sizeof(arr) <<" "<<sizeof(pointer) <<endl;

     int num[4]={11,21,13,14};
     cout<<*(arr) <<" "<<*(arr+1)<<endl;
     int *T=num;
    // find the outcome
     cout<<T[2]<<endl;

    // here you are trying to update the symbol table
     int dum[4]={11,21,31,41};
    //  int *R=dum++;
    // find the outcome
    //  cout<< *R<<endl;

     char ch='a';
     char *y=&ch;
     ch++;
    // find the outcome
     cout<<*y<<endl;


     int frst=110;
     int *g=&frst;
     int **f=&g;
     int scnd=(**f)++ +9;
     cout<<"first is"<<frst<<" " << scnd<<endl;

     int third=100;
     int *hpointer=&third;
     int **secpointer=&hpointer;
     int fourth=++(**secpointer);
     int *newpointer=*secpointer;
     ++(*newpointer);
    // find the outcome
     cout<< third<<" "<<fourth<<endl;

     


}