#ifndef FILES_H
#define FILES_H

/**
 * @struct FilePathRule
 * @brief Represents a rule for specifying file or folder paths with optional prefixes.
 *
 * This structure is used to define rules for matching target folders or files based on their names.
 * It also allows specifying an optional file prefix pattern when the path represents a folder.
 *
 * @param path
 *     The concrete name of the target folder or file.
 * @param prefix
 *     The optional file prefix pattern applied when [path] represents a folder.
 *     For example, if [path] is a folder, [prefix] can be used to specify a pattern like "*.c" or "*.md".
 */
struct FilePathRule {
  char *path;    /// The concrete name of the target file or folder.
  char *prefix;  /// The file prefix if [path] is a folder (e.g., "path/*.md").
};

/**
 * @typedef rp
 * @brief A function pointer type for the replace method.
 */
typedef int (*rp)(const char *x, const char *y, const char *path);

/**
 * @brief Generate a FilePathRule from the provided path, separating the target and prefix if present.
 *
 * @param path The path to be converted into a FilePathRule.
 * @return A FilePathRule structure containing the parsed path and prefix.
 */
struct FilePathRule generateFilePathRule(char *path);

/**
 * @brief Generate a list of FilePathRules from the provided list of paths.
 *
 * This function converts an array of path strings into an array of FilePathRules.
 *
 * @param pathsLen The number of paths in the input array.
 * @param path An array of strings representing paths.
 * @return An array of FilePathRule structures generated from the input paths.
 */
struct FilePathRule *generateFilePathRules(int pathsLen, char **path);

/**
 * @brief Recursively collect files and directories under the specified base path (bp).
 *
 * This function collects files and directories under the specified base path (bp), based on the given prefix (pr),
 * and stores them in the result array.
 *
 * @param bp The base path under which files and directories will be collected.
 * @param pr The file prefix pattern (if applicable) to filter files under the base path.
 * @param x Replacement string 'x' for replace method.
 * @param y Replacement string 'y' for replace method.
 * @param count Pointer to an integer representing the number of collected paths.
 * @param result An array to store the collected file and directory paths.
 * @param replace A function pointer for a custom replacement method.
 */
void forEachFile(const char *bp, const char *pr, char *x, char *y, int *count,
                 char ***result, rp replace);

/**
 * @brief Generate full paths based on an array of FilePathRule structures.
 *
 * This function generates full paths based on an array of FilePathRule structures,
 * considering both the target path and optional prefixes.
 *
 * @param rules An array of FilePathRule structures.
 * @param rulesCount The number of rules in the input array.
 * @param x Replacement string 'x' for replace method.
 * @param y Replacement string 'y' for replace method.
 * @param replace A function pointer for a custom replacement method.
 * @return An array of full paths based on the rules provided.
 */
char **forEachRule(struct FilePathRule *rules, int rulesCount, char *x, char *y,
                   rp replace);

/**
 * @brief Read the content of a file specified by its path.
 *
 * This function reads and returns the content of a file located at the given path.
 *
 * @param path The path to the file to be read.
 * @return A string containing the content of the file, or NULL if an error occurs.
 */
char *readFileContent(const char *path);

#endif
