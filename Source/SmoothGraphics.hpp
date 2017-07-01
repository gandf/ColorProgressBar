// CodeGear C++Builder
// Copyright (c) 1995, 2013 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'SmoothGraphics.pas' rev: 25.00 (Windows)

#ifndef SmoothgraphicsHPP
#define SmoothgraphicsHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// Pascal unit
#include <SysInit.hpp>	// Pascal unit
#include <Winapi.Windows.hpp>	// Pascal unit
#include <System.SysUtils.hpp>	// Pascal unit
#include <System.Classes.hpp>	// Pascal unit
#include <Vcl.Graphics.hpp>	// Pascal unit

//-- user supplied -----------------------------------------------------------

namespace Smoothgraphics
{
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::Uitypes::TColor __fastcall Blend(System::Uitypes::TColor Color1, System::Uitypes::TColor Color2, System::Byte Value);
extern DELPHI_PACKAGE void __fastcall SmoothGradient(Vcl::Graphics::TCanvas* Canvas, const System::Types::TRect &ARect, const System::Uitypes::TColor c1, const bool Gray = false, const System::Uitypes::TColor HorzGradientColorBright = (System::Uitypes::TColor)(0xffffff), const System::Uitypes::TColor HorzGradientColorDark = (System::Uitypes::TColor)(0x808080), const System::Uitypes::TColor VertGradientColorBright = (System::Uitypes::TColor)(0xffffff), const System::Uitypes::TColor VertGradientColorDark = (System::Uitypes::TColor)(0x0), const float PositionHeight = 2.250000E+00f, const int PositionWidth = 0x19);
}	/* namespace Smoothgraphics */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_SMOOTHGRAPHICS)
using namespace Smoothgraphics;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// SmoothgraphicsHPP
