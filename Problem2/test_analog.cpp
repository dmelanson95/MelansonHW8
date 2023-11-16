/* test_analog.cpp
 *
 * Function file written by David Melanson for IoT Homework 8
 * Used in conjunction with AnalogIn.cpp and AnalogIn.h
 * 
 * Function instantiates an AnalogIn object with number 0
 * Calls getNumber() and calls readAdcSample() writing to cout
 *
 */

#include <iostream>
#include "AnalogIn.h"

using namespace std;

int main(void) {

	cout << "Starting test_analog.cpp" << endl;

	AnalogIn ai(0);
	cout << "AnalogIn object created with number " << ai.getNumber() << "." << endl;
	cout << "AnalogIn reads value of " << ai.readAdcSample() << "." << endl;

	cout << "Finished Program." << endl;

	return 0;
}

