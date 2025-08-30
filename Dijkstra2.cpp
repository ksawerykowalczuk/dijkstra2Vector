#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main ()
{
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> tablicaPolaczen(n);
    for (int i = 0; i < m; i++)
    {
        int a,b,c;
        cin >> a>> b >> c;
        a--; b--;
        tablicaPolaczen[a].push_back({c, b});
        tablicaPolaczen[b].push_back({c, a});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> klelele;
    klelele.push({0, 0});
    vector<int> tablicaOdleglosci(tablicaPolaczen.size(), 2147483647);
    tablicaOdleglosci[klelele.top().second] = 0;
    while (!klelele.empty())
    {
        pair<int,int> obecny = klelele.top();
        klelele.pop();
        int ilosc = tablicaPolaczen[obecny.second].size();
        for (int i = 0; i < ilosc; i++)
        {
            pair<int,int> Sasiad = tablicaPolaczen[obecny.second][i];
            if (tablicaOdleglosci[Sasiad.second] > tablicaOdleglosci[obecny.second] + Sasiad.first)
            {
                klelele.push(Sasiad);
                tablicaOdleglosci[Sasiad.second] = tablicaOdleglosci[obecny.second] + Sasiad.first;
            }
        }
    }
    if (tablicaOdleglosci[tablicaOdleglosci.size()-1] == 2147483647)
    {
        cout << "-1";
    }
    else
    {
        cout << tablicaOdleglosci[tablicaOdleglosci.size()-1];
    }
}