/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include						"export.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	RESOURCE.CPP				(c)	YoY'99						WEB: search aestesis
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include						<assert.h>
#include						<stdio.h>
#include						"resource.h"
#include						"resources.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL ACI						Aresobj::CI=ACI("Aresobj", GUID(0xAE57E515,0x00000210), &Anode::CI, 0, NULL);

ADLL ACI						Aresource::CI=ACI("Aresource", GUID(0xAE57E515,0x00000200), &Anode::CI, 0, NULL);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL Aresobj::Aresobj(Aresource *r, char *name, char *type) : Anode("Aresobj")
{
	this->r=r;
    h=FindResource(r->hinstance, name, type);
    this->type=type;
	nlock=0;
	ptr=NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL Aresobj::~Aresobj()
{
	while(nlock)
		unlock();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL int Aresobj::getSize()
{
	return SizeofResource(r->hinstance, h);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL void * Aresobj::lock()
{
	if(!nlock)
	{
		ptr=(void *)LockResource(LoadResource(r->hinstance, h));
		if(ptr)
			nlock++;
		return ptr;
	}
	else
	{
		nlock++;
		return ptr;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL void Aresobj::unlock()
{
	if(nlock)
		nlock--;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL Aresource::Aresource() : Anode("main default resource")	// 4test
{
	hinstance=GetModuleHandle(NULL);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL Aresource::Aresource(char *name, HINSTANCE h) : Anode(name)
{
	assert(h);
	hinstance=h;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL Aresource::~Aresource()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL Aresobj Aresource::get(char *name, char *type)
{
	return Aresobj(this, name, type);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL Aresobj * Aresource::getObj(char *name, char *type)
{
	return new Aresobj(this, name, type);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////