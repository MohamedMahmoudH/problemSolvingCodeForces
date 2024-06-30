#include <string>
#include <iostream>
#include <algorithm>
#define ByMohamedMahmoud ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define loop(i,a,b) for(int i = a ; i < b ; ++i)
#define all(x) (x).begin() , (x).end()
using namespace std;

void solve()
{
    string str1 , str2;
    cin >> str1 >> str2;

    int size1 = str1.size() , size2 = str2.size() , Max = 0;
    loop(i,0,size2)
    {
        int j = 0 , k = i;
        while(j < size1 && k < size2)
        {
            if(str1[j] == str2[k])k++;
            j++;
        }
        Max = max(Max , k - i);
    }
    cout << size1 + size2 - Max << '\n';
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
the previous idea not consider position of char 
when input : asd dsa
the output : 3
the correct output is : 5
*/
