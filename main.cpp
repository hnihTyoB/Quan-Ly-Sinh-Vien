#include "danhsachsinhvien.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DanhsachSinhvien w;
    w.show();
    return a.exec();
}
