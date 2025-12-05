#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/observer/observador.h"
#include <iostream>

/**
 * @file AlertaStockBajo.h
 * @brief Implementación concreta del observador encargado de mostrar alertas de stock bajo.
 *
 * Esta clase forma parte del **patrón Observer**. Su función es reaccionar a las
 * notificaciones enviadas por el sujeto (`Inventario`) cuando detecta que un
 * producto tiene poca existencia disponible.
 */

 /**
  * @class AlertaStockBajo
  * @brief Observador que imprime un mensaje de alerta al recibir notificaciones.
  *
  * Cuando el inventario determina que el stock de un producto bajó de cierto
  * umbral (por ejemplo, menos de 5 unidades), llama a `notificar()` y esta clase
  * responde mediante el método `actualizar()`, mostrando un aviso en consola.
  */
class AlertaStockBajo : public Observador {
public:

    /**
    * @brief Recibe el mensaje enviado por el inventario y lo muestra en consola.
    *
    * @param mensaje Texto que describe la alerta, usualmente indicando qué
    * producto está por agotarse.
    *
    * Este método sobrescribe la función virtual definida en `Observador` y se
    * ejecuta automáticamente cuando el sujeto invoca `notificar()`.
    */
    void actualizar(const std::string& mensaje) override {
        std::cout << "⚠ ALERTA: " << mensaje << std::endl;
    }
};
