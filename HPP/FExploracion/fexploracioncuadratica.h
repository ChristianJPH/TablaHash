#pragma once

#include "fexploracionbase.h"

class fexploracioncuadratica : public fexploracionbase{
public:
fexploracioncuadratica(int tam);
int operator()( const DNI& key,int i);
};
