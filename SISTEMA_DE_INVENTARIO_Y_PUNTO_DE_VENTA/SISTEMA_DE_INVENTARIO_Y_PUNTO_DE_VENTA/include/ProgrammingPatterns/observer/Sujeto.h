#pragma once
/**
 * @file Sujeto.h
 * @brief Clase base del patrón Observer encargada de gestionar y notificar observadores.
 *
 * La clase `Sujeto` mantiene una lista de objetos `Observador` y proporciona los
 * métodos necesarios para registrar observadores y enviarles notificaciones cuando
 * ocurre un evento relevante.
 *
 * Este componente forma parte del **patrón de diseño Observer**, el cual promueve
 * un acoplamiento débil entre los objetos que generan eventos (sujetos) y los que
 * reaccionan a ellos (observadores).
 *
 * @date 2025-11-07
 * @version 1.0
 * @author Ari
 */
#include "Prerequisites.h"
#include "ProgrammingPatterns/observer/observador.h"
class 
ObservadorStock;

/**
 * @class Sujeto
 * @brief Clase base que gestiona una lista de observadores y las notificaciones hacia ellos.
 *
 * La clase `Sujeto` permite a los observadores suscribirse mediante el método
 * `agregarObservador()` y envía mensajes a todos los observadores registrados
 * mediante el método `notificar()`.
 */
class 
Sujeto {

public: 
    /**
    * @brief Agrega un observador a la lista de observadores registrados.
    *
    * @param obs Puntero al objeto `Observador` que desea recibir notificaciones.
    *
    * El observador permanecerá en la lista hasta que el sujeto sea destruido
    * o el observador sea eliminado manualmente (en una versión extendida del sistema).
    */
	void 
    agregarObservador(Observador* obs);
    /**
   * @brief Notifica a todos los observadores registrados enviándoles un mensaje.
   *
   * @param mensaje Texto descriptivo del evento ocurrido.
   *
   * Este método recorre la lista de observadores y llama al método `actualizar()`
   * de cada uno, permitiendo que reaccionen al evento según su implementación concreta.
   */
	void 
    notificar(const std::string& mensaje);

protected:
    /**
     * @brief Lista de observadores suscritos al sujeto.
     *
     * Cada elemento es un puntero a un objeto que implementa la interfaz `Observador`.
     */
	std::vector<Observador*> observadores;
}; 