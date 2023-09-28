#include "args.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Args parseArgs(int argc, char *argv[]) {
  struct Args args;
  args.target = NULL;
  args.replace = NULL;
  args.paths = NULL;
  args.pathsLen = 0;
  args.exactMatchEnabled = 1;

  if (argc < 3) {
    return args;
  }

  int idx = 1;
  if (strcmp("-w", argv[idx]) == 0 || strcmp("--word", argv[idx]) == 0) {
    args.exactMatchEnabled = 0;
    idx++;
  }

  args.target = argv[idx];
  args.replace = argv[idx + 1];

  if (argc > 3) {
    args.paths = (char **)malloc((argc - 3) * sizeof(char *));
    if (args.paths == NULL) {
      fprintf(stderr, "Memory allocation failed for paths.\n");
      exit(1);
    }

    for (int i = 3; i < argc; i++) {
      args.paths[i - 3] = (char *)malloc(strlen(argv[i]) + 1);
      if (args.paths[i - 3] == NULL) {
        fprintf(stderr, "Memory allocation failed for path %d.\n", i);
        exit(1);
      }
      strcpy(args.paths[i - 3], argv[i]);
      args.pathsLen++;
    }
  }

  return args;
}
