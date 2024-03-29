#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <memory>
#include <vector>
#include <string.h>
#include <chrono>
#include <thread>
#include "syntax.h"
#include "interpreter.h"

Exception InterpretPrint(std::vector<int> values);
Exception InterpretWait(std::vector<int> values);

Exception Interpret(std::vector<Statement> statements)
{
    for (Statement i : statements)
    {
        switch (i.instruction)
        {
        case Instruction::Print:
            InterpretPrint(i.values);
            break;
        case Instruction::Wait:
            InterpretWait(i.values);
            break;
        default:
            return Exception::UnknownInstruction;
            break;
        }
    }

    return Exception::Good;
}

Exception InterpretPrint(std::vector<int> values)
{
    for (char i : values)
    {
        std::cout << i;
    }

    return Exception::Good;
}

Exception InterpretWait(std::vector<int> values)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(values.front()));
    return Exception::Good;
}

