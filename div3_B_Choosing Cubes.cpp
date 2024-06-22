#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define MOD 1000000007
using namespace std;

void solve()
{
    short f , k , n;
    cin >> n >> f >> k;

    vector<short> arr(n);
    for(short i = 0 ; i < n ; ++i)cin >> arr[i];

    short favNum = arr[f - 1];

    bool flag = false;
    sort(arr.begin() , arr.end() , greater<short>());
    for(short i = 0 ; i < k ; ++i)
    {
        if(arr[i] == favNum)flag = true;
        arr[i] = 0;
    }

    sort(arr.begin() , arr.end());
    if(!(binary_search(arr.begin() , arr.end() , favNum)))cout << "YES" << '\n';
    else if(flag)cout << "MAYBE" << '\n';
    else cout << "NO" << '\n';
}

short t;
int main()
{
    cin >> t;
    while(t--)solve();
    return 0;
}
