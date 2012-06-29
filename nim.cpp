#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
using namespace std;

int g_marbles();
// Makes a random Number between 10 and 100
// Passes to a reference called 'marbles'

int c_ai();
//Randomly choose 0 or 1
// 1 => Play smart
// 0 => Play dumb

void c_turn(int ai, int& marbles);
//Given g_ai = 0, computer chooses a random number between 1 and g_marbles()
//Given g_ai = 1, computer chooses an n such that n - marbles = 2^k-1
//Give g_ai = 1, and marbles = 2^k-1, n is chosen from (1,  Marbles/2)
//Subtracts whatever is chosen from the data at pointer 'marbles'

void p_turn(int& marbles);
//Prompts the player to choose between 1 and floor(n/2)
// Subtracts the choice from 'marbles'

void g_nim(int& marbles);
//Takes the functions above and wraps according to the rules of the game
//Declares winners and stuff

int main()
{
  int marbles, ai;
  marbles = g_marbles();    
  g_nim(marbles);
  return 0;
}

int g_marbles()
{
  srand(time(NULL));
  return (rand() % 90 + 10); // Random nums between 10 and 100
}

int c_ai()
{
  return rand()%2; // 0 dumb, 1 smart
}

void c_turn(int ai, int& marbles)
{
  int n_sub;
  switch(ai)
    {
    case 0: // Play Dumb
      n_sub = rand()%((marbles/2)-1) + 1;
      marbles -= n_sub;
      break;
    case 1: // Play Smart
	for(int i = 2; pow(2,i)-1 < marbles; i++)
	{
	  n_sub = pow(2,i)-1; // finds the largest 2^k-1 < Marbles
	}
      if(marbles == n_sub)
	{
	  marbles -= rand()%((marbles/2)-1) + 1; //if marbles = 2^k-1 play rando
	}
      else
	{
	  marbles = n_sub; // Marbles - 2^k-1 = n_sub
	}
      break;
    default:
      cout<<" Error, Ya fucked up!";
    }
  cout << marbles << " Marbles Left"<< endl;
}

void p_turn(int& marbles)
{
  int n_sub;
  cout << "Subtract "; 
  cin >> n_sub; cout << endl;
  while(n_sub > marbles/2)
    {
      cout << "Value must be in the range [1,Marbles/2)" << endl << "Subtract ";
      cin >> n_sub;
    }
  marbles -= n_sub;
  cout << marbles << " Marbles Left" << endl;
}

void g_nim(int& marbles)
{
  int  turn = c_ai(), ai = c_ai();
  cout << "Player "<< turn <<endl;
  switch(turn)
    {
    case 0:
     do{
	cout << marbles << " Marbles"<< endl <<"Playing Strategy: " << ai << endl;
	c_turn(ai, marbles);
	p_turn(marbles);
     } while(marbles != 1);
      break;
    case 1:
     do {
	cout << marbles << " Marbles"<< endl;
	p_turn(marbles);
	cout << "Playing Strategy: " << ai << endl;
	c_turn(ai, marbles);
     } while(marbles != 1);
      break;
    default:
      cout<<"Error: Ya Fucked Up!";
    }
}
	  
