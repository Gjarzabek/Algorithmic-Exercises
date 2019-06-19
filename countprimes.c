#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n) {
  int i = 2;
  while (i <= sqrt(n)) {
    if (n % i == 0)
      return false;
    ++i;
  }
  return true;
}

int countPrimes(int n) {
  int licznik = 0;
  for (int i = 2; i < n; ++i)
    if (is_prime(i))
      ++licznik;
  return licznik;
}

int countpprimes(int n){
  int * tab = (int*)calloc(n+1,sizeof(int));
  int pierwsze_suma = 0;
  if (n>=2) {
    for (int i = 2; i<=sqrt(n); i++) {
      if (tab[i] == 0) {
        for(int j=3; j<n; j++) {
              if (j%i == 0)
                  tab[j] = 1;
                }
              }
            }
            for (int i = 0; i<n; i++) {
              if(!tab[i])
            pierwsze_suma++;
          }
          pierwsze_suma = pierwsze_suma-2;
  /*odejmuje 2 ponieważ pod indeksem 0 i 1 tablica jest uzupełniona zerami, jednak to nie są liczby pierwsze*/
    free(tab);
  }
  return pierwsze_suma;
}

int main(int argc, char const *argv[]) {

  return 0;
}
