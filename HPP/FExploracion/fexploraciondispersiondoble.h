#include "fexploracionbase.h"
#include "fdispersionbase.h"

#include "fdispersionsuma.h"
#include "fdispersionmodulo.h"
#include "fdispersionaleatoria.h"

class fexploraciondispersiondoble : public fexploracionbase{
private:
fdispersionbase* fdispersion;
public:
fexploraciondispersiondoble(char* fdispersio,int tam);
int operator()( const DNI& key,int i);

};
