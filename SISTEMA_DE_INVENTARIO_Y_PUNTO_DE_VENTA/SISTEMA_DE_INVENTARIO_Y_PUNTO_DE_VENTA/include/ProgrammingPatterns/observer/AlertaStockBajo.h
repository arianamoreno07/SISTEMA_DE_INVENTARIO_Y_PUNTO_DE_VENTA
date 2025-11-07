#pragma once
/**
 * @file AlertaStockBajo.h
 * @brief Implementación del observador que muestra alertas de stock bajo.
 *
 * Esta clase concreta implementa la interfaz `Observador` del patrón Observer.
 * Su propósito es recibir notificaciones del sujeto (`Inventario`) cuando el
 * stock de un producto alcanza niveles bajos y mostrar un mensaje de alerta
 * en la consola.
 *
 * @date 2025-11-07
 * @version 1.0
 * @author Ari
 */
#include "Prerequisites.h"
#include "ProgrammingPatterns/observer/observador.h"

 /**
  * @class AlertaStockBajo
  * @brief Observador concreto que muestra mensajes de alerta cuando el stock es bajo.
  *
  * Esta clase forma parte del patrón **Observer**, y actúa como el "Observador".
  * Cuando el `Inventario` (el "Sujeto") detecta que un producto tiene poca existencia,
  * invoca el método `actualizar()` de esta clase para notificar la situación.
  */
class
AlertaStockBajo : public Observador {

public:
    /**
    * @brief Muestra un mensaje de alerta en consola cuando es notificado.
    *
    * @param mensaje Texto con la información del evento (por ejemplo, el nombre del producto con bajo stock).
    *
    * Este método se ejecuta automáticamente cuando el sujeto (`Inventario`) llama a `notificar()`.
    */
	void 
     actualizar(const std::string& mensaje) override {
		std::cout << "ALERTA: " << mensaje << std::endl;

	}

};