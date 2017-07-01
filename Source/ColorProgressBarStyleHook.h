//---------------------------------------------------------------------------

#ifndef ColorProgressBarStyleHookH
#define ColorProgressBarStyleHookH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <ColorProgressBar.h>
#include <System.Math.hpp>
#include "SmoothGraphics.hpp"
//---------------------------------------------------------------------------
class TColorProgressBar;
class PACKAGE TColorProgressBarStyleHook : public TProgressBarStyleHook
{
private:
protected:
	float __fastcall GetPercent();
	virtual void __fastcall PaintBar(Vcl::Graphics::TCanvas* Canvas);
public:
    __fastcall TColorProgressBarStyleHook(Vcl::Controls::TWinControl* AControl);
    static bool __fastcall RegisterStyleHook();
    static bool __fastcall UnRegisterStyleHook();
__published:
};
//---------------------------------------------------------------------------
#endif
