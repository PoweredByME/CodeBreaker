#include<iostream>
#include"Matrix.h"

using namespace std;

int main()
{

Matrix a(2,2);
a.In();
a.Out();

Matrix b(2,2);
b.In();
b.Out();

Matrix c = a+b;
c.Out();
return 0;
}