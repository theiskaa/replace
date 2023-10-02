#ifndef REPLACE_H
#define REPLACE_H

#include "args.h"

/**
 * @brief Replaces all occurrences of character 'x' with character 'y' in a
 * given string.
 *
 * This function replaces all occurrences of character 'x' with character 'y'
 * in the provided string 'zContent'. It dynamically allocates memory for the
 * resulting string, so the caller is responsible for freeing the returned
 * value.
 *
 * @param args A structure containing program arguments.
 * @param zContent The input string in which replacements will be made.
 * @return A dynamically allocated string with replacements.
 */
char *replaceXY(const struct Args args, const char *zContent);

/**
 * @brief Replaces a character 'x' with character 'y' in a path string.
 *
 * This function replaces all occurrences of character 'x' with character 'y'
 * in the given path string.
 *
 * @param args A structure containing program arguments.
 * @param path The path string in which replacements will be made.
 * @return An integer representing the number of replacements made.
 */
int replace(const struct Args args, const char *path);

#endif
