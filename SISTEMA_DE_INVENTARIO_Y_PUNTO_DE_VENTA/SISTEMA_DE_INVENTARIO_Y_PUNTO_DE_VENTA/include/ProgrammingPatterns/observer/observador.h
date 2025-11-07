#pragma once
/**
 * @file Observador.h
 * @brief Interfaz base del patrón Observer para recibir notificaciones del sujeto.
 *
 * La clase `Observador` define la interfaz abstracta que deben implementar
 * todas las clases que deseen recibir notificaciones desde un objeto `Sujeto`.
 *
 * Forma parte del **patrón de diseño Observer**, donde los observadores se
 * registran en un sujeto para ser notificados cuando ocurre un evento relevante.
 *
 * @date 2025-11-07
 * @version 1.0
 * @author Ari
 */
#include "Prerequisites.h"

 /**
  * @class Observador
  * @brief Clase abstracta que define la interfaz del observador.
  *
  * Esta clase sirve como base para todas las clases concretas que desean
  * recibir notificaciones. Cada clase hija debe implementar el método `actualizar()`
  * para definir su comportamiento específico ante los cambios del sujeto.
  */
class
Observador {

public: 
    /**
   * @brief Método virtual puro que se ejecuta cuando el sujeto notifica un evento.
   *
   * @param mensaje Texto descriptivo del evento notificado (por ejemplo, "Stock bajo de Paracetamol").
   *
   * Las clases derivadas deben implementar este método para definir qué hacer
   * cuando reciben una notificación.
   */
	virtual void 
    actualizar(const std::string& mensaje) = 0;
    /**
     * @brief Destructor virtual por defecto.
     *
     * Garantiza la destrucción adecuada de objetos derivados al eliminar
     * punteros del tipo base `Observador`.
     */
	virtual ~Observador() = default;


};