//
// Created by Moaz Alhabbal on 4/13/16.
//

#ifndef PROJECT2_TRIES_H
#define PROJECT2_TRIES_H

#include <iostream>

using namespace std;

class Tries {
public:
    bool end;
    int count;
    Tries *child[26];

} *head;

void inisilize() {
    head = new Tries();
    head->count = 0;
    head->end = false;
}

void insert(string word) {
    Tries *current = head;
    current->count++;
    for (int i = 0; i < word.length(); ++i) {
        int letter = (int) word[i] - (int) 'a';
        if (current->child[letter] == NULL)
            current->child[letter] = new Tries();

        current->child[letter]->count++;
        current = current->child[letter];
    }
    current->end = true;
}

bool search(string word) {
    Tries *current = head;
    for (int i = 0; i < word.length(); ++i) {
        if (current->child[(int) word[i] - (int) 'a'] == NULL)
            return false;
        current = current->child[(int) word[i] - (int) 'a'];
    }
    return current->end;
}


#endif //PROJECT2_TRIES_H
