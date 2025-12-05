#pragma once
#include "ProgrammingPatterns/gasolinera/Gasolinera.h"
#include "ProgrammingPatterns/strategy/MetodoPago.h"

/**
 * @file SistemaGasolineraFacade.h
 * @brief Fachada para simplificar y centralizar las operaciones de la gasolinera.
 *
 * Este archivo declara la clase `SistemaGasolineraFacade`, la cual implementa
 * el patrón **Facade** para encapsular la lógica necesaria al procesar
 * una carga de combustible.
 *
 * El propósito es proporcionar una interfaz simple que coordine:
 *  - Registro de litros cargados
 *  - Validación del tipo de combustible
 *  - Cálculo del total a pagar
 *  - Ejecución de la estrategia de pago (Strategy)
 *  - Generación de ticket o recibo (si aplica)
 *
 * Esto permite que el resto del sistema interactúe con la gasolinera sin
 * preocuparse por los detalles internos.
 */

 /**
  * @class SistemaGasolineraFacade
  * @brief Clase fachada para administrar procesos de carga de combustible.
  *
  * Esta clase centraliza las operaciones necesarias para procesar una
  * venta de gasolina. Oculta la complejidad de los subsistemas como:
  *  - La lógica interna de la gasolinera
  *  - Validación de litros y tipos de combustible
  *  - Métodos de pago implementados mediante Strategy
  *
  * De esta manera, el cliente (main, menú, UI) solo necesita llamar a un método:
  * `procesarCarga()`.
  */

class 
SistemaGasolineraFacade {
public:

    /**
     * @brief Procesa una carga de gasolina usando la fachada.
     *
     * Este método se encarga de:
     *  1. Registrar los litros que se desean cargar.
     *  2. Validar el tipo de combustible solicitado.
     *  3. Calcular el monto total multiplicando litros × precio por litro.
     *  4. Ejecutar la estrategia de pago seleccionada (efectivo, crédito, débito).
     *  5. Registrar la operación dentro del sistema interno de la gasolinera.
     *
     * @param gasolinera Referencia al sistema de gasolinera.
     * @param litros Cantidad de litros que el cliente desea cargar.
     * @param tipo Tipo de combustible (Ejemplo: "Magna", "Premium", "Diesel").
     * @param precioLitro Precio actual por litro del tipo de combustible.
     * @param metodo Estrategia de pago seleccionada. Debe ser una subclase de MetodoPago.
     */
    void procesarCarga(Gasolinera& gasolinera,
        double litros,
        const std::string& tipo,
        double precioLitro,
        MetodoPago* metodo);
};
