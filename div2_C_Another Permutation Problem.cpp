#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()
#define ull unsigned long long

const int OO = 0x3f3f3f3f;
using namespace std;

void solve()
{
    short n , ind = 2;
    cin >> n;
    if(n == 2)
    {
        cout << 2 << '\n' ;
        return;
    }
    int res = 0 , curr = 0 , x = 0 , mx = 0;
    vector<int> perm(n) , s;

    loop(i,0,n)perm[i] = i + 1;
    loop(i,1,n-1)x += i*i;
    s = perm ; s[n-1]-- ; s[n-2]++;
    loop(i,0,n/2)
    {
        curr = x , x -= ((n - ind)*(n - ind)) , mx = 0;
        loop(i,n - ind,n)
        {
            curr += s[i]*(i + 1);
            mx = max(mx , s[i]*(i + 1));
        }
        curr -= mx;
        res = max(res , curr);
        ind++;
        s.erase(s.end() - ind) , s.push_back(s[n-2] - 1);
    }
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


/// this code for get the right pattern for this permutation problem ///
/*
int suii(vector<int>& vec , int n)
{
    ull res = 0;
    int mx = 0;
    for(int i = 1 ; i <= n ; ++i)
    {
        res += vec[i-1]*i;
        mx = max(mx , vec[i-1]*i);
    }
    return(res - mx);
}

int main()
{
    {
        int n;
        cin >> n;
        vector<int> vec(n);
        loop(i,0,n)vec[i] = i + 1;

        int x = 0 , y = 0;
        do{
            x = suii(vec , n);
            if(x >= y)
            {
                loop(i,0,n)cout << vec[i] << ' ';
                cout << "-------> " << suii(vec , n) << '\n';
            }
            if(y < x)y = x;
        }while(next_permutation(all(vec)));
    }
    return 0;
}
*/
