//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "ColorProgressBarStyleHook.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

static inline void ValidCtrCheck(TColorProgressBarStyleHook *)
{
    new TColorProgressBarStyleHook(NULL);
}
//---------------------------------------------------------------------------
__fastcall TColorProgressBarStyleHook::TColorProgressBarStyleHook(Vcl::Controls::TWinControl* AControl)
    : TProgressBarStyleHook(AControl)
{
if (!AControl->ClassNameIs(TColorProgressBar::ClassName()) && !AControl->ClassNameIs(TProgressBar::ClassName()))
   {
   //this style work only for TColorProgressBar and TProgress
   throw Exception("TColorProgressBarStyleHook ne s'applique qu'aux TProgressBar et TColorProgressBar");
   }
}
//---------------------------------------------------------------------------
void __fastcall TColorProgressBarStyleHook::PaintBar(Vcl::Graphics::TCanvas* Canvas)
{
TProgressBar* ProgressBar = NULL;
if (this->Control->ClassNameIs(TProgressBar::ClassName()))
   {
   ProgressBar = (TProgressBar *)this->Control;
   }
TColorProgressBar* ColorProgressBar = NULL;
if (this->Control->ClassNameIs(TColorProgressBar::ClassName()))
   {
   ColorProgressBar = (TColorProgressBar *)this->Control;
   }
if (ProgressBar != NULL)
   {
   if (ProgressBar->BarColor == Vcl::Graphics::clDefault)
      {
      TProgressBarStyleHook::PaintBar(Canvas);
      return;
      }
   }
if (ColorProgressBar != NULL)
   {
   if (ColorProgressBar->BarColor == Vcl::Graphics::clDefault)
      {
      TProgressBarStyleHook::PaintBar(Canvas);
      return;
      }
   }

TRect FillR;
int W, Pos;
if (!StyleServices()->Available)
   {
   return;
   }
FillR = BarRect;
InflateRect(FillR, -1, -1);
if (Orientation == pbHorizontal)
   {
   W = FillR.Width();
   }
else {
     W = FillR.Height();
     }
Pos = RoundTo(W * GetPercent(), 0);
FillR.Right = FillR.Left + Pos;

if (ProgressBar != NULL)
   {
   SmoothGradient(Canvas, FillR, ProgressBar->BarColor, false);
   }
else {
     SmoothGradient(Canvas, FillR, ColorProgressBar->BarColor, ColorProgressBar->BarGray, ColorProgressBar->BarHorzGradientColorBright,
       ColorProgressBar->BarHorzGradientColorDark, ColorProgressBar->BarVertGradientColorBright, ColorProgressBar->BarVertGradientColorDark,
       ColorProgressBar->BarVertGradientPosition, ColorProgressBar->BarPositionWidth);
     }
}
//---------------------------------------------------------------------------
float __fastcall TColorProgressBarStyleHook::GetPercent()
{
float LMin, LMax, LPos;
LMin = Min;
LMax = Max;
LPos = Position;
if ((LMin >= 0) && (LPos >= LMin) && (LMax >= LPos) && (LMax - LMin != 0))
   {
   return (LPos - LMin) / (LMax - LMin);
   }
else {
     return 0;
     }
}
//---------------------------------------------------------------------------
bool __fastcall TColorProgressBarStyleHook::RegisterStyleHook()
{
bool Result = true;
TColorProgressBar* Temp = NULL;
TColorProgressBarStyleHook* Temp2 = NULL;
try {
    try {
        Temp = new TColorProgressBar(NULL);
        Temp2 = new TColorProgressBarStyleHook(Temp);
        TCustomStyleEngine::RegisterStyleHook(Temp->ClassType(), Temp2->ClassType());
        }
    catch (...)
          {
          Result = false;
          }
    }
__finally {
          if (Temp != NULL)
             {
             try {
                 delete Temp;
                 }
             catch (...)
                   {
                   }
             Temp = NULL;
             }
          if (Temp2 != NULL)
             {
             try {
                 delete Temp2;
                 }
             catch (...)
                   {
                   }
             Temp2 = NULL;
             }
          }
TProgressBar* Temp3 = NULL;
try {
    try {
        Temp3 = new TProgressBar((System::Classes::TComponent *)NULL);
        Temp2 = new TColorProgressBarStyleHook(Temp3);
        TCustomStyleEngine::RegisterStyleHook(Temp3->ClassType(), Temp2->ClassType());
        }
    catch (...)
          {
          Result = false;
          }
    }
__finally {
          if (Temp3 != NULL)
             {
             try {
                 delete Temp3;
                 }
             catch (...)
                   {
                   }
             Temp3 = NULL;
             }
          if (Temp2 != NULL)
             {
             try {
                 delete Temp2;
                 }
             catch (...)
                   {
                   }
             Temp2 = NULL;
             }
          }
return Result;
}
//---------------------------------------------------------------------------
bool __fastcall TColorProgressBarStyleHook::UnRegisterStyleHook()
{
bool Result = true;
TColorProgressBar* Temp = NULL;
TColorProgressBarStyleHook* Temp2 = NULL;
try {
    try {
        Temp = new TColorProgressBar(NULL);
        Temp2 = new TColorProgressBarStyleHook(Temp);
        TCustomStyleEngine::UnRegisterStyleHook(Temp->ClassType(), Temp2->ClassType());
        }
    catch (...)
          {
          Result = false;
          }
    }
__finally {
          if (Temp != NULL)
             {
             try {
                 delete Temp;
                 }
             catch (...)
                   {
                   }
             Temp = NULL;
             }
          if (Temp2 != NULL)
             {
             try {
                 delete Temp2;
                 }
             catch (...)
                   {
                   }
             Temp2 = NULL;
             }
          }
TProgressBar* Temp3 = NULL;
try {
    try {
        Temp3 = new TProgressBar((System::Classes::TComponent *)NULL);
        Temp2 = new TColorProgressBarStyleHook(Temp3);
        TCustomStyleEngine::UnRegisterStyleHook(Temp3->ClassType(), Temp2->ClassType());
        }
    catch (...)
          {
          Result = false;
          }
    }
__finally {
          if (Temp3 != NULL)
             {
             try {
                 delete Temp3;
                 }
             catch (...)
                   {
                   }
             Temp3 = NULL;
             }
          if (Temp2 != NULL)
             {
             try {
                 delete Temp2;
                 }
             catch (...)
                   {
                   }
             Temp2 = NULL;
             }
          }
return Result;
}
//---------------------------------------------------------------------------
