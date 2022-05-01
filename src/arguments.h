#if !defined(_H_ARGUMENTS)
#define _H_ARGUMENTS

/* Used by main to communicate with parse_opt. */
struct arguments
{
    char *files[99]; /* arg1 & arg2 */
    int silent, verbose, file_count;
    char *output_file;
};

#endif // _H_ARGUMENTS