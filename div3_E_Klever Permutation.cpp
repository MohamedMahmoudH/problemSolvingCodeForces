#include <vector>
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b)    for(int i = a ; i < b  ; ++i )
#define pool(i,a,b)    for(int i = a ; i >= b ; --i )
#define loopx(i,a,b,x) for(int i = a ; i < b  ; i+=x)
#define condx(i,a,x,q) for(int i = a ;   (q)  ; i+=x)
#define all(x)  (x).begin()  , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define print(x) cout << x << '\n'
#define line cout << '\n'
#define ull unsigned long long

const int OO = 0x3f3f3f3f;
using namespace std;

void solve()
{
    int n , k;
    cin >> n >> k;
    int b = n , c = 1;
    vector<int> perm(n);
    loop(i,0,k)loopx(j,i,n,k)i%2 ? perm[j] = b-- : perm[j] = c++;
    loop(i,0,n)cout << perm[i] << ' ';line;
}

short t;
int main()
{
    ///ByMohamedMahmoud///
    cin >> t;
    while(t--)solve();
    return 0;
}


/*
int main()
{
    int t = 1000;
    while(t--)
    {
        int n , k , x = 0 , y = 0;
        cin >> n >> k;

        vector<int> perm(n) , sum;
        loop(i,0,n)perm[i]=i+1;

        do{
            x = 0;sum.clear();
            while(x+k <= n)
            {
                y = accumulate(perm.begin()+x , perm.begin()+x+k , 0);
                sum.push_back(y);
                //x += k-1;
                x++;
                //cout << "suii\n";
            }

            bool flag = true;
            loop(i,0,sum.size()-1)if(abs(sum[i] - sum[i+1]) > 1)flag = false;

            if(flag)
            {
                loop(i,0,n)cout << perm[i] << ' ';
                cout << '\t';
                loop(i, 0, sum.size()) cout << sum[i] << ' ';
                cout << '\n';
            }

            /*
            loop(i,0,n)cout << perm[i] << ' ';cout << '\t';
            loop(i,0,sum.size())cout << sum[i] << ' ';cout << '\n';
            *
        }while(next_permutation(all(perm)));
        cout << "\n***************************************\n";
    }
}
*/
