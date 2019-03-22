#include "Palavra.h"

Palavra::Palavra() {
}

Palavra::Palavra(std::string valor) {
	this->valor = valor;
}

void Palavra::setValor(std::string valor) {
	this->valor = valor;
}

std::string Palavra::getValor() const {
	return this->valor;
}

bool Palavra::semelhante(Palavra palavra) {
	return this->valor.substr(0, 2) == palavra.getValor().substr(0, 2);
}

bool Palavra::operator==(const Palavra &palavra) const {
	return this->valor == palavra.getValor();
}

bool Palavra::operator<(const Palavra &palavra) const {
	return this->getValor() < palavra.getValor();
}
