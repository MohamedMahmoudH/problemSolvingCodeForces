#include <string>
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

short m;
int k , n;
string str;
vector<int> existOfL;

string TheGreed()/*الطمع*/
{
    int ind = 0;
    while('F' != str[existOfL[ind]])
    {
        if(existOfL[ind+1] - existOfL[ind] <= m)ind++;
        else{pool(i,existOfL[ind]+m,existOfL[ind]+1){if('W' == str[i]){loop(j,i,existOfL[ind+1]){if('W' == str[j])k--;else return "NO";}ind++;break;} else return "NO";}} /// dirty code
        if(k < 0)return "NO";
    }
    return "YES";
}

void solve()
{
    cin >> n >> m >> k;
    cin.ignore();
    getline(cin , str);
    str = 'X' + str + 'F';
    str.erase(unique(all(str) , [](char a ,char b){return a == b && a == 'L';}) , str.end()); /// erase all duplicated 'L'
    n = str.size();

    existOfL.clear();
    existOfL.push_back(0);
    loop(i,1,n-1)if('L' == str[i])existOfL.push_back(i);existOfL.push_back(n-1);

    cout << TheGreed() << '\n';
}

short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while(t--)solve();
    return 0;
}
