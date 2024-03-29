#include <bits/stdc++.h> 
#include <iostream>
#include <numeric>
// #include <algorithm>

using namespace std;

class Fraction {
public: 
    int nume;
    int deno;

public:

    int gcd(int a, int b){
      if(b == 0)  return a;
      while(b != 0){
        int temp = b;
         b = a % b;
         a = temp;
      }
      return a;
    }
    Fraction(int n, int d){
        this->nume = n;
        this->deno = d;
    }

    void add(Fraction f){
        this->nume = (this->nume * f.deno) + (f.nume * this->deno);
        this->deno *= f.deno; 
    }

    void multiply(Fraction f){
        this->nume *= f.nume;
        this->deno *= f.deno;
    }

    void simplify(){
        int n = gcd(this->nume, this->deno);
        this->nume /= n;
        this->deno /= n;
    }

    void print(){
        cout<<this->nume<<"/"<<this->deno;
    }

};

int main() {

   int n1, d1;
   cin>>n1>>d1;
   Fraction f1(n1, d1);
   int query;
   cin>>query;

   for(int i = 1; i <= query; i++ ){
       int type, n2, d2;
       cin>>type>>n2>>d2; 
        Fraction f2(n2, d2);

        if(type == 1){
            f1.add(f2);
            f1.simplify();
            f1.print();
        }
        else{
            f1.multiply(f2);
            f1.simplify();
            f1.print();
        }
   }
}