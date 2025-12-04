#pragma once
#include "Prerequisites.h"
#include <string>
#include "ProgrammingPatterns/observer/observador.h"

class Sujeto {
public:
    virtual void agregarObservador(Observador* obs) = 0;
    virtual void eliminarObservador(Observador* obs) = 0;
    virtual void notificar(const std::string& mensaje) = 0;
};
