#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve()
{
    short n , m;
    cin >> n >> m;

    if(m > n) cout << -1;
    else
    {
        n++;
        n /= 2;
        if(!(n % m))cout << n;
        else cout << n + m - n%m ;
    }
}


int main()
{
    ByMohamedMahmoud
    solve();
    return 0;
}
