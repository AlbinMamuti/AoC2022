#include <bits/stdc++.h>
using namespace std;
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <stdlib.h>
#include <cmath>
#define ll long long
struct pairB
{
    ll xS;
    ll yS;
    ll xB;
    ll yB;
    ll dist;
};

ll manDist(ll x1, ll y1, ll x2, ll y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("inputPartOne.txt", "r", stdin);
    bool part1 = true;
    vector<pairB> posREADS;
    set<pair<int, int>> beacons;
    set<pair<int, int>> sensors;
    set<pair<int, int>> noBeacons;
    ll xS, yS, xB, yB;
    while (scanf("Sensor at x=%lld, y=%lld: closest beacon is at x=%lld, y=%lld ", &xS, &yS, &xB, &yB) == 4)
    {
        pairB t = {
            xS,
            yS,
            xB,
            yB,
            manDist(xS, yS, xB, yB),
        };
        posREADS.push_back(t);
        beacons.emplace(make_pair(xB, yB));
        sensors.emplace(make_pair(xS, yS));
    }
    if (part1)
    {
        ll sol = 0;
        for (ll x = -5'000'000; x <= 5'000'000; x++)
        {
            ll y = 2000000;
            for (auto pos : posREADS)
            {
                ll debug = manDist(x, y, pos.xS, pos.yS);
                if (debug <= pos.dist && (x != pos.xB || y != pos.yB))
                {
                    auto search = beacons.find({x, y});
                    if (search != beacons.end())
                        continue;
                    sol++;
                    break;
                }
            }
        }
        cout << sol << endl;
        return 0;
    }
    for (ll x = 0; x <= 4000000; x++)
    {
        ll y = 0;
        bool changed = true;
        while (changed)
        {
            changed = false;
            for (auto pos : posREADS)
            {
                ll debug = abs(pos.xS - x) + abs(pos.yS - y);
                if (debug <= pos.dist)
                {
                    y = pos.yS + pos.dist - abs(pos.xS - x) + 1;
                    changed = true;
                }
            }
        }
        if (y <= 4000000)
        {
            cout << (x * 4000000 + y) << endl;
            return 0;
        }
    }
    return 0;
}
