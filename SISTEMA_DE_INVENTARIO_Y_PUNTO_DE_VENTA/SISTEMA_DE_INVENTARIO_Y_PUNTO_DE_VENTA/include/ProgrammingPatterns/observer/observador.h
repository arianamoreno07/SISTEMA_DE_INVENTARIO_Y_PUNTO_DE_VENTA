#pragma once
#include "Prerequisites.h"
#include <string>

/**
 * @file Observador.h
 * @brief Interfaz base del patrón Observer.
 *
 * Esta clase define la interfaz que deben implementar todos los observadores
 * dentro del patrón de diseño **Observer**. Un observador se suscribe a un
 * sujeto para recibir notificaciones cuando ocurre un evento relevante.
 */

 /**
  * @class Observador
  * @brief Interfaz abstracta para objetos que reciben notificaciones.
  *
  * Las clases que hereden de esta interfaz deben implementar el método
  * `actualizar()`, el cual será llamado por el sujeto cuando necesite comunicar
  * un cambio o un evento. El mensaje es definido por el sujeto.
  */
class 
Observador {
public:

    /**
     * @brief Método que recibe un mensaje enviado por el sujeto.
     *
     * @param mensaje Texto informativo sobre el evento ocurrido.
     *
     * Este método debe ser implementado por todos los observadores concretos.
     * El sujeto lo invoca automáticamente cuando desea notificar cambios.
     */
    virtual void actualizar(const std::string& mensaje) = 0;
};
