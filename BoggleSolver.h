//
// Created by Moaz Alhabbal on 4/21/16.
//

#ifndef PROJECT2_BOGGLESOLVER_H
#define PROJECT2_BOGGLESOLVER_H

#include <iostream>
#include <stddef.h>
#include <fstream>
#include <sstream>
#include "Tries.h"
#include<iostream>
#include<cstring>

using namespace std;

#define M 4
#define N 4

int count_words = 0;

void lettersSequence(char boggle[M][N], bool visited[M][N], int i, int j, string &str) {

    visited[i][j] = true;
    str = str + boggle[i][j];

    if (search(str) && str.length() > 3) {
        cout << str << endl;
        count_words += 1;
    }

    for (int row = i - 1; row <= i + 1 && row < M; row++)
        for (int col = j - 1; col <= j + 1 && col < N; col++)
            if (row >= 0 && col >= 0 && !visited[row][col])
                lettersSequence(boggle, visited, row, col, str);

    str.erase(str.length() - 1);
    visited[i][j] = false;
}

void findWords(char boggle[M][N]) {

    bool visited[M][N] = {{false}};
    string str = "";
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            lettersSequence(boggle, visited, i, j, str);
}

#endif //PROJECT2_BOGGLESOLVER_H
