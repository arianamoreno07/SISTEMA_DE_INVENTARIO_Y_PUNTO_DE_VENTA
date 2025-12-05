#include "ProgrammingPatterns/facade/SistemaGasolineraFacade.h"

/**
 * @file SistemaGasolineraFacade.cpp
 * @brief Implementación del método principal del Facade para la gasolinera.
 *
 * Este archivo contiene la lógica que simplifica el proceso de registrar
 * una carga de gasolina. El cliente solo necesita llamar a este método,
 * evitando manejar directamente la interacción con la clase Gasolinera.
 *  * @date 2025-12-04
 * @version 1.0
 * @author Ari
 */

void SistemaGasolineraFacade::procesarCarga(Gasolinera& gasolinera,
    double litros,
    const std::string& tipo,
    double precioLitro,
    MetodoPago* metodo) {

    // Delegamos toda la lógica interna a la clase Gasolinera.
    gasolinera.registrarCarga(litros, tipo, precioLitro, metodo);
}
