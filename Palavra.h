#ifndef PALAVRA_H
#define PALAVRA_H

#include <string>

class Palavra {
public:
	Palavra();
	Palavra(std::string valor);

	void setValor(std::string valor);
	std::string getValor() const;

	bool semelhante(const Palavra palavra);
	bool operator ==(const Palavra &palavra) const;
	bool operator <(const Palavra &palavra) const;
private:
	std::string valor;
};

#endif