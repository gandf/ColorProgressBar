{*******************************************************************************
  Author      : Roy Magne Klever (rmklever@gmail.com)
  Created     : Mai 14 2009 (Delphi 2007)
  Version     : 1.0
  Components  : TVistaProBar

  License     : Freeware
*******************************************************************************}
unit SmoothGraphics;

interface

uses
  Windows, SysUtils, Classes, Vcl.Graphics;

function Blend(Color1, Color2: TColor; Value: Byte): TColor;
procedure SmoothGradient(Canvas: TCanvas; const ARect: TRect; const c1: TColor; const Gray: Boolean = False;
  const HorzGradientColorBright: TColor = clWhite; const HorzGradientColorDark: TColor = clGray;
  const VertGradientColorBright: TColor = clWhite; const VertGradientColorDark: TColor = clBlack;
  const PositionHeight: Single = 2.25; const PositionWidth: Integer = 25);

implementation

// Mix two colors (value in percent)

function Blend(Color1, Color2: TColor; Value: Byte): TColor;
var
  i: LongInt;
  r1, g1, b1, r2, g2, b2: byte;
begin
  Value := Round(2.56 * Value);
  i := ColorToRGB(Color2);
  R1 := Byte(i);
  G1 := Byte(i shr 8);
  B1 := Byte(i shr 16);
  i := ColorToRGB(Color1);
  R2 := Byte(i);
  G2 := Byte(i shr 8);
  B2 := Byte(i shr 16);
  R1 := (Value * (R2 - R1)) shr 8 + R1;
  G1 := (Value * (G2 - G1)) shr 8 + G1;
  B1 := (Value * (B2 - B1)) shr 8 + B1;
  Result := (B1 shl 16) + (G1 shl 8) + R1;
end;

procedure SmoothGradient(Canvas: TCanvas; const ARect: TRect; const c1: TColor; const Gray: Boolean;
  const HorzGradientColorBright: TColor; const HorzGradientColorDark: TColor;
  const VertGradientColorBright: TColor; const VertGradientColorDark: TColor;
  const PositionHeight: Single; const PositionWidth: Integer);
type
  PRGB = ^TRGB;
  TRGB = record b, g, r: Byte;
  end;
  PRGBArray = ^TRGBArray;
  TRGBARRAY = array[0..0] of TRGB;
var
  rc1, gc1, bc1, rc2, gc2, bc2, rc3, gc3, bc3, rc4, gc4, bc4: Integer;
  x, y, w, h: Integer;
  i, w1, w2, h1, sp, sm: Integer;
  Row: PRGBArray;
  C: TRGB;
  slMain, slSize, slPtr: Integer;
  Color, tc: Integer;
  Profil: array of TRGB;
  r, g, b: Byte;
  bmp: TBitmap;
begin
  if ((ARect.Right - ARect.Left) - 1 <= 0) or ((ARect.Bottom - ARect.Top) - 1 <= 1) then
    exit;
  bmp := TBitmap.Create;
  bmp.PixelFormat := pf24Bit;
  bmp.Width := (ARect.Right - ARect.Left) - 1;
  bmp.Height := (ARect.Bottom - ARect.Top) - 1;
  h := bmp.Height;
  w := bmp.Width;
  SetLength(Profil, h);
  // Get colors for first gradient
  Color := ColorToRGB(c1);
  if Gray then
  begin
    rc1 := 253;
    gc1 := 253;
    bc1 := 253;
    rc2 := 218;
    gc2 := 218;
    bc2 := 218;
    rc3 := 160;
    gc3 := 160;
    bc3 := 160;
    rc4 := 213;
    gc4 := 213;
    bc4 := 213;
  end
  else
  begin
    tc := Blend(Color, VertGradientColorBright, 5);
    rc1 := Byte(tc);
    gc1 := Byte(tc shr 8);
    bc1 := Byte(tc shr 16);
    tc := Blend(Color, VertGradientColorBright, 50);
    rc2 := Byte(tc);
    gc2 := Byte(tc shr 8);
    bc2 := Byte(tc shr 16);
    tc := Blend(Color, VertGradientColorDark, 60);
    rc3 := Byte(tc);
    gc3 := Byte(tc shr 8);
    bc3 := Byte(tc shr 16);
    tc := Blend(Color, VertGradientColorDark, 80);
    rc4 := Byte(tc);
    gc4 := Byte(tc shr 8);
    bc4 := Byte(tc shr 16);
  end;
  // Calc first gradient
  sp := Trunc(h / PositionHeight);
  y := sp;
  for i := 0 to y - 1 do
  begin
    C.r := Byte(rc1 + (((rc2 - rc1) * (i)) div y));
    C.g := Byte(gc1 + (((gc2 - gc1) * (i)) div y));
    C.b := Byte(bc1 + (((bc2 - bc1) * (i)) div y));
    Profil[i] := C;
  end;
  for i := y to h - 1 do
  begin
    C.r := Byte(rc3 + (((rc4 - rc3) * (i)) div h));
    C.g := Byte(gc3 + (((gc4 - gc3) * (i)) div h));
    C.b := Byte(bc3 + (((bc4 - bc3) * (i)) div h));
    Profil[i] := C;
  end;
  // First gradient done
  if Gray then
  begin
    rc1 := 200;
    gc1 := 200;
    bc1 := 200;
    rc2 := 253;
    gc2 := 253;
    bc2 := 253;
  end
  else
  begin
    tc := Blend(Color, HorzGradientColorDark, 50);
    rc1 := Byte(tc);
    gc1 := Byte(tc shr 8);
    bc1 := Byte(tc shr 16);
    tc := Blend(Color, HorzGradientColorBright, 50);
    rc2 := Byte(tc);
    gc2 := Byte(tc shr 8);
    bc2 := Byte(tc shr 16);
  end;
  w1 := w - 1;
  w := (w shr 1) + (w and 1);
  // Init scanline accsess
  slMain := Integer(bmp.ScanLine[0]);
  slSize := Integer(bmp.ScanLine[1]) - slMain;
  // Paint gradient
  h1 := h shr 1;
  w2 := PositionWidth;
  for x := 0 to w - 1 do
  begin
    if x < w2 then
    begin
      C.b := Byte(bc1 + (((bc2 - bc1) * x) div w2));
      C.g := Byte(gc1 + (((gc2 - gc1) * x) div w2));
      C.r := Byte(rc1 + (((rc2 - rc1) * x) div w2));
    end
    else
    begin
      C.b := bc2;
      C.g := gc2;
      C.r := rc2;
    end;
    slPtr := slMain;
    for y := 0 to h - 1 do
    begin
      Row := PRGBArray(slPtr);
      r := Profil[y].r;
      g := Profil[y].g;
      b := Profil[y].b;
      if x = 0 then
        sm := 3
      else
        sm := 2;
      if (x = 0) or ((y < sp) or (y = h - 1)) then
      begin
        Row[x].r := (C.r - r) shr sm + r;
        Row[x].g := (C.g - g) shr sm + g;
        Row[x].b := (C.b - b) shr sm + b;
      end
      else
      begin
        Row[x].r := (C.r - r) shr 1 + r;
        Row[x].g := (C.g - g) shr 1 + g;
        Row[x].b := (C.b - b) shr 1 + b;
      end;
      if (x < (w1 - x)) then
      begin
        Row[w1 - x].r := Row[x].r;
        Row[w1 - x].g := Row[x].g;
        Row[w1 - x].b := Row[x].b;
      end;
      slPtr := slPtr + slSize;
    end;
  end;
  Profil := nil;
  Canvas.Draw(ARect.Left, Arect.Top, bmp);
  FreeAndNil(bmp);
end;

end.
