#ifndef KMP_AGT
#define KMP_AGT

#include <bits/stdc++.h>

using namespace std;

#define MAX_S 256

class KMP{
private:
    string text, pattern;
    vector<long> dfa;
    long N, M;

public:
    KMP(string text, string pattern) {
        this->text = text;
        this->pattern = pattern;
        this->N = text.size();
        this->M = pattern.size();
        dfa.resize(N);
        long i=0, j=-1;
        dfa[0]=-1;
        while(i<M) {
            while(j >= 0 && pattern[i]!=pattern[j]) j = dfa[j];
            i++, j++;
            dfa[i] = j;
        }
        search();
    }

    long search() {
        long i=0, j=0, words=0;
        while(i < N) {
            while(j >= 0 && text[i]!=pattern[j]) j = dfa[j];
            i++, j++;
            if(j == M) {
                cout << "Present at word number " << words+1 << "." << endl;
                j = dfa[j];
            }
            if(i>0 && text[i]!=text[i-1] && text[i]==' ')
                words++;
        }
    }
};

#endif

