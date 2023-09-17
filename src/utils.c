#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to concatenate two strings and normalize the path.
char *concatenateStrings(const char *x, const char *y) {
  int xLen = strlen(x);
  int yLen = strlen(y);

  int hasTrailingSlashX = (xLen > 0 && x[xLen - 1] == '/');
  int hasLeadingSlashY = (yLen > 0 && y[0] == '/');
  int totalLength = xLen + yLen + 1;

  if (hasTrailingSlashX && hasLeadingSlashY) {
    totalLength--;
  }

  char *result = (char *)malloc(totalLength);
  if (!result) {
    perror("Memory allocation error");
    exit(EXIT_FAILURE);
  }

  strcpy(result, x);

  if (!(hasTrailingSlashX || hasLeadingSlashY)) {
    strcat(result, "/");
  }

  strcat(result, y);
  return result;
}
