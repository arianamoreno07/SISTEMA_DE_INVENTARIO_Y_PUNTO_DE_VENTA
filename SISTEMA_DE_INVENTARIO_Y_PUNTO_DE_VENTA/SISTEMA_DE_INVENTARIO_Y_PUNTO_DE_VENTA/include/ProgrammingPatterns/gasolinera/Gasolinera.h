#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "ProgrammingPatterns/strategy/MetodoPago.h"

/**
 * @file Gasolinera.h
 * @brief Declaración de la clase Gasolinera y sus operaciones principales.
 *
 * Esta clase representa el sistema central de una gasolinera, permitiendo:
 *  - Registrar cargas de combustible.
 *  - Validar pagos usando el patrón Strategy.
 *  - Almacenar un historial de todas las cargas realizadas.
 *  - Guardar y cargar dicho historial desde un archivo JSON.
 *
 * La clase se integra con el patrón **Strategy** mediante objetos de tipo `MetodoPago`,
 * y con un **Facade** externo que facilita su uso desde otros módulos.
 */

 /**
  * @struct CargaGasolina
  * @brief Estructura que almacena los datos completos de una carga.
  *
  * Contiene:
  *  - Litros cargados.
  *  - Tipo de combustible (Ej: Magna, Premium, Diesel).
  *  - Precio por litro al momento de la carga.
  *  - Total pagado por el cliente.
  */

struct 
CargaGasolina {
    double litros;
    std::string tipo;
    double precioLitro;
    double totalPagado;
};

/**
 * @class Gasolinera
 * @brief Clase principal para gestionar el registro de cargas de gasolina.
 *
 * Esta clase administra todo el flujo interno relacionado con cargar combustible:
 * cálculo de total, validación del pago, registro histórico y almacenamiento en JSON.
 *
 * La validación del pago depende del método recibido, el cual utiliza el patrón Strategy
 * para ejecutar comportamientos distintos según el tipo de pago.
 */
class 
Gasolinera {
private:

    /// Historial completo de cargas realizadas.
    std::vector<CargaGasolina> historial;

public:
    Gasolinera() = default;
    ~Gasolinera() = default;

    /**
     * @brief Valida si el monto pagado cubre el total calculado.
     *
     * Total esperado = litros × precioLitro.
     * Devuelve true si el monto pagado es mayor o igual al total.
     *
     * @param litros Cantidad de litros que se desean cargar.
     * @param precioLitro Costo del combustible por litro.
     * @param montoPagado Monto que el cliente pagó mediante un método Strategy.
     * @return true si el pago es suficiente, false si no.
     */
    bool validarPago(double litros, double precioLitro, double montoPagado) const;

    /**
     * @brief Registra una carga usando un método de pago Strategy.
     *
     * Este método:
     *  1. Calcula el total según litros × precio.
     *  2. Ejecuta la estrategia de pago seleccionada.
     *  3. Valida si el pago fue suficiente.
     *  4. Agrega la carga al historial si procede.
     *
     * @param litros Cantidad de litros cargados.
     * @param tipo Tipo de combustible (Magna, Premium, Diesel, etc.).
     * @param precioLitro Precio actual por litro.
     * @param metodo Puntero a un objeto de tipo MetodoPago.
     */
    void registrarCarga(double litros, const std::string& tipo, double precioLitro, MetodoPago* metodo);

    /**
    * @brief Muestra en consola todo el historial de cargas realizadas.
    */
    void mostrarHistorial() const;

    /**
     * @brief Guarda el historial completo en un archivo JSON.
     *
     * @param archivo Ruta y nombre del archivo donde se guardará el historial.
     */
    void guardarHistorialJson(const std::string& archivo) const;

    /**
   * @brief Carga el historial desde un archivo JSON.
   *
   * Sobrescribe el historial actual por el contenido del archivo.
   *
   * @param archivo Ruta del archivo JSON.
   */
    void cargarHistorialJson(const std::string& archivo);
};
