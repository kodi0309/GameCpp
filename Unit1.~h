//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TKodiGame : public TForm
{
__published:	// IDE-managed Components
        TShape *Rocket;
        TShape *Board;
        TLabel *Info;
        TTimer *Timer1;
        TLabel *GameName;
        TLabel *BallCounter;
        TShape *Hell;
        TButton *PlayAgain;
        TLabel *Rules;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *TopScoreInf;
        void __fastcall BoardMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall RocketMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall PlayAgainClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TKodiGame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKodiGame *KodiGame;
//---------------------------------------------------------------------------
#endif
