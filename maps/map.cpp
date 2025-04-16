#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

//map stores data in key value pair, i.e pair
int main(){
    unordered_map<string, int> m;

    //insertion
    //1
    pair<string,int> p=make_pair("Nani" , 3);
    m.insert(p);
    //2
    m.insert({"panyu", 2});
    //3
    pair<string,int> p2("is" , 3);
    m.insert(p2);

    //4
    m["good"]=1;

    //what will happen
    m["good"]=2;

    //when first insertion with a key is called than creation of key and val happens
    //when second insertion with a key is called than updation of val of that key happens
    //There is a single entry for a key, if you use a existing key than updation happens

    //search
    cout<<m["good"]<<endl;
    cout<<m.at("Nani")<<endl;

    // cout<<m.at("Newkey")<<endl;// like this you cannot create a new key this is only used to get value of an existion key
    cout<<m["Newkey"]<<endl; //like this you can create a new key("Newkey") with setting its value to 0 (if value is an int)Newkey:0

    //size
     cout<<m.size()<<endl; 

     //check presence
     cout<<m.count("Nani")<<endl; //return 1 if  key exist in m , else returns 0 if key does not exist in m

    //erase
    m.erase("Nani");
    cout<<m.count("Nani")<<endl;

    //accessing
    //1
    for(auto i:m){
        cout<<i.first<<" "; //to get key of m[i]
        cout<<i.second<<endl; //to get value of m[i]
    }
    //2 using iterator
    unordered_map<string,int> :: iterator it=m.begin();
    while(it!=m.end()){ //in unordered_map it is not printed in the order you have inserted(order you have inserted is not preserved)
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }





}