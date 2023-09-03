#ifndef FILES_H
#define FILES_H

/**
 * @struct FilePathRule
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

struct FilePathRule generateFilePathRule(char *path);

#endif
