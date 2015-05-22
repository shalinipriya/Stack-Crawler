#include <stdio.h>

int tb1(){
return 1;
}
void tb(){
int i=tb1();
}

void bar(int x, int y)
{
  int z;
  z = x + y;
	tb();
  //traceback(stdout);
}

void foo() {
  bar (5,17);
traceback(stdout);
}

int main (int argc, char **argv)
{
  foo();
  return 0;
}
