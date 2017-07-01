//---------------------------------------------------------------------------

#ifndef ColorProgressBarH
#define ColorProgressBarH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Themes.hpp>
#include <ColorProgressBarStyleHook.h>
//---------------------------------------------------------------------------
class TColorProgressBarStyleHook;
class PACKAGE TColorProgressBar : public TProgressBar
{
private:
    bool FBarGray;
    System::Uitypes::TColor FBarHorzGradientColorBright;
    System::Uitypes::TColor FBarHorzGradientColorDark;
    System::Uitypes::TColor FBarVertGradientColorBright;
    System::Uitypes::TColor FBarVertGradientColorDark;
	float FBarVertGradientPosition;
    int FBarPositionWidth;

protected:
    void __fastcall SetBarVertGradientPosition(float PValue);
    void __fastcall SetBarPositionWidth(int PValue);
public:
    __fastcall TColorProgressBar(TComponent* Owner);
__published:
	__property bool BarGray = {read=FBarGray, write=FBarGray};
	__property System::Uitypes::TColor BarHorzGradientColorBright = {read=FBarHorzGradientColorBright, write=FBarHorzGradientColorBright, default=Vcl::Graphics::clWhite};
	__property System::Uitypes::TColor BarHorzGradientColorDark = {read=FBarHorzGradientColorDark, write=FBarHorzGradientColorDark, default=Vcl::Graphics::clGray};
	__property float BarVertGradientPosition = {read=FBarVertGradientPosition, write=SetBarVertGradientPosition};
	__property System::Uitypes::TColor BarVertGradientColorBright = {read=FBarVertGradientColorBright, write=FBarVertGradientColorBright, default=Vcl::Graphics::clWhite};
	__property System::Uitypes::TColor BarVertGradientColorDark = {read=FBarVertGradientColorDark, write=FBarVertGradientColorDark, default=Vcl::Graphics::clBlack};
	__property int BarPositionWidth = {read=FBarPositionWidth, write=SetBarPositionWidth, default=25};
};
//---------------------------------------------------------------------------
#endif
