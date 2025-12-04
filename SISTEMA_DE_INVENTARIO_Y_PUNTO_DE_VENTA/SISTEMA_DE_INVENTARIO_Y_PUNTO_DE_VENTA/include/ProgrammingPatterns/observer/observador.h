#pragma once
#include "Prerequisites.h"
#include <string>

class Observador {
public:
    virtual void actualizar(const std::string& mensaje) = 0;
};
