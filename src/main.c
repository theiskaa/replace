#include "debug.c"
#include "files.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[]) {
  checkArgs(argc, argv);

  // Note: Enable for dev mode.
  // TODO: include the modes in argv.
  if (false) {
    return debugRun(argc, argv);
  }

  struct Args args = parseArgs(argc, argv);
  struct FilePathRule *rules = generateFilePathRules(args.pathsLen, args.paths);
  int len = args.pathsLen;
  if (len == 0) {
    len = 1;
  }

  char **replaced = forEachRule(rules, len, args.target, args.replace, replace);
  for (int i = 0; replaced[i] != NULL; i++) {
    printf("Replaced: '%s' with '%s' in %s\n", args.target, args.replace, replaced[i]);
  }

  free(replaced);
  free(rules);

  return EXIT_SUCCESS;
}
