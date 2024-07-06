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
    int m , s , z;
    cin >> m >> s;z=s;
    if(!s){
        if(1 == m)cout << "0 0";
        else cout << "-1 -1";
        return;
    }

    vector<int> small(m) , large(m);

    /// small :
    if(s > 9*m) cout << -1;
    else if(s > 9*(m-1))
    {
        loop(i,0,m-1) small[i] = 9;
        small[m-1] = s - 9*(m-1);
        pool(i,m-1,0)cout << small[i];
    }
    else
    {
        int x = s/9;
        if(x)
        {
            loop(i,0,x-1) small[i] = 9;
            s -= 9*(x - 1);
            if(s > 9) small[x-1] = 9 , s -= 9 , x++;
            if(s%9) small[x-1] = (s%9-1);
            else small[x-1] = 8;
            small[m-1]++;
        }
        else small[0] = s-1 , small[m-1]++;
        pool(i,m-1,0)cout << small[i];
    }

    cout << ' ';
    /// large :
    s = z;
    if(s > 9*m) cout << -1 << ' ';
    else
    {
        loop(i,0,s/9)large[i] = 9;
        large[s/9] = s%9;
        loop(i,0,m)cout << large[i];
    }
}

int main()
{
    ByMohamedMahmoud
    solve();
    return 0;
}
