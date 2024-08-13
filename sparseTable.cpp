// sparse table

#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int merge(int a ,int b) // depends on the operator in the problem 
{
    return min(a , b);
}

void sparseTable()
{
    int n; cin >> n;
    vector<int> arr(n);
    for(int &in : arr)cin >> in;

    vector<vector<int>> sparse((int)log2(n)+1 , vector<int>(n));

    sparse[0] = arr;
    for (int msk = 1 ; (1ULL << msk) <= n ; ++msk) // O[n.log(n)]
        for (int i = 0 ; i + (1ULL << msk) <= n ; ++i)
            sparse[msk][i] = merge(sparse[msk - 1][i] , sparse[msk - 1][i + (1 << msk - 1)]);
    
    int q , l , r;
    cin >> q;
    while(q--)
    {
        cin >> l >> r;
        int msk = (int)log2(r - l + 1);
        cout << merge(sparse[msk][l] , sparse[msk][r - (1 << msk) + 1]) << '\n';
    }
}

int main()
{
    sparseTable();
    return 0;
}
