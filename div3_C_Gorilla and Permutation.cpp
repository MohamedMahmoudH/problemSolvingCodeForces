#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i <  b ; ++i)
#define pool(i,a,b) for(int i = a ; i >= b ; --i)
#define all(x) (x).begin() , (x).end()
#define ull unsigned long long

const int OO = 0x3f3f3f3f;
using namespace std;

void solve()
{
    int n , m , k;
    cin >> n >> m >> k;
    vector<int> perm(n);
    loop(i,0,n)perm[i] = n-i;
    reverse(perm.end() - m , perm.end());
    loop(i,0,n)cout << perm[i] << ' ';
    cout << '\n';
}

short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while(t--)solve();
    return 0;
}

/// i got the pattern from testcases so don't need that
/*
int main()
{
    int n;cin >> n;
    vector<int> perm(n);
    loop(i,1,n+1)perm[i-1]=i;

    do
    {

    }while(next_permutation(perm));
}
*/
