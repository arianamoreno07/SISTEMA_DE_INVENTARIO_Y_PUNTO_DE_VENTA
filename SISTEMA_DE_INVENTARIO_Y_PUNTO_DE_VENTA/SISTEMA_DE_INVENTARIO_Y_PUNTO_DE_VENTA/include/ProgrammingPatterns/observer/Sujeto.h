#pragma once
#include "Prerequisites.h"
#include "ProgrammingPatterns/observer/observador.h"
class 
ObservadorStock;

class 
Sujeto {

public: 
	void agregarObservador(Observador* obs);
	void notificar(const std::string& mensaje);

protected:
	std::vector<Observador*> observadores;
}; 