
/**
 * @file Sujeto.cpp
 * @brief Implementación de la clase Sujeto del patrón Observer.
 *
 * Esta clase mantiene una lista de observadores registrados y se encarga de
 * notificarles los eventos relevantes (por ejemplo, cuando el inventario detecta
 * bajo stock en un producto).
 *
 * Forma parte del patrón de diseño **Observer**, actuando como el "Sujeto" que
 * emite notificaciones a los "Observadores".
 *
 * @date 2025-11-07
 * @version 1.0
 * @author Ari
 */
#include "ProgrammingPatterns/observer/Sujeto.h"


 /**
  * @brief Registra un nuevo observador en la lista.
  *
  * Este método permite que un observador se suscriba a las notificaciones
  * del sujeto. Los observadores deben implementar la interfaz `Observador`.
  *
  * @param obs Puntero al objeto observador que desea suscribirse.
  */
void Sujeto::agregarObservador(Observador* obs) {
	observadores.push_back(obs);

}


/**
 * @brief Notifica a todos los observadores registrados.
 *
 * Recorre la lista de observadores y ejecuta el método `actualizar()` de cada uno,
 * enviándoles el mensaje recibido como parámetro.
 *
 * @param mensaje Cadena de texto con la información del evento (por ejemplo, “Stock bajo de Paracetamol”).
 */
void 
Sujeto::notificar(const std::string& mensaje) {
	for (auto& obs : observadores) {
		obs->actualizar(mensaje);
	}
}
