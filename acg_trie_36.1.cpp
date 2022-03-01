// #include <iostream>
// #include <vector>
#include<bits/stdc++.h>
using namespace std;
class Trie{
    public:
        class node{
            public:
                bool end;
                node*next[26];
                node(){
                    end = false;
                    for(int i=0;i<26;i++){
                        next[i] = NULL;
                    }
                }
        };
        node * trie;
        Trie(){
            trie = new node();
        }

        void insert(string word){
            int i=0;
            node * it =  trie;
            while(i<word.size()){
                if(it->next[word[i]-'a'] == NULL){ // if node doesnt exist
                    it->next[word[i]-'a'] = new node();
                }
                it = it->next[word[i]-'a'];
                i++;
            }
            it->end =true;
        }

        bool search(string word){

            int i=0;
            node* it  = trie;
            while(i<word.size()){
                if(it->next[word[i]-'a'] == NULL)
                    return false;
                it = it->next[word[i]-'a'];
                i++;
            }
            return it->end;

        }



} ; 
int main() 
{  Trie *mytrie  = new Trie();
    vector<string> words= { "ayush","daasi"};
    for(auto w:words){
        mytrie->insert(w);
    }
    if(mytrie->search("madhav")){
        cout<<"madhav found\n";
    }
    else{
        cout<<"madhav not found \n";
    }
    if(mytrie->search("ayush")){
        cout<<"ayush found\n";
    }
    else{
        cout<<"ayush not found \n";
    }
    
    
    
    cout<<endl;
    return 0;
  }