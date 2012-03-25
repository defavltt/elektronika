/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	trans-slice.H				(c)	YoY'01						WEB: www.aestesis.org
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef							_TRANSSLICE_H_
#define							_TRANSSLICE_H_
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include						<elektro.h>
#include						"../elektro/elektro.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define							guidTRANSSLICE					(Atransslice::CI.guid)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Atransslice : public Atransition
{
	AOBJ

								Atransslice						(QIID qiid, char *name, Aobject *father, int x, int y);
	virtual						~Atransslice					();

	virtual bool				notify							(Anode *o, int event, dword p);
	virtual void				paint							(Abitmap *b);
	virtual bool				mouse							(int x, int y, int state, int event);

	virtual bool				load							(class Afile *f);
	virtual bool				save							(class Afile *f);

	virtual bool				action							(Abitmap *out, Abitmap *in0, Abitmap *in1, float cross, int src, float power, Abitmap *in[8]);
	virtual void				settings						(bool emergency);
	
	virtual void				change							();

	Asection					section;
	Abitmap						*bmp[16];
	bool						bChange;
	Alist						*list;
	Aitem						*items;
	ActrlButton					*flipx;
	ActrlButton					*flipy;
	class Asnap					*snap;
	int							nwipe;
	Abitmap						*wipe;
	Abitmap						*sources;
	Abitmap						*transform;
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class AtranssliceInfo : public AtransitionInfo
{
	AOBJ 

								AtranssliceInfo					(char *name, ACI *eci, char *ename, char *ehelp);

	virtual Atransition *		create							(QIID qiid, char *name, Aobject *father, int x, int y);
};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

__inline AtranssliceInfo::AtranssliceInfo(char *name, ACI *eci, char *ename, char *ehelp) : AtransitionInfo(name, eci, ename, ehelp)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Aplugz *					transsliceGetInfo				();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif							//_TRANSSLICE_H
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////