//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <ActnList.hpp>
#include <StdActns.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
        TButton *Button1;
        TListBox *ListBox1;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TActionList *ActionList1;
        TFileOpen *FileOpen1;
        TFileSaveAs *FileSaveAs1;
        TLabel *Label5;
        TEdit *Edit1;
        TLabel *Label6;
        TEdit *Edit2;
        TLabel *Label7;
        TEdit *Edit3;
        TButton *Button7;
        TButton *Button8;
        TTimer *Timer1;
        TButton *Button9;
        TTimer *Timer2;
        TPanel *Panel1;
        TImage *Image1;
        TLabel *Label1;
        TImage *Image5;
        TImage *Image6;
        TImage *Image7;
        TImage *Image8;
        TImage *Image9;
        TImage *Image10;
        TImage *Image11;
        TImage *Image12;
        TImage *Image13;
        TImage *Image14;
        TImage *Image15;
        TImage *Image16;
        TImage *Image17;
        TImage *Image18;
        TImage *Image19;
        TImage *Image20;
        TImage *Image69;
        TImage *Image70;
        TImage *Image3;
        TLabel *Label3;
        TImage *Image37;
        TImage *Image38;
        TImage *Image39;
        TImage *Image40;
        TImage *Image41;
        TImage *Image42;
        TImage *Image43;
        TImage *Image44;
        TImage *Image45;
        TImage *Image46;
        TImage *Image47;
        TImage *Image48;
        TImage *Image49;
        TImage *Image50;
        TImage *Image51;
        TImage *Image52;
        TImage *Image2;
        TLabel *Label2;
        TImage *Image21;
        TImage *Image22;
        TImage *Image23;
        TImage *Image24;
        TImage *Image25;
        TImage *Image26;
        TImage *Image27;
        TImage *Image28;
        TImage *Image29;
        TImage *Image30;
        TImage *Image31;
        TImage *Image32;
        TImage *Image33;
        TImage *Image34;
        TImage *Image35;
        TImage *Image36;
        TImage *Image4;
        TLabel *Label4;
        TImage *Image53;
        TImage *Image54;
        TImage *Image55;
        TImage *Image56;
        TImage *Image57;
        TImage *Image58;
        TImage *Image59;
        TImage *Image60;
        TImage *Image61;
        TImage *Image62;
        TImage *Image63;
        TImage *Image64;
        TImage *Image65;
        TImage *Image66;
        TImage *Image67;
        TImage *Image68;
        TPanel *Panel2;
        TLabel *Label9;
        TLabel *Label10;
        TComboBox *ComboBox1;
        TLabel *Label8;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TButton *Button10;
        TButton *Button6;
        TCheckBox *CheckBox1;
        TButton *Button2;
        TEdit *Edit4;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Image5Click(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall FileOpen1Accept(TObject *Sender);
        void __fastcall FileSaveAs1Accept(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall ComboBox1Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Edit2Change(TObject *Sender);
        void __fastcall Edit3Change(TObject *Sender);
        void __fastcall Edit4KeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);

private:	// Anwender-Deklarationen
//void __fastcall FormPaint(TObject *Sender);
public:		// Anwender-Deklarationen
        __fastcall TForm1(TComponent* Owner);
};

	DWORD m_DefaultCamera;
	DWORD m_MyCamera[3];
	DWORD m_CurrentCamera;
	double m_Degrees;
	DWORD m_Cube[64];
        DWORD Stab[48];
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
