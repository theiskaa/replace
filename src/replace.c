#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int replace(char x, char y, char *path) {
  // TODO: add replace functionality
  return 0;
}

char **replaceAll(char x, char y, char **paths) {
  char **replaced = (char **)malloc(sizeof(char *));
  if (!replaced) {
    // TODO: implement errors.
    perror("Memory allocation error");
    return NULL;
  }

  int pathsLen = 0;
  for (int i = 0; paths[i] != NULL; i++) {
    int hasReplaced = replace(x, y, paths[i]);
    if (hasReplaced != 0) {
      continue;
    }

    replaced[pathsLen++] = strdup(paths[i]);
    replaced = (char **)realloc(replaced, sizeof(char *) * (pathsLen + 1));
    if (!replaced) {
      // TODO: implement errors.
      perror("Memory allocation error");
      return NULL;
    }
  }

  replaced[pathsLen + 1] = NULL;
  return replaced;
}
