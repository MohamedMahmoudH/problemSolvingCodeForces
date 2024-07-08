#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i <  b ; ++i)
#define pool(i,a,b) for(int i = a ; i >= b ; --i)
#define all(x) (x).begin() , (x).end()
#define ull unsigned long long

short dx[5] = {0 , 1 , 1 , 0};
short dy[5] = {0 , 0 , 1 , 1};

const int OO = 0x3f3f3f3f;
using namespace std;

void operation(vector<vector<short>>& a , vector<vector<short>>& b , short i , short j)
{
    loop(l,0,4)a[i + dx[l]][j + dy[l]] = (a[i + dx[l]][j + dy[l]] + ((l % 2) ? 2 : 1))%3;
}

void solve()
{
    short n , m;
    cin >> n >> m;

    vector<vector<short>> a(n , vector<short>(m)) , b(n , vector<short>(m));
    string A , B;
    loop(i,0,n){cin >> A ; loop(j,0,m)a[i][j] = A[j]%3;} // '0' == 48
    loop(i,0,n){cin >> B ; loop(j,0,m)b[i][j] = B[j]%3;}

    /****************************************
    cout << "\n-----------------------------------\n";
    loop(i,0,n)
    {
        loop(j,0,m) cout << a[i][j] << ' ';
        cout << '\t';
        loop(j,0,m) cout << b[i][j] << ' ';
        cout << '\n';
    }
    cout << "\n-----------------------------------\n";
    /****************************************/

    loop(i,0,n-1)loop(j,0,m-1)while(a[i][j] != b[i][j])operation(a,b,i,j);

    /****************************************
    loop(i,0,n)
    {
        loop(j,0,m) cout << a[i][j] << ' ';
        cout << '\t';
        loop(j,0,m) cout << b[i][j] << ' ';
        cout << '\n';
    }
    cout << "\n-----------------------------------\n";
    /****************************************/

    if(a == b)cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while(t--)solve();
    return 0;
}
