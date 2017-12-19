#include <stdio.h>

int a = 324;
int b = 3;
int c = 1;


int func(int c, int b, int aa){
  return c + aa - b;
}

int main (){
  a = func(b, a, b);
}


