#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);
char *make_newl(char *output, char *chunks, char *out_ptr);
void prep(char *chunks, int flag);
char *bigger_out(char *output, int passage_cnt);
char *search_flag(char *chunks);
char *get_last(char* input);

