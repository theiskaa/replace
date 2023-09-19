#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

/// Prints the help.txt file from assets directory.
void printHelp() {
  FILE *helpFile = fopen("assets/help.txt", "r");
  if (helpFile == NULL) {
    printf("Cannot open: help.txt\n");
    exit(EXIT_FAILURE);
    return;
  }

  char *line = NULL;
  size_t len = 0;
  while (getline(&line, &len, helpFile) != -1) {
    printf("%s", line);
  }

  free(line);
  fclose(helpFile);
}

void checkArgs(int argc) {
  if (argc < 2) {
    printHelp();
    exit(1);
  } else if (argc < 3) {
    fprintf(stderr, "Error: target(X) is provided but replace(Y) is not");
    exit(1);
  }
}
