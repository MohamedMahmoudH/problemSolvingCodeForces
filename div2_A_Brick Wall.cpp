#include <cmath>
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve()
{
    short n ,m;
    cin >> n >> m;

    if(m % 2)m--;
    cout << (n*m/2) << "\n";
}

short t;
int main()
{
    ByMohamedMahmoud
    cin >> t;
    while(t--)solve();
    return 0;
}
