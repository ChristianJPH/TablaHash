#pragma once
#include "fdispersionbase.h"

class fdispersionmodulo : public fdispersionbase{
public:
fdispersionmodulo(int tam);
int  operator()( const DNI& key);
};
