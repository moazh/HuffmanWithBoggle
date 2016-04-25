//
// Created by Moaz Alhabbal on 4/18/16.
//

#ifndef PROJECT2_NODE_H
#define PROJECT2_NODE_H

#include <stddef.h>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

bool enter = true;
int indexOF = 0;
string letters[27][2];

long chNumOriginal = 0;
long chNumEncoded = 0;

struct node {
    int freq;
    char ch;
    node *left;
    node *right;

    node(char c = ' ', int f = -1) {
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }

    node(node *link1, node *link2) {
        ch = ' ';
        freq = link1->freq + link2->freq;
        left = link1;
        right = link2;
    }

    bool operator()(const node &l, const node &r) {
        return l.freq > r.freq;
    }

    void traverse(string code = "") const;
};

void node::traverse(string code) const {

    if (enter) {
        enter = false;
        indexOF = 0;
    }

    if (left) {
        left->traverse(code + '0');
        right->traverse(code + '1');
    } else {
        chNumEncoded += freq * code.length();
        letters[indexOF][0] = ch;
        letters[indexOF][1] = code;
        indexOF++;
    }
}

void writeLastFile(string outputName, string inputName) {

    ofstream file;
    file.open(outputName, ios::trunc);
    string line;
    string str;
    ifstream infile(inputName);


    for (int i = 0; i < 27; i++) {
        file << letters[i][0];
        file << " ";
        file << letters[i][1];
        file << "\n";
    }
    while (std::getline(infile, line)) {
        chNumOriginal += line.length();
        for (char &c : line + "|") {
            int letter = (int) c;
            for (int i = 0; i < 27; i++)
                if ((int) (letters[i][0]).front() == letter)
                    file << letters[i][1];
        }
    }

    chNumOriginal *= 8;
    cout << "*the number of bits are needed for  ASCII  representation are: " << chNumOriginal << " bits" << endl;
    cout << "*the number of bits are needed for HUFFMAN representation are: " << chNumEncoded << "  bits" << endl;

    double rate = (chNumEncoded * 100) / chNumOriginal;
    cout << "*rate: " << rate << "%" << '\n' << endl;

    infile.close();
    file.close();
}


#endif //PROJECT2_NODE_H
