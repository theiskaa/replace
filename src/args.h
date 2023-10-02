#ifndef ARGS_H
#define ARGS_H

/**
 * @brief Structure for storing command-line arguments.
 *
 * This structure is used to hold the command-line arguments parsed from the
 * input arguments of a program.
 */
struct Args {
  char *target;  /// The character to be replaced (X).
  char *replace; /// The character to replace 'target' with (Y).
  char **paths;  /// An array of strings representing paths (Z).
  int pathsLen;  /// The number of paths in the 'paths' array.
  int wordMatch; /// This int flag determines whether the replacement
                 /// algorithm requires an exact, space-free match for
                 /// segments to be replaced.
};

/**
 * @brief Parse command-line arguments and populate an Args structure.
 *
 * This function takes the command-line arguments (argc and argv) and parses
 * them to populate an Args structure with the provided values.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of strings representing the command-line arguments.
 * @return An Args structure containing the parsed arguments.
 */
struct Args parseArgs(int argc, char *argv[]);

#endif
