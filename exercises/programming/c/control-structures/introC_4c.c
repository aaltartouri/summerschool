#include  <stdio.h>

void add_one_to_both(int *i, int *j){
  (*i)++;
  (*j)++;
}

int main(void) {
  int a=10, b=20;

  add_one_to_both(&a, &b);
  printf("%d\t%d\n", a, b);
}
