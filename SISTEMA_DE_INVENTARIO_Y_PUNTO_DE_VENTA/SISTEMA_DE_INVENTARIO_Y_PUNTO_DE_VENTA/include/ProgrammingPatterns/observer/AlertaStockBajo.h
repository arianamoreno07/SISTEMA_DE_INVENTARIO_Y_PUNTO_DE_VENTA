#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/observer/observador.h"
#include <iostream>

class AlertaStockBajo : public Observador {
public:
    void actualizar(const std::string& mensaje) override {
        std::cout << "⚠ ALERTA: " << mensaje << std::endl;
    }
};
