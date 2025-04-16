#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Trienode{
    public:
        char ch;
        Trienode* children[26];
        bool isterminalnode;    //to keep track it is a word that has been inserted

        Trienode(char data){
            ch=data;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
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
            }

            //recursion
            insertutil(child , word.substr(1)); //now insert in child
        }

        void insertword(string word){
            insertutil(root,word);
            cout<<"It worked"<<endl;
        }

        //searching a word in our dictionary
        bool searchutil(Trienode* root,string word){
            //base case
            if(word.size()==0){
                return root->isterminalnode;
            }

            //Assumption , word will be in caps
            int index=word[0]-'A';  //to check if the first word of a string/substring is present in root->children
            Trienode* child;

            //present
            if(root->children[index]!=NULL){
                child=root->children[index]; //aage baro
            }
            else{
                //absent
                return false;
            }

            //recursion
            return searchutil(child,word.substr(1));
        }

        bool searchword(string word){
            return searchutil(root,word);
        }

        //deleting a word
        void deletewordutil(Trienode* root,string word){
            //base case
            if(word.size()==0){
                if(root->isterminalnode){
                    root->isterminalnode=false;  //deleting the existence of word by making its terminal node =false
                }
                return;
            }

            //Assumption , word will be in caps
            int index=word[0]-'A';    //to check if the first word of a string/substring is present in root->children
            Trienode* child;

            //present
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{  //if the word is not found
                //absent
                return;
            }

            //recursion
            return deletewordutil(child,word.substr(1));
        }

        void deleteword(string word){
            deletewordutil(root,word);
        }
};

int main(){
    Trie *t = new Trie();
    t->insertword("ABCD");
    t->insertword("DOG");
    t->insertword("NEW");

    cout<<"Present or not"<<t->searchword("DO")<<endl;
}