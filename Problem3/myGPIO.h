/* Header file for GPIO class created by David Melanson
 *for CPE 422 IoT HW8
 *
 */

#ifndef GPIO_H_
#define GPIO_H_

#include <fstream>
#include <string>
#include <iostream>

using namespace std; 

#define GPIO_PATH "/sys/class/gpio/"
enum GPIO_DIRECTION { IN, OUT };
enum GPIO_VALUE{ LOW, HIGH };

// IN, LOW = 0
// HIGH, OUT = 1

class MYGPIO {
	private:
		int number;
		string name, path;
		int write(string filename, string value);
		int write (string filename, int value);
		string read(string filename);
		ofstream stream;

	public:
		MYGPIO(int number);
		int getNumber();
		void setDirection(GPIO_DIRECTION dir);
		GPIO_DIRECTION getDirection();
		int setValue(GPIO_VALUE val);
		GPIO_VALUE getValue();
		void toggleOutput();
		~MYGPIO();
};

#endif
