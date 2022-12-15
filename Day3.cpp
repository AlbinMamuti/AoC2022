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

int findFirst(string first, string sec)
{
    // cout << first << ", " << sec << endl;

    for (int i = 0; i < first.length(); i++)
    {
        for (int j = 0; j < sec.length(); j++)
        {
            if (first[i] == sec[j])
            {
                // cout << first[i] << ", " << sec[j] << endl;
                char found = first[i];
                int ind = found - 65;
                // cout << ind << endl;
                if (ind < (91 - 65))
                {
                    ind += 26;
                    return ind + 1;
                }
                ind -= 32;
                return ind + 1;
            }
        }
    }

    return 0;
}
int findFirstMod(string first, string sec, string third)
{

    for (int i = 0; i < first.length(); i++)
    {
        for (int j = 0; j < sec.length(); j++)
        {
            for (int k = 0; k < third.length(); k++)
            {
                if (first[i] == sec[j] && first[i] == third[k])
                {
                    // cout << first[i] << ", " << sec[j] << endl;
                    char found = first[i];
                    int ind = found - 65;
                    // cout << ind << endl;
                    if (ind < (91 - 65))
                    {
                        ind += 26;
                        return ind + 1;
                    }
                    ind -= 32;
                    return ind + 1;
                }
            }
        }
    }

    return 0;
}
int main()
{
    string filename = "inputPartOne.txt";
    ifstream input_file(filename);

    int sumTemp = 0;

    int sumTempPart2 = 0;

    schema.push_back({3, 4, 8});
    schema.push_back({1, 5, 9});
    schema.push_back({2, 6, 7});

    vector<string> group;
    int k = 0;

    for (string line; getline(input_file, line);)
    {
        /*         stringstream ss(line);
                std::string first;
                std::string sec;

                std::getline(ss, first, ' ');
                std::getline(ss, sec, ' '); */
        group.push_back(line);
        k++;
        if (k % 3 == 0)
        {
            sumTempPart2 += findFirstMod(group[0], group[1], group[2]);
            group.clear();
        }
        int length = line.length();
        string first = line.substr(0, length / 2);
        string sec = line.substr(length / 2);

        int temp = findFirst(first, sec);
        // cout << temp << endl;
        sumTemp += temp;

        // sumTempPart2 += part2(first, sec);
    }

    cout << sumTemp << endl;
    cout << sumTempPart2 << endl;
}
