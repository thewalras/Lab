#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;



double ntp(double num,double p);
double pie(int n);

int main(){

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
 cout.precision(10);


  double tol;
  cout<<"Enter a number of tolerance:"<<endl;
  cin>>tol;
  
  int i = 0;
    double pi = 0, diff = 0;
  do{
    pi = pie(i);
    diff =fabs( pi - pie(i+1));
    cout<< pi <<" " << diff << " " << i<<endl;
    i++;
      } while(diff > tol);
  
  return 0;
}
double ntp(double num,double p){
  double p_num=1;
  for(int i=1;i<=p;i++){
    p_num*=num;
       }
  return p_num;
}
double pie(int n){
  double pi=0;
  int i=0;
  do{
 pi+=ntp(-1,i)/(ntp(3,i)*(2*i+1));
 i++;
  }while(i<=n);
  return (pi*(6/sqrt(3)));
 }
