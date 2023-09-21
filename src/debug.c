#include "args.c"
#include "errors.c"
#include "files.c"
#include "files.h"
#include "replace.c"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/// A debug version of main function body.
int debugRun(int argc, char *argv[]) {
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

  printf("--------------------------\n");
  printf(">>> Replacing in Paths <<<\n");
  printf("--------------------------\n");

  char **replaced = forEachRule(rules, len, args.target, args.replace, replace);
  for (int i = 0; replaced[i] != NULL; i++) {
    printf("Replaced: '%s' with '%s' in %s\n", args.target, args.replace, replaced[i]);
  }

  free(replaced);
  free(rules);

  return EXIT_SUCCESS;
}
