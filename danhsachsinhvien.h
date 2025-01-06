#ifndef DANHSACHSINHVIEN_H
#define DANHSACHSINHVIEN_H
#include <QWidget>
//Add
#include "Array.h"
#include "SingleLinkList.h"
#include "CircularLinkedList.h"
#include "DoubleLinkedList.h"
QT_BEGIN_NAMESPACE

namespace Ui {
class DanhsachSinhvien;
}
QT_END_NAMESPACE

class DanhsachSinhvien : public QWidget
{
    Q_OBJECT

public:
    DanhsachSinhvien(QWidget *parent = nullptr);

    QString Title();
    QString TitleRed();

    QString In0(Student s_v);
    QString InReverse0(Student s_v);

    void ShowList0(Student *s_v, int n);
    void ShowListReverse0(Student *s_v, int n);

    void ShowList(sv a);
    void ShowListReverse(sv a);

    void ShowList2(sv2 b);
    void ShowListReverse2(sv2 b);

    void ShowList3(sv3 c);
    void ShowListReverse3(sv3 c);

    bool IsValidStudent();

    string Upper(string s);
    string Digit(string s);
    string Proper(string s);

    ~DanhsachSinhvien();

private slots:


    void on_pbImport_clicked();

    void on_ccbSort_currentIndexChanged(int index);

    void on_cbSort_clicked();

    void on_leSearch_textChanged(const QString &arg1);

    void on_cbReverse_clicked();

    void on_pushButtonChInsert_clicked();

    void on_pbInsert_clicked();

    void on_leIdOfStudent_textChanged(const QString &arg1);

    void on_pushButtonChDelete_clicked();

    void on_pbReset_clicked();

    void on_tabWidgetEdit_tabBarClicked(int index);

    void on_ldClassOfStudent_textChanged(const QString &arg1);

    void on_ldScoresOfStudent_textChanged(const QString &arg1);

    void on_leLastNameOfStudent_textChanged(const QString &arg1);

    void on_leFirstNameOfStudent_textChanged(const QString &arg1);

    void on_cbbSortOption_currentIndexChanged(int index);

    void on_pbExport_clicked();

private:
    Ui::DanhsachSinhvien *ui;
    //Add
    Student *s_v = new Student[200];
    Student *a = new Student[200];
    int n = 0;
    sv First = NULL;
    sv2 First2 = NULL;
    sv2 Last2 = NULL;
    sv3 Last3 = NULL;
};
#endif // DANHSACHSINHVIEN_H
