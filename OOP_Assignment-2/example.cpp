#include <iostream>

using namespace std;

int main() { int x[] = {2, 3, 4, 5, 6, 7, 8};

int *a[] = {x+2, x+4, x, x+6, x+8};

int **b = a;

cout << *x << " " << **a << " " << **b << endl; 

++*++*b;

cout << *x << " " << **a << " " << **b << endl; 

++++*a;

++*++++b;

cout << *x << " " << **a << " " << **b << endl; 

return 0;

}