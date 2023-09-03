#include "files.h"
#include <string.h>

// Generate a FilePathRule from the provided path, separating target and prefix if present.
struct FilePathRule generateFilePathRule(char *path) {
  struct FilePathRule fpr;
  fpr.path = NULL;
  fpr.prefix = NULL;

  char *lastPrefixIndicator = strrchr(path, '*');

  if (lastPrefixIndicator == NULL) {
    fpr.path = strdup(path);
    return fpr;
  }

  fpr.path = strndup(path, lastPrefixIndicator - path);
  fpr.prefix = lastPrefixIndicator;
  return fpr;
}
