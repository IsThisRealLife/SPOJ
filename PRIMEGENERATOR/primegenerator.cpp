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

void sieveSegmented(int n)
{
    int low = n;
    int high = 2*n; 

    unsigned primesBelowN = primes.size();

    while(low < MAXNUM)
    {
        bool mark[n + 1];
        memset(mark, true, sizeof(mark));

        for(unsigned i = 0; i < primesBelowN; i++) 
        {
            int toLim = floor(low/primes[i]) * primes[i]; 
            if(toLim < low)
                toLim += primes[i];

            for(int j = toLim; j < high; j += primes[i])
                mark[j - low] = false;
        }

       int a = 0;
        for(int i = low; i < high; i++)
            if(mark[i - low])
            {
                a++; 
                primes.push_back(i);
            }

        low += n;
        high += n;
        if(high >= MAXNUM)
            high = MAXNUM;

        
            
        //cout << "LOW: " << low << " HIGH: " << high << endl;
    }
}

int main()
{
    //create sieve until sqrt(MAXNUM)
    int sq = floor(sqrt(MAXNUM)) + 1;
    sieveFill(sq);


     sieveSegmented(sq);     

    int t; cin >> t;


    
    while(t--)
    {
        int n, m; cin >> n >> m;
        
        for(unsigned i = 0; i < primes.size(); i++) 
        {
            if(primes[i] >= n && primes[i] <=m)
            {
                cout << primes[i] << endl;
            }
            
        }
        cout << endl;
    }
    

    return 0;
}

