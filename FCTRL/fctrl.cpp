#include <bits/stdc++.h>

using namespace std;

template<class T> string toString(T x) {ostringstream ss; ss << x; return ss.str();}
const int inf = 1000000000;

int compute(int N)
{
    int p = 5;
    int result = 0;

    while(p <= N)
    {
        result += N / p;
        p *= 5;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--)
    {
        int N; cin >> N;

        cout << compute(N) << endl;
    }

    return 0;
}

