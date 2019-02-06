#include <bits/stdc++.h>

using namespace std;

template<class T> string toString(T x) {ostringstream ss; ss << x; return ss.str();}
const int inf = 1000000000;

unsigned hash_(string& key)
{
    unsigned ind = 0;

    for(unsigned i = 1; i <= key.size(); i++) 
    {
        ind += key[i - 1] * i; 
    }
    
    return (ind*19) % 101;
}



void insert_key(string& key, vector<string>& hashTable)
{
    unsigned hashed_ind = hash_(key);

    //if already there, return
    for(int j = 0; j < 20; j++)
    {
        if(hashTable[(hashed_ind + j*j + 23*j) % 101] == key) 
        {
            return;
        }
    }
    
    //if not already in and
    //if there is a non-empty slot, insert it
    for(int j = 0; j < 20; j++)
    {
        if(hashTable[(hashed_ind + j*j + 23*j) % 101].empty())
        {
            hashTable[(hashed_ind + j*j + 23*j) % 101] = key;
            return;
        }
    }
}


void delete_key(string& key, vector<string>& hashTable)
{
    unsigned hashed_ind = hash_(key); 

    for(int j = 0; j < 20; j++)
    {
        if(hashTable[(hashed_ind + j*j + 23*j) % 101] == key) 
            hashTable[(hashed_ind + j*j + 23*j) % 101] = "";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;

    while(t--)
    {
        
        vector<string> hashTable(101);

        int n1; cin >> n1;

        while(n1--)
        {
            string input;
            cin >> input;

            string op, key;

            op = input.substr(0,3);
            key = input.substr(4,input.length() - 4);

            if(op == "ADD")
                insert_key(key, hashTable);
            else
                delete_key(key, hashTable);

        }

        unsigned nonEmpty = 0;
        for(unsigned i = 0; i < hashTable.size(); i++) 
        {
            if(hashTable[i].size() > 0)
                nonEmpty += 1;
        }
        
        cout << nonEmpty << endl;

        for(unsigned i = 0; i < hashTable.size(); i++) 
        {
            if(hashTable[i].size() > 0)
                cout << i << ":" << hashTable[i] << endl;
        }

        hashTable.clear();
    }

    return 0;
}

