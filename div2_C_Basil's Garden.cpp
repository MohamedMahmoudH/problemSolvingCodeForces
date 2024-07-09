#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i <  b ; ++i)
#define pool(i,a,b) for(int i = a ; i >= b ; --i)
#define  all(x) (x).begin()  , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define ull unsigned long long

short dx[5] = {0 , 1 , 1 , 0};
short dy[5] = {0 , 0 , 1 , 1};

const int OO = 0x3f3f3f3f;
using namespace std;

void solve()
{
    int n , x = 0 , res = 0;
    cin >> n;
    loop(i,0,n){cin >> x; res = max(res , x+i);}
    cout << res << '\n';
}

short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while(t--)solve();
    return 0;
}

