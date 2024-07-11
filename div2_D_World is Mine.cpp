#include <cmath>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(short i = a ; i <  b ; ++i)
#define pool(i,a,b) for(short i = a ; i >= b ; --i)
#define all(x) (x).begin() , (x).end()
#define ull unsigned long long

const int OO = 0x3f3f3f3f;
using namespace std;

short n , mx;
vector<short> cakes , freq;

short dis(short x , short y)
{
    return abs(distance(lower_bound(all(cakes) , x) , lower_bound(all(cakes) , y)));
}

short dp(short a , short b)
{
    loop(i,a+1,5005)
    {
        if(freq[i]){a = i;freq[a] = 0;break;}
        if(5004 == i)return 0;
    }

    if(!freq[b])loop(i,a+1,5005)if(1 == freq[i] && dis(i,a) >= freq[i]){b = i;break;}
    if(!freq[b])loop(j,1,mx+1)loop(i,a+1,5005)if(j == freq[i] && dis(i,a) >= freq[i]){b = i;break;} // it didn't take j = 1 !!
    if(freq[b])freq[b]--;

    loop(i,0,cakes[cakes.size()-1]+1)cout << freq[i] << ' ';cout << "\n------------\n";

    return(1 + dp(a , b));
}

void solve()
{
    cin >> n;
    freq.clear();cakes.clear();
    freq.resize(5005);cakes.resize(n);

    loop(i,0,n){cin >> cakes[i]; freq[cakes[i]]++;}
    mx = *max_element(all(freq));

    sort(all(cakes));
    cakes.erase(unique(all(cakes)) , cakes.end());

    loop(i,0,cakes[cakes.size()-1]+1)cout << i << ' ';cout << '\n';/***/
    loop(i,0,cakes[cakes.size()-1]+1)cout << freq[i] << ' ';/**********/
    cout << "\n********************************************************\n";

    cout << dp(0 , 0) << '\n';
    cout << "/********************************************/////////////////\n\n\n";
}

short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while(t--)solve();
    return 0;
}
