#include <string>
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i <  b ; ++i)
#define pool(i,a,b) for(int i = a ; i >= b ; --i)
#define all(x) (x).begin() , (x).end()
#define ull unsigned long long

const int OO = 0x3f3f3f3f;
using namespace std;

short where(string& str , short a , short z)
{
    loop(i,a,z)if(str[i] != '?')return i;
    return -1;
}

void solve()
{
    short n , x = 0;
    string str;
    cin >> n >> str;

    if(1 == n)
    {
        cout << ((str[0] == '?')? 'B' : str[0]) << '\n';
        return;
    }

    x = where(str , 0 , n);
    if(x == -1)
    {
        loop(i,0,n)cout << ((i%2)? 'B' : 'R');
        cout << '\n';
        return;
    }

    loop(i,0,n)
    {
        x = where(str , i , n);
        if(x != -1 && x)
        {
            i = x;
            if(str[x - 1] != '?')continue;
            pool(j,x-1,0)
            {
                if(str[j] == '?')str[j] = ((str[j + 1] == 'R')? 'B' : 'R');
                else continue;
            }
        }
        else if(-1 == x)
        {
            loop(j,i,n)str[j] = ((str[j - 1] == 'R')? 'B' : 'R');
            break;
        }
    }
    loop(i,0,n)cout << str[i];
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
