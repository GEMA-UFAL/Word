#ifndef JUSTIFIER_AGT
#define JUSTIFIER_AGT

#include <bits/stdc++.h>
#define pb push_back
using namespace std;


class Justifier {
private:
    vector< vector<long> > X;
    vector<string> list;
    vector<long> optimal, line;
    long width, opt;
public:
    Justifier(long width, vector<string> &list) {
        this->width = width;
        this->list = list;
        this->opt = INT_MAX;
	justify();
    }

    void justify() {
        precalculate();
        pathfind();
        print();
    }

    //O(n²/2)=O(n²) cost precalculation)
    void precalculate() {
        long N = list.size();
        X.resize(N);
        for(long i=0; i<N;i++)
            X[i].assign(N, INT_MAX);
        for(long i=0; i<N; i++) {
            long sum = 0;
            for(long j=i; j<N; j++, sum++) {
                sum += list[j].size();
                if(sum <= width)
                    X[i][j] = (long) pow(width-sum, 2);
            }
        }
    }

    //O(n²/2)=O(n²) find optimal answer with DP
    void pathfind() {
        optimal.resize(X.size()), line.resize(X.size());
        for(long i=X.size()-1; i>=0; i--) {
            optimal[i] = X[i][X.size()-1];
            line[i] = X.size();
            for(long j=X.size()-1; j>i; j--) {
                if(X[i][j-1] != INT_MAX) {
                    if(optimal[i] > optimal[j] + X[i][j-1]) {
                        optimal[i] = optimal[j] + X[i][j-1];
                        line[i] = j;
                    }
                }
            }
        }
    }

    void print() {
	cout << endl;
        for(long i=0, j=0; j<X.size(); i=j) {
            j = line[i];
            for(long k=i; k<j; k++) {
                cout << list[k];
                if(k+1 != j) cout << " ";
            }
            cout << endl;
        }
	cout << endl;
    }
};

#endif

