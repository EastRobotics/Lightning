//Make conditional #including of Lightning easily possible
#ifndef LIGHTNING
#define LIGHTNING
#else
#warning "LIGHTNING already defined elsewhere, so conditional #including of the Lightning/Lightning.h is impossible"
#endif

//Conditionally #include MHObject
#ifndef MHOBJECT
#include "MHObject.h"
#endif
