#include <bits/stdc++.h>
#define MAXNUM 1000000000

using namespace std;

template<class T> string toString(T x) {ostringstream ss; ss << x; return ss.str();}
const int inf = 1000000000;

vector<bool> sieve;
vector<int> primes;

void sieveFill(int n)
{
    //calculate primes until n
    for(int i = 0; i <= n; i++) 
    {
        sieve.push_back(true); 
    }
    
    int n_sq = sqrt(n); 

    for(int i = 2; i <= n_sq;  i++) 
    {
        if(sieve[i])
        {
            for(int j = 2*i; j <= n; j += i) 
            {
                sieve[j] = false; 
            }
        }
    }

    for(int i = 2; i <= n; i++)
        if(sieve[i])
            primes.push_back(i);
}

void sieveSegmented(int n, int m)
{
    if(n == 1)
        n ++ ;

    int sq = sqrt(m) + 1;

    bool mark[m - n + 1];
    memset(mark, true, sizeof(mark));

    for(unsigned i = 0; i < primes.size() && primes[i] <= sq ; i++) 
    {
        int toLim = floor(n/primes[i]) * primes[i]; 

        if(toLim < n)
            toLim += primes[i];

        if(toLim > primes[i])
            mark[toLim - n] = false;
        for(int j = toLim + primes[i]; j <= m; j += primes[i])
        {
            mark[j - n] = false;
        }
    }


    for(int i = n; i <= m; i++)
        if(mark[i - n])
        {
            cout << i << endl;
        }
}


int main()
{
    //create sieve until sqrt(MAXNUM)
    int sq = floor(sqrt(MAXNUM)) + 1;
    sieveFill(sq);

    int t; cin >> t;

    while(t--)
    {
        int n, m; cin >> n >> m;
        sieveSegmented(n, m);
        cout << endl;
    }
    

    return 0;
}

