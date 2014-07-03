//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <3DSTATE.H>
//---------------------------------------------------------^^------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int Max=0;
int Selected=0;
int Data[5000][66];
void Load_Dat(int ID);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
for (int i=0;i<5000;i++)
for (int b=0;b<66;b++){
Data[i][b]=0;
}

FileOpen1->Dialog->InitialDir=ExtractFilePath(Application->ExeName);
FileSaveAs1->Dialog->InitialDir=ExtractFilePath(Application->ExeName);

Form1->Left=0;
Form1->Top=0;
ComboBox1->ItemIndex=0;

Button2->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//STATE_IMPORT DWORD STATE_WINAPI STATE_object_get_polygon(DWORD object_handle, char *polygons_name);
//STATE_IMPORT int STATE_WINAPI STATE_object_get_number_of_polygons(DWORD object_handle);

int answer = STATE_engine_load_world("World8.wld",
                                           "Worlds",
                                           "Worlds/Bitmaps",
                                            USER_DEFINED_BEHAVIOR);
    if(answer != OK)
    {
         ShowMessage("Failed to load world, aborting.\nLook at error.log to see why");
         Close();
         return;
    }


String q = "LED_"+IntToStr(0);
m_Cube[0] = STATE_object_get_object_using_name(q.c_str());

for (int i=1;i<64;i++){
m_Cube[i]=STATE_object_duplicate(m_Cube[0], YES);
}

DWORD STATE_bmp=STATE_bitmap_load("rot.bmp",-1 );        //GLASS0.jpg
for (int i=0;i<64;i++){
STATE_object_disable(m_Cube[i]);
STATE_object_set_location(m_Cube[i],  -300+(i%4*75) ,-225-((i/4)%4*75) , (225-(((int) i/16)*75)));
STATE_object_set_bitmap(m_Cube[i], STATE_bmp);
}

Stab[0] = STATE_object_get_object_using_name("Stab_0");
for (int i=1;i<48;i++)Stab[i]=STATE_object_duplicate(Stab[0], YES);

for (int i=0;i<16;i++){
STATE_object_rotate_x(Stab[i], -9, 0);
STATE_object_rotate_z(Stab[i], -11, 0);
STATE_object_set_location(Stab[i],  -300+(i%4*75) ,-350+10, (225-(((int) i/4)*75)));

STATE_object_rotate_x(Stab[i+16], -9, 0);
STATE_object_rotate_z(Stab[i+16], -11-90, 0);
STATE_object_set_location(Stab[i+16],  -300+75+25+12 ,-350+(i%4*75)-75-25, (225-(((int) i/4)*75)));

STATE_object_rotate_x(Stab[i+32], -9-90, 0);
STATE_object_rotate_z(Stab[i+32], -11-90, 0);

STATE_object_rotate_x(Stab[i+32], -11, 0);
STATE_object_set_location(Stab[i+32],  -300+(i%4*75)+2.5 ,-225-((i/4)%4*75), (225-75-25-12.5));//(((int) i/4)*75)
}

for (int i=0;i<48;i++){
        int num_of_polys=STATE_object_get_number_of_polygons(Stab[i]);
DWORD *poly_array=(DWORD *)malloc(num_of_polys*sizeof(DWORD));
STATE_object_get_all_polygons(Stab[i], poly_array);
for (int b=0;b<num_of_polys;b++){
STATE_polygon_set_translucent(poly_array[b], CONTROL_GLASS);
}
}

    //Gets Default Camera.
    m_DefaultCamera = STATE_camera_get_default_camera();

    m_CurrentCamera = m_DefaultCamera;

    STATE_3D_card_use(YES);

  STATE_engine_set_picture_quality(1024*768);
  
//Label1->Hide();
//Label2->Hide();
//Label3->Hide();
//Label4->Hide();
Label5->Hide();
Label6->Hide();
Label7->Hide();
//Label8->Hide();
 Label9->Hide();

Button1->Hide();
//Button2->Hide();
Button3->Hide();
Button4->Hide();
Button5->Hide();
//Button6->Hide();
Button7->Hide();
Button8->Hide();

Edit1->Hide();
Edit2->Hide();
Edit3->Hide();
//Edit4->Hide();
//ComboBox1->Hide();
//ListBox1->Hide();
//Image1->Hide();
//Image2->Hide();
//Image3->Hide();
//Image4->Hide();
//CheckBox1->Hide();
//SpeedButton1->Hide();
//SpeedButton2->Hide();
 /*TImage *Dat[64] = {Form1->Image5,Form1->Image6,Form1->Image7,Form1->Image8,Form1->Image9,Form1->Image10,Form1->Image11,Form1->Image12,Form1->Image13,Form1->Image14,Form1->Image15,Form1->Image16,Form1->Image17,Form1->Image18,Form1->Image19,Form1->Image20,Form1->Image21,Form1->Image22,Form1->Image23,Form1->Image24,Form1->Image25,Form1->Image26,Form1->Image27,Form1->Image28,Form1->Image29,Form1->Image30,Form1->Image31,Form1->Image32,Form1->Image33,Form1->Image34,Form1->Image35,Form1->Image36,Form1->Image37,Form1->Image38,Form1->Image39,Form1->Image40,Form1->Image41,Form1->Image42,Form1->Image43,Form1->Image44,Form1->Image45,Form1->Image46,Form1->Image47,Form1->Image48,Form1->Image49,Form1->Image50,Form1->Image51,Form1->Image52,Form1->Image53,Form1->Image54,Form1->Image55,Form1->Image56,Form1->Image57,Form1->Image58,Form1->Image59,Form1->Image60,Form1->Image61,Form1->Image62,Form1->Image63,Form1->Image64,Form1->Image65,Form1->Image66,Form1->Image67,Form1->Image68};
for (int i=0;i<64;i++){
Dat[i]->Hide();
}    */
double x,y,z;
	STATE_camera_get_location(STATE_camera_get_default_camera(), &x,&y,&z);
		y -=350;
		z +=100;
                x-=400;
	STATE_camera_set_location(STATE_camera_get_default_camera(), x, y, z);

Timer1->Enabled=true;
Button9->Click();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
if (CheckBox1->Checked==false){
if (Max>0){
for (int i=0;i<66;i++){
Data[Max][i]=Data[Max-1][i];
}

}
Selected=Max;
ListBox1->Items->Add("A-"+IntToStr(Max));
ListBox1->ItemIndex=Selected;
Data[Selected][64]=125;
Data[Selected][65]=(ComboBox1->ItemIndex+1)*10;
}
else
{
if (Max>0){


// Umsortieren
for (int i=Max-1;i > Selected;i--){
for (int b=0;b<66;b++){
Data[i][b]=Data[i-1][b];
}
}
}

for (int i=0;i<66;i++){
Data[Selected+1][i]=Data[Selected][i];
}
Selected++;
ListBox1->Items->Insert(Selected,"A-"+IntToStr(Selected)+"C");
ListBox1->ItemIndex=Selected;
Data[Selected][64]=125;
Data[Selected][65]=100;
}
Load_Dat(Selected);
Max++;
}
//---------------------------------------------------------------------------

void Load_Dat(int ID){
 TImage *Dat[64] = {Form1->Image5,Form1->Image6,Form1->Image7,Form1->Image8,Form1->Image9,Form1->Image10,Form1->Image11,Form1->Image12,Form1->Image13,Form1->Image14,Form1->Image15,Form1->Image16,Form1->Image17,Form1->Image18,Form1->Image19,Form1->Image20,Form1->Image21,Form1->Image22,Form1->Image23,Form1->Image24,Form1->Image25,Form1->Image26,Form1->Image27,Form1->Image28,Form1->Image29,Form1->Image30,Form1->Image31,Form1->Image32,Form1->Image33,Form1->Image34,Form1->Image35,Form1->Image36,Form1->Image37,Form1->Image38,Form1->Image39,Form1->Image40,Form1->Image41,Form1->Image42,Form1->Image43,Form1->Image44,Form1->Image45,Form1->Image46,Form1->Image47,Form1->Image48,Form1->Image49,Form1->Image50,Form1->Image51,Form1->Image52,Form1->Image53,Form1->Image54,Form1->Image55,Form1->Image56,Form1->Image57,Form1->Image58,Form1->Image59,Form1->Image60,Form1->Image61,Form1->Image62,Form1->Image63,Form1->Image64,Form1->Image65,Form1->Image66,Form1->Image67,Form1->Image68};

 if (Selected< Form1->ComboBox1->Items->Count){
  if ((Data[Selected][65]/10)-1>=0 && (Data[Selected][65]/10)-1<Form1->ComboBox1->Items->Count){
  Form1->ComboBox1->ItemIndex =  (Data[Selected][65]/10)-1;
  }
   else
   Form1->ComboBox1->ItemIndex=0;

  Form1->Edit4->Text=Form1->ListBox1->Items->Strings[Selected];
  }
  else{

  Form1->Edit4->Text="";
  }


 for (int i=0;i<64;i++){
Form1->Edit2->Text=IntToStr(Data[Selected][64]);
Form1->Edit3->Text=IntToStr(Data[Selected][65]);
if (Data[Selected][i] == 0){
Dat[i]->Picture = Form1->Image70->Picture;
}
else
{
Dat[i]->Picture = Form1->Image69->Picture;
}
}
}


void __fastcall TForm1::Image5Click(TObject *Sender)
{
TImage *Dat[64] = {Image5,Image6,Image7,Image8,Image9,Image10,Image11,Image12,Image13,Image14,Image15,Image16,Image17,Image18,Image19,Image20,Image21,Image22,Image23,Image24,Image25,Image26,Image27,Image28,Image29,Image30,Image31,Image32,Image33,Image34,Image35,Image36,Image37,Image38,Image39,Image40,Image41,Image42,Image43,Image44,Image45,Image46,Image47,Image48,Image49,Image50,Image51,Image52,Image53,Image54,Image55,Image56,Image57,Image58,Image59,Image60,Image61,Image62,Image63,Image64,Image65,Image66,Image67,Image68};
if (Max>Selected){
for (int i=0;i<64;i++){
if (Dat[i]==Sender){
if (Data[Selected][i] == 0){
Dat[i]->Picture = Image69->Picture;
Data[Selected][i]=1;
}
else
{
Dat[i]->Picture = Image70->Picture;
Data[Selected][i]=0;
}
break;
}}
}
else
ShowMessage("Es existiert keine Animation!");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
Selected = ListBox1->ItemIndex;

Load_Dat(Selected);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
TStringList *List = new TStringList();
List->Add(Edit1->Text+"_Anz: .db "+IntToStr(Max)+",0");
List->Add(Edit1->Text+":");

for (int i=0;i<Max;i++){
String a = ".db ";
for (int b=0;b<64;b++){
if (b%8==0){
a=a+"0b";
}
a=a+IntToStr(Data[i][-1+(((int) b/8)+1)*8-b%8]);
if (b%8==7){
a=a+",";
}
}
a = a+IntToStr(Data[i][64])+","+IntToStr(Data[i][65]);
List->Add(a);
}
List->SaveToFile(ExtractFilePath(Application->ExeName)+Edit1->Text+".asm");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
FileOpen1->Dialog->FileName="";
FileOpen1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
FileSaveAs1->Dialog->FileName="";
FileSaveAs1->Execute();        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FileOpen1Accept(TObject *Sender)
{
String a = FileOpen1->Dialog->FileName;
if (a!=""){
// Öffnen
if (ExtractFileExt(a).UpperCase()!=".AD")a=a.SubString(1,a.Length()-ExtractFileExt(a).Length())+".ad";
TStringList *Liste = new TStringList();
Liste->LoadFromFile(a);

Max = StrToInt(Liste->Strings[0]);
Edit1->Text=Liste->Strings[1];
ListBox1->Clear();
Liste->Delete(0);
Liste->Delete(0);
for (int i=0;i<Max;i++){
ListBox1->Items->Add(Liste->Strings[i*67]);

for (int b=0;b<66;b++){
Data[i][b] = StrToInt(Liste->Strings[i*67 + b + 1]);
}
}
ListBox1->ItemIndex=0;
Selected = ListBox1->ItemIndex;
Load_Dat(Selected);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FileSaveAs1Accept(TObject *Sender)
{
String a = FileSaveAs1->Dialog->FileName;
if (a!=""){
// Speichern
if (ExtractFileExt(a).UpperCase()!=".AD")a=a.SubString(1,a.Length()-ExtractFileExt(a).Length())+".ad";
TStringList *List = new TStringList();
List->Add(IntToStr(Max));
List->Add(Edit1->Text);
for (int i=0;i<Max;i++){
List->Add(ListBox1->Items->Strings[i]);
for (int b=0;b<66;b++){
List->Add(IntToStr(Data[i][b]));
}
}
List->SaveToFile(a);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
// Löschen
if (Max>Selected){
for (int i=Selected;i<Max-1;i++){
ListBox1->Items->Strings[i] = ListBox1->Items->Strings[i+1];
for (int b=0;b<66;b++){
Data[i][b] = Data[i+1][b];
}

}
ListBox1->Items->Delete(ListBox1->Count-1);
Max--;
if (Selected==Max)Selected--;
Load_Dat(Selected);
ListBox1->ItemIndex=Selected;
}
else
ShowMessage("Es existiert keine Animation!");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Click(TObject *Sender)
{
Edit2->Text="125";
Edit3->Text=IntToStr((ComboBox1->ItemIndex+1)*10);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
for (int i=0;i<Max;i++){
Data[i][65]=(ComboBox1->ItemIndex+1)*10;
}
Edit3->Text=IntToStr((ComboBox1->ItemIndex+1)*10);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button8Click(TObject *Sender)
{
for (int i=0;i<Max;i++){
Data[i][65]=StrToInt(Edit3->Text);
}
}
//---------------------------------------------------------------------------

int Posi;

void Next_Anim(int ID);
bool oldF2 = false;
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
Form1->SetFocus();

if(GetAsyncKeyState(VK_F2) < 0 && oldF2==false){
// show/hide level Panel
if (Panel1->Visible){
Panel1->Hide();
Panel2->Hide();
ListBox1->Hide();
}
else     {
Panel1->Show();
 Panel2->Show();
 ListBox1->Show();
}
oldF2=true;
}
else
oldF2=false;



	if(GetAsyncKeyState(VK_ESCAPE) < 0){
        // Beenden
Timer1->Enabled=false;
Timer2->Enabled=false;
        Label1->Show();
Label2->Show();
Label3->Show();
Label4->Show();
//Label5->Show();
//Label6->Show();
//Label7->Show();
Label8->Show();
Label9->Show();

Button1->Show();
Button2->Show();
//Button3->Show();
Button4->Show();
Button5->Show();
Button6->Show();
Panel1->Show();
Panel2->Show();
//Button7->Show();
//Button8->Show();

//Edit1->Show();
//Edit2->Show();
//Edit3->Show();
Edit4->Show();

SpeedButton1->Show();
SpeedButton2->Show();

ComboBox1->Show();
ListBox1->Show();
Image1->Show();
Image2->Show();
Image3->Show();
Image4->Show();
CheckBox1->Show();
 TImage *Dat[64] = {Form1->Image5,Form1->Image6,Form1->Image7,Form1->Image8,Form1->Image9,Form1->Image10,Form1->Image11,Form1->Image12,Form1->Image13,Form1->Image14,Form1->Image15,Form1->Image16,Form1->Image17,Form1->Image18,Form1->Image19,Form1->Image20,Form1->Image21,Form1->Image22,Form1->Image23,Form1->Image24,Form1->Image25,Form1->Image26,Form1->Image27,Form1->Image28,Form1->Image29,Form1->Image30,Form1->Image31,Form1->Image32,Form1->Image33,Form1->Image34,Form1->Image35,Form1->Image36,Form1->Image37,Form1->Image38,Form1->Image39,Form1->Image40,Form1->Image41,Form1->Image42,Form1->Image43,Form1->Image44,Form1->Image45,Form1->Image46,Form1->Image47,Form1->Image48,Form1->Image49,Form1->Image50,Form1->Image51,Form1->Image52,Form1->Image53,Form1->Image54,Form1->Image55,Form1->Image56,Form1->Image57,Form1->Image58,Form1->Image59,Form1->Image60,Form1->Image61,Form1->Image62,Form1->Image63,Form1->Image64,Form1->Image65,Form1->Image66,Form1->Image67,Form1->Image68};
for (int i=0;i<64;i++){
Dat[i]->Show();
}
STATE_engine_close();
return;
        }

        if(GetAsyncKeyState(VK_SPACE) < 0){
        // Neustart
        //Posi=0;
        //Next_Anim(Posi);
        //




        }




double x=0,y=0,z=0;

	//Gets camera's location coordinates 
       //	STATE_camera_get_location(STATE_camera_get_default_camera(), &x,&y,&z);
        
if(GetAsyncKeyState(VK_UP) < 0) // move camera up
		STATE_camera_rotate_y(STATE_camera_get_default_camera(), -3, CAMERA_SPACE);
	if(GetAsyncKeyState(VK_DOWN) < 0) // move camera down
		STATE_camera_rotate_y(STATE_camera_get_default_camera(), +3, CAMERA_SPACE);
                
	if(GetAsyncKeyState(VK_RIGHT) < 0) // move camera right
	STATE_camera_rotate_z(STATE_camera_get_default_camera(), -3, WORLD_SPACE);//x +=25;
	if(GetAsyncKeyState(VK_LEFT) < 0) // move camera left
	STATE_camera_rotate_z(STATE_camera_get_default_camera(), +3, WORLD_SPACE);//	x -=25;

        if(GetAsyncKeyState('A') < 0) // move camera back
		y -=25;
	if(GetAsyncKeyState('D') < 0) // move camera forward
		y +=25;
                if(GetAsyncKeyState('S') < 0) // move camera back
		x +=25;
	if(GetAsyncKeyState('W') < 0) // move camera forward
		x -=25;

	if(GetAsyncKeyState('F') < 0) // move camera back
		z +=25;
	if(GetAsyncKeyState('B') < 0) // move camera forward
		z -=25;

       //	STATE_camera_set_location(STATE_camera_get_default_camera(), x, y, z);
        STATE_camera_move(STATE_camera_get_default_camera(), CAMERA_SPACE, x, y, z);

    if (STATE_engine_is_engine_empty())
        return;

     // Puts the image seen from the camera on the window.
    // STATE_engine_render(Handle,m_CurrentCamera);
    STATE_engine_render(Handle,STATE_camera_get_default_camera());

     //STATE_IMPORT int STATE_WINAPI STATE_camera_move_with_collision_detection(DWORD camera, double wanted_location[3], double camera_physical_width);
//STATE_IMPORT void STATE_WINAPI STATE_object_move(DWORD object_handle, int space_flag, double x, double y, double z);

}
//---------------------------------------------------------------------------

void Next_Anim(int ID){
Form1->Timer2->Interval=1000*((double) Data[Posi][64]*Data[Posi][65]/12500);
for (int i=0;i<64;i++){
if (Data[Posi][i]==0){
STATE_object_disable(m_Cube[i]);
}
else
STATE_object_enable(m_Cube[i]);
}

Posi++;
if (Posi>=Max)Posi=0;
}

void __fastcall TForm1::Button9Click(TObject *Sender)
{
Button9->Hide();
Posi=0;
   //STATE_object_disable(m_Cube);
Timer2->Interval=1000;
Timer2->Enabled=true;

/*for (int i=0;i<64;i++){
     int num_of_polys=STATE_object_get_number_of_polygons(m_Cube[i]);
DWORD *poly_array=(DWORD *)malloc(num_of_polys*sizeof(DWORD));
STATE_object_get_all_polygons(m_Cube[i], poly_array);
for (int b=0;b<num_of_polys;b++){
STATE_polygon_set_translucent(poly_array[b], NORMAL_GLASS);
}
}*/
//Timer3->Enabled=true;

}

//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
Next_Anim(Posi);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
if (Selected>0){
for (int i=0;i<66;i++){
int a = Data[Selected][i];
Data[Selected][i] = Data[Selected-1][i];
Data[Selected-1][i] = a;
}
String a = ListBox1->Items->Strings[Selected-1];
ListBox1->Items->Strings[Selected-1]=ListBox1->Items->Strings[Selected];
ListBox1->Items->Strings[Selected] = a;
Selected--;
ListBox1->ItemIndex=Selected;
Load_Dat(Selected);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
if (Selected<=Max-2){
for (int i=0;i<66;i++){
int a = Data[Selected][i];
Data[Selected][i] = Data[Selected+1][i];
Data[Selected+1][i] = a;
}
String a = ListBox1->Items->Strings[Selected+1];
ListBox1->Items->Strings[Selected+1]=ListBox1->Items->Strings[Selected];
ListBox1->Items->Strings[Selected] = a;
Selected++;
ListBox1->ItemIndex=Selected;
Load_Dat(Selected);
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
//STATE_engine_close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
ComboBox1->ItemIndex=0;
ComboBox1->OnClick(NULL);        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
Data[Selected][64]=StrToInt(Edit2->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Change(TObject *Sender)
{
Data[Selected][65]=StrToInt(Edit3->Text);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Edit4KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Selected>=0 && Selected<Form1->ListBox1->Items->Count)
Form1->ListBox1->Items->Strings[Selected]=Form1->Edit4->Text;
}
//---------------------------------------------------------------------------

