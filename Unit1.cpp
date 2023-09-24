//---------------------------------------------------------------------------

#include <vcl.h>
#include <string>
#include <windows.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKodiGame *KodiGame;
//---------------------------------------------------------------------------
        //sizes
                //dims
                //window 1300x680px
                //board left: 100px, top: 20px, right: 700px, bottom: 620px;

                //board
                int boardHeight = 600;
                int boardWidth = 600;
                //rocket
                int rocketHeight = 20;
                int rocketWidth = 100;
                //ball
                int ballHeight = 25;
                int ballWidth = 50;
                //space
                int leftSpace = 100;
                int topSpace = 20;
                //box
                int boxHeight = 5;
                int boxWidth = 100;
                //it
                int i=0;
                int b=0;
                int t=0;
                int activeBalls=0;
                //f
                int f=0;
                int topScore = 1;
                int lastAB;




        //class
        class MBall
        {
                public:
                int ID, px, py, vx, vy;

                TShape *newBall;

                void ballMove();

                MBall();
                ~MBall();
        };

                //obj
                MBall *OBall[500];

        class Box
        {
                public:
                int px, py;

                TShape *newBox;

                void chPos();

                Box();
                ~Box();
        };
                //obj
                Box *OBox[5];

        //fcn
        int rocketMove(int lSpace)
        {
                TPoint p = Mouse->CursorPos;
                KodiGame->ScreenToClient(p);

                int pos;
                int space = lSpace;
                int cor = KodiGame->Left;
                int pRel=p.x-cor;

                if(pRel>boardWidth-rocketWidth/2+space)
                {
                pos=boardWidth;
                }
                else if(pRel<space+rocketWidth/2)
                {
                pos=space;
                }
                else
                {
                pos=pRel - rocketWidth/2;
                };
                return pos;
        };

        MBall::MBall()
        {
                ID = i;

                px=random(boardWidth-ballWidth)+leftSpace;
                py=random(boardHeight/2)+topSpace;

                vx=3;
                vy=3;

                newBall = new TShape(KodiGame);
                newBall -> Parent = KodiGame;
                newBall -> Left = px;
                newBall -> Top = py;
                newBall -> Width = ballWidth;
                newBall -> Height = ballHeight;
                newBall -> Shape = stCircle;
                newBall -> Brush -> Color = (TColor) 0x806032;

                activeBalls++;
                i++;
        };

        MBall::~MBall()
        {
                //delete(newBall);
        };


        void Box::chPos()
        {
                        newBox->Left=rand()%(boardWidth-boxWidth)+leftSpace;
                        t++;
        };

        Box::Box()
        {
                px=rand()%(boardWidth-boxWidth)+leftSpace;
                py=21;

                newBox = new TShape(KodiGame);
                newBox -> Parent = KodiGame;
                newBox -> Left = px;
                newBox -> Top = py;
                newBox -> Width = boxWidth;
                newBox -> Height = boxHeight;
                newBox -> Shape = stRectangle;
                newBox -> Brush -> Color = (TColor) 0x109932;

                b++;
        };

        Box::~Box()
        {
                //void
        };

        void MBall::ballMove()
        {
               int ptX = newBall -> Left;
               int ptY = newBall -> Top;

               if (ptX >= leftSpace+boardWidth-3*ballWidth/4 || ptX <= leftSpace-ballWidth/4)
               {
                        vx = -vx;
               };

               if (ptY < topSpace)
               {
                        vy=-vy;
               };

               if (ptY > boardHeight-boardHeight/20-rocketHeight-2 && ptY < boardHeight-boardHeight/20-rocketHeight+2 && ptX >= rocketMove(leftSpace)-3*ballWidth/4 && ptX < rocketMove(leftSpace)+rocketWidth-ballWidth/4)
               {
                        f=0;
                        vy=-vy;
               };

               if (ptY >= boardHeight-boardHeight/20-rocketHeight+2 && ptY < boardHeight-boardHeight/20 && ptX >= rocketMove(leftSpace)-3*ballWidth/4 && ptX < rocketMove(leftSpace)+rocketWidth-ballWidth/4)
               {
                        vx = -vx;
               };

               if (ptY >= topSpace+boardHeight && ptY <= topSpace+boardHeight+2) // delete lost Ball
               {
                        f=0;
                        activeBalls--;
               };

               ptX = ptX + vx;
               px=ptX;
               newBall -> Left = ptX;

               ptY = ptY + vy;
               py=ptY;
               newBall -> Top = ptY;
        };

      

//---------------------------------------------------------------------------
__fastcall TKodiGame::TKodiGame(TComponent* Owner)
        : TForm(Owner)
{
        Board->Width=boardWidth;
        Board->Height=boardHeight;
        Board->Left=leftSpace;

        Rocket->Width=rocketWidth;
        Rocket->Height=rocketHeight;
        Rocket->Top=boardHeight-boardHeight/20;

        Hell ->Brush->Color=(TColor) 0xff8080;

        OBall[i] = new MBall;  //start Ball
        OBox[0] = new Box;

}
//---------------------------------------------------------------------------
void __fastcall TKodiGame::BoardMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        Rocket->Left=rocketMove(leftSpace);
}
//---------------------------------------------------------------------------

void __fastcall TKodiGame::RocketMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
        Rocket->Left=rocketMove(leftSpace);
}
//---------------------------------------------------------------------------


void __fastcall TKodiGame::Timer1Timer(TObject *Sender)
{
        for (int n=0; n<=i; n++)
        {
                if(OBall[n]!= NULL)
                {
                        OBall[n] -> ballMove();

                        if(OBall[n]->py<boxHeight+topSpace && OBall[n]->px+3*ballWidth/4 > OBox[0]->px   &&   OBall[n]->px+ballWidth/4 < OBox[0]->px+boxWidth )
                        {
                                if(OBox[0]!=NULL && f==0)
                                {
                                        OBox[0]->chPos();
                                        OBall[i] = new MBall;
                                        f=1;
                                };
                        };
                };
        };

        String strAB = "Balls in game: " + IntToStr((int)activeBalls);
        BallCounter -> Caption = strAB;

        if(activeBalls == 0)
        {
                PlayAgain -> Cursor = crHandPoint;
                PlayAgain -> Enabled = true;
                PlayAgain -> Caption = "Play Again!";
        };


        if(topScore < activeBalls)
        {
                topScore=activeBalls;
        };

        String strTS = "Top score: " + IntToStr((int)topScore);
        TopScoreInf -> Caption = strTS;

        lastAB = activeBalls;
}
//---------------------------------------------------------------------------

void __fastcall TKodiGame::PlayAgainClick(TObject *Sender)
{
        PlayAgain -> Cursor = crDefault;
        PlayAgain -> Enabled = false;
        PlayAgain -> Caption = "In the game!";

        OBall[i] = new MBall;
}
//---------------------------------------------------------------------------


