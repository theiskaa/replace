#ifndef REPLACE_H
#define REPLACE_H

/**
 * @brief Replaces all occurrences of character 'x' with character 'y' in a given string.
 *
 * This function replaces all occurrences of character 'x' with character 'y'
 * in the provided string 'zContent'. It dynamically allocates memory for the
 * resulting string, so the caller is responsible for freeing the returned value.
 *
 * @param x The character to be replaced.
 * @param y The character to replace 'x' with.
 * @param zContent The input string in which replacements will be made.
 * @return A dynamically allocated string with replacements.
 */
char *replaceXY(const char *x, const char *y, const char *zContent);

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
int replace(const char *x, const char *y, const char *path);

#endif
