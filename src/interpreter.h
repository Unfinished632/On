#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <memory>
#include <vector>
#include "syntax.h"

enum Exception{
    Good,
    UnknownInstruction,
    NullReferenceException
};

Exception Interpret(std::vector<Statement> statements);