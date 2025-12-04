#include "ProgrammingPatterns/facade/SistemaGasolineraFacade.h"

void SistemaGasolineraFacade::procesarCarga(Gasolinera& gasolinera,
    double litros,
    const std::string& tipo,
    double precioLitro,
    MetodoPago* metodo) {
    gasolinera.registrarCarga(litros, tipo, precioLitro, metodo);
}
