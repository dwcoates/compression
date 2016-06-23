%module compressor

extern unsigned long long basic(const char* str, int str_pos, int N);
extern const char* core(const char* str, const char* alphabet, const int comp_fact, const int N);
