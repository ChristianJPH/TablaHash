#pragma once

#include "fexploracionbase.h"

class fexploracionlineal : public fexploracionbase{
public:
fexploracionlineal(int tam);
int operator()( const DNI& key,int i);
};
