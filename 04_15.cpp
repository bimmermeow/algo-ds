#include <iostream>

using namespace std;

int Tn(int n) {
  if(n==1) return 1;
  return n*T(n-1)+n;
}
int Tni(int n) {
  int e=1;
  int eme=1;
  for(int i=2;i<=n;i++) {
    eme = e;
    e = i*eme+n;
   }
   return e;
}
 
int main() {
  for(int i=0;i<10;i++) {
    cout << Tn(i) << endl;
    cout << Tni(i) << endl;
  }
}
    
