#include <vector>
#include <iostream>
#define f(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()
using namespace std;

int gcd(int a , int b)
{
    if(!b)return a;
    return gcd(b , a % b);
}

void solve()
{
    int n , x = 0;
    cin >> n;

    vector<int> arr(n);
    vector<int> GCD(n-1);

    cin >> arr[0];
    for(int i = 1 ; i < n ; ++i)
    {
        cin >> arr[i];
        GCD[i - 1] = gcd(arr[i - 1] , arr[i]);
    }

    bool flag = false;
    for(int i = 1 ; i < n-1 ; ++i)
    {
        if(GCD[i] < GCD[i - 1])
        {
            if(flag)
            {
                cout << "NO" << '\n';
                return;
            }

            if(i >= 1 && i <= n-3)
            {
                x = gcd(arr[i - 1] , arr[i + 1]);
                if((i != 1 && x < GCD[i - 2]) || x > GCD[i + 1])
                {
                    x = gcd(arr[i] , arr[i + 2]);
                    if(x < GCD[i - 1] || (i != n-3 && x > GCD[i + 2]))
                    {
                        if(GCD[i] >= GCD[i - 2] && i != 1)
                        {
                            x = gcd(arr[i] , arr[i - 2]);
                            if(x < GCD[i - 2] || x > GCD[i + 1])
                            {
                                cout << "NO" << '\n';
                                return;
                            }
                            else GCD[i - 1] = GCD[i - 2] = x;
                        }
                        else
                        {
                            cout << "NO" << '\n';
                            return;
                        }
                    }
                    else GCD[i] = GCD[i + 1] = x;
                }
                else GCD[i] = GCD[i - 1] = x;
            }
            flag = true;
        }
    }
    cout << "YES" << '\n';
}

int main()
{
    ///ByMohamedMahmoud///
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
