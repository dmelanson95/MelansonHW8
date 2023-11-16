/* Class implementation file for myGPIO by David Melason
 * for CPE 422 IoT HW8
 */

#include "myGPIO.h"
#include <fstream>


MYGPIO::MYGPIO(int number){
	this->number = number;
	ofstream stream;
	this->name = "gpio" + to_string(number);
	this->path = GPIO_PATH + this->name + "/";
}

int MYGPIO::write(string filename, string value){
	stream.open(this->path + filename);
	stream << value;
	stream.close();
	if(read(filename) != value) {
		cout << "Write to " << this->name << " failed." << endl;
		return -1;
	}
	cout << "Write to " << this->name << " successful." << endl;
	return 0;
}

int MYGPIO::write(string filename, int value){
	return write(filename, to_string(value));

}

// 'file' is string direction or value and function reads either one accordingly
string MYGPIO::read(string filename){
	ifstream instream;
	instream.open(this->path + filename);
	while(!instream.is_open());
	string myOut;
       	getline(instream, myOut);
	instream.close();
	while(instream.is_open());
	return myOut;
}

void MYGPIO::setDirection(GPIO_DIRECTION dir){
	stream.open(this->path + "direction");
	while(!stream.is_open());
	stream << dir;
	stream.close();
	while(stream.is_open());
}

int MYGPIO::getNumber(){
	return this->number;
}

GPIO_VALUE MYGPIO::getValue(){
	string val = this->read("value");
	if(val == "0"){
		return HIGH;
	}
	else return LOW;
}

GPIO_DIRECTION MYGPIO::getDirection(){
	string val = this->read("direction");
	if(val == "in") {return IN;}
	else return OUT;
}

void MYGPIO::toggleOutput(){
	int success;
	this->setDirection(OUT);
	if(this->getValue() == LOW){
		success = this->setValue(HIGH);
	}
	else{
		success = this->setValue(LOW);
	}
	if(!success){
		cout << "Output of " << this->name << " toggled successfully." << endl;
	}
	else {
		cout << "Output of " << this->name << "toggled unsuccessfully." << endl;
	}
}

int MYGPIO::setValue(GPIO_VALUE val){
	return this->write("value", val);
}

MYGPIO::~MYGPIO(){
	cout << "DESTROYING " << this->name << "." << endl;
}

