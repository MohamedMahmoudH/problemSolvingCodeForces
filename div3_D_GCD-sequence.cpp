#include <vector>
#include <iostream>
#define loop(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()
using namespace std;
 
int gcd(int a , int b)
{
    if(!b)return a;
    return gcd(b , a % b);
}
 
bool isGCDSeq(vector<int>& vec)
{
    int sz = vec.size() , last = 0 , current = 0;
    last = gcd(vec[0] , vec[1]);
    loop(i,1,sz-1)
    {
        current = gcd(vec[i] , vec[i + 1]);
        if(current < last)return false;
        last = current;
    }
    return true;
}
 
void solve()
{
    int n , x = 0;
    cin >> n;
 
    vector<int> arr(n);
    vector<int> GCD(n-1);
 
    cin >> arr[0];
    loop(i,1,n)
    {
        cin >> arr[i];
        GCD[i - 1] = gcd(arr[i - 1] , arr[i]);
    }
 
    bool flag = true;
    loop(i,1,n-1)
    {
        if(GCD[i] < GCD[i - 1])
        {
            x = i;
            flag = false;
            break;
        }
    }
    if(flag)
    {
        cout << "YES\n";
        return;
    }
 
    vector<int> check1 , check2 , check3;
    check1 = check2 = check3 = arr;
    check1.erase(check1.begin() + x - 1);
    check2.erase(check2.begin() + x);
    if(x < n - 1) check3.erase(check3.begin() + x + 1);
 
    if(isGCDSeq(check1) || isGCDSeq(check2) || isGCDSeq(check3)) cout << "YES\n";
    else cout << "NO\n";
}
 
int main()
{
    ///ByMohamedMahmoud///
    int t = 1;
    cin >> t;
    while(t--)solve();
    return 0;
}
