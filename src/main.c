#include <stdlib.h>
#include <argp.h>
#include "arguments.h"
#include "really.h"

const char *argp_program_version =
	"0.0.1";
const char *argp_program_bug_address =
	"<who-asked@domain.com>";

/* Program documentation. */
static char doc[] =
	"x86cc -- A compiler for the x86 architecture.";

/* A description of the arguments we accept. */
static char args_doc[] = "file..";

/* The options we understand. */
static struct argp_option options[] = {
	{"verbose", 'v', 0, 0, "Produce verbose output"},
	//{"quiet",    'q', 0,      0,  "Don't produce any output" },
	//{"silent",   's', 0,      OPTION_ALIAS },
	{"output", 'o', "file", 0,
	 "Output to FILE instead of standard output"},
	{0}};

/* Parse a single option. */
static error_t parse_opt(int key, char *arg, struct argp_state *state)
{
	/* Get the input argument from argp_parse, which we
	   know is a pointer to our arguments structure. */
	struct arguments *arguments = state->input;

	switch (key)
	{
	case 'q':
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
		if (state->arg_num >= 2)
			/* Too many arguments. */
			argp_usage(state);

		arguments->files[state->arg_num] = arg;
		arguments->file_count++;

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
	arguments.file_count = 0;
	arguments.output_file = "a.out";

	/* Parse our arguments; every option seen by parse_opt will
	   be reflected in arguments. */
	argp_parse(&argp, argc, argv, 0, 0, &arguments);

	do_files(&arguments);

	return 0;
}