#include <vector>
#include <iostream>
#include <algorithm>
#define ByAgamestaTeam ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i <  b ; ++i)
#define pool(i,a,b) for(int i = a ; i >= b ; --i)
#define all(x)  (x).begin()  , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define ull unsigned long long

const int OO = 0x3f3f3f3f;
using namespace std;

void solve()
{
    int n , q ,l , r , trc = 0;
    cin >> n;

    vector<int> arr(n) , checkDiff(n);
    loop(i,0,n)cin >> arr[i];

    loop(i,1,n)
    {
        if(arr[i] == arr[i-1]){checkDiff[i] = trc;continue;}
        checkDiff[i] = trc = i+1;
    }
    cin >> q;
    loop(i,0,q)
    {
        cin >> l >> r;l--;r--;
        if(checkDiff[l] == checkDiff[r])cout << "-1 -1\n";
        else cout << checkDiff[r] << ' ' <<  checkDiff[r]-1 << '\n';
    }
}

short t;
int main()
{
    ///ByAgamestaTeam///
    cin >> t;
    while(t--)solve();
    return 0;
}
