//---------------------------------------------------------------------------

#include <vcl.h>

#pragma hdrstop

#include "ColorProgressBar.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

static inline void ValidCtrCheck(TColorProgressBar *)
{
    new TColorProgressBar(NULL);
}
//---------------------------------------------------------------------------
__fastcall TColorProgressBar::TColorProgressBar(TComponent* Owner)
    : TProgressBar(Owner)
{
FBarGray = false;
FBarHorzGradientColorBright = Vcl::Graphics::clWhite;
FBarHorzGradientColorDark = Vcl::Graphics::clGray;
FBarVertGradientColorBright = Vcl::Graphics::clWhite;
FBarVertGradientColorDark = Vcl::Graphics::clBlack;
FBarVertGradientPosition = 2.25;
FBarPositionWidth = 25;
}
//---------------------------------------------------------------------------
void __fastcall TColorProgressBar::SetBarVertGradientPosition(float PValue)
{
if (PValue <= 0.0)
   {
   PValue = 0.1;
   }
FBarVertGradientPosition = PValue;
}
//---------------------------------------------------------------------------
void __fastcall TColorProgressBar::SetBarPositionWidth(int PValue)
{
if (PValue <= 0)
   {
   PValue = 1;
   }
FBarPositionWidth = PValue;
}
//---------------------------------------------------------------------------
namespace Colorprogressbar
{
    void __fastcall PACKAGE Register()
    {
         TComponentClass classes[1] = {__classid(TColorProgressBar)};
         RegisterComponents(L"Samples", classes, 0);
    }
}
//---------------------------------------------------------------------------
