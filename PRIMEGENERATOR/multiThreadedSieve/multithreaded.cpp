#include <bits/stdc++.h>                                                              
#include <pthread.h>
#include <cstdlib>
                                                                                      
using namespace std;                                                                  
                                                                                      
template<class T> string toString(T x) {ostringstream ss; ss << x; return ss.str();}  
const int inf = 1000000000;                                                           
                                                                                      
int primes_cnt = 0;                                                                       
vector<int> prime;

struct range
{
	int limit;
    int low;
    int high;
    int returned_sum;
};
                                                                                      
void simpleSieve(int limit)                                       
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

void *computation(void* r)
{
    range *rr = (range *)r;



	int low = rr->low;
	int high = rr->high;
	int limit = rr->limit;

    //cout << "From " << low << " to " << high << endl;

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
            rr->returned_sum++;
		}
	}

    //cout << "prime form " << low << " to " << high << " are " << rr->returned_sum << endl;
    pthread_exit(0); 
}

void segmentedSieve(int n)
{
    int limit = floor(sqrt(n)) + 1;
    simpleSieve(limit);

    int low = limit;
    int high = 2*limit;

    int num_of_threads = n / limit;

    pthread_t threads[num_of_threads];
    struct range r[num_of_threads];

    for(int i = 0; i < num_of_threads; i++) 
    {
		r[i].limit = limit;
        r[i].low = low;
        r[i].high = high;
        r[i].returned_sum = 0;

        pthread_create(&threads[i], NULL, computation, (void *)&r[i]); 

        low += limit;
        high += limit;
        if(high >= n) high = n; 
    }

    primes_cnt = prime.size();

    for(int i = 0; i < num_of_threads; i++) 
    {
        pthread_join(threads[i], NULL);
        primes_cnt += r[i].returned_sum;
    }
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


