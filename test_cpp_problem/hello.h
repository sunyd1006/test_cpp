
#ifndef HELLO_WORLD_H
#define HELLO_WORLD_H

#include <string>

struct Print {
    virtual std::string PrintHelloWorld() = 0;
};

struct HelloWorld : public Print
{
    std::string mName;
    explicit HelloWorld(const std::string name) : mName(name) {}
    std:string PrintHelloWorld();
};



#endif	// HELLO_WORLD_H