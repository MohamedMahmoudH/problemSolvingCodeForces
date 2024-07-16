#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i <  b ; ++i)
#define pool(i,a,b) for(int i = a ; i >= b ; --i)
#define all(x)  (x).begin()  , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define ull unsigned long long

const int OO = 0x3f3f3f3f;
using namespace std;

void solve()
{
    short n , k , cnt = 0;
    cin >> n >> k;

    for(;n > 1;++cnt)n -= (k - 1);
    cout << cnt << '\n';
}

short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while(t--)solve();
    return 0;
}
/*
if(2 == k)cout << n-1 << '\n';
else if(k >= n) cout << 1 << '\n';
else cout << n/(--k) << '\n';
*/
