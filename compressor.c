#include <string.h>
#include <stdlib.h>
#include "compressor.h"

#define min(a,b) (((a) < (b)) ? (a) : (b))

/*
 * Compress the string between str_pos and str_pos+N into a 64-bit value
 * with a near-uniform distribution of randomness.
 */
uint64_t basic(const char* str, const uint32_t str_pos, const uint32_t N) {
  uint64_t acc = 0, val;
  uint32_t i, end_pos;

  end_pos = min(str_pos+N, strlen(str));
  // Starting with no bits set in an accumulator, for each element in
  // the neighborhood str_pos to end_pos, XOR in the element at a fresh 8-bit
  // position. Wrap around and keep going if N is long enough to exhaust the 56
  // bits alloted.
  for(i=str_pos; i<end_pos; i++) {
    val = (uint64_t) str[i];
    val <<= ((i-str_pos) * 8 % 56);
    acc ^= val;
  }

  return acc;
}

