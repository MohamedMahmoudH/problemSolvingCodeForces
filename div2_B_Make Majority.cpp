#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i <  b ; ++i)
#define pool(i,a,b) for(int i = a ; i >= b ; --i)
#define all(x)  (x).begin()  , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define ull unsigned long long

const int OO = 0x3f3f3f3f;
using namespace std;

string solve()
{
    int n , ones = 0 , cnt = -1;
    cin >> n;

    string str;
    cin.ignore();
    getline(cin , str);

    bool flag = false;
    vector<int> zeros;
    loop(i,0,n)
    {
        if('1' == str[i]){ones++;flag = false;}
        else if(flag) zeros[cnt]++;
        else{zeros.push_back(0);cnt++;flag = true;}
    }
    if(2*ones > n)return "YES";
    zeros.push_back(-1); // as a flag

    cnt = 0;
    while(-1 != zeros[cnt])n -= zeros[cnt++];
    if(n >= 2*ones)return "NO";
    else return "YES";

}

unsigned short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while(t--)cout << solve() << '\n';
    return 0;
}
