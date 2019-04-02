#pragma once
#include "fdispersionbase.h"
class fdispersionsuma: public fdispersionbase{
public:
fdispersionsuma(int tam);
virtual int operator()( const DNI& key);
};
