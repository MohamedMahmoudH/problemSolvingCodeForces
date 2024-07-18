#include <cmath>
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i <  b ; ++i)
#define pool(i,a,b) for(int i = a ; i >= b ; --i)
#define all(x)  (x).begin()  , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define ull unsigned long long

const int OO = 0x3f3f3f3f;
using namespace std;

bool isPowerofTwo(ull n)
{
    return (n > 0) && ((n & (n - 1)) == 0);
}

void solve()
{
    ull n , suii = 0;
    cin >> n;
    if(1 == n){cout << "1\n1\n";return;}
    if(isPowerofTwo(n)){cout << "1\n" << n << '\n';return;}
    int ones = __builtin_popcountll(n) , x = floor(log2(n));
    cout << ones+1 << '\n';

    pool(i,x,0)
    {
        suii = n & ~(1ULL << i);
        if(n == suii)continue;
        cout << suii << ' ';
    }
    cout << n << '\n';
}

short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while(t--)solve();
    return 0;
}
