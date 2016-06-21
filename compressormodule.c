#include <string.h>
#include <stdlib.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

int output_char(char* output, const int x, const char* alphabet, const int A, const int C);
int basic(const char* str, const int str_pos, const int N);


const char* core(const char* str, const char* alphabet, const int comp_fact, const int N) {
  int str_pos = 0,
      str_len = strlen(str),
      alpha_len = strlen(alphabet),
      indx,
      acc;

  // this is unsafe, particularly for small input strings, but whatever.
  int max_sig_len = (str_len/comp_fact) * 1.5;
  int sig_len = 0;
  char* output = malloc(max_sig_len);

  for(str_pos=0; (str_pos+N) < str_len; str_pos++) {
    acc = 0;

    // whoops...

    int char_outputted = output_char(output, sig_len, alphabet, acc, comp_fact);
    if(char_outputted) {
      sig_len++;
    }
  }

  return output;
}


/*
 * Assign pseudorandom character from 'alphabet' at position 'x' in string 'output'.
 * Likelihood of assigning a character must be near 1/C assuming a uniform distribution of
 * input 'A'.
 */
int output_char(char* output, const int x, const char* alphabet, const int A, const int C) {
  if((A % C) == 0) {
    indx = A % alpha_len;
    output[x] = alphabet[indx];

    return 1;
  }

  return 0;
}


/*
 * Compress the string between str_pos and str_pos+N into a 64-bit value
 * with a near-uniform distribution of randomness.
 */
 int basic(const char* str, const int str_pos, const int N) {;
   int acc = 0,
     val,
     i,
     end_pos;

   end_pos = min(str_pos+N, strlen(str));
   // Starting with no bits set in an accumulator, for each element in
   // the neighborhood str_pos to end_pos, XOR in the element at a fresh 8-bit
   // position. Wrap around and keep going if N is long enough to exhaust the 56
   // bits alloted.
   for(i=str_pos; i<end_pos; i++) {
     val = (int) str[i];
     val <<= ((i-str_pos) * 8 % 56);
     acc ^= val;
     acc = abs(acc);
   }

   return acc;
 }
