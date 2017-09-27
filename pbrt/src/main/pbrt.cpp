#include "pbrt.h"

static void usage(const char *msg = nullptr) {
	if (msg) fprintf(stderr, "pbrt: %s\n\n", msg);

	fprintf(stderr, R"(
usage: pbrt [<options>] <filename.pbrt...>
Rendering options:
  --help               Print this help text.
  --nthreads <num>     Use specified number of threads for rendering.
  --outfile <filename> Write the final image to the given filename.
  --quick              Automatically reduce a number of quality settings to
                       render more quickly.
  --quiet              Suppress all text output other than error messages.
Logging options:
  --logdir <dir>       Specify directory that log files should be written to.
                       Default: system temp directory (e.g. $TMPDIR or /tmp).
  --logtostderr        Print all logging messages to stderr.
  --minloglevel <num>  Log messages at or above this level (0 -> INFO,
                       1 -> WARNING, 2 -> ERROR, 3-> FATAL). Default: 0.
  --v <verbosity>      Set VLOG verbosity.
Reformatting options:
  --cat                Print a reformatted version of the input file(s) to
                       standard output. Does not render an image.
  --toply              Print a reformatted version of the input file(s) to
                       standard output and convert all triangle meshes to
                       PLY files. Does not render an image.
)");
}


int main(int argc, char *argv[]) {
	Options options;
	std::vector<std::string> filenames;

	// Process command-line arguments
	for (int i = 1; i < argc; ++i) {
		if (!strcmp(argv[i], "--nthreads") || !strcmp(argv[i], "-nthreads")) {
			if (i + 1 == argc) usage("Missing value after --nthreads argument");
			options.nThreads = atoi(argv[++i]);
		}
		else if (!strncmp(argv[i], "--nthreads=", 11)) {
			options.nThreads = atoi(&argv[i][11]);
		}
		else if (!strcmp(argv[i], "--outfile") || !strcmp(argv[i], "-outfile")) {
			if (i + 1 == argc) usage("Missing value after --outfile argument");
			options.imageFile = argv[++i];
		}
		else if (!strncmp(argv[i], "--outfile=", 10)) {
			options.imageFile = &argv[i][10];
		}
		else if (!strcmp(argv[i], "--logdir") || !strcmp(argv[i], "-logdir")) {
			if (i + 1 == argc) usage("Missing value after --logdir argument");
			FLAGS_log_dir = argv[++i];
		}
		
	}
	int a;
	std::cout << "Output goes here..." << std::endl;
	std::cin >> a;
	return 0;
}