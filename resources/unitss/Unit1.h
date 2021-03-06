//--------------------------------------------------------------------------- ****

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPageControl *PageControl1;
    TTabSheet *TabSheet1;
    TTabSheet *TabSheet2;
    TGroupBox *GroupBox4;
    TGroupBox *GroupBox3;
    TStringGrid *StringGrid3;
    TStringGrid *StringGrid4;
    TGroupBox *GroupBox1;
    TStringGrid *StringGrid1;
    TGroupBox *GroupBox2;
    TStringGrid *StringGrid2;
    TButton *Button2;
    TButton *Button3;
    TButton *Button4;
    TOpenDialog *OpenDialog1;
    TSaveDialog *SaveDialog1;
    TLabel *Label1;
    TEdit *Edit1;
    TButton *Button5;
    TCheckBox *autoFindCoefFormy;
        TPopupMenu *PopupMenu1;
        TMenuItem *Save1;
        TEdit *Edit2;
        TEdit *Edit3;
        TEdit *Edit4;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TTabSheet *TabSheet3;
        TMemo *Memo1;
        TButton *Button7;
        TButton *Button6;
        TButton *Button1;
        TGroupBox *GroupBox5;
        TImage *Image1;
        TGroupBox *GroupBox6;
        TPanel *Panel1;
        TMemo *Memo2;
        TLabel *Label5;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall Button3Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Save1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
