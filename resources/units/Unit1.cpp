//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#include <fstream.h>
#include <string.h>
#include <iostream>        //������ ��� ���� � �������
#include <ctime>           //������ ��� ���� � �������
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include "SDU.cpp"
#include "mymath.cpp"
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;     //������ ��� ���� � �������

TForm1 *Form1;
//enum vars_{_x=1,_y,_z,_v,_psi1,_psi2,_x1,_x2,_alpha1,_alpha2,_r,_pi,_deltaz,OUTTABL3COLNUM};  //�������� �����
enum indata1{_D,_tetao,_i, _Y, INTABL1COLNUM};
enum indata2{_Xn,_Yn,_Zn,_Xtn,_teta0n,_Kvr,_vo,_dP,_dtau,_Wx,_Wz,_Tz,_dq,_dvo,_d,_qo,_tn,_tauaN,_I1N,_w0,_K1,_K2,_tauoN,_go,_R,_ltz,_lq,_PoN,_dteta,_eta,_L,_A,_rteta0,_rv0,_rc,_rw,_rz,_Bsh,_ag,_Omegaz,_Rz,_dt1, _dt2, _dovorot, _yrr, INTABL2ROWNUM};
//enum outdata_{Xt_,Zt_,dXtys_,Zd_,dXw_,dXh_,dXt_,dXtz_,dXvo_,dXq_,dZw_,dXtzr_,Xr_,Zr_};
enum outdata1{_Xt,_Yt,_Zt,_tetac,_vc,_tc,_N,_tr,_vr,_tetar,OUTTABL1COLNUM};
enum outdata2{_teta0,_Xt4,_Pri,_dXtys,_Zd,_dXw,_dXc,_dXh,_dXt,_dXtz,_dXvo,_dXq,_dZw,_dXvr,_dZvr,_Xr,_Yrm,_Zr,_Vdteta0,_Vdv0,_Vdc,_Vd,_Vv,_Vb,_Ybul,OUTTABL2COLNUM};
AnsiString invarname1[INTABL1COLNUM],invarname2[INTABL2ROWNUM],
		   outvarname1[OUTTABL1COLNUM],outvarname2[OUTTABL2COLNUM]/*,outvarname3[OUTTABL3COLNUM]*/;

double vd_opitnie[2][28]={1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000,21000,22000,23000,24000,25000,26000,27000,28000,
43,40,37,35,33,32,31,31,31,32,33,35,37,40,43,46,49,53,56,60,63,67,71,75,80,86,92,100};

double vv_opitnie[2][28]={1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000,21000,22000,23000,24000,25000,26000,27000,28000,
0.3,0.5,0.8,1.1,1.4,1.7,2.2,2.7,3.4,4.3,5.5,7,9.1,12,15,19,24,30,37,45,54,64,77,91,109,132,161,207};

double vb_opitnie[2][28]={1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000,21000,22000,23000,24000,25000,26000,27000,28000,
0.3,0.5,0.8,1,1.3,1.6,1.9,2.1,2.4,2.7,3,3.3,3.6,4,4.3,4.7,5.2,5.7,6.3,6.9,7.6,8.3,9.2,10,11,12,14,15};
//double indata_[INDATA1NUM];
//double outdata_[OUTDATANUM];
/*double invartabl1[INTABL1ROWNUM]={0};
double invartabl2[INTABL2ROWNUM]={0};
double outvartabl1[OUTTABL1COLNUM]={0};
double outvartabl2[OUTTABL2COLNUM]={0};*/

AnsiString temps;

double round(double d)
{
  return floor(d + 0.5);
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void readindata(const char* fname)
{
    ifstream file(fname);
    char str[100];


        file>>str;
        if(strcmp(str,"none")!=0)
        Form1->Edit2->Text=str;


        file>>str;
        if(strcmp(str,"none")!=0)
        Form1->Edit3->Text=str;

        file>>str;
        if(strcmp(str,"none")!=0)
        Form1->Edit4->Text=str;

    int RC;
    file>>RC;
    //ShowMessage(RC);


    Form1->StringGrid1->RowCount=RC+1;
    for(int i=0;i<Form1->StringGrid1->RowCount-1;++i)
    for(int j=0;j<INTABL1COLNUM;++j)
    {
        file>>str;
        if(strcmp(str,"none")!=0)
        Form1->StringGrid1->Cells[j][i+1]=str;
        else
        Form1->StringGrid1->Cells[j][i+1]="";
    }
    for(int i=0;i<INTABL2ROWNUM;++i)
    {
        file>>str;
        if(strcmp(str,"none")!=0)
        Form1->StringGrid2->Cells[2][i]=str;
        else
        Form1->StringGrid2->Cells[2][i]="";
    }
    file.close();
}

void saveindata(const char* fname)
{
    ofstream file(fname);

    file<<Form1->Edit2->Text.c_str()<<endl;
    file<<Form1->Edit3->Text.c_str()<<endl;
    file<<Form1->Edit4->Text.c_str()<<endl;
    file<<Form1->StringGrid1->RowCount-1<<"\t";
    for(int i=0;i<Form1->StringGrid1->RowCount-1;++i)
    for(int j=0;j<INTABL1COLNUM;++j)
    {
        if(Form1->StringGrid1->Cells[j][i+1]=="")
        file<<"none"<<endl;
        else
        file<<Form1->StringGrid1->Cells[j][i+1].c_str()<<endl;
    }
    for(int i=0;i<INTABL2ROWNUM;++i)
    {
        if(Form1->StringGrid2->Cells[2][i]=="")
        file<<"none"<<endl;
        else
        file<<Form1->StringGrid2->Cells[2][i].c_str()<<endl;
    }
    file.close();
}

void __fastcall TForm1::FormCreate(TObject *Sender)
{

    invarname1[_D]="�, �";
    invarname1[_tetao]="TETAo, ����,����";
    invarname1[_i]="i";
    invarname1[_Y]="Y, ���";

    invarname2[_Xn]="Xo, �";
    invarname2[_Yn]="Yo, �";
    invarname2[_Zn]="Zo, �";
    invarname2[_Xtn]="Xt, �";
    invarname2[_teta0n]="teta0, ����";
    invarname2[_Kvr]="���";
    invarname2[_vo]="Vo, �/�";
    invarname2[_dP]="dP, ��.��.��.";
    invarname2[_dtau]="dtau, ����.";
    invarname2[_Wx]="Wx, �/�";
    invarname2[_Wz]="Wz, �/�";
    invarname2[_Tz]="T�, ����.";
    invarname2[_dq]="dq, 1�/��";
    invarname2[_dvo]="dV�, %Vo";
    invarname2[_d]="d, �";
    invarname2[_qo]="qo, ��";
    invarname2[_tn]="t0, c";
    invarname2[_tauaN]="tauaN, c";
    invarname2[_I1N]="I1N";
    invarname2[_w0]="w0";
    invarname2[_K1]="K1";
    invarname2[_K2]="K2";
    invarname2[_tauoN]="tau_ON, �";
    invarname2[_go]="go, �/�2";
    invarname2[_R]="R, �/����";
    invarname2[_ltz]="l��";
    invarname2[_lq]="lq";
    invarname2[_PoN]="Pon, ��.��.��";
    invarname2[_dteta]="dteta, ���";
    invarname2[_eta]="eta";
    invarname2[_L]="L";
    invarname2[_A]="A";
    invarname2[_rteta0]="rteta0, ���";
    invarname2[_rv0]="rv0, %";
    invarname2[_rc]="rc, %";
    invarname2[_rw]="rw, ���";
    invarname2[_rz]="rz, ���";
    invarname2[_Bsh]="��, ���.";
    invarname2[_ag]="��, ���.";
    invarname2[_Omegaz]="Omega_�, ���/�";
    invarname2[_Rz]="R�, �";
    invarname2[_dt1]="deltat1";
    invarname2[_dt2]="deltat2";
    invarname2[_dovorot]="dovorot";
    invarname2[_yrr]="������ �������";

    outvarname1[_Xt]="��, �";
    outvarname1[_Yt]="Y�, �";
    outvarname1[_Zt]="Z�, �";
    outvarname1[_tetac]="TETAc, ����";
    outvarname1[_vc]="Vc, �/�";
    outvarname1[_tc]="tc, �";
    outvarname1[_N]="N";
    outvarname1[_tetar]="TETAr";
    outvarname1[_vr]="Vr";
    outvarname1[_tr]="tr";

    //� �������� ������� ����������� �������� X� ���� ����� ���� ���������� ���������� � ������� ��������
    outvarname2[_teta0]="����0, ����,����";
    outvarname2[_Xt4]="��, �";


        outvarname2[_Pri]="�";

    outvarname2[_dXtys]="dX���, �";
    outvarname2[_Zd]="Z, ���";
    outvarname2[_dXw]="dXw, �";
    outvarname2[_dXh]="dX�, �";
    outvarname2[_dXt]="dX�, �";
    outvarname2[_dXtz]="dX��, �";
    outvarname2[_dXvo]="dXvo, �";
    outvarname2[_dXq]="dXq, �";
    outvarname2[_dZw]="dZw, ���";
    outvarname2[_dXvr]="dXvr, �";
    outvarname2[_dZvr]="dZvr, ���";
    outvarname2[_Xr]="��, �";
    outvarname2[_Yrm]="Y�, �";
    outvarname2[_Zr]="Z�, �";
    outvarname2[_dXc]="dXc, �";
    outvarname2[_Vd]="��, �";
    outvarname2[_Vv]="��, �";
    outvarname2[_Vb]="��, �";
    outvarname2[_Vdteta0]="��_����0, �";
    outvarname2[_Vdv0]="��_V0, �";
    outvarname2[_Vdc]="��_�, �"; 
    outvarname2[_Ybul]="YYYYYYYYYY, �";

  /*  outvarname3[_x]="�, �";           //�������� �����
    [_y]="Y, �";
    outvarname3[_zoutvarname3]="Z, �";
    outvarname3[_v]="v, �/�";
    outvarname3[_psi1]="psi1";
    outvarname3[_psi2]="psi2";
    outvarname3[_x1]="x1";
    outvarname3[_x2]="x2";
    outvarname3[_alpha1]="alpha1";
    outvarname3[_alpha2]="alpha2";
    outvarname3[_r]="r";
    outvarname3[_pi]="pi";
    outvarname3[_deltaz]="deltaz";                          */



    
    StringGrid5->Cells[0][0]="�������";
    StringGrid5->Cells[1][0]=6;
    StringGrid5->Cells[2][0]=5;
    StringGrid5->Cells[3][0]=4;
    StringGrid5->Cells[4][0]="3 ���.";
    StringGrid5->Cells[5][0]=2;
    StringGrid5->Cells[6][0]=1;
    StringGrid5->Cells[0][1]="��,�";
    StringGrid5->Cells[0][2]="Z�,�";
    StringGrid5->Cells[0][3]="h�,�";
    StringGrid5->Cells[0][4]="Alpha(���)";
    StringGrid5->Cells[0][5]="�����";

    StringGrid6->Cells[0][0]="� �/�";
    StringGrid6->Cells[1][0]="���������";
    StringGrid6->Cells[2][0]="��������";
    StringGrid6->Cells[0][1]=1;
    StringGrid6->Cells[0][2]=2;
    StringGrid6->Cells[0][3]=3;
    StringGrid6->Cells[0][4]=4;
    StringGrid6->Cells[0][5]=5;
    StringGrid6->Cells[1][1]="H�, ��. ��. ��.";
    StringGrid6->Cells[1][2]="t�, C";
    StringGrid6->Cells[1][3]="Alpha wo, ���. ���.";
    StringGrid6->Cells[1][4]="W�, �/�";
    StringGrid6->Cells[1][5]="h��, �";

    StringGrid7->Cells[0][0]="� �/�";
    StringGrid7->Cells[1][0]="���������";
    StringGrid7->Cells[2][0]="�";
    StringGrid7->Cells[3][0]="�";
    StringGrid7->Cells[4][0]="�";
    StringGrid7->Cells[5][0]="�";
    StringGrid7->Cells[6][0]="�";
    StringGrid7->Cells[7][0]="�";
    StringGrid7->Cells[8][0]="�";
    StringGrid7->Cells[9][0]="�";
    StringGrid7->Cells[0][1]=1;
    StringGrid7->Cells[0][2]=2;
    StringGrid7->Cells[0][3]=3;
    StringGrid7->Cells[0][4]=4;
    StringGrid7->Cells[0][5]=5;
    StringGrid7->Cells[0][6]=6;
    StringGrid7->Cells[0][7]=7;
    StringGrid7->Cells[0][8]=8;
    StringGrid7->Cells[1][1]="X�, �";
    StringGrid7->Cells[1][2]="Y�=Z�, �";
    StringGrid7->Cells[1][3]="h�, �";
    StringGrid7->Cells[1][4]="���, �";
    StringGrid7->Cells[1][5]="Delta��, �";
    StringGrid7->Cells[1][6]="Alpha �, �";
    StringGrid7->Cells[1][7]="delta h�, �";
    StringGrid7->Cells[1][8]="Y���";

    StringGrid8->Cells[0][0]=1;
    StringGrid8->Cells[0][1]=2;
    StringGrid8->Cells[0][2]=3;
    StringGrid8->Cells[1][0]="Ho";
    StringGrid8->Cells[1][1]="-Hno";
    StringGrid8->Cells[1][2]="deltaHo";
    StringGrid8->Cells[3][0]=4;
    StringGrid8->Cells[3][1]=5;
    StringGrid8->Cells[3][2]=6;
    StringGrid8->Cells[4][0]="to";
    StringGrid8->Cells[4][1]="+deltaTv";
    StringGrid8->Cells[4][2]="tauo";
    StringGrid8->Cells[6][0]=7;
    StringGrid8->Cells[6][1]=8;
    StringGrid8->Cells[6][2]=9;
    StringGrid8->Cells[7][0]="tauo";
    StringGrid8->Cells[7][1]="-tauNo";
    StringGrid8->Cells[7][2]="delta tauo��";
    StringGrid8->Cells[9][0]=10;
    StringGrid8->Cells[9][1]=11;
    StringGrid8->Cells[10][0]="Alpha wo";
    StringGrid8->Cells[10][1]="Wo";


    StringGrid9->Cells[0][0]="�";
    StringGrid9->Cells[1][0]=1;
    StringGrid9->Cells[2][0]=2;
    StringGrid9->Cells[3][0]=3;
    StringGrid9->Cells[4][0]=4;
    StringGrid9->Cells[5][0]=5;
    StringGrid9->Cells[6][0]=6;
    StringGrid9->Cells[7][0]=7;
    StringGrid9->Cells[1][1]="Y�(���), �";
    StringGrid9->Cells[2][1]="delta_tau_y, C";
    StringGrid9->Cells[3][1]="delta_alpha_wy, �.�.";
    StringGrid9->Cells[4][1]="alpha_wy, �.�.";
    StringGrid9->Cells[5][1]="Wy, �/�";
    StringGrid9->Cells[6][1]="���������� ��������";
    StringGrid9->Cells[0][2]=12;
    StringGrid9->Cells[0][3]=13;
    StringGrid9->Cells[0][4]=14;
    StringGrid9->Cells[0][5]=15;
    StringGrid9->Cells[0][6]=16;
    StringGrid9->Cells[0][7]=17;
    StringGrid9->Cells[0][8]=18;
    StringGrid9->Cells[0][9]=19;
    StringGrid9->Cells[0][10]=20;
    StringGrid9->Cells[0][11]=21;
    StringGrid9->Cells[1][2]=0;
    StringGrid9->Cells[1][3]=200;
    StringGrid9->Cells[1][4]=400;
    StringGrid9->Cells[1][5]=800;
    StringGrid9->Cells[1][6]=1200;
    StringGrid9->Cells[1][7]=1600;
    StringGrid9->Cells[1][8]=2000;
    StringGrid9->Cells[1][9]=2400;
    StringGrid9->Cells[1][10]=3000;
    StringGrid9->Cells[1][11]=4000;
    StringGrid9->Cells[3][3]="100";
    StringGrid9->Cells[3][4]="200";
    StringGrid9->Cells[3][5]="300";
    StringGrid9->Cells[3][6]="300";
    StringGrid9->Cells[3][7]="400";
    StringGrid9->Cells[3][8]="400";
    StringGrid9->Cells[3][9]="400";
    StringGrid9->Cells[3][10]="500";
    StringGrid9->Cells[3][11]="500";


    StringGrid10->Cells[0][0]="delta Ha";
    StringGrid10->Cells[1][0]="delta tau_y";
    StringGrid10->Cells[2][0]="Wx";
    StringGrid10->Cells[3][0]="Wz";

    StringGrid12->Cells[0][0]="���";
    StringGrid12->Cells[1][0]="D��";
    StringGrid12->Cells[2][0]="Xp";
    StringGrid12->Cells[3][0]="Zp";
    StringGrid12->Cells[4][0]="Pr_tys";
    StringGrid12->Cells[5][0]="Pr_do;";
    StringGrid12->Cells[6][0]="delta_P_h";
    StringGrid12->Cells[7][0]="teta,grad";
    StringGrid12->Cells[8][0]="teta,min";


    StringGrid8->Cells[2][1]=750;
    StringGrid8->Cells[8][1]=15.9;

    StringGrid11->Cells[0][0]="��������";
    StringGrid11->Cells[0][1]="��������";
    StringGrid11->Cells[1][0]="DeltaVo";
    StringGrid11->Cells[2][0]="��";
    StringGrid11->Cells[3][0]="Delta q";
    StringGrid11->Cells[4][0]="Vo, �/�";
    StringGrid11->Cells[5][0]="l��";
    StringGrid11->Cells[6][0]="lq";


    StringGrid11->Cells[1][1]=-0.7;
    StringGrid11->Cells[2][1]=-16;
    StringGrid11->Cells[3][1]=3;

    StringGrid5->Cells[4][1]=37235;
    StringGrid5->Cells[4][2]=94830;
    StringGrid5->Cells[4][3]=180;
    StringGrid5->Cells[4][4]="52,00";
    StringGrid5->Cells[4][5]="�������.";

    StringGrid6->Cells[2][1]=783;
    StringGrid6->Cells[2][2]=-24;
    StringGrid6->Cells[2][3]="1,00";
    StringGrid6->Cells[2][4]=5;
    StringGrid6->Cells[2][5]=200;

    StringGrid7->Cells[2][1]=40150;
    StringGrid7->Cells[2][2]=93200;
    StringGrid7->Cells[2][3]=190;
    StringGrid7->Cells[2][4]=1000;


    

    StringGrid1->ColCount=INTABL1COLNUM;
    for(int i=0;i<StringGrid1->ColCount;++i)
    {
        StringGrid1->Cells[i][0]=invarname1[i];
    }

    StringGrid2->RowCount=INTABL2ROWNUM;
    for(int i=0;i<StringGrid2->RowCount;++i)
    {
        StringGrid2->Cells[0][i]=IntToStr(i+1);
        StringGrid2->Cells[1][i]=invarname2[i];
    }

    StringGrid3->ColCount=OUTTABL1COLNUM;
    for(int i=0;i<StringGrid3->ColCount;++i)
    StringGrid3->Cells[i][0]=outvarname1[i];

    StringGrid4->ColCount=OUTTABL2COLNUM;
    for(int i=0;i<StringGrid4->ColCount;++i)
    StringGrid4->Cells[i][0]=outvarname2[i];

  /*  Form2->StringGrid1->ColCount=OUTTABL3COLNUM;              //�������� �����:�������
    for(int i=0;i<Form2->StringGrid1->ColCount;++i)
    Form2->StringGrid1->Cells[i][0]=outvarname3[i];                */

    //readindata("resources\\indata__.txt");

    OpenDialog1->InitialDir=ExtractFileDir(Application->ExeName);
    SaveDialog1->InitialDir=ExtractFileDir(Application->ExeName);

    Edit1->Text=StringGrid1->RowCount-1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{            //��� ��� ������ ���� ��� ������ �������� �����
   /* char str[50];
    ifstream file("data.txt");
    for(int i=0;i<INDATA1NUM;++i)
    {
        file>>str;
        point2comma(str);
        Form1->StringGrid1->Cells[2][i]=str;
    }
    //StringGrid1->Cells[2][_tetao]=delugl2degstr(StringGrid1->Cells[2][_tetao]);
    file.close();    */
   //Form2->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    if(!Form1->OpenDialog1->Execute())return;
    readindata(Form1->OpenDialog1->FileName.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    if(!Form1->SaveDialog1->Execute())return;
    saveindata(Form1->SaveDialog1->FileName.c_str());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    saveindata("resources\\indata__.txt");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{

    // Insert code
    float Xc,Zc,hc,Xb,Zb,hb,alpha_osi;
    float delta_X,delta_Z,delta_h_c,H,alpha_c,D_c_t,delta_c_t,delta_c_t_shryh,sigma_c,Ho,to,alpha_wo,Wo,hmc,delta_Ho,delta_Hb,Y_byl,delta_Tv,tau0,delta_tau_0mp,delta_tau_y,Wy,Aw,Aw_grad,Wx,Wz;
    float table_1[2][11] =
    {
        { 0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50 },
        { 0.3, 0.5, 0.6, 0.9, 1.3, 1.8, 2.4, 3.3, 4.4, 5.8, 7.4}
    };



    int table_4_col_3[9] = {100, 200, 300, 300, 400, 400, 400, 500, 500};
    int table_4_col_1[10] = {0, 200, 400, 800, 1200, 1600, 2000, 2400, 3000, 4000};
    float table_4[19][15] =
    {                                                 
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50},
        {200, -1, -2, -3, -4, -5, -6, -7, -8, -8, -9, -20, -29, -39, -49},
        {200, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {400, -1, -2, -3, -4, -5, -6, -6, -7, -8, -9, -19, -29, -38, -48},
        {400, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {800, -1, -2, -3, -4, -5, -6, -6, -7, -7, -8, -18, -28, -37, -46},
        {800, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {1200, -1, -2, -3, -4, -4, -5, -5, -6, -7, -8, -17, -26, -35, -44},
        {1200, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {1600, -1, -2, -3, -3, -4, -4, -5, -6, -7, -8, -17, -25, -34, -42},
        {1600, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {2000, -1, -2, -3, -3, -4, -4, -5, -6, -6, -7, -16, -24, -32, -40},
        {2000, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {2400, -1, -2, -2, -3, -4, -4, -5, -5, -6, -7, -15, -23, -31, -38},
        {2400, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {3000, -1, -2, -2, -3, -4, -4, -4, -5, -5, -6, -15, -22, -30, -37},
        {3000, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {4000, -1, -2, -2, -3, -4, -4, -4, -4, -5, -6, -14, -20, -27, -34},
        {4000, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0}
    };

    float table_3[10][15] = {                              
        {0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
        {200, 3, 4, 6, 8, 9, 10, 12, 14, 15, 16, 18, 20, 21, 22},
        {400, 4, 5, 7, 10, 11, 12, 14, 17, 18, 20, 22, 23, 25, 27},
        {800, 4, 5, 8, 10, 11, 13, 15, 18, 19, 21, 23, 25, 27, 28},
        {1200, 4, 5, 8, 11, 12, 13, 16, 19, 20, 22, 24, 26, 28, 30},
        {1600, 4, 6, 8, 11, 13, 14, 17, 20, 21, 23, 25, 27, 29, 32},
        {2000, 4, 6, 9, 11, 13, 14, 17, 20, 21, 24, 26, 28, 30, 32},
        {2400, 4, 6, 9, 12, 14, 15, 18, 21, 22, 25, 27, 29, 32, 34},
        {3000, 5, 6, 9, 12, 14, 15, 18, 21, 23, 25, 28, 30, 32, 36},
        {4000, 5, 6, 10, 12, 14, 16, 19, 22, 24, 26, 29, 32, 34, 36}
    };

     int table_4_col_2[9] = {200, 400, 800, 1200, 1600, 2000, 2400, 3000, 4000};
    int table_4_row_1[14] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50};
    float table_4_minus[9][14] =
    {
        {-1, -2, -3, -4, -5, -6, -7, -8, -8, -9, -20, -29, -39, -49},
        {-1, -2, -3, -4, -5, -6, -6, -7, -8, -9, -19, -29, -38, -48},
        {-1, -2, -3, -4, -5, -6, -6, -7, -7, -8, -18, -28, -37, -46},
        {-1, -2, -3, -4, -4, -5, -5, -6, -7, -8, -17, -26, -35, -44},
        {-1, -2, -3, -3, -4, -4, -5, -6, -7, -8, -17, -25, -34, -42},
        {-1, -2, -3, -3, -4, -4, -5, -6, -6, -7, -16, -24, -32, -40},
        {-1, -2, -2, -3, -4, -4, -5, -5, -6, -7, -15, -23, -31, -38},
        {-1, -2, -2, -3, -4, -4, -4, -5, -5, -6, -15, -22, -30, -37},
        {-1, -2, -2, -3, -4, -4, -4, -4, -5, -6, -14, -20, -27, -34}
    };
    float table_4_plus[9][14] =
    {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 0, 0}
    };
    StringGrid8->Cells[2][0]=Form1->StringGrid6->Cells[2][1];
    StringGrid8->Cells[11][0]=Form1->StringGrid6->Cells[2][3];
    StringGrid8->Cells[11][1]=Form1->StringGrid6->Cells[2][4];
    StringGrid8->Cells[5][0]=Form1->StringGrid6->Cells[2][2];

    StringGrid11->Cells[4][1]= Form1->StringGrid2->Cells[2][6];
    StringGrid11->Cells[5][1]= Form1->StringGrid2->Cells[2][25];
    StringGrid11->Cells[6][1]= Form1->StringGrid2->Cells[2][26];


    Xc=StrToFloat(Form1->StringGrid7->Cells[2][1]);
    Zc=StrToFloat(Form1->StringGrid7->Cells[2][2]);
    hc=StrToFloat(Form1->StringGrid7->Cells[2][3]);
    Xb=StrToFloat(Form1->StringGrid5->Cells[4][1]);
    Zb=StrToFloat(Form1->StringGrid5->Cells[4][2]);
    hb=StrToFloat(Form1->StringGrid5->Cells[4][3]);
    alpha_osi=StrToFloat(Form1->StringGrid5->Cells[4][4]);

    delta_X = Xc - Xb;
    delta_Z = Zc - Zb;
    delta_h_c = hc - hb;
    StringGrid7->Cells[2][7]=delta_h_c;
    H=atan(-1*(delta_Z/delta_X));
    if (delta_Z>=0 && delta_X>0){
        alpha_c = (H*30)/M_PI;
    } else if (delta_Z>0 && delta_X==0) {
        alpha_c = 15.0;
    } else if (delta_Z>=0 && delta_X<0) {
        alpha_c = ((M_PI-H)*30)/M_PI;
    } else if (delta_Z<=0 && delta_X<0) {
        alpha_c = ((M_PI+H)*30)/M_PI;
    } else if (delta_Z<0 && delta_X==0) {
        alpha_c = 45.00;
    } else if (delta_Z<=0 && delta_X>0) {
        alpha_c = ((2*M_PI-H)*30)/M_PI;
    }
    D_c_t = sqrt(pow(delta_Z,2)+pow(delta_X,2));
    D_c_t = floor(((float)(int)(D_c_t * 100 + 0.5)) / 100);
    StringGrid7->Cells[2][4]=D_c_t;

    delta_c_t_shryh = alpha_c - alpha_osi;
    StringGrid7->Cells[2][5]=((float)(int)(delta_c_t_shryh * 100 + 0.5)) / 100;

    StringGrid7->Cells[2][6]=((float)(int)(alpha_c * 100 + 0.5)) / 100;

    if (abs(delta_c_t_shryh) <= 30){
        delta_c_t = delta_c_t_shryh;
    } else if ((abs(delta_c_t_shryh) > 30) && (delta_c_t_shryh < 0)){
        delta_c_t = alpha_c - alpha_osi + 60;
    } else if ((abs(delta_c_t_shryh) > 30) && (delta_c_t_shryh > 0)){
        delta_c_t = alpha_c - alpha_osi - 60;
    }

    sigma_c = (delta_h_c * 0,95)/(0,001*D_c_t*100);
    //   2 ��������
    Ho = StrToFloat(Form1->StringGrid6->Cells[2][1]);
    to = StrToFloat(Form1->StringGrid6->Cells[2][2]);
    alpha_wo = StrToFloat(Form1->StringGrid6->Cells[2][3])*100;
    Wo = StrToFloat(Form1->StringGrid6->Cells[2][4]);
    hmc = StrToFloat(Form1->StringGrid6->Cells[2][5]);

    delta_Ho = Ho - 750;
    StringGrid8->Cells[2][2]=delta_Ho;
    delta_Hb = delta_Ho + (hmc - hb)/10;
    //StringGrid2->Cells[2][7]=delta_Hb;
    for(int i=1;i<(StringGrid1->RowCount)-1;++i){
        if (StrToFloat(StringGrid1->Cells[0][i]) <= D_c_t && StrToFloat(StringGrid1->Cells[0][i+1]) >= D_c_t){
            Y_byl = (((D_c_t - StrToFloat(StringGrid1->Cells[0][i]))*(StrToFloat(StringGrid1->Cells[3][i+1])-StrToFloat(StringGrid1->Cells[3][i])))/(StrToFloat(StringGrid1->Cells[0][i+1]) - StrToFloat(StringGrid1->Cells[0][i])))+StrToFloat(StringGrid1->Cells[3][i]);
        }
    }

    // for(temp1 = 1; D_c_t > StrToFloat(StringGrid1->Cells[temp1][0]); temp1++){
    //     if((StrToFloat(StringGrid1->Cells[temp1][o])+StrToFloat(StringGrid1->Cells[temp1-1][0]))/2 < D_c_t){
    //         continue;
    //     }
    //     else{
    //         temp1=temp1-1;
    //     }
    // }
    // Y_byl = StrToFloat(StringGrid1->Cells[2][temp1]);
    StringGrid7->Cells[2][8]=Y_byl;

    for(int i=0;i<11-1;++i){
        if (table_1[0][i] <= to && table_1[0][i+1] >= to){
            delta_Tv = ( ( to - table_1[0][i] )*( table_1[1][i+1] - table_1[1][i]) / ( table_1[0][i+1] - table_1[0][i]) ) + table_1[1][i];
        }
    }
    delta_Tv;
    StringGrid8->Cells[5][1]=((float)(int)(delta_Tv * 100 + 0.5)) / 100;
    tau0 = to + delta_Tv;
    StringGrid8->Cells[5][2]=floor(((float)(int)(tau0 * 100 + 0.5)) / 100);
    StringGrid8->Cells[8][0]=floor(((float)(int)(tau0 * 100 + 0.5)) / 100);
    delta_tau_0mp=tau0-15.9;
    StringGrid8->Cells[8][2]=((float)(int)(delta_tau_0mp * 100 + 0.5)) / 100;
    // Y = ( ( X - X0 )*( Y1 - Y0) / ( X1 - X0) ) + Y0

    StringGrid8->Cells[8][2] = floor(StrToFloat(StringGrid8->Cells[8][2]));
    StringGrid9->Cells[2][2] = StringGrid8->Cells[8][2];

    int  count=0;
        for(int i=0;i<19-1;++i){
        float local_delta_tau_0mp;
        if (delta_tau_0mp < 0){
            //local_delta_tau_0mp = (delta_tau_0mp-StrToFloat(StringGrid9->Cells[3][3+count])) * -1;
            local_delta_tau_0mp = delta_tau_0mp * -1;
        }
        for(int j=0;j<15-1;++j){
            if (table_4[i][j] <= local_delta_tau_0mp && table_4[i][j+1] >= local_delta_tau_0mp){
                if (delta_tau_0mp < 0){
                    delta_tau_y = ( ( local_delta_tau_0mp - table_4[i][j] )*( table_4[i+1][j+1] - table_4[i+1][j]) / ( table_4[i][j+1] - table_4[i][j]) ) + table_4[i+1][j];
                }else{
                    delta_tau_y = ( ( local_delta_tau_0mp - table_4[i][j] )*( table_4[i+2][j+1] - table_4[i+2][j]) / ( table_4[i][j+1] - table_4[i][j]) ) + table_4[i+2][j];
                }
                i++;
            }
        }
        count++;
        StringGrid9->Cells[2][2+count]=floor(delta_tau_y+0.5);
    }
    delta_tau_0mp = floor(delta_tau_0mp);
    int trp=0;
    count=0;
    int tmp;
for(int i=0;i<9;++i){
        //StringGrid7->Cells[3][1+i]=i;
        //StringGrid7->Cells[6][1+i]=count;
        if (delta_tau_0mp > 0){
            trp=0;
            for(int j=0;j<14;j++){
                if(delta_tau_0mp == table_4_row_1[j]){
                    StringGrid9->Cells[2][3+count]=table_4_plus[count][j];
                    trp=1;
                    break;
                }
            }
            if(trp==0){
                for(int j=9;j<13;j++){
                    if(delta_tau_0mp > table_4_row_1[j] && delta_tau_0mp < table_4_row_1[j+1]){
                        tmp = delta_tau_0mp - table_4_row_1[j];
                        StringGrid9->Cells[2][3+count]=table_4_plus[count][j]+table_4_plus[count][tmp];
                        break;
                    }
                }
            }
        }else{
            trp=0;
            for(int j=0;j<14;j++){
                if((delta_tau_0mp*-1) == table_4_row_1[j]){
                    StringGrid9->Cells[2][3+count]=table_4_minus[count][j];
                    trp=1;
                    break;
                }
            }
            if(trp==0){
                for(int j=11;j<14;j++){
                    if(delta_tau_0mp > table_4_row_1[j] && delta_tau_0mp < table_4_row_1[j+1]){
                        tmp = delta_tau_0mp - table_4_row_1[j];
                        StringGrid9->Cells[2][3+count]=table_4_minus[count][j]+table_4_minus[count][tmp];
                        break;
                    }
                }
            }
        }

        count++;
    }
    StringGrid9->Cells[4][2]=alpha_wo;
    StringGrid9->Cells[5][2]=Wo;
    for(int i=0;i<9;++i){
        StringGrid9->Cells[4][3+i]=alpha_wo+table_4_col_3[i];
    }
    for(int j=0;j<9;++j){
        for(int i=1;i<16-1;++i){
            if (table_3[0][i] <= Wo && table_3[0][i+1] >= Wo){
             Wy = ( ( Wo - table_3[0][i] )*( table_3[j+1][i] - table_3[j+1][i]) / ( table_3[0][i+1] - table_3[0][i]) ) + table_3[j+1][i];
            }
        }
        StringGrid9->Cells[5][3+j]=Wy;
    }

    int temp;
    for(temp = 0; Y_byl > table_4_col_1[temp]; temp++){
        if((table_4_col_1[temp]+table_4_col_1[temp-1])/2 < Y_byl){
            continue;
        }
        else{
            temp=temp-1;
        }
    }

    if(alpha_c*100>=StrToFloat(StringGrid9->Cells[4][2+temp])){
        Aw = alpha_c * 100 - StrToFloat(StringGrid9->Cells[4][2+temp]);
    }else if(alpha_c*100<StrToFloat(StringGrid9->Cells[4][2+temp])){
        Aw = alpha_c * 100 + 60 - StrToFloat(StringGrid9->Cells[4][2+temp]);
    }
    /*ofstream foutf;
    foutf.open("log.txt");
    foutf << StrToFloat(StringGrid9->Cells[5][2+temp]);
    foutf.close();*/

    Aw_grad = (Aw*3.6)/60;
    Aw_grad = floor(Aw_grad+0.5);

    Wx = -1 * StrToFloat(StringGrid9->Cells[5][2+temp]) * cos(Aw_grad*3.14/180);
    Wz = StrToFloat(StringGrid9->Cells[5][2+temp]) * sin(Aw_grad*3.14/180);
    float tds = StrToFloat(StringGrid9->Cells[5][2+temp]);


    StringGrid10->Cells[0][1]=delta_Hb;
    StringGrid10->Cells[1][1]=StringGrid9->Cells[2][2+temp];
    StringGrid10->Cells[2][1]=floor(Wx+0.5);
    StringGrid10->Cells[3][1]=floor(Wz+0.5);


    //end of code

    for(int i=1;i<StringGrid1->RowCount;++i)
    point2comma(StringGrid1->Cells[2][i].c_str());

    for(int i=0;i<StringGrid2->RowCount;++i)
    point2comma(StringGrid2->Cells[2][i].c_str());

    TSDUSolver S;

    StringGrid3->RowCount=StringGrid1->RowCount;
    StringGrid4->RowCount=StringGrid1->RowCount;
    Form4->StringGrid1->ColCount=StringGrid1->RowCount;

    //������ �������� ������, ����� ��� ���� ����������
    S.v0=StrToFloat(StringGrid2->Cells[2][_vo]);
    S.dP=StrToFloat(StringGrid2->Cells[2][_dP]);
    S.dtau=StrToFloat(StringGrid2->Cells[2][_dtau]);
    S.Wx=StrToFloat(StringGrid2->Cells[2][_Wx]);
    S.Wz=StrToFloat(StringGrid2->Cells[2][_Wz]);
    S.Tz=StrToFloat(StringGrid2->Cells[2][_Tz]);
    S.dq=StrToFloat(StringGrid2->Cells[2][_dq]);
    S.dvo=StrToFloat(StringGrid2->Cells[2][_dvo]);
    S.d=StrToFloat(StringGrid2->Cells[2][_d]);
    S.qo=StrToFloat(StringGrid2->Cells[2][_qo]);
    S.tauoN=StrToFloat(StringGrid2->Cells[2][_tauoN]);
    S.go=StrToFloat(StringGrid2->Cells[2][_go]);
    S.R=StrToFloat(StringGrid2->Cells[2][_R]);
    S.ltz=StrToFloat(StringGrid2->Cells[2][_ltz]);
    S.lq=StrToFloat(StringGrid2->Cells[2][_lq]);
    S.PoN=StrToFloat(StringGrid2->Cells[2][_PoN]);
    S.dteta=StrToFloat(StringGrid2->Cells[2][_dteta]);
    S.eta=StrToFloat(StringGrid2->Cells[2][_eta]);
    S.L=StrToFloat(StringGrid2->Cells[2][_L]);
    S.A=StrToFloat(StringGrid2->Cells[2][_A]);
    S.rteta0=StrToFloat(Form1->StringGrid2->Cells[2][_rteta0]);
    S.rv0=StrToFloat(Form1->StringGrid2->Cells[2][_rv0]);
    S.rc=StrToFloat(Form1->StringGrid2->Cells[2][_rc]);
    S.rw=StrToFloat(Form1->StringGrid2->Cells[2][_rw]);
    S.rz=StrToFloat(Form1->StringGrid2->Cells[2][_rz]);
    S.Bsh=StrToFloat(Form1->StringGrid2->Cells[2][_Bsh]);
    S.ag=StrToFloat(Form1->StringGrid2->Cells[2][_ag]);
    S.Omegaz=StrToFloat(Form1->StringGrid2->Cells[2][_Omegaz]);
    S.Rz=StrToFloat(Form1->StringGrid2->Cells[2][_Rz]);
    S.x0=StrToFloat(Form1->StringGrid2->Cells[2][_Xn]);
    S.y0=StrToFloat(Form1->StringGrid2->Cells[2][_Yn]);
    S.z0=StrToFloat(Form1->StringGrid2->Cells[2][_Zn]);
    S.Xtn=StrToFloat(Form1->StringGrid2->Cells[2][_Xtn]);
    S.teta0n=StrToFloat(Form1->StringGrid2->Cells[2][_teta0n]);
    S.Kvrs=StrToFloat(Form1->StringGrid2->Cells[2][_Kvr]);
    S.tn=StrToFloat(Form1->StringGrid2->Cells[2][_tn]);
    S.tauaN=StrToFloat(Form1->StringGrid2->Cells[2][_tauaN]);
    S.I1N=StrToFloat(Form1->StringGrid2->Cells[2][_I1N]);
    S.wo=StrToFloat(Form1->StringGrid2->Cells[2][_w0]);
    S.K1=StrToFloat(Form1->StringGrid2->Cells[2][_K1]);
    S.K2=StrToFloat(Form1->StringGrid2->Cells[2][_K2]);
    S.deltat1=StrToFloat(Form1->StringGrid2->Cells[2][_dt1]);     //boop
    S.deltat2=StrToFloat(Form1->StringGrid2->Cells[2][_dt2]);       //boop
    S.dovorot=StrToFloat(Form1->StringGrid2->Cells[2][_dovorot]);
    //S.yrr=StrToFloat(Form1->StringGrid2->Cells[2][_yrr]);
    yrr=StrToFloat(Form1->StringGrid2->Cells[2][_yrr]);

    /*Form2->Series1->Clear();
    Form2->Series2->Clear();
    Form2->Series3->Clear();
    Form2->Series4->Clear();  */

    Form3->Series1->Clear();
    Form3->Series2->Clear();
    Form3->Series3->Clear();


    ofstream file1 ("parameters\\Vd.txt");
    ofstream file2 ("parameters\\Vdteta0.txt");
    ofstream file3 ("parameters\\Vdv0.txt");
    ofstream file4 ("parameters\\Vdc.txt");
    ofstream file5 ("parameters\\Vv.txt");
    ofstream file6 ("parameters\\Vb.txt");
    ofstream file7 ("parameters\\Xt.txt");
    ofstream file8 ("parameters\\Yt.txt");
    ofstream file9 ("parameters\\Zt.txt");
    ofstream file10 ("parameters\\tetac.txt");
    ofstream file11 ("parameters\\vc.txt");
    ofstream file12 ("parameters\\tc.txt");
    ofstream file13 ("parameters\\dXtys.txt");
    ofstream file14 ("parameters\\Zd.txt");
    ofstream file15 ("parameters\\dXw.txt");
    ofstream file16 ("parameters\\dXh.txt");
    ofstream file17 ("parameters\\dXt.txt");
    ofstream file18 ("parameters\\dXtz.txt");
    ofstream file19 ("parameters\\dXvo.txt");
    ofstream file20 ("parameters\\dXvo1proc.txt");
    ofstream file21 ("parameters\\dXq.txt");
    ofstream file22 ("parameters\\dZw.txt");
    ofstream file23 ("parameters\\dXvr.txt");
    ofstream file24 ("parameters\\dzvr.txt");
    ofstream file25 ("parameters\\dXtzr.txt");
    ofstream file26 ("parameters\\Xr.txt");
    ofstream file27 ("parameters\\Zr.txt");
    ofstream file28 ("parameters\\dXc.txt");
    ofstream file29 ("parameters\\Ptys.txt");
    ofstream file30 ("parameters\\Yrm.txt");
        ofstream file31 ("parameters\\dt.txt");

    ofstream file89 ("parameters\\Cx(vrtau).html");
    file89<<"<center><h2>���� ������</h2></center><table align='center' border=1>\t"<<endl;
    file89<<"<center><h3>���� ��������</h3></center><table align='center' border=1>\t"<<endl;
    file89<<"<tr>\t<td>vrtau</td>\t<td>Cx</td>\t</tr>"<<endl;


   Form4->StringGrid1->Cells[0][1]="��, � ����.";
   Form4->StringGrid1->Cells[0][2]="��, � ����.";
   Form4->StringGrid1->Cells[0][3]="��, � ����.";
   Form4->StringGrid1->Cells[0][4]="��, � ����.";
   Form4->StringGrid1->Cells[0][5]="��, � ����.";
   Form4->StringGrid1->Cells[0][6]="��, � ����.";

  /* Form2->StringGrid1->Cells[0][1]="x,�";        //������� �������� �����
   Form2->StringGrid1->Cells[0][2]="x,��";
   Form2->StringGrid1->Cells[0][3]="x,���";
   Form2->StringGrid1->Cells[0][4]="x,����";      */
    int p;
    if (S.teta0n==0)
    {
    p=StringGrid1->RowCount-1;
    }
    else{
    /// my choose
    p=1;
    }

    /// reduce to one flow
    for(int k=0;k<p;++k)
    {
        S.D = StrToFloat(StringGrid1->Cells[_D][k+1]);

        double teta0;
            int p;
            if (S.teta0n==0)
            {
                teta0=StrToFloat(StringGrid1->Cells[_tetao][k+1]);
                S.teta0=(int(teta0)+(teta0-int(teta0))*100/60)*M_PI/180;
            }
            else{
                /// my choose
                teta0=S.teta0n;
                S.teta0=(int(teta0)+(teta0-int(teta0))*100/60)*M_PI/180;
            }

 //       double teta0=StrToFloat(StringGrid1->Cells[_tetao][k+1]);
 //       S.teta0=(int(teta0)+(teta0-int(teta0))*100/60)*M_PI/180;
        if ((StringGrid1->Cells[_i][k+1])!="")
        {
            S.i=StrToFloat(StringGrid1->Cells[_i][k+1]);
        }
        else
        {

            /*if (g1>0 && g2<p)*/

                /*double proc=(StrToFloat(StringGrid1->Cells[_D][k+1])-StrToFloat(StringGrid1->Cells[_D][k]))/
                    (StrToFloat(StringGrid1->Cells[_D][k+2])-StrToFloat(StringGrid1->Cells[_D][k]));

                S.i=StrToFloat(StringGrid1->Cells[_i][k])+(StrToFloat(StringGrid1->Cells[_i][k+2])-
                    StrToFloat(StringGrid1->Cells[_i][k]))*proc;*/
/////////////////
				double temptet=StrToFloat(StringGrid1->Cells[_tetao][k+1]);;
                double pred;
                					TSDU Sm;
                                                        //Sm.yrr=StrToFloat(Form1->StringGrid2->Cells[2][_yrr]);
                                                        //Sm.yrr=S.yrr;
                    ifstream filem("resources\\152-��_��_2�3-��540-������-����.dat");
                    filem>>pred;
					for(int i=0;i<pred;++i)
					{
						filem>>Sm.mtetk[i];
						filem>>Sm.mkform[i];

					}
					filem.close();
/////////�-30

                   /* if (Form1->ComboBox1->ItemIndex==1)
                    if (Form1->ComboBox2->ItemIndex==0)
                    if (Form1->ComboBox3->ItemIndex==0)
                    if (Form1->ComboBox4->ItemIndex==0){
                    ifstream filem("resources\\122-��_�_�30-������-����.dat");
                    filem>>pred;
					for(int i=0;i<pred;++i){
						filem>>Sm.mtetk[i];
						filem>>Sm.mkform[i];

					}
					filem.close();	}*/
					for(int i=0;i<(pred);++i){

						if(temptet>=Sm.mtetk[i] && temptet<=Sm.mtetk[i+1])
						{
							double proc=(temptet-Sm.mtetk[i])/(Sm.mtetk[i+1]-Sm.mtetk[i]);
							S.i=(Sm.mkform[i]+(Sm.mkform[i+1]-Sm.mkform[i])*proc);
						}
                        /*else{
                            if (temptet<Sm.mtetk[0]) S.i=Sm.mkform[0];
                        }*/
					}
					if(temptet<Sm.mtetk[0])
					{
						S.i=Sm.mkform[0];

					}
					if(temptet>Sm.mtetk[3])
					{
						S.i=Sm.mkform[3];
					}
/////////////////
                StringGrid1->Cells[_i][k+1]=(FloatToStr(S.i));

        }

        S.calculate(Form1->autoFindCoefFormy->Checked);

        /// not necessary
        if (Form1->autoFindCoefFormy->Checked) {
            StringGrid1->Cells[_i][k+1] = FloatToStr(S.i);
        }


        StringGrid3->Cells[_Xt][k+1]=FloatToStr(okr(S.Xt));
        StringGrid3->Cells[_Yt][k+1]=FloatToStr(okr(S.Yt));
        StringGrid3->Cells[_Zt][k+1]=FloatToStr(okr(S.Zt));
        StringGrid3->Cells[_tetac][k+1]=FloatToStr(okr(S.tetac*180/M_PI));
        StringGrid3->Cells[_vc][k+1]=FloatToStr(okr(S.vc));
        StringGrid3->Cells[_tc][k+1]=FloatToStr(okr(S.tc));
        StringGrid3->Cells[_N][k+1]=FloatToStr(okr(S.N));
        StringGrid3->Cells[_tetar][k+1]=FloatToStr(okr(S.tetar*180/M_PI));
        StringGrid3->Cells[_vr][k+1]=FloatToStr(okr(S.vr));
        S.tr = 0;StringGrid3->Cells[_tr][k+1]=FloatToStr(okr(S.tr));

        StringGrid4->Cells[_Xt4][k+1]=FloatToStr(okr(S.Xt));
        if (StrToFloat(StringGrid2->Cells[2][_eta])==1) {
            StringGrid4->Cells[_Pri][k+1]=FloatToStr((1500-okr(S.Ptys))+250);
        }
        else{
            StringGrid4->Cells[_Pri][k+1]=FloatToStr(okr(S.Ptys));
        }


        StringGrid4->Cells[_dXtys][k+1]=FloatToStr(okr(S.dXtys));
        StringGrid4->Cells[_Zd][k+1]=FloatToStr(okr(S.Zd));
        StringGrid4->Cells[_dXw][k+1]=FloatToStr(okr(S.dXw));
        StringGrid4->Cells[_dXh][k+1]=FloatToStr(okr(S.dXh));
        StringGrid4->Cells[_dXt][k+1]=FloatToStr(okr(S.dXt));
        StringGrid4->Cells[_dXtz][k+1]=FloatToStr(okr(S.dXtz));
        StringGrid4->Cells[_dXvo][k+1]=FloatToStr(okr(S.dXvo));
        StringGrid4->Cells[_dXq][k+1]=FloatToStr(okr(S.dXq));
        StringGrid4->Cells[_dZw][k+1]=FloatToStr(okr(S.dZw));
        StringGrid4->Cells[_dXvr][k+1]=FloatToStr(okr(S.dXvr));
        StringGrid4->Cells[_dZvr][k+1]=FloatToStr(okr(S.dZvr));
        StringGrid4->Cells[_Xr][k+1]=FloatToStr(okr(S.Xr));
        StringGrid4->Cells[_Yrm][k+1]=FloatToStr(okr(S.Yrm));
        StringGrid4->Cells[_Zr][k+1]=FloatToStr(okr(S.Zr));
        StringGrid4->Cells[_dXc][k+1]=FloatToStr(okr(S.dXc));
        StringGrid4->Cells[_Vd][1+k]=FloatToStr(okr(S.Vd));
        StringGrid4->Cells[_Vv][1+k]=FloatToStr(okr(S.Vv));
        StringGrid4->Cells[_Vb][1+k]=FloatToStr(okr(S.Vb));
        StringGrid4->Cells[_Vdteta0][1+k]=FloatToStr(okr(S.Vdteta0));
        StringGrid4->Cells[_Vdv0][1+k]=FloatToStr(okr(S.Vdv0));
        StringGrid4->Cells[_Vdc][1+k]=FloatToStr(okr(S.Vdc));
        StringGrid4->Cells[_teta0][k+1]=FloatToStr(teta0);
        StringGrid4->Cells[_Ybul][k+1]=FloatToStr(S.Ybul);

        //Form2->Series1->AddXY(S.Xt,S.Vd);
        //Form2->Series2->AddXY(S.Xt,S.Vdteta0);
        //Form2->Series3->AddXY(S.Xt,S.Vdv0);
        //Form2->Series4->AddXY(S.Xt,S.Vdc);

        Form3->Series1->AddXY(S.Xt,S.Vd);
        Form3->Series2->AddXY(S.Xt,S.Vv);
        Form3->Series3->AddXY(S.Xt,S.Vb);

        Form4->StringGrid1->Cells[k+1][0]=FloatToStr(okr(S.Xt));
        Form4->StringGrid1->Cells[k+1][1]=FloatToStr(okr(S.Vd));
        Form4->StringGrid1->Cells[k+1][2]=FloatToStr(okr(S.Vv));
        Form4->StringGrid1->Cells[k+1][3]=FloatToStr(okr(S.Vb));

        for (int vi=0;vi<28;vi++)
        if (okr(S.Xt)==vd_opitnie[0][vi])
        {
         Form4->StringGrid1->Cells[k+1][4]=vd_opitnie[1][vi];
         Form4->StringGrid1->Cells[k+1][5]=vv_opitnie[1][vi];
         Form4->StringGrid1->Cells[k+1][6]=vb_opitnie[1][vi];

        }
        //�������� �����

//����� �������� �����

        file1<<okr(S.Xt)<<"\t"<<okr(S.Vd)<<endl;
        file2<<okr(S.Xt)<<"\t"<<S.Vdteta0<<endl;
        file3<<okr(S.Xt)<<"\t"<<S.Vdv0<<endl;
        file4<<okr(S.Xt)<<"\t"<<S.Vdc<<endl;
        file5<<okr(S.Xt)<<"\t"<<okr(S.Vv)<<endl;
        file6<<okr(S.Xt)<<"\t"<<okr(S.Vb)<<endl;
        file7<<okr(S.Xt)<<endl;
        file8<<okr(S.Xt)<<"\t"<<okr(S.Yt)<<endl; ("parameters\\Yt.txt");
        file9<<okr(S.Xt)<<"\t"<<okr(S.Zt)<<endl; ("parameters\\Zt.txt");
        file10<<okr(S.Xt)<<"\t"<<okr(S.tetac*180/M_PI)<<endl; ("parameters\\tetac.txt");
        file11<<okr(S.Xt)<<"\t"<<okr(S.vc)<<endl; ("parameters\\vc.txt");
        file12<<okr(S.Xt)<<"\t"<<okr(S.tc)<<endl; ("parameters\\tc.txt");
        file13<<okr(S.Xt)<<"\t"<<okr(S.dXtys)<<endl; ("parameters\\dXtys.txt");
        file14<<okr(S.Xt)<<"\t"<<okr(S.Zd)<<endl; ("parameters\\Zd.txt");
        file15<<okr(S.Xt)<<"\t"<<okr(S.dXw)<<endl; ("parameters\\dXw.txt");
        file16<<okr(S.Xt)<<"\t"<<okr(S.dXh)<<endl; ("parameters\\dXh.txt");
        file17<<okr(S.Xt)<<"\t"<<okr(S.dXt)<<endl; ("parameters\\dXt.txt");
        file18<<okr(S.Xt)<<"\t"<<okr(S.dXtz)<<endl; ("parameters\\dXtz.txt");
        file19<<okr(S.Xt)<<"\t"<<okr(S.dXvo)<<endl; ("parameters\\dXvo.txt");
        file20<<okr(S.Xt)<<"\t"<<okr(S.dXvo1proc)<<endl; ("parameters\\dXvo1proc.txt");
        file21<<okr(S.Xt)<<"\t"<<okr(S.dXq)<<endl; ("parameters\\dXq.txt");
        file22<<okr(S.Xt)<<"\t"<<okr(S.dZw)<<endl; ("parameters\\dZw.txt");
        file23<<okr(S.Xt)<<"\t"<<okr(S.dXvr)<<endl; ("parameters\\dXvr.txt");
        file24<<okr(S.Xt)<<"\t"<<okr(S.dZvr)<<endl; ("parameters\\dZvr.txt");
        file25<<okr(S.Xt)<<"\t"<<okr(S.dXtzr)<<endl; ("parameters\\dXtzr.txt");
        file26<<okr(S.Xt)<<"\t"<<okr(S.Xr)<<endl; ("parameters\\Xr.txt");
        file27<<okr(S.Xt)<<"\t"<<okr(S.Zr)<<endl; ("parameters\\Zr.txt");
        file28<<okr(S.Xt)<<"\t"<<okr(S.dXc)<<endl; ("parameters\\dXc.txt");
        file29<<okr(S.Xt)<<"\t"<<okr(S.Ptys)<<endl; ("parameters\\Ptys.txt");
        file30<<okr(S.Xt)<<"\t"<<okr(S.Yrm)<<endl; ("parameters\\Yrm.txt");
        file31<<okr(S.deltat1)<<""<<okr(S.deltat2)<<endl; ("parameters\\dt.txt");
    }
            file89<<S.Cx.c_str()<<endl; ("parameters\\current_f(Mtau).txt");
            temps=/*temps+*/"<td>"+S.Cx+"</td>\t</tr>";
        S.vrtau="";
        S.Cx="";
         file1.close();
         file2.close();
         file3.close();
         file4.close();
         file5.close();
         file6.close();
         file7.close();
         file8.close();
         file9.close();
         file10.close();
         file11.close();
         file12.close();
         file13.close();
         file14.close();
         file15.close();
         file16.close();
         file17.close();
         file18.close();
         file19.close();
         file20.close();
         file21.close();
         file22.close();
         file23.close();
         file24.close();
         file25.close();
         file26.close();
         file29.close();
         file30.close();
                  file31.close();
         file89<<"</table>\t"<<endl;
         file89.close();


  /*  outdata_[Xt_]=S.Xt;
    outdata_[Zt_]=S.Zt;
    outdata_[dXtys_]=S.dXtys;
    outdata_[Zd_]=S.Zd/100;
    outdata_[dXw_]=S.dXw;
    outdata_[dXh_]=S.dXh;
    outdata_[dXt_]=S.dXt;
    outdata_[dXtz_]=S.dXtz;
    outdata_[dXvo_]=S.dXvo;
    outdata_[dXq_]=S.dXq;
    outdata_[dZw_]=S.dZw/100;
    outdata_[dXtzr_]=0;
    outdata_[Xr_]=S.Xr;
    outdata_[Zr_]=S.Zr;

    ofstream file("data2.txt");
    for(int i=0;i<OUTDATANUM;++i)
    file<<outdata_[i]<<endl;
    file<<S.dXvo1proc<<endl;
    file.close(); */

    if(!Form1->CheckBox1->Checked){
        PageControl1->ActivePageIndex=1;
        return;
    }


    //----------������ ������� �----------------------------------------//


    float table_coef_row_one[6] = {0, 1000, 2000, 0, -1000, -2000};
    float table_coef_col_one[33] = {350, 370, 390, 410, 430, 450, 470, 490, 510, 530, 550, 570, 590, 610, 630, 650, 670, 690, 710, 730, 750, 770, 790, 810, 830, 850, 870, 890, 910, 930, 950, 970, 990};
    float table_coef[33][6] = {
        {0.15, 0.14, 0.14, 0, 0, 0},
        {0.17, 0.16, 0.16, 0, 0, 0},
        {0.19, 0.18, 0.18, 0, 0, 0},
        {0.21, 0.2, 0.2, 0, 0, 0.1},
        {0.23, 0.22, 0.22, 0, 0, 0.12},
        {0.25, 0.24, 0.24, 0, 0, 0.14},
        {0.27, 0.27, 0.26, 0, 0.16, 0.16},
        {0.3, 0.29, 0.29, 0, 0.18, 0.18},
        {0.32, 0.32, 0.31, 0, 0.21, 0.21},
        {0.35, 0.35, 0.34, 0, 0.23, 0.23},
        {0.38, 0.38, 0.37, 0, 0.26, 0.26},
        {0.42, 0.41, 0.41, 0, 0.29, 0.29},
        {0.45, 0.44, 0.44, 0, 0.32, 0.32},
        {0.5, 0.5, 0.49, 0.36, 0.35, 0.35},
        {0.55, 0.54, 0.53, 0.41, 0.4, 0.4},
        {0.6, 0.59, 0.59, 0.45, 0.45, 0.44},
        {0.6, 0.6, 0.59, 0.5, 0.5, 0.49},
        {0.74, 0.73, 0.72, 0.5, 0.5, 0.5},
        {0.81, 0.8, 0.79, 0.63, 0.63, 0.62},
        {0.9, 0.88, 0.88, 0.7, 0.7, 0.69},
        {0.99, 0.98, 0.98, 0.78, 0.78, 0.77},
        {1.11, 1.1, 1.09, 0.88, 0.87, 0.87},
        {1.24, 1.23, 1.23, 0.98, 0.98, 0.98},
        {1.4, 1.39, 1.39, 1.11, 1.11, 1.1},
        {1.59, 1.58, 1.58, 1.26, 1.26, 1.26},
        {1.82, 1.82, 1.82, 1.44, 1.44, 1.44},
        {2.11, 2.11, 2.12, 1.66, 1.67, 1.67}, 
        {2.48, 2.5, 2.51, 1.94, 1.95, 1.96}, 
        {2.97, 3, 3.03, 2.29, 2.31, 2.33},
        {3.73, 3.81, 3.9, 2.76, 2.79, 2.83},
        {5.16, 5.33, 5.54, 3.4, 3.44, 3.49},
        {0, 0, 0, 4.08, 4.16, 4.24},
        {0, 0, 0, 5.09, 5.22, 5.38}
    };
    int temp2 = 2;
    float Xp,Zp,Dsum,deltaXw,deltaXh,deltaXt,delta_tauY,deltaXtz,deltaTz,deltaXvo,deltaVo,deltaXq,deltaQ,deltaDsum,deltaZw,D_c_v,Pr_tys,Pr_dol;
    String a = StringGrid7->Cells[2][4];
    String b = StringGrid1->Cells[0][temp2];
    for(temp2 = 2; StrToFloat(a) > StrToFloat(StringGrid1->Cells[0][temp2]); temp2++){
        String c = StringGrid1->Cells[0][temp2];
        String d = StringGrid1->Cells[0][temp2-1];
        if((StrToFloat(c)+StrToFloat(d))/2 < StrToFloat(a)){
            continue;
        }
        else{
            temp2=temp2-1;
        }
    }
    Wx = StrToFloat(StringGrid10->Cells[2][1]);
    Wz = StrToFloat(StringGrid10->Cells[3][1]);
    delta_Hb = StrToFloat(StringGrid10->Cells[0][1]);
    delta_tauY = StrToFloat(StringGrid10->Cells[1][1]);
    deltaXw = StrToFloat(StringGrid4->Cells[6][temp2-1]);
    deltaXh = StrToFloat(StringGrid4->Cells[7][temp2-1]);
    deltaXt = StrToFloat(StringGrid4->Cells[8][temp2-1]);
    deltaXtz = StrToFloat(StringGrid4->Cells[9][temp2-1]);
    deltaTz = StrToFloat(StringGrid11->Cells[2][1])-15;
    deltaXvo = StrToFloat(StringGrid4->Cells[10][temp2-1]);
    deltaVo = StrToFloat(StringGrid11->Cells[1][1]);
    deltaXq = StrToFloat(StringGrid4->Cells[11][temp2-1]);
    deltaQ = StrToFloat(StringGrid11->Cells[3][1]);
    Dsum = (0.1 * deltaXw * Wx) + (0.1 * deltaXh * delta_Hb) + (0.1 * deltaXt * delta_tauY) + (0.1 * deltaXtz * deltaTz) + (deltaXvo * deltaVo) + (deltaXq * deltaQ);
    Dsum = floor(Dsum+0.5);
    deltaZw = StrToFloat(StringGrid4->Cells[5][temp2-1]);
    deltaDsum = 0.1 * deltaZw * Wz;
    deltaDsum = floor(deltaDsum+0.5);
    D_c_t = StrToFloat(StringGrid7->Cells[2][4]);
    Zp=(deltaDsum*D_c_t)/955;
    Zp = floor(Zp+0.5);
    Xp=D_c_t+Dsum;
    delta_c_t = StrToFloat(StringGrid7->Cells[2][5]);
    D_c_v = delta_c_t + deltaDsum/100;
    D_c_v = ((float)(int)(D_c_v * 100)) / 100;
    int i;
    float Tetav_1,Tetav_2;
    for(i=1;i<(StringGrid1->RowCount)-1;++i){
        if (StrToFloat(StringGrid1->Cells[0][i]) <= Xp && StrToFloat(StringGrid1->Cells[0][i+1]) >= Xp){
            Tetav_1 = StrToFloat(StringGrid1->Cells[1][i]);
            Tetav_2 = StrToFloat(StringGrid1->Cells[1][i+1]);
            break;
        }
    }
    float tdmp,tdmp2;
    tdmp = Xp - StrToFloat(StringGrid1->Cells[0][i]);
    float Tetav_1_first, Tetav_1_second, Tetav_2_first, Tetav_2_second, Tatav_rad,Tatav_1_min,Tatav_2_min,Tetav_min,Tetav_grad;
    Tetav_1_first = floor(Tetav_1);
    // ������� round
    Tetav_1_second = round((Tetav_1-(floor(Tetav_1)))*100);
    Tetav_2_first = floor(Tetav_2);
    Tetav_2_second = round((Tetav_2-(floor(Tetav_2)))*100);
    Tatav_1_min = (Tetav_1_first*60)+ Tetav_1_second;
    Tatav_2_min = (Tetav_2_first*60)+ Tetav_2_second;

    Tatav_rad = Tatav_1_min - Tatav_2_min;
    tdmp2 = floor((Tatav_rad/100)*tdmp+0.5);
    Tetav_grad = floor((Tatav_1_min-tdmp2)/60);
    Tetav_min = (Tatav_1_min-(Tetav_grad*60))-tdmp2;

    Pr_tys = (Tetav_grad * 60 + Tetav_min)/3.6;
    Pr_tys = floor(Pr_tys+0.5);
    Pr_dol = (1500 - Pr_tys) + 250;
    StringGrid12->Cells[2][1] = Pr_tys;
    StringGrid12->Cells[1][1] = Pr_dol;
    StringGrid12->Cells[0][1] = round(Tetav_1*10)/10;
    int j=0;
    float Kph,delta_P_h,P_v_r,delta_d_sum;

    delta_d_sum = (Zp*955)/D_c_t;
    delta_h_c = StrToFloat(StringGrid7->Cells[2][4]);
    for(i=0;i<5;++i){
        if (table_coef_row_one[i] <= delta_h_c && table_coef_row_one[i+1] >= delta_h_c){
            j = i+1;
            break;
        }
    }


    /*if (j > delta_h_c){
        j = 3;
    }
    j = 5; */

    for(i=0;i<32;++i){
        if (table_coef_col_one[i] <= Pr_dol && table_coef_col_one[i+1] >= Pr_dol){
            Kph = table_coef[i+1][j];
            break;
        }
    }
    delta_h_c = StrToFloat(StringGrid7->Cells[2][7]);
    delta_P_h = 0.1 * Kph * delta_h_c;
        if(delta_P_h < 0) {
                delta_P_h = floor(delta_P_h);
        } else {
            delta_P_h = ceil(delta_P_h);
        }

    //delta_P_h = floor(delta_P_h+0.5);
    P_v_r = Pr_dol + delta_P_h;
    P_v_r = floor(P_v_r+0.5);
        delta_h_c = StrToFloat(StringGrid7->Cells[2][5])+delta_d_sum;
    //Tetav_1
    //1 ' = 0.00029088820866572 rad
    //grad* (pi/180)
    //180/pi*rad
    StringGrid12->Cells[0][1] = P_v_r;
    StringGrid12->Cells[1][1] = D_c_v;
    StringGrid12->Cells[2][1] = Xp;
    StringGrid12->Cells[3][1] = Zp;

    StringGrid12->Cells[4][1] = Pr_tys;
    StringGrid12->Cells[5][1] = Pr_dol;
    StringGrid12->Cells[6][1] = delta_P_h;
    StringGrid12->Cells[7][1] = Tetav_grad;
    StringGrid12->Cells[8][1] = Tetav_min;
    PageControl1->ActivePageIndex=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
    int RC=StrToInt(Edit1->Text);
    if(RC>0)
    StringGrid1->RowCount=RC+1;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button6Click(TObject *Sender)
{
Form4->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
Form3->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Save1Click(TObject *Sender)
{
    ofstream file99 ("Rezult.html");

	char dateandtime[50];                          //���������
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%B, %d, %Y ����. %I:%M:%S ";
	setlocale(LC_ALL, "");
	strftime(dateandtime, 50, format, timeinfo);

    file99<<"<p><i><font size=\"3\">"<<dateandtime<<"</font></i></p>"<<endl;  //���� � �����

    file99<<"<p align=\"center\"><b><font size=\"4\">��� ������ ����</font></b></p>"<<endl;
    file99<<"<p align=\"center\"><b><font size=\"4\">������� ��������</font></b></p>"<<endl;
    file99<<"<p align=\"center\"><b><font size=\"4\">"<<Form1->Edit2->Text.c_str()<<",     ����� "<<Form1->Edit4->Text.c_str()<<",      ������ "<<Form1->Edit3->Text.c_str()<<"</font></b></p>"<<endl;

    //if (Form1->StringGrid2->Cells[0][4]==0){
    file99<<"<center><h2>���� ������</h2></center><table align='center' border=1>\t"<<endl;
    file99<<"<center><h3>���� ��������</h3></center>"<<endl;
    file99<<"<table align='center' border=1>"<<endl;
    for(int i=0;i<=Form1->StringGrid1->RowCount-1;i++){
        file99<<"<tr>"<<endl;
        file99<<"<td>"<<(Form1->StringGrid1->Cells[0][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid1->Cells[1][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid1->Cells[2][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid1->Cells[3][i].c_str())<<"</td>"<<endl;
        file99<<"</tr>"<<endl;
    }
    file99<<"</table>"<<endl;
    file99<<"<br>"<<endl;
    file99<<"<br>"<<endl;
    //}

    file99<<"<center><h3>�������� �������� ��� ������� ��������� ����������</h3></center>"<<endl;
    file99<<"<table align='center' border=1>"<<endl;
    for(int i=0;i<=Form1->StringGrid2->RowCount-1;i++){
        file99<<"<tr>"<<endl;
        file99<<"<td>"<<(Form1->StringGrid2->Cells[0][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid2->Cells[1][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid2->Cells[2][i].c_str())<<"</td>"<<endl;
        file99<<"</tr>"<<endl;
    }
    file99<<"</table>"<<endl;
    file99<<"<br>"<<endl;
    file99<<"<br>"<<endl;

    file99<<"<center><h3>��������� ����������</h3></center>"<<endl;
    file99<<"<table align='center' border=1>"<<endl;
    for(int i=0;i<=Form1->StringGrid3->RowCount-1;i++){
        file99<<"<tr>"<<endl;
        file99<<"<td>"
        <<(Form1->StringGrid3->Cells[0][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid3->Cells[1][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid3->Cells[2][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid3->Cells[3][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid3->Cells[4][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid3->Cells[5][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid3->Cells[6][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid3->Cells[7][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid3->Cells[8][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid3->Cells[9][i].c_str())<<"</td>"<<endl;
        file99<<"</tr>"<<endl;
    }
    file99<<"</table>"<<endl;
    file99<<"<br>"<<endl;
    file99<<"<br>"<<endl;

    file99<<"<center><h3>����������� �����</h3></center>"<<endl;
  /*  file99<<"����0, ����,����"<<"\t"
    <<"��, �"<<"\t"
    <<"�, ���"<<"\t"
    <<"dX���, �"<<"\t"
    <<"Z, ���"<<"\t"
    <<"dXw, �"<<"\t"
    <<"dXc, �"<<"\t"
    <<"dX�, �"<<"\t"
    <<"dX�, �"<<"\t"
    <<"dX��, �"<<"\t"
    <<"dXvo, �"<<"\t"
    <<"dXq, �"<<"\t"
    <<"dZw, ���"<<"\t"
    <<"dXvr, �"<<"\t"
    <<"dZvr, ���"<<"\t"
    <<"��, �"<<"\t"
    <<"Ys, �"<<"\t"
    <<"Z�, �"<<"\t"
    <<"��_����0, �"<<"\t"
    <<"��_V0, �"<<"\t"
    <<"��_�, �"<<"\t"
    <<"��, �"<<"\t"
    <<"��, �"<<"\t"
    <<"��, �"<<endl;*/
    file99<<"<table align='center' border=1>"<<endl;


    for(int i=0;i<=0;i++){
        file99<<"<tr>"<<endl;
        file99<<"<td>"
        <<(Form1->StringGrid4->Cells[1][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[2][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[3][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[4][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[5][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[7][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[8][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[9][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[10][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[11][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[12][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[13][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[14][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[15][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[16][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[17][i].c_str())<<"</td><td>"

        <<(Form1->StringGrid4->Cells[21][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[22][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[23][i].c_str())<<"</td>"<<endl;
        file99<<"</tr>"<<endl;
    }
        file99<<"<tr>"<<endl;
        for(int i=1;i<=19;i++){
        file99<<"<td>"<<(i)<<"</td>"<<endl;
        }
        file99<<"</tr>"<<endl;

    for(int i=1;i<=Form1->StringGrid1->RowCount-1;i++){
        file99<<"<tr>"<<endl;
        file99<<"<td>"
        <<(Form1->StringGrid4->Cells[1][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[2][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[3][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[4][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[5][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[7][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[8][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[9][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[10][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[11][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[12][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[13][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[14][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[15][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[16][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[17][i].c_str())<<"</td><td>"

        <<(Form1->StringGrid4->Cells[21][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[22][i].c_str())<<"</td><td>"
        <<(Form1->StringGrid4->Cells[23][i].c_str())<<"</td>"<<endl;
        file99<<"</tr>"<<endl;
    }
    file99<<"</table>"<<endl;
    //file99<<(Form1->StringGrid4->Cells[0][1])<<"</td><td>"<<(Form1->StringGrid4->Cells[1][1])<<endl;
    //file99<<okr(S.Xt)<<"</td><td>"<<okr(S.dXc)<<endl;

    file99<<"<center><h3>������������</h3></center><table align='center' border=1>\t"<<endl;
    file99<<"<tr>\t<td>vrtau</td>\t<td>Cx</td>\t</tr>"<<endl;
    file99<<temps.c_str()<<endl; ("parameters\\current_f(Mtau).txt");

    file99<<"</table>"<<endl;

    file99.close();
}

//---------------------------------------------------------------------------



void __fastcall TForm1::Button8Click(TObject *Sender)
{
                float table_coef_row_one[6] = {0, 1000, 2000, 0, -1000, -2000};
    float table_coef_col_one[33] = {350, 370, 390, 410, 430, 450, 470, 490, 510, 530, 550, 570, 590, 610, 630, 650, 670, 690, 710, 730, 750, 770, 790, 810, 830, 850, 870, 890, 910, 930, 950, 970, 990};
    float table_coef[33][6] = {
        {0.15, 0.14, 0.14, 0, 0, 0},
        {0.17, 0.16, 0.16, 0, 0, 0},
        {0.19, 0.18, 0.18, 0, 0, 0},
        {0.21, 0.2, 0.2, 0, 0, 0.1},
        {0.23, 0.22, 0.22, 0, 0, 0.12},
        {0.25, 0.24, 0.24, 0, 0, 0.14},
        {0.27, 0.27, 0.26, 0, 0.16, 0.16},
        {0.3, 0.29, 0.29, 0, 0.18, 0.18},
        {0.32, 0.32, 0.31, 0, 0.21, 0.21},
        {0.35, 0.35, 0.34, 0, 0.23, 0.23},
        {0.38, 0.38, 0.37, 0, 0.26, 0.26},
        {0.42, 0.41, 0.41, 0, 0.29, 0.29},
        {0.45, 0.44, 0.44, 0, 0.32, 0.32},
        {0.5, 0.5, 0.49, 0.36, 0.35, 0.35},
        {0.55, 0.54, 0.53, 0.41, 0.4, 0.4},
        {0.6, 0.59, 0.59, 0.45, 0.45, 0.44},
        {0.6, 0.6, 0.59, 0.5, 0.5, 0.49},
        {0.74, 0.73, 0.72, 0.5, 0.5, 0.5},
        {0.81, 0.8, 0.79, 0.63, 0.63, 0.62},
        {0.9, 0.88, 0.88, 0.7, 0.7, 0.69},
        {0.99, 0.98, 0.98, 0.78, 0.78, 0.77},
        {1.11, 1.1, 1.09, 0.88, 0.87, 0.87},
        {1.24, 1.23, 1.23, 0.98, 0.98, 0.98},
        {1.4, 1.39, 1.39, 1.11, 1.11, 1.1},
        {1.59, 1.58, 1.58, 1.26, 1.26, 1.26},
        {1.82, 1.82, 1.82, 1.44, 1.44, 1.44},
        {2.11, 2.11, 2.12, 1.66, 1.67, 1.67}, 
        {2.48, 2.5, 2.51, 1.94, 1.95, 1.96}, 
        {2.97, 3, 3.03, 2.29, 2.31, 2.33},
        {3.73, 3.81, 3.9, 2.76, 2.79, 2.83},
        {5.16, 5.33, 5.54, 3.4, 3.44, 3.49},
        {0, 0, 0, 4.08, 4.16, 4.24},
        {0, 0, 0, 5.09, 5.22, 5.38}
    };
    int temp2 = 2;
    float Wx, Wz, delta_Hb, D_c_t, delta_c_t, Xp,Zp,Dsum,deltaXw,deltaXh,deltaXt,delta_tauY,deltaXtz,deltaTz,deltaXvo,deltaVo,deltaXq,deltaQ,deltaDsum,deltaZw,D_c_v,Pr_tys,Pr_dol;
    String a = StringGrid7->Cells[2][4];
    String b = StringGrid1->Cells[0][temp2];
    for(temp2 = 2; StrToFloat(a) > StrToFloat(StringGrid1->Cells[0][temp2]); temp2++){
        String c = StringGrid1->Cells[0][temp2];
        String d = StringGrid1->Cells[0][temp2-1];
        if((StrToFloat(c)+StrToFloat(d))/2 < StrToFloat(a)){
            continue;
        }
        else{
            temp2=temp2-1;
        }
    }
    Wx = StrToFloat(StringGrid10->Cells[2][1]);
    Wz = StrToFloat(StringGrid10->Cells[3][1]);
    delta_Hb = StrToFloat(StringGrid10->Cells[0][1]);
    delta_tauY = StrToFloat(StringGrid10->Cells[1][1]);
    deltaXw = StrToFloat(StringGrid4->Cells[6][temp2-1]);
    deltaXh = StrToFloat(StringGrid4->Cells[7][temp2-1]);
    deltaXt = StrToFloat(StringGrid4->Cells[8][temp2-1]);
    deltaXtz = StrToFloat(StringGrid4->Cells[9][temp2-1]);
    deltaTz = StrToFloat(StringGrid11->Cells[2][1])-15;
    deltaXvo = StrToFloat(StringGrid4->Cells[10][temp2-1]);
    deltaVo = StrToFloat(StringGrid11->Cells[1][1]);
    deltaXq = StrToFloat(StringGrid4->Cells[11][temp2-1]);
    deltaQ = StrToFloat(StringGrid11->Cells[3][1]);
    Dsum = (0.1 * deltaXw * Wx) + (0.1 * deltaXh * delta_Hb) + (0.1 * deltaXt * delta_tauY) + (0.1 * deltaXtz * deltaTz) + (deltaXvo * deltaVo) + (deltaXq * deltaQ);
    Dsum = floor(Dsum+0.5);
    deltaZw = StrToFloat(StringGrid4->Cells[5][temp2-1]);
    deltaDsum = 0.1 * deltaZw * Wz;
    deltaDsum = floor(deltaDsum+0.5);
    D_c_t = StrToFloat(StringGrid7->Cells[2][4]);
    Zp=(deltaDsum*D_c_t)/955;
    Zp = floor(Zp+0.5);
    Xp=D_c_t+Dsum;
    delta_c_t = StrToFloat(StringGrid7->Cells[2][5]);
    D_c_v = delta_c_t + deltaDsum/100;
    D_c_v = ((float)(int)(D_c_v * 100)) / 100;
    int i;
    float Tetav_1,Tetav_2;
    for(i=1;i<(StringGrid1->RowCount)-1;++i){
        if (StrToFloat(StringGrid1->Cells[0][i]) <= Xp && StrToFloat(StringGrid1->Cells[0][i+1]) >= Xp){
            Tetav_1 = StrToFloat(StringGrid1->Cells[1][i]);
            Tetav_2 = StrToFloat(StringGrid1->Cells[1][i+1]);
            break;
        }
    }
    float tdmp,tdmp2;
    tdmp = Xp - StrToFloat(StringGrid1->Cells[0][i]);
    float Tetav_1_first, Tetav_1_second, Tetav_2_first, Tetav_2_second, Tatav_rad,Tatav_1_min,Tatav_2_min,Tetav_min,Tetav_grad;
    Tetav_1_first = floor(Tetav_1);
    // ������� round
    Tetav_1_second = round((Tetav_1-(floor(Tetav_1)))*100);
    Tetav_2_first = floor(Tetav_2);
    Tetav_2_second = round((Tetav_2-(floor(Tetav_2)))*100);
    Tatav_1_min = (Tetav_1_first*60)+ Tetav_1_second;
    Tatav_2_min = (Tetav_2_first*60)+ Tetav_2_second;

    Tatav_rad = Tatav_1_min - Tatav_2_min;
    tdmp2 = floor((Tatav_rad/100)*tdmp+0.5);
    Tetav_grad = floor((Tatav_1_min-tdmp2)/60);
    Tetav_min = (Tatav_1_min-(Tetav_grad*60))-tdmp2;

    Pr_tys = (Tetav_grad * 60 + Tetav_min)/3.6;
    Pr_tys = floor(Pr_tys+0.5);
    Pr_dol = (1500 - Pr_tys) + 250;
    StringGrid12->Cells[2][1] = Pr_tys;
    StringGrid12->Cells[1][1] = Pr_dol;
    StringGrid12->Cells[0][1] = round(Tetav_1*10)/10;
    int j=0;
    float delta_h_c, Kph,delta_P_h,P_v_r,delta_d_sum;

    delta_d_sum = (Zp*955)/D_c_t;
    delta_h_c = StrToFloat(StringGrid7->Cells[2][4]);
    for(i=0;i<5;++i){
        if (table_coef_row_one[i] <= delta_h_c && table_coef_row_one[i+1] >= delta_h_c){
            j = i+1;
            break;
        }
    }


    /*if (j > delta_h_c){
        j = 3;
    }
    j = 5; */

    for(i=0;i<32;++i){
        if (table_coef_col_one[i] <= Pr_dol && table_coef_col_one[i+1] >= Pr_dol){
            Kph = table_coef[i+1][j];
            break;
        }
    }
    delta_h_c = StrToFloat(StringGrid7->Cells[2][7]);
    delta_P_h = 0.1 * Kph * delta_h_c;
        if(delta_P_h < 0) {
                delta_P_h = floor(delta_P_h);
        } else {
            delta_P_h = ceil(delta_P_h);
        }

    //delta_P_h = floor(delta_P_h+0.5);
    P_v_r = Pr_dol + delta_P_h;
    P_v_r = floor(P_v_r+0.5);
        delta_h_c = StrToFloat(StringGrid7->Cells[2][5])+delta_d_sum;
    //Tetav_1
    //1 ' = 0.00029088820866572 rad
    //grad* (pi/180)
    //180/pi*rad
    StringGrid12->Cells[0][1] = P_v_r;
    StringGrid12->Cells[1][1] = D_c_v;
    StringGrid12->Cells[2][1] = Xp;
    StringGrid12->Cells[3][1] = Zp;

    StringGrid12->Cells[4][1] = Pr_tys;
    StringGrid12->Cells[5][1] = Pr_dol;
    StringGrid12->Cells[6][1] = delta_P_h;
    StringGrid12->Cells[7][1] = Tetav_grad;
    StringGrid12->Cells[8][1] = Tetav_min;
}
//---------------------------------------------------------------------------
