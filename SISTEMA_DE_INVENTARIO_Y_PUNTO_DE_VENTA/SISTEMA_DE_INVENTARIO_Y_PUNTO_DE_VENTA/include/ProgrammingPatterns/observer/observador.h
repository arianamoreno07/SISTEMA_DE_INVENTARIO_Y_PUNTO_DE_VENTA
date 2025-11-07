#pragma once
#include "Prerequisites.h"

class
Observador {

public: 
	virtual void actualizar(const std::string& mensaje) = 0;
	virtual ~Observador() = default;


};