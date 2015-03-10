//Make conditional #including of MHObject possible
#ifndef MHOBJECT
#define MHOBJECT
#else
#warning "MHOBJECT already defined elsewhere, so conditional #including of Lightning/MHObject.h is impossible"
#endif

//MHObject -- The base class (or struct, I guess) of every Lightning object
typedef struct _MHObject{
	//A conditionally-set tag, so it's easy to keep track of what's what
	int tag;
}MHObject;

//MARK: - Function Declarations

//MHObject designated initializer -- Returns a pointer to a new MHObject
MHObject *newObject();

//MARK: - Function Definitions

MHObject *newObject(){
	MHObject new;
	new.tag = 0;
	return &new;
}
