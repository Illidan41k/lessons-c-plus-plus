#pragma once
#include <string>

/**
 * @brief Calculates exponential and dumps the result into text file.
 * Uses rdbuf redirection.
 *
 * @param degree exponential degree.
 * @param filename Where to write output data.
*/
void exponential(double degree, std::string filename);


/**
 * @brief Just shows the difference in calculation precision using double and float.
*/
void test_types_operations();



/**
 * @brief Opens file and reads integer values from it.  Shows them in a column. Stops when can't read int.
 * @param filename Source for reading.
*/
void test_ifstream(std::string filename);


/**
 * @brief Separates input string into float values. Shows them in a column. Stops when can't read float.
 * @param input String contains values. Example: "13.2 14.9 3.14444 9.0567"
*/
void test_stringstream(std::string input);


/**
 * @brief converts string to int. adds 10 to result. Prints it. nothing more.
 * @param input String contains int value. Example: "459"
*/
void test_conversion(std::string input);

