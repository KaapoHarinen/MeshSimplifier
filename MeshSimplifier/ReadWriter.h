#pragma once
#include <string>

class ReaderWriter
{
public:
	virtual ~ReaderWriter() {}
	virtual void Read(const std::string& path) = 0;
	virtual void Write(const std::string& path) = 0;
};