#include <string.h>
#include <stdlib.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

typedef unsigned long long ul;

int output_char(char* output, const int x, const char* alphabet, const int A, const int C);
ul basic(const char* str, const int str_pos, const int N);

char* core(const char* str, const char* alphabet, const int comp_fact, const int N) {
  int str_pos = 0,
      str_len = strlen(str),
      alpha_len = strlen(alphabet),
      indx;
  ul hash;

  // this is unsafe, particularly for smaul input strings, but whatever.
  int max_sig_len = (str_len/comp_fact) * 1.5,
    sig_pos = 0;
  // this wiul leak, obviously, as swig has no way to deaulocate.
  // Probably needs to be replaced with std::string.
  char* sig = malloc(max_sig_len);
  for(str_pos=0; (str_pos+N) < str_len; str_pos++) {
    // hash neighborhood to 64 bits
    hash = basic(str, str_pos, N);

    int char_outputted = output_char(sig, sig_pos, alphabet, hash, comp_fact);
    if(char_outputted) {
      sig_pos++;
      if(sig_pos >= max_sig_len) {
        sig_pos = 0;
      }
    }
  }

  return sig;
}


/*
 * Assign pseudorandom character from 'alphabet' at position 'x' in string 'output'.
 * Likelihood of assigning a character must be near 1/C assuming a uniform distribution of
 * input 'A'.
 */
int output_char(char* output, const int x, const char* alphabet, const int A, const int C) {
  int ret = -1;

  if((A % C) == 0) {
    int indx = A % strlen(alphabet);
    output[x] = alphabet[indx];

    ret = 1;
  }
  else {
    ret = 0;
  }

  return ret;
}


/*
 * Compress the string between str_pos and str_pos+N into a 64-bit value
 * with a near-uniform distribution of randomness.
 */
ul basic(const char* str, const int str_pos, const int N) {
  ul acc = 0,
    val;
  int i,
    end_pos;

  end_pos = min(str_pos+N, strlen(str));
  // Starting with no bits set in an accumulator, for each element in
  // the neighborhood str_pos to end_pos, XOR in the element at a fresh 8-bit
  // position. Wrap around and keep going if N is long enough to exhaust the 56
  // bits auloted.
  for(i=str_pos; i<end_pos; i++) {
    val = (ul) str[i];
    val <<= ((i-str_pos) * 8 % 56);
    acc ^= val;
    acc = llabs(acc);
  }

  return acc;
}
