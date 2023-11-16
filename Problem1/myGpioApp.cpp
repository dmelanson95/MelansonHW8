/* myGpioApp.cpp
 * by David Melanson 
 *
 * Used in conjunction with MYGPIO.cpp and MYGPIO.h also written by David Melanson
 * For IoT HW8 Problem 1.3 a-d
 *
 */

#include "myGPIO.h"
#include <unistd.h>

using namespace std;

int main(void) {


	//Problem 3a
	//pin p9.12 = GPIO_60
	MYGPIO P9_12(60);
	P9_12.setDirection(OUT);

	//Problem 3b
	//pin p8.16 = GPIO_46
	 MYGPIO P8_16(46);
	P8_16.setDirection(IN);
	
	//Problem 3c
	P9_12.setValue(HIGH);
	cout << "GPIO" << P9_12.getNumber() << " value set to " <<  P9_12.getValue() << endl;
	sleep(3);
	P9_12.toggleOutput();
	cout << "GPIO" << P9_12.getNumber() << " value set to " <<  P9_12.getValue() << endl;

	//Problem 3d
	cout << "GPIO" <<  P8_16.getNumber() << " value is " << P8_16.getValue() << endl;
	
}
