#include <bits/stdc++.h>
using namespace std;
#include <stack>
#include <map>
#include <queue>
#include <stdlib.h>
#include <cmath>

int H = 41;
int W = 179;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("inputPartOne.txt", "r", stdin);

    vector<vector<char>> grid(H, vector<char>(W));

    pair<int, int> start = {0, 0};
    pair<int, int> end = {-1, -1};
    for (int i = 0; i < H; i++)
    {
        string line;
        getline(cin, line);
        for (int j = 0; j < line.length(); j++)
        {

            grid[i][j] = line[j];
            if (grid[i][j] == 'S')
            {
                start = {i, j};
                grid[i][j] = 'a';
            }
            if (grid[i][j] == 'E')
            {
                end = {i, j};
                grid[i][j] = 'z';
            }
        }
    }
    vector<vector<bool>> visited(H, vector<bool>(W));
    queue<pair<int, int>> q;
    q.push(start);
    vector<vector<int>> dist(H, vector<int>(W, -1));
    dist[start.first][start.second] = 0;
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        if (curr.first == end.first && curr.second == end.second)
        {
            cout << dist[curr.first][curr.second] << endl;
            break;
        }
        for (auto d : dir)
        {
            pair<int, int> to = {curr.first + d.first, curr.second + d.second};
            if (to.first < 0 || to.first >= H || to.second < 0 || to.second >= W || dist[to.first][to.second] != -1)
            {
                continue;
            }
            int distt = grid[curr.first][curr.second] - grid[to.first][to.second];
            if (distt >= -1)
            {
                dist[to.first][to.second] = dist[curr.first][curr.second] + 1;

                q.push(to);
            }
        }
    }
    while (!q.empty())
        q.pop();
    q.push(end);
    long long sol = 0;
    dist = vector<vector<int>>(H, vector<int>(W, -1));
    dist[end.first][end.second] = 0;
    vector<int> sols;
    while (!q.empty())
    {
        pair<int, int> curr = q.front();
        q.pop();
        if (grid[curr.first][curr.second] == 'a')
        {
            sols.push_back(dist[curr.first][curr.second]);
            continue;
        }
        for (auto d : dir)
        {
            pair<int, int> to = {curr.first + d.first, curr.second + d.second};
            if (to.first < 0 || to.first >= H || to.second < 0 || to.second >= W || dist[to.first][to.second] != -1)
            {
                continue;
            }
            int distt = grid[curr.first][curr.second] - grid[to.first][to.second];
            if (distt <= +1)
            {
                dist[to.first][to.second] = dist[curr.first][curr.second] + 1;

                q.push(to);
            }
        }
    }
    sort(sols.begin(), sols.end());
    cout << sols[0] << endl;
    return 0;
}