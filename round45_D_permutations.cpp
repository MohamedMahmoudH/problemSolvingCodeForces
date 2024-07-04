#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> vec(n) , freq(100005);
    loop(i,0,n)
    {
       cin >> vec[i];
       freq[vec[i]]++;
    }
    if(!is_sorted(freq.begin()+1 , freq.end() , greater<int>()))
    {
        cout << -1 ;
        return;
    }

    cout << freq[1] << '\n';
    loop(i,0,n)cout << freq[vec[i]]-- << ' ' ;
}

int main()
{
    ByMohamedMahmoud
    solve();
    return 0;
}
