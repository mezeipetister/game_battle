#include <assert.h>

int get_int_one() {
  return 1;
}

int get_int(int n) {
  return n;
}

int main() {
  assert("Wooow error occured"
         && get_int_one() == get_int(2));
}
