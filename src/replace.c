#include "args.h"
#include "files.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Replaces args.target with args.replace in zContent.
char *replaceXY(struct Args args, const char *zContent) {
  size_t xLen = strlen(args.target);
  size_t zLen = strlen(zContent);

  char *buffer = malloc((zLen + 1) * sizeof(char));

  if (buffer == NULL) {
    printf("Cannot allocate memory to replace x with y\n");
    return NULL;
  }

  memset(buffer, 0, zLen + 1);

  size_t pos = 0;
  while (pos < zLen) {
    char *match = strstr(zContent + pos, args.target);

    if (match == NULL) {
      strcat(buffer, zContent + pos);
      break;
    }

    if (args.wordMatch == 1) {
      strncat(buffer, zContent + pos, match - (zContent + pos));
      strcat(buffer, args.replace);
      pos = match - zContent + xLen;
      continue;
    }

    if ((match == zContent || isspace(*(match - 1))) && (match[xLen] == '\0' || isspace(match[xLen]))) {
      strncat(buffer, zContent + pos, match - (zContent + pos));
      strcat(buffer, args.replace);
      pos = match - zContent + xLen;
    } else {
      strncat(buffer, zContent + pos, match - (zContent + pos) + 1);
      pos = match - zContent + 1;
    }
  }

  return buffer;
}

// Replaces x with y in FILE of path.
// If something wents wrong, error will be logged in console
// appropriate error number will be returned.
int replace(struct Args args, const char *path) {
  char *zContent = readFileContent(path);
  if (zContent == NULL) {
    return 1;
  }

  char *modifiedContent = replaceXY(args, zContent);
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
