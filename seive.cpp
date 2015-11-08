#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>

std::vector<int> get_primes(int max)
{
   bool *values = (bool*)malloc(max);
   for(int i = 0; i < max; ++i)
      values[i] = true;

   int sqr = sqrt(max);
   for(int i = 2; i < sqr; ++i)
   {
      if(values[i] == true)
         for(int d = i+i; d < max; d += i)
            values[d] = false;
   }

   std::vector<int> primes;
   for(int i = 0; i < max; ++i)
   {
      if(values[i])
         primes.push_back(i);
   }

   return primes;
}

int main()
{
   std::vector<int> primes = get_primes(1000000000);
   std::vector<int>::iterator it;
   for(it=primes.begin(); it < primes.end(); it++)
      std::cout << *it << " ";

}
