#ifndef ERRORS_H
#define ERRORS_H

/**
 * @brief Check the number of command-line arguments.
 *
 * This function checks if the number of command-line arguments (argc) is
 * within the expected range and raises an error if it is not.
 *
 * @param argc The number of command-line arguments.
 * @throws An error if the argument count is not as expected.
 */
void checkArgs(int argc, char *argv[]);

/**
 * @brief Print the help information for the 'rp' command.
 *
 * This function prints the usage information and examples for the 'rp' command,
 * which is a versatile tool for efficiently replacing content within specified
 * files. The help text provides details on how to use the command, its
 * arguments, and usage examples. It also includes notes on using shell
 * wildcards and the behavior when no 'FILES' argument is provided.
 *
 * The help information is displayed to the console when the 'rp' command is entered.
 */
void printHelp();

#endif
