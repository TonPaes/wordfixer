#ifndef ERRADA_H
#define ERRADA_H

#include "Palavra.h"

#include <map>

class PalavrasErradas
{
public:
	void incrementarErro(Palavra palavra);

private:
	std::map<Palavra, int> erroPalavra;
};

#endif