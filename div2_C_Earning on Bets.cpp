#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void solve()
{
    short n , maxNum = 0;
    cin >> n;

    long double frac = 0;
    vector<short> arr(n);
    for(short i = 0 ; i < n ; ++i)
    {
        cin >> arr[i];
        frac += 1.0 / arr[i];
        maxNum = max(arr[i] , maxNum);
    }
    long double q = 0;
    for(short i = 0 ; i < n ; ++i)
    {
        q += (long double)maxNum / arr[i];
    }

    if(q >= maxNum) cout << -1 << '\n';
    else
    {
        int x = ceil((long double)n / (1 - frac));
        frac = 0;
        for(short i = 0 ; i < n - 1 ; ++i)
        {
            cout << (int)(floor((long double)x / arr[i]) + 1) << ' ';
            frac +=  floor((long double)x / arr[i]) + 1;
        }
        cout  << (int)(x - frac) << '\n';
    }

}

short t;
int main()
{
    cin >> t;
    while(t--)
    {
        solve();
    }
    return 0;
}

