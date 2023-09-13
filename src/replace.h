#ifndef REPLACE_H
#define REPLACE_H

/**
 * @brief Replaces a character 'x' with character 'y' in a path string.
 *
 * This function replaces all occurrences of character 'x' with character 'y'
 * in the given path string.
 *
 * @param x The character to be replaced.
 * @param y The character to replace 'x' with.
 * @param path The path string in which replacements will be made.
 * @return An integer representing the number of replacements made.
 */
int replace(char x, char y, char *path);

/**
 * @brief Iterates through the array of paths and executes character
 * replacement.
 *
 * This function iterates through an array of paths and replaces all occurrences
 * of character 'x' with character 'y' in each path string.
 *
 * @param x The character to be replaced.
 * @param y The character to replace 'x' with.
 * @param paths An array of strings representing paths.
 * @return An array of strings with replacements.
 */
char **replaceAll(char x, char y, char **paths);

#endif
