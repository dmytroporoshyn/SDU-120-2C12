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
//#include "Unit3.h"
#include "Unit4.h"
#include "SDU.cpp"
#include "mymath.cpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
using namespace std;     //������ ��� ���� � �������

TForm1 *Form1;
//enum vars_{_x=1,_y,_z,_v,_psi1,_psi2,_x1,_x2,_alpha1,_alpha2,_r,_pi,_deltaz,OUTTABL3COLNUM};  //�������� �����
enum indata1{_D,_tetao,_i,INTABL1COLNUM};
enum indata2{_Xn,_Yn,_Zn,_Xtn,_teta0n,_Kvr,_vo,_dP,_dtau,_Wx,_Wz,_Tz,_dq,_dvo,_d,_qo,_tn,_tauaN,_I1N,_w0,_K1,_K2,_tauoN,_go,_R,_ltz,_lq,_PoN,_dteta,_eta,_L,_A,_rteta0,_rv0,_rc,_rw,_rz,_Bsh,_ag,_Omegaz,_Rz,_dt1, _dt2,_hr, INTABL2ROWNUM};
//enum outdata_{Xt_,Zt_,dXtys_,Zd_,dXw_,dXh_,dXt_,dXtz_,dXvo_,dXq_,dZw_,dXtzr_,Xr_,Zr_};
enum outdata1{_Xt,_Yt,_Zt,_tetac,_vc,_tc,OUTTABL1COLNUM};
enum outdata2{_teta0,_Xt4,_Pri,_dXtys,_Zd,_dXw,_dXc,_dXh,_dXt,_dXtz,_dXvo,_dXq,_dZw,_dXvr,_dZvr,_Xr,_Yrm,_Zr,_Vdteta0,_Vdv0,_Vdc,_Vd,_Vv,_Vb,OUTTABL2COLNUM};
AnsiString invarname1[INTABL1COLNUM],invarname2[INTABL2ROWNUM],
           outvarname1[OUTTABL1COLNUM],outvarname2[OUTTABL2COLNUM]/*,outvarname3[OUTTABL3COLNUM]*/;

double vd_opitnie[2][28]={1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000,21000,22000,23000,24000,25000,26000,27000,28000,43,40,37,35,33,32,31,31,31,32,33,35,37,40,43,46,49,53,56,60,63,67,71,75,80,86,92,100};

double vv_opitnie[2][28]={1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000,21000,22000,23000,24000,25000,26000,27000,28000,0.3,0.5,0.8,1.1,1.4,1.7,2.2,2.7,3.4,4.3,5.5,7,9.1,12,15,19,24,30,37,45,54,64,77,91,109,132,161,207};

double vb_opitnie[2][28]={1000,2000,3000,4000,5000,6000,7000,8000,9000,10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000,21000,22000,23000,24000,25000,26000,27000,28000,0.3,0.5,0.8,1,1.3,1.6,1.9,2.1,2.4,2.7,3,3.3,3.6,4,4.3,4.7,5.2,5.7,6.3,6.9,7.6,8.3,9.2,10,11,12,14,15};
//double indata_[INDATA1NUM];
//double outdata_[OUTDATANUM];
/*double invartabl1[INTABL1ROWNUM]={0};
double invartabl2[INTABL2ROWNUM]={0};
double outvartabl1[OUTTABL1COLNUM]={0};
double outvartabl2[OUTTABL2COLNUM]={0};*/

AnsiString temps;

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
    invarname2[_hr]="H �������";

    outvarname1[_Xt]="��, �";
    outvarname1[_Yt]="Y�, �";
    outvarname1[_Zt]="Z�, �";
    outvarname1[_tetac]="TETAc, ����";
    outvarname1[_vc]="Vc, �/�";
    outvarname1[_tc]="tc, �";

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

  /*  outvarname3[_x]="�, �";           //�������� �����
    outvarname3[_y]="Y, �";
    outvarname3[_z]="Z, �";
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
//void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
//{
//	saveindata("resources\\indata__.txt");
//}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
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
    S.hr=StrToFloat(Form1->StringGrid2->Cells[2][_hr]);

    /*Form2->Series1->Clear();
    Form2->Series2->Clear();
    Form2->Series3->Clear();
    Form2->Series4->Clear();  */

	//Form3->Series1->Clear();
	//Form3->Series2->Clear();
	//Form3->Series3->Clear();


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
    if (S.teta0n==0){
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
            if (S.teta0n==0){
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
        if ((StringGrid1->Cells[_i][k+1])!=""){
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




                    ifstream filem("resources\\152-��_��_2�3-��540-������-����.dat");
                    filem>>pred;
					for(int i=0;i<pred;++i){
						filem>>Sm.mtetk[i];
						filem>>Sm.mkform[i];

					}
					filem.close();




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
					if(temptet<Sm.mtetk[0]){
						S.i=Sm.mkform[0];

					}
					if(temptet>Sm.mtetk[3]){
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
        StringGrid4->Cells[_Zr][k+1]=FloatToStr(okr(S.Zr));     //nil
        StringGrid4->Cells[_dXc][k+1]=FloatToStr(okr(S.dXc));
        StringGrid4->Cells[_Vd][1+k]=FloatToStr(okr(S.Vd));
        StringGrid4->Cells[_Vv][1+k]=FloatToStr(okr(S.Vv));
        StringGrid4->Cells[_Vb][1+k]=FloatToStr(okr(S.Vb));
        StringGrid4->Cells[_Vdteta0][1+k]=FloatToStr(okr(S.Vdteta0));
        StringGrid4->Cells[_Vdv0][1+k]=FloatToStr(okr(S.Vdv0));
        StringGrid4->Cells[_Vdc][1+k]=FloatToStr(okr(S.Vdc));
        StringGrid4->Cells[_teta0][k+1]=FloatToStr(teta0);

        //Form2->Series1->AddXY(S.Xt,S.Vd);
        //Form2->Series2->AddXY(S.Xt,S.Vdteta0);
        //Form2->Series3->AddXY(S.Xt,S.Vdv0);
        //Form2->Series4->AddXY(S.Xt,S.Vdc);

		//Form3->Series1->AddXY(S.Xt,S.Vd);
		//Form3->Series2->AddXY(S.Xt,S.Vv);
		//Form3->Series3->AddXY(S.Xt,S.Vb);

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
//Form3->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Save1Click(TObject *Sender)
{
    ofstream file99 ("Output/res.html");

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
        <<(Form1->StringGrid1->Cells[2][i].c_str())<<"</td>"<<endl;
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
        <<(Form1->StringGrid3->Cells[5][i].c_str())<<"</td>"<<endl;
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
