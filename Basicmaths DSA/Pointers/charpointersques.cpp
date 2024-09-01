#include<iostream>
using namespace std;
void increment(int **p){
    ++(**p);
}
int main(){
char arr[]="abcde";
char *p=&arr[0];
cout<<p<<endl;

char str[]="babbar";
char *P=str;
cout <<str[0]<<" "<<P[0]<<endl; 


int num=100;
int *ptr=&num;
increment(&ptr);
cout<< num <<endl;

}
