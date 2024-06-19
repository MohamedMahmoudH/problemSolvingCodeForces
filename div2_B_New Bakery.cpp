#include <algorithm>
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void solve()
{
    unsigned long long profit = 0;
    int n , a , b , k = 0;
    cin >> n >> a >> b;

    k = b - a;
    if(k > min(n , b)) k = min(n , b);
    if(a >= b) k = 0;
    profit = (n - k) * (unsigned long long)a;
    if(k) profit += (unsigned long long)k * b - ((unsigned long long)k * (k - 1)) / 2;
    cout << profit << '\n';
}

short t;
int main()
{
    ByMohamedMahmoud
    cin >> t;
    while(t--)solve();
    return 0;
}
