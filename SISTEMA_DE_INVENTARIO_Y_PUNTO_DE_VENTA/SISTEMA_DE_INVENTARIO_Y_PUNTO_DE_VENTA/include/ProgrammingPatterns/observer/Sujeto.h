#pragma once
#include "Prerequisites.h"
#include <string>
#include "ProgrammingPatterns/observer/observador.h"


/**
 * @file Sujeto.h
 * @brief Interfaz del Sujeto para el patrón Observer.
 *
 * Esta clase define la interfaz que deben implementar todos los objetos
 * capaces de notificar a observadores cuando ocurre un evento relevante.
 * Forma parte del patrón de diseño **Observer**, donde un "Sujeto" mantiene
 * una lista de observadores y los notifica de cambios.
 */

 /**
  * @class Sujeto
  * @brief Interfaz abstracta para objetos observables.
  *
  * Las clases que hereden de esta interfaz deben proporcionar mecanismos
  * para registrar, eliminar y notificar observadores. Esto permite
  * establecer un sistema de suscripción donde los observadores reaccionan
  * automáticamente a cambios del sujeto.
  */
class 
Sujeto {

public:
    /**
   * @brief Registra un nuevo observador.
   *
   * @param obs Puntero al observador que desea recibir notificaciones.
   *
   * Agrega el observador a la lista interna del sujeto. Cada vez que ocurra
   * un evento, el observador será notificado mediante su método `actualizar()`.
   */
    virtual void agregarObservador(Observador* obs) = 0;

    /**
    * @brief Elimina un observador previamente registrado.
    *
    * @param obs Observador que ya no desea recibir notificaciones.
    *
    * Si el observador estaba registrado, se elimina de la lista y deja
    * de recibir eventos generados por el sujeto.
    */
    virtual void eliminarObservador(Observador* obs) = 0;

    /**
    * @brief Notifica a todos los observadores registrados.
    *
    * @param mensaje Texto descriptivo del evento ocurrido.
    *
    * Recorre la lista de observadores y llama su método `actualizar()` con el
    * mensaje correspondiente, permitiendo que reaccionen al cambio.
    */
    virtual void notificar(const std::string& mensaje) = 0;
};
