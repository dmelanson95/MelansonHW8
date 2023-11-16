/* gpioApp.cpp
 *
 * Written by David Melanson for IoT Homework 8 Problem 3
 * Part B: turns on LEDs 1 and 3
 * B: Flashes LED 2
 * C: Reads temperature sensor and displays its value
 * D: Reads the push button on P8_16
 * D2: Turns on LED wired to P9_12 if button is pushed
 * 
 */


#include <iostream>
#include "myGPIO.h"
#include "LED.h"
#include "AnalogIn.h"

using namespace std;

int main(void) {
	
	cout << "Starting Problem 3 Executable File" << endl;

	//Problem 3.1a
	cout << "Creating LEDs" << endl;
	LED led1(1), led2(2), led3(3);
	cout << "LEDs created" << endl;
	led1.turnOn();
	led3.turnOn();
	cout << "LED 1 and 3 turned on" << endl;
	
	//Problem 3.1b
	led2.flash("50");
	cout << "LED 2 flashing" << endl;
	
	//Problem 3.1c
	AnalogIn ai(0);
	cout << "AnalogIn object of number " << ai.getNumber() << "reads with value " << ai.readAdcSample() << endl;

	//Problem 3.1d
	cout << "Creating GPIO Objects" << endl;
	MYGPIO P8_16(46), P9_12(60);
	P8_16.setDirection(IN);
	P9_12.setDirection(OUT);
	int val = P8_16.getValue();
	if(val == 0){
		P9_12.setValue(HIGH);
	}

	cout << "Finished" << endl;
	
}
