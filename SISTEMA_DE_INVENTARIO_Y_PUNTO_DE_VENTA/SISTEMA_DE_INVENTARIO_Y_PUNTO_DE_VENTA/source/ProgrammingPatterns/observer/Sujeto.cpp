
#include "ProgrammingPatterns/observer/Sujeto.h"

void Sujeto::agregarObservador(Observador* obs) {
	observadores.push_back(obs);

}

void Sujeto::notificar(const std::string& mensaje) {
	for (auto& obs : observadores) {
		obs->actualizar(mensaje);
	}
}
