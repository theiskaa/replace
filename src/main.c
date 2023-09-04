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
  if (args.target == NULL || args.replace == NULL) {
    return EXIT_FAILURE;
  }

  printf("X: %s\n", args.target);
  printf("Y: %s\n", args.replace);
  if (args.paths == NULL) {
    printf("Z: all files \n");
  } else {
    printf("Z:\n");
    struct FilePathRule *rules = generateFilePathRules(args.pathsLen, args.paths);
    for (int i = 0; i < args.pathsLen; i++) {
      printf("  - %d: %s \n", i, args.paths[i]);
      struct FilePathRule fpr = rules[i];
      printf("\t- target: %s\n", fpr.path);
      if (fpr.prefix == NULL) {
        printf("\t- prefix: null\n");
      } else {
        printf("\t- prefix: %s\n", fpr.prefix);
      }
    }
  }

  return EXIT_SUCCESS;
}
