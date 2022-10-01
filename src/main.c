#include <stdlib.h>
#include <argp.h>
#include "out.h"

const char *argp_program_version =
    "x86cc 0.1";
const char *argp_program_bug_address =
    "https://github.com/seals-are-bouncy/x86cc";

/* Program documentation. */
static char doc[] =
    "x86cc -- a c compiler";

/* A description of the arguments we accept. */
static char args_doc[] = "file...";

/* The options we understand. */
static struct argp_option options[] = {
    {"standard", 't', 0, 0, "Set the C standard"},
    {"quiet", 'q', 0, 0, "Don't produce any output"},
    {"silent", 's', 0, OPTION_ALIAS},
    {"output", 'o', "FILE", 0,
     "Output to FILE instead of standard output"},
    {0}};

/* Used by main to communicate with parse_opt. */
struct arguments
{
    char *args[90]; /* arg1 & arg2 */
    int silent, verbose, argc;
    char *output_file, std;
};

/* Parse a single option. */
static error_t
parse_opt(int key, char *arg, struct argp_state *state)
{
    /* Get the input argument from argp_parse, which we
       know is a pointer to our arguments structure. */
    struct arguments *arguments = state->input;

    switch (key)
    {
    case 't':
        arguments->std = arg;        
    case 's':
        arguments->silent = 1;
        break;
    case 'v':
        arguments->verbose = 1;
        break;
    case 'o':
        arguments->output_file = arg;
        break;

    case ARGP_KEY_ARG:
        //if (state->arg_num >= 2)
            /* Too many arguments. */
            //argp_usage(state);

        arguments->args[state->arg_num] = arg;
        arguments->argc++;

        break;

    case ARGP_KEY_END:
        if (state->arg_num < 1)
            /* Not enough arguments. */
            argp_usage(state);
        break;

    default:
        return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

/* Our argp parser. */
static struct argp argp = {options, parse_opt, args_doc, doc};

int main(int argc, char **argv)
{
    struct arguments arguments;

    /* Default values. */
    arguments.silent = 0;
    arguments.verbose = 0;
    arguments.output_file = "-";

    /* Parse our arguments; every option seen by parse_opt will
       be reflected in arguments. */
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    for (size_t i = 0; i < arguments.argc; i++)
    {
        out_success(arguments.args[i]);
    }
    

}