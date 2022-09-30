#pragma once
#include <sstream>

class CannotOpenFileException : public std::runtime_error
{
public:
	using std::runtime_error::runtime_error;
};

class ParseError : public std::runtime_error
{
public:
	using std::runtime_error::runtime_error;
};

class InvalidArgumentError : public std::runtime_error
{
public:
	using std::runtime_error::runtime_error;
};