#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve()
{
    short n , a , b;
    cin >> n >> a >> b;
    if(b < 2*a)cout << (n/2)*b + (n%2)*a << "\n";
    else cout << n*a << "\n" ;
}

short t;
int main()
{
    ByMohamedMahmoud
    cin >> t;
    while(t--)solve();
    return 0;
}
