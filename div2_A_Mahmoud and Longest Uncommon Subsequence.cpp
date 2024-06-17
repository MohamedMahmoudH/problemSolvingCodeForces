#include <string>
#include <iostream>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

int main()
{
    ByMohamedMahmoud
    string a, b;
    cin >> a >> b;
    if (a == b)cout << "-1";
    else cout << max(a.size(), b.size());
    return 0;
}


/*
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
using namespace std;

void solve(vector<char>& bigVec , vector<char>& smallVec)
{
    for(char ch : smallVec)
    {
        auto it = find(bigVec.begin() , bigVec.end() , ch);
        if(it != bigVec.end()) bigVec.erase(it);
    }
    if(bigVec.size())cout << bigVec.size();
    else cout << -1;
}

int main()
{
    ByMohamedMahmoud

    int result = 0;
    vector<char> a , b;
    string temp;
    cin >> temp;
    a.assign(temp.begin() , temp.end());
    cin >> temp;
    b.assign(temp.begin() , temp.end());

    (a.size() > b.size())?solve(a,b):solve(b,a);
    return 0;
}
*/
