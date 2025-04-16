#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Trienode{
    public:
        char ch;
        int childcount;  //keepint a track of child of each trienode
        Trienode* children[26];
        bool isterminalnode;    //to keep track it is a word that has been inserted

        Trienode(char data){
            ch=data;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            childcount=0;
            isterminalnode=false;  //if false then the word is present as a substring of other string
        }  
};

class Trie{
    public:

        //Our dictionary will start from one single one node which can have 26 children
        Trienode* root;
        Trie(){
            root=new Trienode('\0'); //inserting NULL character
        }
        //inserting word
        void insertutil(Trienode* root , string word){
            //base case
            if(word.size()==0){
                root->isterminalnode=true;
                return;
            }
            //Assumption , word will be in caps
            int index=word[0] - 'A';      //to check if the first word of a string/substring is present in root->children
            Trienode* child;

            //present
            if(root->children[index]!=NULL){
                child=root->children[index]; // move forward and go to for next char
            }

            //absent
            else{
                child=new Trienode(word[0]);
                root->children[index]=child;
                root->childcount++;
            }

            //recursion
            insertutil(child , word.substr(1)); //now insert in child
        }

        void insertword(string word){
            insertutil(root,word);
            cout<<"It worked"<<endl;
        }
};

//trie approach
string longestCommonPrefix(vector<string> &arr, int n) {
    Trie *root=new Trie();

    // inerting the strings in arr in trie
    for(int i=0;i<n;i++){
        root->insertword(arr[i]);
    }
    string a=arr[0]; // taking a string to get index of trienodes
    int i=0;
    string ans;  // here we will push our longest prefix substring/string
    Trienode* currentNode = root->root; //first node of our trie(it is null and has childs)
    while(i<a.size()){
        int index=a[i]-'a'; //getting index of prefix of words to go to its postion of child node.
        if(currentNode->childcount>1){
            break;
        }
        else if(currentNode->childcount==0){ //if no common prefix return empty string
            ans="";
            break;
        }
        else{
            ans.push_back(a[i]); //if only 1 child node push tha char in ans
            currentNode=currentNode->children[index]; //and move one to the next single child
        }
        i++;
    }
    return ans;
}


//loop approach
string longestCommonPrefix(vector<string> &arr, int n) {
    string a=arr[0]; 
    string ans;  // here we will push our longest prefix substring/string
    for(int i=0;i<a.size();i++){
        char ch=a[i];
        bool match=true;
        for(int j=1;j<n;j++){
            if(arr[j].size()<=i || arr[j][i]!=ch ){//when the commparing string char index get greater than a string and if a same index char of strings does not match
                match=false;
                break;
            }
        }
        if(match){ //if char is amtch in all strings push the char in ans
            ans.push_back(ch);
        }
        else{
            break;
        }
    }
    return ans;
}
