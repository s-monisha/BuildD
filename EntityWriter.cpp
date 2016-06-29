#include "EntityWriter.h"
#include<iostream>
EntityWriter::EntityWriter(dxfRW &dxfW) : dxfW(dxfW) {
}


//void EntityWriter::LineV(int a, int b, int c, int d)
//{
//    DRW_Line line;
//    std::cout<<a<<endl<<b<<endl<<c<<endl<<d<<endl;
//    line.basePoint.x = a;
//    line.basePoint.y = b;
//    line.secPoint.x = c;
//    line.secPoint.y = d;
//    dxfW.writeLine(&line);
//}



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

//void EntityWriter::Arc(int x, int y, double radius, double staangle, double endangle)
//{
//    DRW_Arc arc;
//    arc.basePoint.x = x;
//    arc.basePoint.y = y;
//    arc.radious = radius;
//    arc.staangle = staangle;
//    arc.endangle = endangle;
//    arc.color = 4;
//    arc.layer = "arc";
//    dxfW.writeArc(&arc);
//}

//void EntityWriter::Trace(int a, int b, int c, int d, int e, int f)
//{
//    DRW_Trace trace;
//    trace.basePoint.x = a;
//    trace.basePoint.y = b;
//    trace.secPoint.x = c;
//    trace.secPoint.y = d;
//    trace.thirdPoint.x = e;
//    trace.thirdPoint.y = f;
//    trace.color = 7;
//    trace.thickness = 10;
//    trace.layer = "trace";
//    dxfW.writeTrace(&trace);
//}






//void EntityWriter::Text(int Height, int Width, string s, int x, int y)
//{
//    DRW_Text Tex;
//    Tex.height = Height;
//    Tex.widthscale = Width;
//    Tex.text= s;
//    Tex.angle=0;
//    Tex.oblique=10;
//    Tex.layer="text";
//    Tex.basePoint.x = x;
//    Tex.basePoint.y = y;
//    Tex.color = 1;
//    dxfW.writeText(&Tex);
//}


//void EntityWriter::dimension()
//{
//    DRW_DimLinear dim;
//    dim.layer = "dimension";
//    dxfW.writeDimension(&dim);

//}


void EntityWriter::spline(double ex, double ey, double tgsx, double tgsy, double tgex, double tgey, int flags, int degree)
{
    DRW_Spline Spline;
    Spline.ex = 1;
    Spline.ey = 2;
    Spline.ez= 1;
    Spline.tgez= 1;
    Spline.tgsz= 1;
    Spline.tgsx = 1;
    Spline.tgsy = 2;
    Spline.tgex = 2;
    Spline.tgey = 2;
    Spline.flags = 1;
    Spline.degree = 2;
    Spline.layer = "spline";

    dxfW.writeSpline(&Spline);
}

void EntityWriter::mtext()
{
    DRW_MText Mtext;
    Mtext.widthscale = 10;
    Mtext.height = 20;
    Mtext.text = "helo";
    Mtext.interlin = 1;

    Mtext.basePoint.x = 20;
    Mtext.basePoint.y = 40;


    dxfW.writeMText(&Mtext);






}

void EntityWriter::hatch()
{
    DRW_Hatch Hatch;
    Hatch.basePoint.x = 10;
    Hatch.basePoint.y = 20;
    Hatch.angle = 60;
    Hatch.scale = 20;
    Hatch.hpattern = 10;
    Hatch.deflines = 25;
    Hatch.solid = 12;
    Hatch.loopsnum = 11;
    dxfW.writeHatch(&Hatch);
}


void EntityWriter::writeEntities() {
//    LineV(20,20,70,70);
    Point(10, 20, "point");
//    Text(20, 21,'m', 10, 20);
    spline(0, 1, 3, 3, 12, 12, 0, 2);
    mtext();
    hatch();

//    Arc(45, 90, 20, 1.57, 4.17);
//    Trace(-43,72,-52,125,-40,80);

}


