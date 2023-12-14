#include "FileException.h"

FileException::FileException(string text){
	this->message = text;
}

void FileException::show(){
	cout << endl << message << endl;
}

void FileException::close(string s) {
	cout << endl << s << endl;
}