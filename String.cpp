#include "String.h"

Custom::String::String(const char * text)
{
	while (text[length] != '\0') {
		length++;
	}
	buffer = new char[length + 1];
	for (unsigned int i = 0; i < length; i++)
	{
		buffer[i] = text[i];
	}
	buffer[length] = '\0';
}

Custom::String::~String()
{
	if(buffer != nullptr)
		delete[] buffer;
}

Custom::String & Custom::String::operator+(String & string)
{
	//copy buffer and allocate new
	char* tempBuffer = this->buffer;
	this->buffer = new char[this->length + string.length + 1];
	for (unsigned int i = 0; i < this->length; i++)
	{
		this->buffer[i] = tempBuffer[i];
	}
	delete[] tempBuffer;

	//add new chars to buffer
	int index = 0;
	for (unsigned int i = this->length; i < string.length + this->length; i++)
	{
		this->buffer[i] = string.buffer[index];
		index++;
	}
	this->length += string.length;
	buffer[this->length] = '\0';
	return *this;
}

Custom::String & Custom::String::operator+(const char * buffer)
{
	String tempBuffer(buffer);
	return this->operator+(tempBuffer);
}

void Custom::String::operator+=(const char * buffer)
{
	String tempBuffer(buffer);
	this->operator+=(tempBuffer);
}

void Custom::String::operator+=(String & string)
{
	//copy buffer and allocate new
	char* tempBuffer = this->buffer;
	this->buffer = new char[this->length + string.length + 1];
	for (unsigned int i = 0; i < this->length; i++)
	{
		this->buffer[i] = tempBuffer[i];
	}
	delete[] tempBuffer;

	//add new chars to buffer
	int index = 0;
	for (unsigned int i = this->length; i < string.length + this->length; i++)
	{
		this->buffer[i] = string.buffer[index];
		index++;
	}
	this->length += string.length;
	buffer[this->length] = '\0';
}

bool Custom::String::Empty()
{
	return (length != 0);
}

void Custom::String::Clear()
{
	delete[] buffer;
	buffer = nullptr;
	length = 0;
}

unsigned int Custom::String::Find(char symbol)
{
	for (unsigned int i = 0; i < this->length; i++)
	{
		if (symbol == buffer[i])
			return i;
	}
	return -1;
}

bool Custom::String::Swap(unsigned int from, unsigned int to)
{
	if (to == length || from == length)
		return false;
	char temp = buffer[from];
	buffer[from] = buffer[to];
	buffer[to] = temp;
	return true;
}

bool Custom::String::Replace(char symbol, unsigned int position)
{
	if(position == length)
		return false;
	buffer[position] = symbol;
	return true;
}

bool Custom::String::Erase(unsigned int position)
{
	if(position == length)
		return false;
	char* tempBuffer = this->buffer;
	this->length--;
	this->buffer = new char[this->length + 1];
	for (unsigned int i = 0; i < this->length; i++)
	{
		if(i >= position)
			this->buffer[i] = tempBuffer[i + 1];
		else
			this->buffer[i] = tempBuffer[i];
	}
	buffer[length] = '\0';
	delete[] tempBuffer;
	return true;
}

char Custom::String::Front()
{
	return buffer[0];
}

char Custom::String::Back()
{
	return buffer[length - 1];
}

std::ostream & Custom::operator<<(std::ostream & os, const String & text)
{
	os << text.buffer;
	return os;
}

std::ostream & Custom::operator<<(std::ostream & os, const String * text)
{
	os << text->buffer;
	return os;
}

std::istream & Custom::operator>>(std::istream & is, String & text)
{
	text.Clear();
	text.buffer = new char[255];
	is >> text.buffer;
	return is;
}

std::istream & Custom::operator>>(std::istream & is, String * text)
{
	text->Clear();
	text->buffer = new char[255];
	is >> text->buffer;
	return is;
}
