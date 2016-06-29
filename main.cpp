#include <QProcess>
#include "EntityWriter.h"
using namespace std;

    int main()
    {
        dxfRW dxf("./output.dxf");

        EntityWriter writer(dxf);
//        writer.LineV(12,34,45,65);
        dxf.write(&writer, DRW::Version::AC1024, false);
        QProcess::execute("librecad output.dxf");
        return 0;
    }
