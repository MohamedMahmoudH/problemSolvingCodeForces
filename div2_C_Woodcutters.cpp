#include <vector>
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i <  b ; ++i)
#define pool(i,a,b) for(int i = a ; i >= b ; --i)
#define all(x) (x).begin() , (x).end()
#define ull unsigned long long

const int OO = 0x3f3f3f3f;
using namespace std;

void solve()
{
    int n , counter = 0;
    cin >> n;
    if(1 == n)counter = -1;

    vector<pair<int , int>> road(n);
    loop(i,0,n)cin >> road[i].first >> road[i].second;

    loop(i,1,n-1)
    {
        if     (road[i].first - road[i].second > road[i - 1].first)counter++;
        else if(road[i].first + road[i].second < road[i + 1].first)counter++ , road[i].first += road[i].second;
    }
    cout << counter + 2;
}

short t;
int main()
{
    ByMohamedMahmoud
    solve();
    return 0;
}

