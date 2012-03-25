/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include						"export.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//	MSGBOX.CPP					(c)	YoY'02						WEB: www.aestesis.org
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include						<windows.h>
#include						<stdio.h>
#include						"msgbox.h"
#include						"window.h"
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL ACI						Amsgbox::CI=ACI("Amsgbox", GUID(0xAE57E515,0x00002010), &Anode::CI, 0, NULL); // countof(properties), properties);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL Amsgbox::Amsgbox(char *name, Aobject *onotify, char *title, char *text, int type, int icon) : Anode(name, NULL)
{
	HWND	hw=onotify->getWindow()->hw;
	int		tp=MB_TOPMOST|MB_APPLMODAL;
	toNotify=onotify;

	switch(type)
	{
		case MBABORTRETRYIGNORE:
		tp|=MB_ABORTRETRYIGNORE;
		break;
		case MBCANCELTRYCONTINUE:
		tp|=MB_CANCELTRYCONTINUE;
		break;
		case MBOK:
		tp|=MB_OK;
		break;
		case MBOKCANCEL:
		tp|=MB_OKCANCEL;
		break;
		case MBRETRYCANCEL:
		tp|=MB_RETRYCANCEL;
		break;
		case MBYESNO:
		tp|=MB_YESNO;
		break;
		case MBYESNOCANCEL:
		tp|=MB_YESNOCANCEL;
		break;
	}

	switch(icon)
	{
		case MBICONEXCLAMATION:
		tp|=MB_ICONEXCLAMATION;
		break;
		case MBICONWARNING:
		tp|=MB_ICONWARNING;
		break;
		case MBICONINFORMATION:
		tp|=MB_ICONINFORMATION;
		break;
		case MBICONASTERISK:
		tp|=MB_ICONASTERISK;
		break;
		case MBICONQUESTION:
		tp|=MB_ICONQUESTION;
		break;
		case MBICONSTOP:
		tp|=MB_ICONSTOP;
		break;
		case MBICONERROR:
		tp|=MB_ICONERROR;
		break;
		case MBICONHAND:
		tp|=MB_ICONHAND;
		break;
	}

	switch(MessageBox(hw, text, title, tp))
	{
		case IDABORT:
		rvalue=MBRABORT;
		break;
		case IDCANCEL:
		rvalue=MBRCANCEL;
		break;
		case IDCONTINUE:
		rvalue=MBRCONTINUE;
		break;
		case IDIGNORE:
		rvalue=MBRIGNORE;
		break;
		case IDNO:
		rvalue=MBRNO;
		break;
		case IDOK:
		rvalue=MBROK;
		break;
		case IDRETRY:
		rvalue=MBRRETRY;
		break;
		case IDTRYAGAIN:
		rvalue=MBRTRYAGAIN;
		break;
		case IDYES:
		rvalue=MBRYES;
		break;
		default:
		rvalue=MBRERROR;
		break;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL Amsgbox::~Amsgbox()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL int Amsgbox::getValue()
{
	return rvalue;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

ADLL int Amsgbox::msgbox(Aobject *object, char *title, char *text, int type, int icon)
{
	int		v;
	Amsgbox	*mb=new Amsgbox("msgbox", object, title, text, type, icon);
	v=mb->getValue();
	delete(mb);
	return v;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////