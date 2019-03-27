#pragma once

template <typename T>
void print_bits(T x) {
  T orig = x;
  size_t wl = sizeof(T) * 8 - 1;
  unsigned mask;
  for (mask = 1 << wl; mask; mask >>= 1) {
    printf("%c", (x & mask ? '1' : '0'));
  }
  printf(" -> %d in decimal\n", orig);
}