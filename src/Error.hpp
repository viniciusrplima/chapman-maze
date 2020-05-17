/*
 *	Error.hpp
 *
 *	by Vinicius Rodrigues
 *	May 17, 2020
 */


#include <string>

#ifndef __ERROR_HPP__
#define __ERROR_HPP__

class Error {

	std::string message;

public:
	Error(std::string msg) {
		message = msg;
	}

	std::string getMessage() {
		return message;
	}
};

#endif
