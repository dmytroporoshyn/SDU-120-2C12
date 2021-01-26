#include <math.h>
#include <system.hpp>
#include <sysutils.hpp>

double okr(double x,double e)
{
    double powten=pow(10,e);
    double x1=x*powten;
    double floorv=floor(x1);
    double ceilv=ceil(x1);
    double ld,hd;
    if(x>=0)
    {
     	ld=x1-floorv;
     	hd=ceilv-x1;
     	return ((ld<hd)?floorv:ceilv)/powten;
    }
    else
    {
    	hd=x1-floorv;
		ld=ceilv-x1;
		return ((ld<hd)?ceilv:floorv)/powten;
	}
}

double okr(double x)
{
	if(abs(x)>10)
	return okr(x,0);
	else
	return okr(x,1);
}

char* point2comma(char* str)
{
    for(int i=0;str[i]!=0;++i)
    if(str[i]==46)str[i]=44;
    return str;
}

char* comma2point(char* str)
{
    for(int i=0;str[i]!=0;++i)
    if(str[i]==44)str[i]=46;
    return str;
}

/*double deg2rad_(AnsiString angle)
{
    AnsiString degStr;
    int i=0;
    for(;i<angle.Length()&&angle[i]!=',';i++)
    degStr+=angle[i];

}*/

double deg2rad_(double deg)
{
    double grad,min,sec;
    if(deg>0)
    {
        grad=floor(deg);
		deg=(deg-grad)*100;
		min=floor(deg);
		deg=okr((deg-min)*100,0);
		sec=floor(deg);
    }
	else
    {
        grad=ceil(deg);
		deg=(deg-grad)*100;
		min=ceil(deg);
		deg=okr((deg-min)*100,0);
		sec=ceil(deg);
    }
    return (grad+min/60+sec/3600)*M_PI/180;
}

AnsiString deg2radstr(AnsiString str)
{
    return FloatToStr(deg2rad_(StrToFloat(str)));
}

double rad2deg_(double rad)
{
	double deg,grad,min,sec;
    deg=rad*180/M_PI;

    if(deg>0)
    {
        grad=floor(deg);
		min=floor((deg-grad)*60);
		sec=okr(((deg-grad)-min/60)*3600,0);
    }
	else
    {
        grad=ceil(deg);
		min=ceil((deg-grad)*60);
		sec=okr(((deg-grad)-min/60)*3600,0);
    }
    min+=int(sec)/60;
    sec=int(sec)%60;
    grad+=int(min)/60;
    min=int(min)%60;
    return okr(grad+min/100+sec/10000,4);
}

AnsiString rad2degstr(AnsiString str)
{
    return FloatToStr(rad2deg_(StrToFloat(str)));
}

double delugl2rad_(double delugl)
{
    return (delugl*100)*M_PI/3000;
}

AnsiString delugl2radstr(AnsiString str)
{
    return FloatToStr(delugl2rad_(StrToFloat(str)));
}

AnsiString delugl2degstr(AnsiString str)
{
    return FloatToStr(rad2deg_(delugl2rad_(StrToFloat(str))));
}

double rad2delugl_(double rad)
{
    return  okr((rad*3000/M_PI)/100,2);
}