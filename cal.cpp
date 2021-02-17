#include <stdio.h>
#include <omp.h>
#include<iostream>
#include <thread>
using namespace std;
void add(int a, int b) {
 cout<<"The addition of two number is: "<<a + b<<"\n";
}
void sub(int a, int b) {
 cout<<"The subtraction of two number is: "<<a - b<<"\n";
}
void multiply(int a, int b) {
 cout<<"The multiplication of two number is: "<<a * b<<"\n";
}
void divide(int a, int b) {
 cout<< "The division of two number is: "<<(a / b)<<"\n";
}
int main () {
 int a,b;

 cout << "Enter first number: ";
 cin >> a;
 cout<<"\n";

 cout << "Enter second number: ";
 cin >> b;
 cout<<"\n";
 #pragma omp parallel
 thread t1(add, a, b);
 thread t2(sub, a, b);
 thread t3(multiply, a, b);
 thread t4(divide, a, b);
 t1.join();
 t2.join();
 t3.join();
 t4.join();
 return 0;
}
