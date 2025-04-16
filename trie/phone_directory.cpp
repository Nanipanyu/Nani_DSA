#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Trienode
{
public:
    char ch;
    Trienode *children[26];
    bool isterminalnode; // to keep track it is a word that has been inserted

    Trienode(char data)
    {
        ch = data;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isterminalnode = false; // if false then the word is present as a substring of other string
    }
};

class Trie
{
public:
    // Our dictionary will start from one single one node which can have 26 children
    Trienode *root;
    Trie()
    {
        root = new Trienode('\0'); // inserting NULL character
    }
    // inserting word
    void insertutil(Trienode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            root->isterminalnode = true;
            return;
        }
        // Assumption , word will be in caps
        int index = word[0] - 'a'; // to check if the first word of a string/substring is present in root->children
        Trienode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index]; // move forward and go to for next char
        }

        // absent
        else
        {
            child = new Trienode(word[0]);
            root->children[index] = child;
        }

        // recursion
        insertutil(child, word.substr(1)); // now insert in child
    }

    void insertword(string word)
    {
        insertutil(root, word);
        // cout<<"It worked"<<endl;
    }

    void printsuggestion(vector<string> &temp, Trienode *curr, string prefix)
    {
        if (curr->isterminalnode)
        {
            temp.push_back(prefix);
            // return;   here we can't use return because even if we reach a terminal node(i.e one complete word/one suggestion) there may be other words that may be on the same chain in trie, and can form a suggestion
        }
        for (char ch = 'a'; ch <= 'z'; ch++) //for the current node(with some char value ) check all its children
        {
            Trienode *next = curr->children[ch - 'a']; //childrens of curr, we check so that to see if a word is forming as suggestion
            if (next != NULL) //means there is a word/suggestion in our contact list
            {
                prefix.push_back(ch); //push the char that is in curr->children(that can form suggestion) to prefix
                printsuggestion(temp, next, prefix); //recursive call; no go and check in next children if a char is present to form a suggestion
                prefix.pop_back(); // when backtracking pop froom prefix so that we can check on all children of curr, to consider all suggestion, (with similar prefix but different suffixes)
            }
        }
    }

    vector<vector<string>> getallsuggestion(string querystr)
    {
        vector<vector<string>> output;
        Trienode *prev = root;
        string prefix = "";   // to store the substring/prefix as we go forward in character of querystring
        for (int i = 0; i < querystr.size(); i++)  //traversing in character of query string
        {
            char lastch = querystr[i]; //last(rightmost) char in query string
            Trienode *curr = prev->children[lastch - 'a']; //curr is the trienode with char= lastch in the children of prev(we move in character in querystring )
            if (curr == NULL) //if curr==NULL means that query string with char 'ch' in rightmost is not available in contact list, so no suggestion
            {
                break;
            }

            //well if there is
            prefix.push_back(lastch); //keep pushing the last ch in prefix
            vector<string> temp; //to store the suggestion for the current specific prefix in contactList
            printsuggestion(temp, curr, prefix); //get all the suggestion for the current prefix in contactlist 
            output.push_back(temp); 
            temp.clear();// clear temp for the new suggestion with new prefix
            prev = curr; //move  prev to the current trienode with the latest char of querystring / we make a trienode with char=latest char in querystring , such as we move forward in our trie
        }
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{

    //    Write your code here.
    vector<vector<string>> allsuggestion(); //vector of vector of all suggestion as we go forward in character of queryStr
    int n = contactList.size();
    Trie *root = new Trie();
    for (int i = 0; i < n; i++) //inserting all the contact list in Trie;
    {
        root->insertword(contactList[i]);
    }
    //get all suggestion for query string
    return root->getallsuggestion(queryStr);
}