#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <queue>

using namespace std;
int eval(string first, string sec)
{
    if (first == "A" && sec == "Y")
        return 6;
    if (first == "B" && sec == "Z")
        return 6;
    if (first == "C" && sec == "X")
        return 6;

    if (first == "A" && sec == "X")
        return 3;
    if (first == "B" && sec == "Y")
        return 3;
    if (first == "C" && sec == "Z")
        return 3;

    if (first == "A" && sec == "Z")
        return 0;
    if (first == "B" && sec == "X")
        return 0;
    if (first == "C" && sec == "Y")
        return 0;
    return 0;
}
vector<vector<int>> schema;

int part2(string first, string sec)
{
    // X Loose
    // Y Draw
    // Z Win
    int f = first == "A" ? 0 : first == "B" ? 1
                                            : 2;
    int s = sec == "X" ? 0 : sec == "Y" ? 1
                                        : 2;
    return schema[f][s];
    //[first][second] = points
}

int main()
{
    string filename = "inputPartOne.txt";
    ifstream input_file(filename);

    // A Rock
    // B Paper
    // c Scissor

    // X Rock  1p
    // Y Paper  2p
    // Z Scissor  3p

    // win 6 p
    // draw 3 p
    // loss 0 p

    int sumTemp = 0;

    int sumTempPart2 = 0;

    schema.push_back({3, 4, 8});
    schema.push_back({1, 5, 9});
    schema.push_back({2, 6, 7});

    for (string line; getline(input_file, line);)
    {
        stringstream ss(line);
        std::string first;
        std::string sec;

        std::getline(ss, first, ' ');
        std::getline(ss, sec, ' ');

        sumTempPart2 += part2(first, sec);

        int choice = 0;
        if (sec == "X")
            choice = 1;
        else if (sec == "Y")
            choice = 2;
        else
            choice = 3;

        sumTemp += (choice + eval(first, sec));
    }

    cout << sumTemp << endl;
    cout << sumTempPart2 << endl;
}
