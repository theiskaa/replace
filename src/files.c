#include "files.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Generate a FilePathRule from the provided path, separating the target and prefix
// if present.
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

// Generate a list of FilePathRules from the provided list of paths.
// Essentially, this function converts an Args structure into an array of FilePathRules.
struct FilePathRule *generateFilePathRules(int pathsLen, char **paths) {
  struct FilePathRule *rules =
      (struct FilePathRule *)malloc(pathsLen * sizeof(struct FilePathRule));

  if (rules == NULL) {
    fprintf(stderr,
            "Memory allocation failed for generating file path rules.\n");
    return NULL;
  }

  for (int i = 0; i < pathsLen; i++) {
    rules[i] = generateFilePathRule(paths[i]);
  }

  return rules;
}
