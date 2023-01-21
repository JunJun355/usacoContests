#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int level = 0;
vector<vector<char>> stage;

ifstream fin("Day17.in");
ifstream finn("Day17.inn");

void move_pat(vector<string> shape) {
    while (stage.size() < level + 7)
        stage.push_back({'.', '.', '.', '.', '.', '.', '.'});
    int blx=2, bly=3;
    for (int x=blx; x < blx + shape.size(); x++) {
        for (int y=level + bly; y < level + bly + shape[0].size(); y++) {
            stage[y][x] = shape[y - level - bly][x - blx];
        }
    }
}

bool move_down(vector<string> shape) {
    return false;
}

int main() {
    vector<string> shapes[5];
    for (int i=0; i<5; i++) {
        string inp; getline(finn, inp);
        do {
            shapes[i].push_back(inp);
            getline(finn, inp);
        } while (inp != "");
    }
    // for (int i=0; i<5; i++) {
    //     for (string j : shapes[i]) cout << j << endl;
    //     cout << endl;
    // }
    string pattern; fin >> pattern;
    for (int j=0; j < 1; j++) {
        do {
            move_pat(shapes[level % 5]);
        }
        while (move_down(shapes[level % 5]));

    }
    for (int i=0; i<stage.size(); i++) {
        for (int j=0; j<7; j++) {
            cout << stage[i][j];
        }
        cout << endl;
    }
}
