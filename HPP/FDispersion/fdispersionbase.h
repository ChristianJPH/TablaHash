#pragma once
#include "DNI.hpp"

class fdispersionbase{
protected:
int tam;
public:
fdispersionbase(int tam_);
virtual int operator()(const DNI& key) =0;
};
