#include <vector>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()
#define ull unsigned long long
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<short> first(n) , second(n);
    loop(i,0,n)cin >> first[i];
    loop(i,0,n)cin >> second[i];

    int a , b , pos , neg;
    a = b = pos = neg = 0;
    loop(i,0,n)
    {
        if(first[i] != second[i]) (first[i] > second[i])? a += first[i] : b += second[i];
        else if(first[i]) (-1 == first[i])? neg-- : pos++;
    }
    while(neg++)(a > b)? a-- : b--;
    while(pos--)(a < b)? a++ : b++;

    cout << min(a , b) << '\n';
}

short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while(t--)solve();
    return 0;
}
