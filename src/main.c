#include "args.c"
#include "errors.c"
#include "files.c"
#include "files.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[]) {
  checkArgs(argc);

  struct Args args = parseArgs(argc, argv);

  printf("---------------------------\n");
  printf(">>> Parsing Args <<<\n");
  printf("---------------------------\n");
  printf("X: %s\n", args.target);
  printf("Y: %s\n", args.replace);

  printf("Z:\n");
  struct FilePathRule *rules = generateFilePathRules(args.pathsLen, args.paths);
  int len = args.pathsLen;

  // Ensure at least one FilePathRule
  if (len == 0) {
    len = 1;
  }

  for (int i = 0; i < len; i++) {
    if (args.pathsLen > i) {
      printf("  - %d: %s \n", i, args.paths[i]);
    } else {
      printf("  - 0: pwd \n");
    }

    struct FilePathRule fpr = rules[i];

    if (fpr.path == NULL) {
      printf("\t- target: pwd\n");
    } else {
      printf("\t- target: %s\n", fpr.path);
    }

    if (fpr.prefix == NULL) {
      printf("\t- prefix: null\n");
    } else {
      printf("\t- prefix: %s\n", fpr.prefix);
    }
  }

  printf("-----------------------------\n");
  printf(">>> Generating Full Paths <<<\n");
  printf("-----------------------------\n");

  char **fullPaths = generateFullPaths(rules, len);
  for (int i = 0; fullPaths[i] != NULL; i++) {
    printf("%s\n", fullPaths[i]);
    free(fullPaths[i]);
  }

  // Clean up allocated memory
  free(fullPaths);
  free(rules);

  return EXIT_SUCCESS;
}
