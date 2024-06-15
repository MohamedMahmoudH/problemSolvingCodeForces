#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve()
{
    short n , k , x = 0;
    cin >> n >> k;

    vector<short>freq(101,0);
    for(short i = 0 ; i < n ; ++i)
    {
        cin >> x;
        freq.at(x)++;
    }
    sort(freq.begin() , freq.end() , greater<short>());

    if(freq[0] < k)cout << n << "\n";
    else cout << k-1 << "\n";
}

short t;
int main()
{
    ByMohamedMahmoud
    cin >> t;
    while(t--)solve();
    return 0;
}

