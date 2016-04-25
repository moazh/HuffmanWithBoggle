//
// Created by Moaz Alhabbal on 4/18/16.
//

#ifndef PROJECT2_HUFFMAN_H
#define PROJECT2_HUFFMAN_H


#include "Node.h"
#include "Timer.h"
#include <queue>
#include<map>


using namespace std;

Timer encoderTIMER, decoderTIMER;
static double encoderTIME, decoderTIME;

class Huffman {
};

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}
std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

void encode(string inputName, string outputName) {
    encoderTIMER.reset();

    int cnt;
    char c;
    priority_queue<node, vector<node>, node> q;
    string line;
    ifstream infile(inputName);

    string str;
    while (std::getline(infile, line)) {
        str += "|" + line;
    }

    for (int i = 97; i <= 124; i++) {
        c = (char) i;
        cnt = (int) count(str.begin(), str.end(), c);
        if (cnt) {
            q.push(node(c, cnt));
            cnt = 0;
        }
    }

    while (q.size() != 1) {
        node *left = new node(q.top());
        q.pop();
        node *right = new node(q.top());
        q.pop();
        q.push(node(left, right));
    }
    q.top().traverse();
    encoderTIME = encoderTIMER.elapsed();
    cout << "the file has been encoded in " << encoderTIME << '\n' << endl;

    writeLastFile(outputName, inputName);
}

void decode(string inputName, string outputName) {

    decoderTIMER.reset();

    char c;
    string s, t, ans;
    map<string, char> mymap;
    map<string, char>::iterator it;

    string line;
    ifstream infile(inputName);

    int count = 0;
    while (std::getline(infile, line)) {
        if (count < 27) {
            string text = line;
            std::vector<std::string> x = split(text, ' ');
            string simple = x.at(0);
            char *cstr = new char[simple.length() + 1];
            std::strcpy(cstr, simple.c_str());
            char q = *cstr;
            mymap[x.at(1)] = q;
            count++;
        }
        else {
            s = line;
        }
    }
    infile.close();

    t = "";
    ans = "";
    for (int i = 0; i < s.size(); i++) {
        t += " ";
        t[t.size() - 1] = s[i];
        it = mymap.find(t);
        if (it != mymap.end()) {
            c = mymap[t];
            ans += " ";
            ans[ans.size() - 1] = c;
            t = "";
        }
    }

    decoderTIME = decoderTIMER.elapsed();
    cout << "the file has been decoded in " << decoderTIME << '\n' << endl;

    ofstream file;
    file.open(outputName);
    file << ans;
    file.close();
}


#endif //PROJECT2_HUFFMAN_H
