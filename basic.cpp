#include <iostream>

bool is_prime(int n)
{
   for(int d = 2; d < n; ++d)
   {
      if(n % d == 0)
         return false;
   }
   return true;
}

int main()
{
   for(int i = 2; i < 1000000; ++i)
   {
      if(is_prime(i))
         std::cout << i << std::endl;
   }
}
