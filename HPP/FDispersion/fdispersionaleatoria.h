#include "fdispersionbase.h"

class fdispersionaleatoria : public fdispersionbase{
public:
fdispersionaleatoria(int tam);
int operator()( const DNI& key);
};
