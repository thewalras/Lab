// Conway's Game of life
#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

//makes the world and prints it
void  world(char erf[20][20]);

int main()
{
  char erf[20][20];
  world(erf);

  return 0;
}

void world(char erf[20][20])
{
  for(int i = 0; i<20; i++)
    {
      for(int j = 0; j<20; j++)
	{
	  erf[i][j] = '0';
	  cout << erf[i][j]<< " ";
	}
      cout << endl;
    }
}
