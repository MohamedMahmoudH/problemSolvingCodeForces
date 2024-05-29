#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(void)
{
    int n , k;
    int counter = 0 ;
    cin >> n >> k;

    if(n == 1)
    {
        cout << k << endl;
    }
    else
    {
        int limit = 1;
        for(counter = 0 ; ((limit << 1) <= k) ; ++counter)
        {
            limit <<= 1 ;
        }

        --limit;
        cout << limit << ' ' << (k -limit) ;
        for(counter = 2 ; counter < (n) ; ++counter)
        {
            cout << " 0";
        }
        cout << endl;
    }
}

short t;
int main()
{
    ByMohamedMahmoud
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}

