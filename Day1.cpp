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

int main()
{
    string filename = "inputPartOne.txt";
    ifstream input_file(filename);
    /*     vector<vector<int>> input; */
    vector<int> sum;
    int max = -1;
    int sumTemp = 0;
    for (string line; getline(input_file, line);)
    {

                if (line.empty())
        {
            sum.push_back(sumTemp);
            sumTemp = 0;
            continue;
        }
        sumTemp += stoi(line);
    }
    sort(sum.begin(), sum.end(), greater<int>());
    cout << sum[0] + sum[1] + sum[2] << endl;
}