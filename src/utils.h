#ifndef UTILS_H
#define UTILS_H

/**
 * @brief Concatenate two strings together.
 *
 * This function concatenates two input strings, 'x' and 'y', and returns the
 * result as a new dynamically allocated string. The caller is responsible for
 * freeing the memory allocated for the returned string.
 *
 * @param x The first string to be concatenated.
 * @param y The second string to be concatenated.
 * @return A dynamically allocated string containing the concatenated result.
 * @note The caller must free the memory allocated for the returned string.
 */
char *concatenateStrings(const char *x, const char *y);

#endif
