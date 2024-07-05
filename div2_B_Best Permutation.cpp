#include <vector>
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()
#define ull unsigned long long

const int OO = 0x3f3f3f3f;
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> perm(n);
    loop(i,0,n)perm[i] = i+1;
    perm[n-3]-- , perm[n-4]++ ;
    if(n >= 6) perm[n-5]-- , perm[n-6]++;

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

/// this code for get the right pattern for this permutation problem ///
/*
int suii(vector<int>& perm , int n)
{
    int x = 0;
    loop(i,0,n)
    {
        if(x < perm[i])x += perm[i];
        else x = 0;
    }
    return x;
}

int main()
{
    int t = 10;
    while(t--)
    {
        int n;cin >> n;

        vector<int> perm(n);
        loop(i,0,n)perm[i] = i + 1;
        int x = 0 , y = 0;
        do
        {
            x = suii(perm , n);
            if(y <= x)
            {
                loop(i,0,n)cout << perm[i] << ' ';
                cout << "----------> " << x << '\n';
            }
            if(y < x)y = x;
        }while(next_permutation(all(perm)));
    }
}
*/

/// this code to check if this pattern is the solution for all n or not ///
/*
bool can(int n)
{
    vector<int> perm(n);
    loop(i,0,n)perm[i] = i+1;
    perm[n-3]-- , perm[n-4]++ ;
    if(n >= 6) perm[n-5]-- , perm[n-6]++;
    int x = 0;
    loop(i,0,n)
    {
        if(x < perm[i])x += perm[i];
        else x = 0;
    }
    if(x == (2*n - 1))return true;
    else return false;
}
int main()
{
    loop(i,4,101)cout << i << " ----> " << can(i) << '\n';
    return 0;
}
*/
