#include "EntityWriter.h"
#include<iostream>
EntityWriter::EntityWriter(dxfRW &dxfW) : dxfW(dxfW) {
}


void EntityWriter::LineV(int a, int b, int c, int d)
{
    DRW_Line line;
    std::cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
    line.basePoint.x = a;
    line.basePoint.y = b;
    line.secPoint.x = c;
    line.secPoint.y = d;
    dxfW.writeLine(&line);
}



void EntityWriter::Point(int x, int y, string layer)
{
    DRW_Point BPoint;
    DRW_Text tex;
    BPoint.basePoint.x = x;
    BPoint.basePoint.y = y;
    BPoint.layer = layer;
    BPoint.color = 6;
    dxfW.writePoint(&BPoint);
}

void EntityWriter::Arc(int x, int y, double radius, double staangle, double endangle)
{
    DRW_Arc arc;
    arc.basePoint.x = x;
    arc.basePoint.y = y;
    arc.radious = radius;
    arc.staangle = staangle;
    arc.endangle = endangle;
    arc.color = 4;
    arc.layer = "arc";
    dxfW.writeArc(&arc);
}

void EntityWriter::Trace(int a, int b, int c, int d, int e, int f)
{
    DRW_Trace trace;
    trace.basePoint.x = a;
    trace.basePoint.y = b;
    trace.secPoint.x = c;
    trace.secPoint.y = d;
    trace.thirdPoint.x = e;
    trace.thirdPoint.y = f;
    trace.color = 7;
    trace.thickness = 10;
    trace.layer = "trace";
    dxfW.writeTrace(&trace);
}






void EntityWriter::Text(int Height, int Width, string s, int x, int y)
{
    DRW_Text Tex;
    Tex.height = Height;
    Tex.widthscale = Width;
    Tex.text= s;
    Tex.angle=0;
    Tex.oblique=10;
    Tex.layer="text";
    Tex.basePoint.x = x;
    Tex.basePoint.y = y;
    Tex.color = 1;
    dxfW.writeText(&Tex);
}


void EntityWriter::dimension()
{
    DRW_DimLinear dim;
    dim.layer = "dimension";
    dxfW.writeDimension(&dim);

}



