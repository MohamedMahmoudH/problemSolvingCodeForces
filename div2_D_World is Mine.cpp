///////////////////////
#include <queue>
#include <vector>
#include <cassert>
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

void solve()
{
    int n;
    cin >> n;
    vector<int> f(n, 0);
    loop(i,0,n){
        int x;
        cin >> x;
        assert(x > 0 && x <= n);
        f[x - 1]++;
    }
    priority_queue<int> hp;
    int sum = 0;
    int tot = 0;
    for(int i = 0, j = 0; i < n; i++){
        if(f[i]){
            tot++;
            sum += f[i];
            hp.push(f[i]);
            while(sum > j){
                sum -= hp.top();
                hp.pop();
                j++;
            }
        }
    }
    cout << tot - hp.size() << '\n';
}

short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while (t--) solve();
    return 0;
}
///////////////////////


/**#include <cmath>
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
vector<short> cakes , fr;

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
    vector<short> freq(5005);
    fr.clear();cakes.clear();cakes.resize(n);

    loop(i,0,n){cin >> cakes[i]; freq[cakes[i]]++;}
    loop(i,0,5005)if(freq[i])fr.push_back(freq[i]);

    /*
    mx = *max_element(all(freq));

    sort(all(cakes));
    cakes.erase(unique(all(cakes)) , cakes.end());
    *

    loop(i,0,cakes[cakes.size()-1]+1)cout << i << ' ';cout << '\n';/***
    loop(i,0,cakes[cakes.size()-1]+1)cout << freq[i] << ' ';/**********
    cout << "\n********************************************************\n";


    cout << dp(0 , 0) << '\n';
    cout << "\n----------------------------------------------\n\n\n";
}

short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while(t--)solve();
    return 0;
}
*/
/*
#include <bits/stdc++.h>
using namespace std; typedef long long int ll; typedef long double ld; const ll inf = 1e18, mod = 1e9 + 7, maxn = 2e6;

int main() {

	ll T ;
	for (T=100; T--;) {
		ll n; cin >> n; vector<ll> a; map<ll, ll> m; for (ll x; n--;) cin >> x, ++m[x]; n = m.size();
		for (auto [x, y] : m) a.emplace_back(y);
		cout << "###### a ---> ";for(auto it : a)cout << it << ' ';cout << '\n';
		vector<ll> dp(n + 1, inf); dp[0] = 0;
		for (ll i = 1; i <= n; ++i) {
			vector<ll> ndp = dp;
			for (ll j = 1; j <= n; ++j) {
				ll nv = dp[j - 1] + a[i - 1];
				if (nv <= i - j) ndp[j] = min(ndp[j], nv);
			}
			dp = ndp;
			cout << i << " ---> ";
			for(short f = 0 ; f < n+1 ; ++f)cout << dp[f] << ' ';cout << '\n';
		}
		ll ans = n; for (; dp[ans] >= inf;) --ans;

        cout << "\n********************************************************\n";

		cout << n - ans << "\n";
	}
	return 0;
}
*/
/**
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
int t , n;
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        map<int , int> cake;
        priority_queue<int , vector<int> , less<int>> f;
        int turn = 0;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            cake[x]++;
        }
        for(auto x : cake){
            if(x.second <= turn){
                turn -= x.second;
                f.push(x.second);
            }
            else{
                if(!f.empty()){
                    int node = f.top();
                    if(x.second < node){
                        turn += node - x.second;
                        f.pop();
                        f.push(x.second);
                    }
                }
                turn++;
            }
        }
        cout << cake.size() - f.size() << '\n';
    }
}
*/
