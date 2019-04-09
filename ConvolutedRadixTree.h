#ifndef CRT_AGT
#define CRT_AGT

#include <bits/stdc++.h>
using namespace std;

const long MAX_S = 256;
#define DEBUG if(0)

class ConvolutedRadixTreeNode {
private:
    string word;
    long sons;
    map<char, ConvolutedRadixTreeNode*> next;
    bool endOfWord;
public:
    /* Constructor
     * Initializes all possible others caracters as null points
     * By default, this code word is "$" and has no sons.*/
    ConvolutedRadixTreeNode() {
        this->word = "$", this->sons = 0; this->endOfWord = false;
    }

    /* Basic encapsulation funcions to get content of a node*/
    string getWord() { return this->word; }
    long getSons() { return this->sons; }
    map<char, ConvolutedRadixTreeNode*> getNext() { return this->next; }
    bool isEndOfWord() { return this->endOfWord; }

    /* Word insertion function
     * Assign the latter word[idx] to this word
     * Creating and assigning the others letters to the other nodes
     * linked to this one */
    void insert(string word, long idx) {
        this->word = word[idx];
        if(idx+1<word.size()) {
            if(!next.count(word[idx+1])) {
                sons += 1;
                next[word[idx+1]] = new ConvolutedRadixTreeNode();
            }
            next[word[idx+1]]->insert(word, idx+1);
        } else {
            this->endOfWord = true;
        }
    }

    /* Debug purporses
     * Prints the dfs spanning tree of this node*/
    void dfs() {
        cout << "Word inside: " << this->word << endl;
        for(long i=0;i<MAX_S;i++)
            if(next[i] != NULL) next[i]->dfs();
    }
};

class ConvolutedRadixTree {
private:
    map<char, ConvolutedRadixTreeNode*> root;
public:
    /*
     * */
    ConvolutedRadixTree(vector<string> dictionary) {
        for(string word : dictionary) {
            if(!root.count(word[0]))
                root[word[0]] = new ConvolutedRadixTreeNode();
            insert(word);
        }
    }

    void insert(string word) {
        if(!root.count(word[0]))
                root[word[0]] = new ConvolutedRadixTreeNode();
        this->root[word[0]]->insert(word, 0);
    }

    /* */
    vector<string> complete(ConvolutedRadixTreeNode *source, string prefix, long idx) {
        vector<string> set;
        if(idx+1 == prefix.size()) {
            for(pair<char, ConvolutedRadixTreeNode*> other : source->getNext()) {
                vector<string> answer = take(other.second);
                for(string substring : answer)
                    set.push_back(substring);
            }
        } else {
            if(source->getNext().count(prefix[idx+1]))
                return complete(source->getNext()[prefix[idx+1]], prefix, idx+1);
        }
        return set;
    }

    /* */
    vector<string> take(ConvolutedRadixTreeNode *source) {
        vector<string> set;
        for(pair<char, ConvolutedRadixTreeNode*> other : source->getNext()) {
                vector<string> answer = take(other.second);
                for(string substring : answer)
                    set.push_back(source->getWord() + substring);
        }
        if(!source->getSons() || source->isEndOfWord())
            set.push_back(source->getWord());
        return set;
    }

    /* */
    void autocomplete(string prefix) {
        cout << endl;
        vector<string> suffixes;
        if(root[prefix[0]])
            suffixes = complete(root[prefix[0]], prefix, 0);
        for(string results : suffixes)
            cout << "A possible suffix: \""<< results << "\"" << " (" << prefix + results << ")" << endl;
        cout << endl;
    }
};

#endif
