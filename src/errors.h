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
void checkArgs(int argc);

/**
 * @brief Print the content of the help.txt file from the assets directory.
 *
 * This function opens and reads the "help.txt" file located in the "assets"
 * directory and prints its content to the console. If the file cannot be opened
 * or read, an error message is displayed, and the program exits.
 */
void printHelp();

#endif
