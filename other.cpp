#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<unsigned long> get_primes(unsigned long max){
    vector<unsigned long> primes;
    char *sieve;
    sieve = new char[max/8+1];
    // Fill sieve with 1  
    memset(sieve, 0xFF, (max/8+1) * sizeof(char));
    for(unsigned long x = 2; x <= max; x++)
        if(sieve[x/8] & (0x01 << (x % 8))){
            primes.push_back(x);
            // Is prime. Mark multiplicates.
            for(unsigned long j = 2*x; j <= max; j += x)
                sieve[j/8] &= ~(0x01 << (j % 8));
        }
    delete[] sieve;
    return primes;
}

int main(void){
    vector<unsigned long> primes;
    primes = get_primes(10000000);
    // return 0;
    // Print out result.
    vector<unsigned long>::iterator it;
    for(it=primes.begin(); it < primes.end(); it++)
        cout << *it << " ";
    
    cout << endl;
    return 0;
}
