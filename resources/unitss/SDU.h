#include <math.h>
#include <fstream.h>
#include <Dialogs.hpp>

class TSDU
{
    enum {VARNUM=8};
    enum {varsLength=40};
    enum {_t,_x,_y,_z,_v,_teta,_psi,_pi};
    typedef double(TSDU::*fptr_d_v)(void);


    //������� ������� ��� ���������
    double xf();
    double yf();
    double zf();
    double vf();
    double tetaf();
    double psif();
    double pif();
    fptr_d_v funs[VARNUM];

    //������� ��� ������� ���������� ������� ��� ���������
    double tauf(double y);
    double Cxf(double vrtau);
    void calcconst();
    void setcoef();
    double Hf(double y);
    double mxwxf(double M);
    double K1f(double tetao, double vo, double c);
    void forderivacija();
    double derivacijaf();

    
    
    //������� ��� ��������� �������
    double vtauar[39],Cxm[39],mx_wx[19][2],h_y[320],k1mas[12][12][11],vomas[12],cmas[11];


    //������� ��� ������� �������
	void RK4();

    //���������� �������
	double *t,*x,*y,*z,*v,*teta,*psi,*pi;
	double var1[VARNUM], var2[VARNUM];

    //��������� ������ ������� �������
	double k[4][VARNUM];

    //������������� ����������
	double integral,atau,Mtau,K,c;
    double ysum,ysr,Mtausum,Mtausr,dtetaprev,
           vsum,vsr;
    int ii;
    double tauy,vr,cos_gamma,ax,ap,gg,gom,Fxk,Fyk,Fzk,r;
    double mo,W2,A3,aa0;


	public:

	TSDU();
	//������ ��� ��� ���������� � �����
	double mdal[13],mtet[13],mtetk[4],mkform[4];	    

    //������� ��� ������� �������
	void solve();
    void solved();
    
    AnsiString aerdin();

    
    //���������
    double K1,K2,Cx,vrtau,tn,tauaN,I1N,wo,Yrmax,go,Wx,Wz,R,dtau,Tz,i,d,qo,dq,tauoN,L,A,eta,k5,Bsh,ag,Omegaz,Rz;
	double Kv;
    double Ka;
    ofstream file;
    AnsiString header[varsLength];
    double vars[varsLength];


    
    //��������� �������� ����������
	double x0,y0,z0,v0,teta0,psi0,pi0;

    //�������� �������� ����������
	double te,xe,ye,ze,ve,tetae,psie,pie;
    double Zd;



    //��������� ������ �������
	double dt,dt1,dt2,ymin,y2;
};


class TSDUSolver
{
    TSDU SLV;
    void setdefault();
    //������� ������� ������������ �����
    void findi();

    public:

    string faer;
    void calculate(bool autoFindCoefFormy);
    double deltat1,deltat2,tn,tauaN,I1N,Kvrs,Xtn,teta0n,x0,y0,z0,D,v0,teta0,d,i,qo,tauoN,go,R,ltz,lq,PoN,dP,dtau,Wx,Wz,dvo,Tz,dq,dteta,eta,L,A,rteta0,rv0,rc,rw,rz,Bsh,ag,Omegaz,Rz;
    double K1,K2,Mtau,Yrmax,wo,Yrm,Ptys,Xt,Yt,Zt,tetac,vc,tc,dXtys,Zd,dXw,dXh,dXt,dXtz,dXvo,dXvo1proc,dXq,dZw,dXvr,dZvr,dXtzr,Xr,Zr,dXc,Vv,Vd,Vb,Vdteta0,Vdv0,Vdc;
    AnsiString Cx,vrtau;
};

