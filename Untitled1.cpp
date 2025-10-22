#include <bits/stdc++.h>
using namespace std;
int num = 3;
vector<pair<string, int>> nnt = {
    {"MARATHON25_CUBESUM", 100},
    {"MARATHON25_STRFIX", 100},
    {"MARATHON25_PFSUM", 100}
};

int main ()
{
    freopen("TaskDirectories.txt", "w", stdout);
    for (int i = 0;i < num;++i)
        cout << nnt[i].first << "\n";
    for (int i = 0;i < num;++i)
        for (int j = 0;j < nnt[i].second;++j)
            cout << nnt[i].first << "\TEST" << (j < 10 ? "0" : "") << j << "\n";

}
