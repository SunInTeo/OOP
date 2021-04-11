#include <iostream>
#include "MyString.h"

using std::cout;
using std::endl;

void MyString::copy(const MyString &rhs)
{
    reallocateMemory();
    strcpy(string, rhs.string);
    length = rhs.length;
}

void MyString::resize(int length)
{
    MyString temp(*this);

    reallocateMemory();
    strcpy(string, temp.c_str());
}

void MyString::clear()
{
    if (string != nullptr)
    {
        delete[] string;
    }

    string == nullptr;
    length = 0;
}

void MyString::reallocateMemory()
{
    clear();
    string = new char[strlen(string) + 1];
}

MyString::MyString()
{
    string = nullptr;
    length = 0;
}

MyString::MyString(const char *str)
{
    if (str == nullptr)
    {
        string = nullptr;
        length = 0;
    }
    else
    {
        length = strlen(str);
        string = new char[length + 1];
        strcpy(string, str);
    }
}

MyString::MyString(const MyString &rhs)
{
    copy(rhs);
}

MyString::~MyString()
{
    clear();
}

// not sure about this one
char &MyString::at(std::size_t pos)
{
    try
    {
        if (pos > 0 && pos <= strlen(string))
        {
            return string[pos];
        }
        else
        {
            throw std::out_of_range("Out of range");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

//about this one either
const char &MyString::at(std::size_t pos) const
{
    try
    {
        if (pos > 0 && pos <= strlen(string))
        {
            return string[pos];
        }
        else
        {
            throw std::out_of_range("Out of range");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

char &MyString::operator[](std::size_t pos)
{
    return string[pos];
}

const char &MyString::operator[](std::size_t pos) const
{
    return string[pos];
}

char &MyString::front()
{
    return string[0];
}

const char &MyString::front() const
{
    return string[0];
}

char &MyString::back()
{
    return string[length];
}

const char &MyString::back() const
{
    return string[length];
}

bool MyString::empty() const
{
    return !length;
}

std::size_t MyString::size() const
{
    return length;
}

void MyString::push_back(char c)
{
    char *buffer = new char[length + 1];

    for (std::size_t i = 0; i < length + 1; ++i)
    {
        buffer[i] = string[i];
    }
    buffer[length] = c;
    buffer[length + 1] = '\0';

    *this = MyString(buffer);

    delete[] buffer;
}

void MyString::pop_back()
{
    char *buffer = new char[length--];

    strcpy(buffer, string);
    buffer[length - 1] = '\0';

    *this = MyString(buffer);

    delete[] buffer;
}

const char *MyString::c_str() const
{
    char *newArray;
    strcpy(newArray, string);
    return newArray;
}

MyString &MyString::operator=(const MyString &rhs)
{
    clear();
    length = rhs.length;
    reallocateMemory();
    strcpy(string, rhs.string);
}

MyString &MyString::operator+=(char c)
{
    push_back(c);
    return *this;
}

MyString &MyString::operator+=(const MyString &rhs)
{
    std::size_t newSize = length + strlen(rhs.string) + 1;
    resize(newSize);
    strcat(string, rhs.string);
    string[newSize] = '\0';
    return *this;
}

MyString MyString::operator+(char c) const
{
    MyString temp(string);

    temp.push_back(c);
    
    temp = *this;
    
    return *this;
}

MyString MyString::operator+(const MyString &rhs) const
{
    std::size_t newSize = rhs.length + length;

    char *buffer = new char[newSize + 1];

    for (int i = 0; i < newSize; ++i)
    {
        if (i < length)
        {
            buffer[i] = string[i];
        }
        else
        {
            buffer[i] = rhs.string[i];
        }
    }

    buffer[newSize] = '\0';

    MyString temp;
    temp.length = strlen(buffer);
    temp.string = new char[strlen(buffer) + 1];
    strcpy(temp.string, buffer);

    delete[] buffer;

    /* might try this instead of the above
    MyString temp(string);
    for(std::size_t i = 0; i < rhs.length; ++i)
    {
        temp.push_back(rhs.string[i]);
    }*/

    temp = *this;

    return *this;
}

bool MyString::operator==(const MyString &rhs) const
{
    return !strcmp(string, rhs.string);
}

bool MyString::operator!=(const MyString &rhs) const
{
    return !(*this == rhs);
}

// not sure about the method
bool MyString::operator<(const MyString &rhs) const
{
    return strcmp(string, rhs.string) < 0;
}