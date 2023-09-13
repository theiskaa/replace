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

#endif
