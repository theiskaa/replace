#include "files.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Replaces x with y in zContent string.
char *replaceXY(const char *x, const char *y, const char *zContent) {
  size_t xLen = strlen(x);
  size_t zLen = strlen(zContent);

  char *buffer = malloc((zLen + 1) * sizeof(char));
  if (buffer == NULL) {
    printf("Cannot allocate memory to replace x with y\n");
    return NULL;
  }

  memset(buffer, 0, zLen + 1);

  size_t pos = 0;
  while (pos < zLen) {
    char *match = strstr(zContent + pos, x);
    if (match == NULL) {
      strcat(buffer, zContent + pos);
      break;
    }

    strncat(buffer, zContent + pos, match - (zContent + pos));
    strcat(buffer, y);
    pos = match - zContent + xLen;
  }

  return buffer;
}

// Replaces x with y in FILE of path.
// If something wents wrong, error will be logged in console
// appropriate error number will be returned.
int replace(const char *x, const char *y, const char *path) {
  char *zContent = readFileContent(path);
  if (zContent == NULL) {
    return 1;
  }

  char *modifiedContent = replaceXY(x, y, zContent);
  if (modifiedContent == NULL) {
    free(zContent);
    return 1;
  }

  if (strcmp(zContent, modifiedContent) == 0) {
    free(zContent);
    free(modifiedContent);
    return 1;
  }

  FILE *file = fopen(path, "w");
  if (file == NULL) {
    free(zContent);
    free(modifiedContent);
    return 1;
  }

  size_t len = strlen(modifiedContent);
  fwrite(modifiedContent, sizeof(char), len, file);

  fclose(file);
  free(zContent);
  free(modifiedContent);

  return 0;
}
