#include <cmath>
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve()
{
    short n , m , k , mostColorUsed = 0;
    cin >> n >> m >> k;
    mostColorUsed = static_cast<short>(ceil(static_cast<double>(n) / m));
    if((n - mostColorUsed) > k)cout << "YES" << endl;
    else cout << "NO" << endl;
}

short t;
int main()
{
    ByMohamedMahmoud
    cin >> t;
    while(t--)solve();
    return 0;
}
