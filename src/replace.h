#ifndef REPLACE_H
#define REPLACE_H

#include "args.h"

/**
 * @brief Replaces all occurrences of character 'x' with character 'y' in a
 * given string, with consideration of the 'wordMatch' flag.
 *
 * This function replaces all occurrences of character 'x' with character 'y'
 * in the provided string 'zContent'. It dynamically allocates memory for the
 * resulting string, so the caller is responsible for freeing the returned
 * value. The behavior of this replacement operation is affected by the
 * 'wordMatch' flag in the provided 'args' structure.
 *
 * If 'wordMatch' is set to 0, the function will perform a word-level
 * replacement, ensuring that 'x' is replaced with 'y' only when it forms a
 * whole word. This means that 'x' will not be replaced if it's part of a larger
 * word or surrounded by non-space characters.
 *
 * If 'wordMatch' is set to 1, the function will replace all instances of 'x'
 * with 'y' without considering word boundaries, providing a character-level
 * replacement.
 *
 * @param args A structure containing program arguments, including 'wordMatch'.
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
