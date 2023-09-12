#ifndef FILES_H
#define FILES_H

/**
 * @struct  FilePathRule
 * Represents a rule for specifying file or folder paths with optional prefixes.
 *
 * This structure is used to define rules for matching target folders or files
 * based on their names and, if applicable, specifying a file prefix pattern
 * when the path represents a folder.
 *
 * @param path
 *     The concrete name of the target folder or file.
 *
 * @param prefix
 *     The optional file prefix pattern applied when [path] represents a folder.
 *     For example, if [path] is a folder, [prefix] can be used to specify a
 *     pattern like *.c or *.md
 */
struct FilePathRule {
  char *path;   // The concrete name of target file or folder.
  char *prefix; // The file prefix if [path] is a folder.
                // Something like: path/*.md
};

// Generate a FilePathRule from the provided path, separating the target and
// prefix if present.
struct FilePathRule generateFilePathRule(char *path);

// Generate a list of FilePathRules from the provided list of paths.
// Essentially, this function converts an Args structure into an array of
// FilePathRules.
struct FilePathRule *generateFilePathRules(int pathsLen, char **path);

// Recursively collects files and directories under the specified base path
// (bp), based on the given prefix (pr) and stores them in the result array.
void collectFiles(const char *bp, const char *pr, char ***result, int *count);

// Generates full paths based on an array of FilePathRule structures.
char **generateFullPaths(struct FilePathRule *rules, int rulesCount);

#endif
