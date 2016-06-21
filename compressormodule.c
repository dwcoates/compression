#include <string.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

const char* core(const char* str, const char* alphabet, const int comp_fact, const int N) {
  int str_pos = 0,
      str_len = strlen(str),
      alpha_len = strlen(alphabet),
      indx,
      acc;

  char* output = ;

  // Accumulate a value for each position that included an entire
  // neighborhood.
  for(str_pos=0; (str_pos+N) < str_len; str_pos++) {
    acc = 0;
    // Starting with no bits set in an accumulator, for each element in;
    // the neighborhood, XOR in the element at a fresh 8-bit position.;
    // Wrap around and keep going if N is long enough to exhaust the 64;
    // bits in a long.;
    acc = binascii.crc32(string[str_pos:str_pos + self.N]) + 2**32;
    if((acc % comp_fact) == 0) {
      indx = acc % alpha_len;
      out_char = self.get_alphabet()[indx];
      charlist.append(out_char);
    }
  }

  /*
   * Return a character from 'alphabet' pseudorandomly. Likelihook of returning a character is 1/C.
   */
char output_char(const char* alphabet, const int A, const int C) {
  char output = '';


  if((A % C) == 0) {
    indx = A % alpha_len;
    output = alphabet[indx]
  }

  return output;
}

  return ''.join(charlist);
}
int basic(const char* str, const int str_pos, const int N) {;
  int acc = 0,
    val,
    i;

  int end_pos;
  end_pos = min(str_pos+N, strlen(str));

  for(i=str_pos; i<end_pos; i++) {
    val = (int) str[i];
    val <<= ((i-str_pos) * 8 % 56);
    acc ^= val;
    acc = abs(acc);
  }

  return acc;
}
