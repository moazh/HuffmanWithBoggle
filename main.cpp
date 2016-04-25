#include <iostream>
#include "Huffman.h"
#include "Tries.h"
#include "BoggleSolver.h"

using namespace std;

int main(int argc, char *argv[]) {

    string options[3];

    options[0] = "solveBoggle";
    options[1] = "Huffman_Encoder";
    options[2] = "Huffman_Decoder";


    string command = (string) argv[1];

    if (command == options[0]) {
        inisilize();
        string line;
        ifstream infile(argv[2]);
        while (std::getline(infile, line)) {
            insert(line);
        }
        cout << "lexicon insertion has been done... \n";

        char boggle[4][4];
        string table = argv[3];
        // eecaalephnboqtty
        int R = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++) {
                boggle[i][j] = table.at(R);
                R += 1;
            }

        findWords(boggle);
        cout << count_words << " words" << endl;

    }
    else if (command == options[1]) {
        encode(argv[2], argv[3]);
        cout << "Encoding has been done... \n";
    }
    else if (command == options[2]) {
        decode(argv[2], argv[3]);
        cout << "Decoding has been done... \n";
    }
    else {
        cout <<
        "the program conatin the following commands: \n \n solveBoggle \n Huffman_Encoder \n Huffman_Decoder \n \n please enter one of them and try again \n \n";
    }

    return 0;
}
