#include "EntityWriter.h"
EntityWriter::EntityWriter(dxfRW &dxfW) : dxfW(dxfW) {
}


void EntityWriter::Line(int a, int b, int c, int d){
    DRW_Line line;
    line.basePoint.x = a;
    line.basePoint.y = b;
    line.secPoint.x = c;
    line.secPoint.y = d;
    //line.layer="line";
    line.layer = "line";
    dxfW.writeLine(&line);
}

void EntityWriter::Point(int x, int y)
{
    DRW_Point BPoint;
    BPoint.basePoint.x = x;
    BPoint.basePoint.y = y;
    BPoint.layer = "Point";
    dxfW.writePoint(&BPoint);
}

//void EntityWriter::Arc(double staangle, double endangle, double thick, double radius, double center, int isccw)
void EntityWriter::Arc(int x, int y, double radius, double staangle, double endangle)
{
    DRW_Arc arc;
    arc.basePoint.x = x;
    arc.basePoint.y = y;
    arc.radious = radius;
    arc.staangle = staangle;
    arc.endangle = endangle;
    arc.color = 5;
//    double s;
//    double e;
//    arc.staangle=startang;
//    arc.endangle=endang;
//    s=arc.startAngle();
//    e=arc.endAngle();
//    arc.isccw = isccw;
//    arc.basePoint.y = radius;
//    arc.basePoint.x = center;
//    arc.basePoint.y = center;
//    arc.thickness = thick;
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
    //trace.fourPoint.x = g;
    //trace.fourPoint.y = h;
    trace.color = 4;
    trace.thickness = 10;
    trace.layer = "trace";
    dxfW.writeTrace(&trace);
    //trace.layer = "1";
    //trace.layerH = "trace";
}

//void EntityWriter::MSolid(int a, int b, int c, int d, int e, int f, int g, int h)
//{
//    DRW_Solid msolid;
//    msolid.basePoint.x = a;
//    msolid.basePoint.y = b;
//-    msolid.fourPoint.x = c;
//-    msolid.fourPoint.y= d;
//    msolid.secPoint.x = c;
//    msolid.secPoint.y = d;
//    msolid.thirdPoint.x = e;
//    msolid.thirdPoint.y = f;
//    msolid.thirdPoint.x = g;
//    msolid.thirdPoint.y = h;

//    msolid.firstCorner();
//    msolid.secondCorner();
//    msolid.thirdCorner();
//    msolid.fourthCorner();
//    msolid.color = 5;
//    msolid.thickness = 10;
//    msolid.thick();
//    msolid.extrusion();
//    msolid.elevation();
//    dxfW.writeSolid(&msolid);
//}

//void EntityWriter::addPoint(int x, int y, int z){
//    DRW_Point Point;
//    Point.basePoint.z = x;
//    Point.extPoint.x = y;
//    Point.extPoint.y = z;
//    Point.extPoint.z = x;
//    Point.thickness = x;
//    dxfW.writePoint(&Point);
//}



//-enum VAlign { VBaseLine =0, VBottom, VMiddle, VTop }

//void EntityWriter::Text(int Height, int Width, int textgen, char s)
void EntityWriter::Text(int Height, int Width)
//-enum DRW_Text::VAlign (int vx, int vy)
{
    DRW_Text Tex;
    //-VAlign alignV;
//     -   eType = DRW::TEXT;
   //   -  text.VAlign::VBaseLine;
      // - text.VAlign::VBottom;
        //-text.VAlign::VMiddle ;
       // -text.VAlign::VTop ;
        //-text.VAlign::textgen;

        Tex.height = Height;
        Tex.widthscale = Width;
//        Tex.textgen=textgen;
//        UTF8STRING text;
//        text="moc";
//        textgen = 1;
        Tex.text="Monisha";
        Tex.angle=0;
        Tex.oblique=10;

        //text=s;
//        dxfW.writeText(&text);
          addText(Tex);
//        angle = 0;
//        widthscale = 1;
//        style = "STANDARD";
//        alignV = VBaseLine;
//        textgen = 1;
//        UTF8STRING text;

//        enum VAlign alignV;
//        UTF8STRING text;
//        double angle;
//        double widthscale;
//        int textgen;
//    dwgHandle styleH;
         Tex.layer="text";
         dxfW.writeText(&Tex);

}

//void EntityWriter::dimension()
//{

//}


void EntityWriter::writeEntities() {
    Line(20,20,70,70);
    Point(10, 20);
    Text(20, 0);
//    Arc(90, 180, 10, 50, 100, 150);
//    Arc(30,120);
    Arc(45, 90, 20, 1.57, 4.17);
//    Trace(-43,72,-52,125,-40,80);
    //Trace(53,13,59,13,56,25);
    Trace(-95,0,-50,0,-70,40);
//    rectangle(20,40,40,40,40,60,20,60);
//    MSolid(20,20,60,60,100,100,20,20);
//    Line(30,30,70,70);
//    Point(40, 44);
//    Line(150,100,30,30);
    //DRW_Point BPoint;,
    //addPoint(DRW_Point &BPoint);
}

//void EntityWriter::rectangle(int x, int y, int a, int b, int c, int d, int e , int f)
//{
//    DRW_Line rect;
//    rect.basePoint.x = x;
//    rect.basePoint.y = y;
//    rect.secPoint.x = a;
//    rect.secPoint.y = b;
//    dxfW.writeLine(&rect);
//    rect.secPoint.x = a;
//    rect.secPoint.y = b;
//    rect.basePoint.x = c;
//    rect.basePoint.y = d;
//    dxfW.writeLine(&rect);
//    rect.basePoint.x = c;
//    rect.basePoint.y = d;
//    rect.secPoint.x = e;
//    rect.secPoint.y = f;
//    dxfW.writeLine(&rect);
//    rect.secPoint.x = e;
//    rect.secPoint.y = f;
//    rect.basePoint.x = x;
//    rect.basePoint.y = y;
//    rect.layer = "rect";
//    dxfW.writeLine(&rect);

//}


