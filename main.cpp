#include <bits/stdc++.h>
#include "ConvolutedRadixTree.h"
#include "Finder.h"
#include "Justifier.h"

int main() {
    cout << "Auto-complete: Enter $$ + query" << endl;
    cout << "Find anything: Enter ## + query" << endl;
    cout << "Justify : Enter @@ + width" << endl;
    cout << "Exit : Enter \"END\"" << endl << endl;
    string text;
    vector<string> list;
    ConvolutedRadixTree crt(list);
    while(true) {
        string str;
        while(cin >> str, str != "END") {
            if(str ==  "$$") {
                string word;
                cin >> word;
                crt.autocomplete(word);
            }
            else if(str == "##") {
                string query;
                cin >> query;
                KMP kmp(text, query);
            } else if(str == "@@") {
                long width;
                cin >> width;
                Justifier js(width, list);
            } else {
                crt.insert(str);
                list.push_back(str);
                text.append(" " + str);
            }
        }
        if(str == "END")
            return 0;
    }
    return 0;
}
