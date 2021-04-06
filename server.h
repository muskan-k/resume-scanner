

struct keys * allocate (int n);
void read_keys(struct keys *k, int n);
int multi_scan(char *strp, struct keys *k, int num, char *op);
int scan(char* ptf, char *key_w);
void initial(int *argc, char *argv[]);
int validate();
int validate_op(char *op);
void lower_case(char *array);
int scan1_loop(int *argc, char *argv[], char *key_w, int *file_count);