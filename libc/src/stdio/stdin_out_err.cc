#include <stdio.h>
#include <unistd.h>
#include "bits/cfile.h"

static _FILE stdin_bits{STDIN_FILENO};
static _FILE stdout_bits{STDOUT_FILENO};
static _FILE stderr_bits{STDERR_FILENO};

FILE *stdin = &stdin_bits;
FILE *stdout = &stdout_bits;
FILE *stderr = &stderr_bits;
