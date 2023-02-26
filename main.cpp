#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ifstream intrare("numar.in");
ofstream iesire("numar.out");

bool estePrim(unsigned long long numar)
{
  unsigned int divizor = 2;

  for (divizor = 2; divizor < sqrt(numar); divizor++)
  {
    if (numar % divizor == 0)
      return false;
  }
  return true;
}

unsigned short int nrCifre(unsigned long long numar)
{
  unsigned short int nrCifre = 0;
  while (numar)
  {
    numar /= 10;
    nrCifre++;
  }
  return nrCifre;
}

// 5 4 3 2 7 3 2 -> nr cifre = 7
// i = 0,5 3 2 7 3 2 -> 5(nr / 10 * nr cifre - i - 1) + 3 2 7 3 2(nr % 10 * nr cifre - i)

unsigned long long celMaiMareNumarPrimPrinStergere(unsigned long long numar)
{
  unsigned short int numarCifre = nrCifre(numar);
  unsigned long long maxNumar = 0;

  for (int i = 0; i < numarCifre; i++)
  {
    unsigned long long impartitorPrimar = pow(10, numarCifre - i);
    unsigned long long impartitorSecundar = pow(10, numarCifre - i - 1);
    unsigned long long cifraPrimara = (numar / impartitorPrimar) * impartitorSecundar;
    unsigned long long cifraSecundara = numar % impartitorSecundar;
    unsigned long long numarFinal = cifraPrimara + cifraSecundara;
    cout << numarFinal << endl;
    if (estePrim(numarFinal) && numarFinal > maxNumar)
    {
      maxNumar = numarFinal;
    }
  }
  return maxNumar;
}

int main()
{
  unsigned long long numar;
  intrare >> numar;
  iesire << celMaiMareNumarPrimPrinStergere(numar);
  return 0;
}