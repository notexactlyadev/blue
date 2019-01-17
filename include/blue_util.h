#pragma once

namespace blue::util {
template <typename T>
void print_bits(T x) {
  T orig = x;
  size_t wl = 16;
  unsigned mask;
  for (mask = 1 << wl; mask; mask >>= 1) {
    printf("%c", (x & mask ? '1' : '0'));
  }
  printf(" -> %i in decimal\n", orig);
}
}