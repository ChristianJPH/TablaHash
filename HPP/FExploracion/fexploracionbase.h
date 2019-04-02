#pragma once
#include "DNI.hpp"

class fexploracionbase{
protected:
int tam;
public:
fexploracionbase(int tam_);
virtual int operator()( const DNI& key,int i)=0;
};
