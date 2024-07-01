#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    cin >> arr[0];
    int tracker = arr[0] , mx = 0 , mo = 0;
    unsigned long long res = 0;
    loop(i,1,n)
    {
        cin >> arr[i];
        if(arr[i] >= tracker)tracker = arr[i];
        else
        {
            mo = tracker - arr[i];
            mx = max(mx , mo);
            res += mo;
        }
    }
    cout << res + mx << '\n';
}

short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while(t--)solve();
    return 0;
}
