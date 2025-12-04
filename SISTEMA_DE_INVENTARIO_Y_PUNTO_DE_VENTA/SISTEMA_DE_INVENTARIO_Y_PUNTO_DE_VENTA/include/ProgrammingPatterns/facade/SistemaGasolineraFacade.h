#pragma once
#include "ProgrammingPatterns/gasolinera/Gasolinera.h"
#include "ProgrammingPatterns/strategy/MetodoPago.h"

/**
 * @file SistemaGasolineraFacade.h
 *
 * Facade para simplificar las operaciones de la gasolinera.
 */

class SistemaGasolineraFacade {
public:
    void procesarCarga(Gasolinera& gasolinera,
        double litros,
        const std::string& tipo,
        double precioLitro,
        MetodoPago* metodo);
};
