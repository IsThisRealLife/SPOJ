#include <bits/stdc++.h>

using namespace std;

template<class T> string toString(T x) {ostringstream ss; ss << x; return ss.str();}
const int inf = 1000000000;

int primes_cnt;

void simpleSieve(int limit, vector<int>& prime)
{
    bool mark[limit + 1];
    memset(mark, true, sizeof(mark));

    for(int p = 2; p*p < limit; p++) 
    {
       if(mark[p])
       {
           for(int i = 2*p; i < limit; i+=p) 
           {
              mark[i] = false; 
           }
        }
    }

    for(int p = 2; p < limit; p++)
    {
        if(mark[p])
        {
            primes_cnt++;
            prime.push_back(p);
        }
    }
}

void segmentedSieve(int n)
{
    int limit = floor(sqrt(n)) + 1;
    vector<int> prime;
    simpleSieve(limit, prime);
    
    int low = limit;
    int high = 2*limit;

    int itrs = 0;
    while(low < n)
    {
        bool mark[limit + 1];
        memset(mark, true, sizeof(mark));
        
        for(unsigned i = 0; i < prime.size(); i++) 
        {
            int toLim = floor(low/prime[i])*prime[i];
            if(toLim < low)
            {
                toLim += prime[i];
            }

            for(int j = toLim; j < high ; j += prime[i])
            {
                mark[j - low] = false; 
            }
        }

        for(int i = low; i < high; i++) 
        {
            if(mark[i - low] == true)
            {
                primes_cnt++;
            }
        }

        low = low + limit;
        high = high + limit;
        if(high >= n) high = n;

        itrs++;
    }
    cout << itrs << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 1000000000;
    segmentedSieve(n);

    cout << primes_cnt << endl;

    return 0;
}

