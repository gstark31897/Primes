#include <vector>
#include <iostream>
#include <math.h>

std::vector<int> primes;

bool is_prime(int n)
{
   int size = primes.size();
   int sqr = sqrt(n);
   if(sqr * sqr == n)
      return false;

   for(int i = 0; i < size; ++i)
   {
      if(n % primes.at(i) == 0)
         return false;
      if(primes.at(i) > sqr)
         goto return_true; 
   }
return_true:
   primes.push_back(n);
   return true;
}

int main()
{
   for(int i = 2; i < 100; ++i)
   {
      is_prime(i);
   }

   std::vector<int>::iterator it;
   for(it=primes.begin(); it < primes.end(); it++)
      std::cout << *it << " ";
}
