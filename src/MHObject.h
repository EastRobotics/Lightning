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
//Setter for tag property
void setTagOfObject(MHObject *object, int newValue);
//Getter for tag property
int getTagOfObject(MHObject *object);

//MARK: - Private Function Declarations

void autoInitializeObject(MHObject *object);

//MARK: - Function Definitions

MHObject *newObject(){
	static int tag = 0;
	MHObject new;
	new.tag = tag;
	tag++;
	return &new;
}

//MARK: - Property Setters

void setTagOfObject(MHObject *object, int newValue){
	autoInitializeObject(object);
	object->tag = newValue;
}

//MARK: - Property Getters

int getTagOfObject(MHObject *object){
	autoInitializeObject(object);
	return object->tag;
}

//MARK: - Hopefully Private Functions

void autoInitializeObject(MHObject *object){
	//If it's NULL, we'll initialize it. Otherwise, we'll just let it be
	if(!object){
		object = newObject();
	}
}
