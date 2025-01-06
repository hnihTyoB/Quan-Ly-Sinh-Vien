#include "danhsachsinhvien.h"
#include "ui_danhsachsinhvien.h"
#include "Array.h"
#include "SingleLinkList.h"
#include "DoubleLinkedList.h"
#include "CircularLinkedList.h"
#include <QListWidgetItem>
#include <QMessageBox>
#include <regex>
#include <chrono>
#include <QFileDialog>
using namespace std;


DanhsachSinhvien::DanhsachSinhvien(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DanhsachSinhvien)
{
    ui->setupUi(this);
    this->setWindowTitle("QUẢN LÝ DANH SÁCH SINH VIÊN");
    //Placeholder Tìm kiếm
    ui->leSearch->setPlaceholderText("Search");
    //Placeholder Thông tin sinh viên
    ui->leLastNameOfStudent->setPlaceholderText("Last Name");
    ui->leFirstNameOfStudent->setPlaceholderText("First Name");
    ui->leIdOfStudent->setPlaceholderText("Id Student");
    ui->ldClassOfStudent->setPlaceholderText("Class");
    ui->ldScoresOfStudent->setPlaceholderText("Score");

    ui->pbExport->setEnabled(false);
    ui->groupBox->setEnabled(false);
    ui->cbReverse->setEnabled(false);

    ui->labelmaSV->hide();
    ui->labelHolot->hide();
    ui->labelTen->hide();
    ui->labelLop->hide();
    ui->labelDiem->hide();
}

QString DanhsachSinhvien::Title(){
    // return QString::fromUtf8("Mã sinh viên\t\tHọ lót" + string(19, ' ') + "\tTên\t\tLớp" + string(12, ' ') + "\t\tĐiểm\n" + string(135, '_') + "\n");
    return QString::fromUtf8("STT\tId Student\t\tLast Name" + string(16, ' ') + "\tFirst Name\t\tClass" + string(12, ' ') + "\t\tScore\n" + string(151, '_') + "\n");
}
QString DanhsachSinhvien::TitleRed(){//Title dao nguoc ten
    // return QString::fromUtf8("Mã sinh viên\t\tTên" + string(15, ' ') + "\tHọ lót\t\tLớp\t\tĐiểm\n" + string(119, '_') + "\n");
    return QString::fromUtf8("STT\tId Student\t\tFirst Name" + string(8, ' ') + "Last Name\t\tClass\t\tScore\n" + string(136, '_') + "\n");
}
QString DanhsachSinhvien::In0(Student s_v){
    return QString::fromUtf8("\t" + s_v.maSV + "\t\t" + s_v.Ho + string(25 - (s_v.Ho).length(), ' ') + "\t" + s_v.Ten + "\t\t"
             + s_v.Lop + string(15 - (s_v.Lop).length(), ' ') + "\t") + QString::fromUtf8(string(2 - QString::number(round(s_v.Diem * 1) / 1).length(), ' ')) + QString::number(round(s_v.Diem * 10) / 10) + QString::fromUtf8("\n");
}
QString DanhsachSinhvien::InReverse0(Student s_v){//In thong tin sv dao nguoc ten
    return QString::fromUtf8("\t" + s_v.maSV + "\t\t" + Daochuoi(s_v.Ten) + string(15 - (s_v.Ten).length(), ' ') + "\t"
                             + Daochuoi(s_v.Ho) + string(25 - (s_v.Ho).length(), ' ') + "\t" + s_v.Lop + string(15 - (s_v.Lop).length(), ' ') + "\t") + QString::fromUtf8(string(2 - QString::number(round(s_v.Diem * 1) / 1).length(), ' ')) + QString::number(round(s_v.Diem * 10) / 10) + QString::fromUtf8("\n");
}
//In Mang
void DanhsachSinhvien::ShowList0(Student *s_v, int n){
    ui->plainTextEdit->clear();

    ui->plainTextEdit->insertPlainText(Title());
    // ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(135, '_')) + QString::fromUtf8("\n"));
    if(ui->leSearch->text() != "")
        ui->plainTextEdit->setStyleSheet("color: rgb(255, 0, 0)");
    else
        ui->plainTextEdit->setStyleSheet("color: rgb(0, 0, 0)");
    int i = 0;
    while (i < n) {
        ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(3 - to_string(i+1).length(), ' ')) + QString::number(i+1));
        ui->plainTextEdit->insertPlainText(In0(s_v[i]));
        i++;
    }
}
void DanhsachSinhvien::ShowListReverse0(Student *s_v, int n){
    ui->plainTextEdit->clear();

    ui->plainTextEdit->insertPlainText(TitleRed());
    // ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(119, '_')) + QString::fromUtf8("\n"));
    if(ui->leSearch->text() != "")
        ui->plainTextEdit->setStyleSheet("color: rgb(255, 0, 0)");
    else
        ui->plainTextEdit->setStyleSheet("color: rgb(0, 0, 0)");

    int i = 0;
    while (i < n) {
    	ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(3 - to_string(i+1).length(), ' ')) + QString::number(i+1));
        ui->plainTextEdit->insertPlainText(InReverse0(s_v[i]));
        i++;
    }
}
//In dslk Don
void DanhsachSinhvien::ShowList(sv a){
    ui->plainTextEdit->clear();

    ui->plainTextEdit->insertPlainText(Title());
    // ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(135, '_')) + QString::fromUtf8("\n"));
    if(ui->leSearch->text() != "")
        ui->plainTextEdit->setStyleSheet("color: rgb(255, 0, 0)");
    else{
        ui->plainTextEdit->setStyleSheet("color: rgb(0, 0, 0)");
    }
	int i = 1;
    while (a != NULL) {
    	ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
        ui->plainTextEdit->insertPlainText(In0(a->s));
        a = a->next;
        i++;
    }
}
void DanhsachSinhvien::ShowListReverse(sv a){
    ui->plainTextEdit->clear();

    ui->plainTextEdit->insertPlainText(TitleRed());
    // ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(119, '_')) + QString::fromUtf8("\n"));
    if(ui->leSearch->text() != "")
        ui->plainTextEdit->setStyleSheet("color: rgb(255, 0, 0)");
    else{
        ui->plainTextEdit->setStyleSheet("color: rgb(0, 0, 0)");
    }
	int i = 1;
    while (a != NULL) {
    	ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
        ui->plainTextEdit->insertPlainText(InReverse0(a->s));
        a = a->next;
        i++;
    }
}
//In dslk Kep
void DanhsachSinhvien::ShowList2(sv2 b){
    ui->plainTextEdit->clear();

    ui->plainTextEdit->insertPlainText(Title());
    // ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(135, '_')) + QString::fromUtf8("\n"));
    if(ui->leSearch->text() != "")
        ui->plainTextEdit->setStyleSheet("color: rgb(255, 0, 0)");
    else{
        ui->plainTextEdit->setStyleSheet("color: rgb(0, 0, 0)");
    }
	int i = 1;
    while (b != NULL) {
    	ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
        ui->plainTextEdit->insertPlainText(In0(b->s));
        b = b->right;
        i++;
    }
}
void DanhsachSinhvien::ShowListReverse2(sv2 b){
    ui->plainTextEdit->clear();

    ui->plainTextEdit->insertPlainText(TitleRed());
    // ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(119, '_')) + QString::fromUtf8("\n"));
    if(ui->leSearch->text() != "")
        ui->plainTextEdit->setStyleSheet("color: rgb(255, 0, 0)");
    else{
        ui->plainTextEdit->setStyleSheet("color: rgb(0, 0, 0)");
    }
	int i = 1;
    while (b != NULL) {
    	ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
        ui->plainTextEdit->insertPlainText(InReverse0(b->s));
        b = b->right;
        i++;
    }
}
//In dslk Vong
void DanhsachSinhvien::ShowList3(sv3 c){
    ui->plainTextEdit->clear();
    ui->plainTextEdit->insertPlainText(Title());
    // ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(135, '_')) + QString::fromUtf8("\n"));
    if(ui->leSearch->text() != "")
        ui->plainTextEdit->setStyleSheet("color: rgb(255, 0, 0)");
    else
        ui->plainTextEdit->setStyleSheet("color: rgb(0, 0, 0)");
    
    int i = 1;
    if(c != NULL){
        sv3 r = c->next;
        while (r != c) {
        	ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
            ui->plainTextEdit->insertPlainText(In0(r->s));
            r = r->next;
            i++;
        }
        ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
        ui->plainTextEdit->insertPlainText(In0(r->s));//Vong lap dung khi gap Last nen thieu phan tu cuoi chua in ra
    }
}
void DanhsachSinhvien::ShowListReverse3(sv3 c){
    ui->plainTextEdit->clear();

    ui->plainTextEdit->insertPlainText(TitleRed());
    // ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(119, '_')) + QString::fromUtf8("\n"));
    if(ui->leSearch->text() != "")
        ui->plainTextEdit->setStyleSheet("color: rgb(255, 0, 0)");
    else{
        ui->plainTextEdit->setStyleSheet("color: rgb(0, 0, 0)");
    }
	int i = 1;
    if(c != NULL){
        sv3 r = c->next;
        while (r != c) {
        	ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
            ui->plainTextEdit->insertPlainText(InReverse0(r->s));
            r = r->next;
            i++;
        }
        ui->plainTextEdit->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
        ui->plainTextEdit->insertPlainText(InReverse0(r->s));
    }
}

bool DanhsachSinhvien::IsValidStudent()
{
    string m = (ui->leIdOfStudent->text()).toStdString();
    string h = (ui->leLastNameOfStudent->text()).toStdString();
    string t = (ui->leFirstNameOfStudent->text()).toStdString();
    string l = (ui->ldClassOfStudent->text()).toStdString();
    string d = (ui->ldScoresOfStudent->text()).toStdString();
    if (m == "" || h == "" || t == "" || l == "" || d == "")
    {
        QMessageBox::critical(this, "ERROR", "Vui lòng nhập đầy đủ thông tin !");
        return false;
    }
    else if(m != "" && h != "" && t != "" && l != "" && d != ""){

        regex studentIdValid("^N\\d{2}DC.+\\d{3}$");//N**DC...***

        regex lastNameValid(
            "^[a-zA-Z_ÀÁÂÃÈÉÊÌÍÒÓÔÕÙÚĂĐĨŨƠàáâãèéêìíòóôõùúăđĩũơƯĂẠẢẤẦẨẪẬẮẰẲẴẶ+"
            "ẸẺẼỀỀỂưăạảấầẩẫậắằẳẵặẹẻẽềềểỄỆỈỊỌỎỐỒỔỖỘỚỜỞỠỢỤỦỨỪễệỉịọỏốồổỗộớờởỡợ+ụủứừỬỮỰỲỴÝỶỸửữựỳỵỷỹ\\s]+$");

        regex firstNameValid(
            "^[a-zA-Z_ÀÁÂÃÈÉÊÌÍÒÓÔÕÙÚĂĐĨŨƠàáâãèéêìíòóôõùúăđĩũơƯĂẠẢẤẦẨẪẬẮẰẲẴẶ+"
            "ẸẺẼỀỀỂưăạảấầẩẫậắằẳẵặẹẻẽềềểỄỆỈỊỌỎỐỒỔỖỘỚỜỞỠỢỤỦỨỪễệỉịọỏốồổỗộớờởỡợ+ụủứừỬỮỰỲỴÝỶỸửữựỳỵỷỹ\\s]+$");

        regex classValid("^D\\d{2}CQ.+\\d{2}-N$");//D**CQ...**-N

        regex scoreValid("^\\d{1,2}");

        if (!regex_match(m, studentIdValid))
        {
            QMessageBox::critical(this, "ERROR", "ID is invalid");
            return false;
        }

        if (!regex_match(h, lastNameValid))
        {
            QMessageBox::critical(this, "ERROR", "Last name is invalid");
            return false;
        }

        if (!regex_match(t, lastNameValid))
        {
            QMessageBox::critical(this, "ERROR", "First name is invalid");
            return false;
        }

        if (!regex_match(l, classValid))
        {
            QMessageBox::critical(this, "ERROR", "Class is invalid");
            return false;
        }

        if (/*!regex_match(d, scoreValid) || */stof(d) < 0 || stof(d) > 10)
        {
            QMessageBox::critical(this, "ERROR", "Score is invalid");
            return false;
        }
    }
    return true;
}

DanhsachSinhvien::~DanhsachSinhvien()
{
    delete []s_v;//mang chinh
    delete []a;//mang luu sv khi tim kiem
    delete ui;
}
//Viet IN HOA khi nhap maSV/Lop
string DanhsachSinhvien::Upper(string s){
    for(unsigned long long i = 0; i < s.length(); i++){
        s[i] = toupper(s[i]);
    }
    return s;
}
//Chi nhan gia tri so khi nhap Diem
string DanhsachSinhvien::Digit(string s){
    string x;
    bool p = true;
    for(unsigned long long i = 0; i < s.length(); i++){
        if(isdigit(s[i]))
            x += s[i];
        else if(s[i] == '.' && p){//Khong cho nhap 2 dau '.' (.8 = 0.8)
            x += '.';
            p = false;
        }
    }
    return x;
}
//Chuan hoa ten
string DanhsachSinhvien::Proper(string s){
    string x;
    stringstream ss(s);
    string token;
    while(ss >> token){
        token[0] = toupper(token[0]);
        for(unsigned long long i = 1; i < token.length(); i++){
            token[i] = tolower(token[i]);
        }
        x += token;
        x += ' ';
    }
    return x;
}


void DanhsachSinhvien::on_pbImport_clicked()
{
    /*"D:/Qt/DanhsachSinhvien/dssv.csv"*/
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "");

    switch(ui->cbbSaveOption->currentIndex()){
    case 0://mang
        if(!DocFile0(s_v, file_name.toStdString(), n))
            QMessageBox::critical(this, "ERROR", "Open fail!");
        else
            ShowList0(s_v, n);
        break;
    case 1://don
        Clearlist(First);
        if(!DocFile(First, file_name.toStdString()))
            QMessageBox::critical(this, "ERROR", "Open fail!");
        else
            ShowList(First);
        break;
    case 2://kep
        Clearlist2(First2);
        if(!DocFile2(First2, Last2, file_name.toStdString()))
            QMessageBox::critical(this, "ERROR", "Open fail!");
        else
            ShowList2(First2);
        break;
    case 3://vong
        Clearlist3(Last3);
        if(!DocFile3(Last3, file_name.toStdString()))
            QMessageBox::critical(this, "ERROR", "Open fail!");
        else
            ShowList3(Last3);
        break;
    }
    ui->pbExport->setEnabled(true);
    ui->cbbSaveOption->setEnabled(false);
}
//Combobox Sort
void DanhsachSinhvien::on_ccbSort_currentIndexChanged(int index)
{
    if(ui->cbSort->isChecked()){
        int choose = ui->cbbSortOption->currentIndex();//Chon sap xep theo maSV, ten, diem
        auto start = chrono::steady_clock::now();
        switch(ui->cbbSaveOption->currentIndex()){
        case 0://mang
            if(index == 0){
                Heap_sort0(s_v, n, choose);
            }
            else if(index == 1){
                Merge_sort0(s_v, 0, n-1, choose);
            }
            else if(index == 2){
                Bubble_sort0(s_v, n, choose);
            }
            else if(index == 3){
                Insertion_sort0(s_v, n, choose);
            }
            else if(index == 4){
                Quick_sort0(s_v, 0, n-1, choose);
            }
            else if(index == 5){
                Selection_sort0(s_v, n, choose);
            }

            break;
        case 1://don
            if(index == 0){
                Heap_sort(First, choose);
            }
            else if(index == 1){
                Merge_sort(First, 0, Size(First)-1, choose);
            }
            else if(index == 2){
                Bubble_sort(First, choose);
            }
            else if(index == 3){
                Insertion_sort(First, choose);
            }
            else if(index == 4){
                Quick_sort(First, 0, Size(First)-1, choose);
            }
            else if(index == 5){
                Selection_sort(First, choose);
            }

            break;
        case 2://kep
            if(index == 0){
                Heap_sort2(First2, choose);
            }
            else if(index == 1){
                Merge_sort2(First2, 0, Size2(First2)-1, choose);
            }
            else if(index == 2){
                Bubble_sort2(First2, choose);
            }
            else if(index == 3){
                Insertion_sort2(First2, choose);
            }
            else if(index == 4){
                Quick_sort2(First2, 0, Size2(First2)-1, choose);
            }
            else if(index == 5){
                Selection_sort2(First2, choose);
            }

            break;
        case 3://vong
            if(index == 0){
                Heap_sort3(Last3, choose);
            }
            else if(index == 1){
                Merge_sort3(Last3, 0, Size3(Last3)-1, choose);
            }
            else if(index == 2){
                Bubble_sort3(Last3, choose);
            }
            else if(index == 3){
                Insertion_sort3(Last3, choose);
            }
            else if(index == 4){
                Quick_sort3(Last3, 0, Size3(Last3)-1, choose);
            }
            else if(index == 5){
                Selection_sort3(Last3, choose);
            }

            break;
        }
        switch(ui->cbbSaveOption->currentIndex()){
        case 0://mang
            ShowList0(s_v, n);
            break;
        case 1://don
            ShowList(First);
            break;
        case 2://kep
            ShowList2(First2);
            break;
        case 3://vong
            ShowList3(Last3);
            break;
        }
        auto end = chrono::steady_clock::now();
        ui->lineEdit->setText(QString::number(chrono::duration_cast<chrono::microseconds>(end - start).count()));
    }
}
//Checkbox Sort
void DanhsachSinhvien::on_cbSort_clicked()
{
    if(ui->cbSort->isChecked()){
        ui->leSearch->clear();       
        ui->ccbSort->setCurrentIndex(0);
        on_ccbSort_currentIndexChanged(0);
    }
    else{
        switch(ui->cbbSaveOption->currentIndex()){
        case 0://mang
            ShowList0(s_v, n);
            break;
        case 1://don
            ShowList(First);
            break;
        case 2://kep
            ShowList2(First2);
            break;
        case 3://vong
            ShowList3(Last3);
            break;
        }
    }
}
//Nhap du lieu vao thanh tim kiem
void DanhsachSinhvien::on_leSearch_textChanged(const QString &arg1)
{
    if(ui->leSearch->text() != ""){
        ui->cbSort->setCheckState(Qt::Unchecked);
        ui->cbReverse->setEnabled(true);
        ui->leIdOfStudent->clear();
        ui->groupBox->setEnabled(false);
        ui->pushButtonChInsert->setStyleSheet("background-color:white");
        ui->pushButtonChDelete->setStyleSheet("background-color:white");

        auto start = chrono::steady_clock::now();

        int choose = ui->cbbSearch->currentIndex();
        if(ui->cbReverse->isChecked()){//Đảo ngược tên
            switch(ui->cbbSaveOption->currentIndex()){
            case 0://mang
                ShowListReverse0(a, Search_info0(s_v, a, arg1.toStdString(), n, choose));
                break;
            case 1://don
                ShowListReverse(Search_info(First, arg1.toStdString(), choose));
                break;
            case 2://kep
                ShowListReverse2(Search_info2(First2, arg1.toStdString(), choose));
                break;
            case 3://vong
                ShowListReverse3(Search_info3(Last3, arg1.toStdString(), choose));
                break;
            }
        }
        else{
            switch(ui->cbbSaveOption->currentIndex()){
            case 0://mang
                ShowList0(a, Search_info0(s_v, a, arg1.toStdString(), n, choose));
                break;
            case 1://don
                ShowList(Search_info(First, arg1.toStdString(), choose));
                break;
            case 2://kep
                ShowList2(Search_info2(First2, arg1.toStdString(), choose));
                break;
            case 3://vong
                ShowList3(Search_info3(Last3, arg1.toStdString(), choose));
                break;
            }
        }

        auto end = chrono::steady_clock::now();
        ui->lineEdit->setText(QString::number(chrono::duration_cast<chrono::microseconds>(end - start).count()));
    }
    else{
        ui->cbReverse->setEnabled(false);
        switch(ui->cbbSaveOption->currentIndex()){
        case 0://mang
            ShowList0(s_v, n);
            break;
        case 1://don
            ShowList(First);
            break;
        case 2://kep
            ShowList2(First2);
            break;
        case 3://vong
            ShowList3(Last3);
            break;
        }
    } 
}
//Checkbox Dao nguoc ten
void DanhsachSinhvien::on_cbReverse_clicked()
{
    on_leSearch_textChanged(ui->leSearch->text());
}
//Chon chuc nang them sinh vien
void DanhsachSinhvien::on_pushButtonChInsert_clicked()
{
    ui->groupBox->setEnabled(true);
    ui->leLastNameOfStudent->setEnabled(false);
    ui->leFirstNameOfStudent->setEnabled(false);
    ui->ldClassOfStudent->setEnabled(false);
    ui->ldScoresOfStudent->setEnabled(false);
    ui->pbInsert->setText("Insert");
    ui->pushButtonChInsert->setStyleSheet("background-color:green");
    ui->pushButtonChDelete->setStyleSheet("background-color:white");

    on_pbReset_clicked();
}

void DanhsachSinhvien::on_pbInsert_clicked()
{
    string m = (ui->leIdOfStudent->text()).toStdString();
    string h = (ui->leLastNameOfStudent->text()).toStdString();
    string t = (ui->leFirstNameOfStudent->text()).toStdString();
    string l = (ui->ldClassOfStudent->text()).toStdString();
    float d = (ui->ldScoresOfStudent->text()).toFloat();

    if(ui->pbInsert->text() == "Insert"){
        bool chk = true;
        switch(ui->cbbSaveOption->currentIndex()){
        case 0://mang
            if(Search_info0(s_v, a, m, n, 0) != 0){
                QMessageBox::critical(this, "ERROR", "Sinh viên đã tồn tại !");
                chk = false;
            }
            break;
        case 1://don
            if(Search_info(First, m, 0) != NULL){
                QMessageBox::critical(this, "ERROR", "Sinh viên đã tồn tại !");
                chk = false;
            }
            break;
        case 2://kep
            if(Search_info2(First2, m, 0) != NULL){
                QMessageBox::critical(this, "ERROR", "Sinh viên đã tồn tại !");
                chk = false;
            }
            break;
        case 3://vong
            if(Search_info3(Last3, m, 0) != NULL){
                QMessageBox::critical(this, "ERROR", "Sinh viên đã tồn tại !");
                chk = false;
            }
            break;
        }

        if(chk){//Neu maSV khong trung lap thi kiem tra thong tin sinh vien
            if(IsValidStudent()){
                switch(ui->cbbSaveOption->currentIndex()){
                case 0://mang
                    Add0(s_v, n, m, h, t, l, d);
                    break;
                case 1://don
                    Add(First, m, h, t, l, d);
                    break;
                case 2://kep
                    Add2(First2, Last2, m, h, t, l, d);
                    break;
                case 3://vong
                    Add3(Last3, m, h, t, l, d);
                    break;
                }
                QMessageBox::information(this, "SUCCESS", "THÊM sinh viên thành công !");
            }
        }
    }
    else if(ui->pbInsert->text() == "Delete"){
        bool chk = true;
        switch(ui->cbbSaveOption->currentIndex()){
        case 0://mang
            if(Search_info0(s_v, a, m, n, 0) == 0){
                QMessageBox::critical(this, "ERROR", "Không tìm thấy sinh viên !");
                chk = false;
            }
            break;
        case 1://don
            if(Search_info(First, m, 0) == NULL || Size(Search_info(First, m, 0)) != 1){//Truong hop khong tim thay hoac tim thay nhieu hon 1
                QMessageBox::critical(this, "ERROR", "Không tìm thấy sinh viên !");
                chk = false;
            }
            break;
        case 2://kep
            if(Search_info2(First2, m, 0) == NULL || Size2(Search_info2(First2, m, 0)) != 1){
                QMessageBox::critical(this, "ERROR", "Không tìm thấy sinh viên !");
                chk = false;
            }
            break;
        case 3://vong
            if(Search_info3(Last3, m, 0) == NULL || Size3(Search_info3(Last3, m, 0)) != 1){
                QMessageBox::critical(this, "ERROR", "Không tìm thấy sinh viên !");
                chk = false;
            }
            break;
        }

        if(chk){//Neu maSV trung lap thi xoa sinh vien
            switch(ui->cbbSaveOption->currentIndex()){
            case 0://mang
                Delete_info0(s_v, n, m);
                break;
            case 1://don
                Delete_info(First, m);
                break;
            case 2://kep
                Delete_info2(First2, Last2, m);
                break;
            case 3://vong
                Delete_info3(Last3, m);
                break;
            }
            QMessageBox::information(this, "SUCCESS", "XÓA sinh viên thành công !");
        }
    }
    
//    switch(ui->cbbSaveOption->currentIndex()){
//    case 0://mang
//        ShowList0(s_v, n);
//        break;
//    case 1://don
//        ShowList(First);
//        break;
//    case 2://kep
//        ShowList2(First2);
//        break;
//    case 3://vong
//        ShowList3(Last3);
//        break;
//    }

    on_leIdOfStudent_textChanged(ui->leIdOfStudent->text());
}
//In danh sach khi nhap maSV
void DanhsachSinhvien::on_leIdOfStudent_textChanged(const QString &arg1)
{
    if(arg1 != ""){
        ui->cbSort->setCheckState(Qt::Unchecked);
        ui->labelmaSV->show();
        if(ui->pbInsert->text() == "Insert")
            ui->leLastNameOfStudent->setEnabled(true);
    }
    else{
        ui->labelmaSV->hide();
        ui->leLastNameOfStudent->setEnabled(false);
    }
    string x = arg1.toStdString();
    ui->leIdOfStudent->setText(QString::fromUtf8(Upper(x)));
    ui->leSearch->clear();
    
    int num = Search_info0(s_v, a, arg1.toStdString(), n, 0);
    switch(ui->cbbSaveOption->currentIndex()){
    case 0://mang
        ShowList0(a, num);
        break;
    case 1://don
        ShowList(Search_info(First, arg1.toStdString(), 0));
        break;
    case 2://kep
        ShowList2(Search_info2(First2, arg1.toStdString(), 0));
        break;
    case 3://vong
        ShowList3(Search_info3(Last3, arg1.toStdString(), 0));
        break;
    }
}
//Chon chuc nang xoa sinh vien
void DanhsachSinhvien::on_pushButtonChDelete_clicked()
{
    on_pbReset_clicked();
    ui->groupBox->setEnabled(true);
    ui->leLastNameOfStudent->setEnabled(false);
    ui->leFirstNameOfStudent->setEnabled(false);
    ui->ldClassOfStudent->setEnabled(false);
    ui->ldScoresOfStudent->setEnabled(false);
    ui->pushButtonChDelete->setStyleSheet("background-color:red");
    ui->pushButtonChInsert->setStyleSheet("background-color:white");

    ui->pbInsert->setText("Delete");
}

void DanhsachSinhvien::on_pbReset_clicked()
{
    ui->leIdOfStudent->clear();
    ui->leLastNameOfStudent->clear();
    ui->leFirstNameOfStudent->clear();
    ui->ldClassOfStudent->clear();
    ui->ldScoresOfStudent->clear();
}
//Chon Overview/Statistics
void DanhsachSinhvien::on_tabWidgetEdit_tabBarClicked(int index)
{
    if(index == 1){//Chon Statistics
        int i = 0;
        int s;
        sv p = NULL;
        sv2 q = NULL;
        sv3 r = NULL;
        ui->plainTextEditMaxScore->clear();
        ui->plainTextEditMinScore->clear();
        ui->plainTextEditMaxScore->insertPlainText(Title());
        ui->plainTextEditMinScore->insertPlainText(Title());

        switch(ui->cbbSaveOption->currentIndex()){
        case 0://mang
            //Tìm Max
            s = TimMaxMin0(s_v, a, n, 1);

            i = 0;
            while (i < s) {
            	ui->plainTextEditMaxScore->insertPlainText(QString::fromUtf8(string(3 - to_string(i+1).length(), ' ')) + QString::number(i+1));
                ui->plainTextEditMaxScore->insertPlainText(In0(a[i]));
                i++;
            }
            //Tìm Min
            s = TimMaxMin0(s_v, a, n, 0);

            i = 0;
            while (i < s) {
            	ui->plainTextEditMinScore->insertPlainText(QString::fromUtf8(string(3 - to_string(i+1).length(), ' ')) + QString::number(i+1));
                ui->plainTextEditMinScore->insertPlainText(In0(a[i]));
                i++;
            }
            //Tính TB
            ui->lineEditTB->setText(QString::number(round(TinhTB0(s_v, n)*10) / 10));
            break;
        case 1://don
            //Tìm Max
            p = TimMaxMin(First, 1);
            
			i = 1;
            while (p != NULL) {
            	ui->plainTextEditMaxScore->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
                ui->plainTextEditMaxScore->insertPlainText(In0(p->s));
                p = p->next;
                i++;
            }
            //Tìm Min
            p = TimMaxMin(First, 0);
			
			i = 1;
            while (p != NULL) {
            	ui->plainTextEditMinScore->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
                ui->plainTextEditMinScore->insertPlainText(In0(p->s));
                p = p->next;
                i++;
            }
            //Tính TB
            ui->lineEditTB->setText(QString::number(round(TinhTB(First)*10) / 10));
            break;
        case 2://kep
            //Tìm Max
            q = TimMaxMin2(First2, 1);
			
			i = 1;
            while (q != NULL) {
            	ui->plainTextEditMaxScore->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
                ui->plainTextEditMaxScore->insertPlainText(In0(q->s));
                q = q->right;
                i++;
            }
            //Tìm Min
            q = TimMaxMin2(First2, 0);

            i = 1;
			while (q != NULL) {
            	ui->plainTextEditMinScore->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
                ui->plainTextEditMinScore->insertPlainText(In0(q->s));
                q = q->right;
                i++;
            }
            //Tính TB
            ui->lineEditTB->setText(QString::number(round(TinhTB2(First2)*10) / 10));
            break;
        case 3://vong
            //Tìm Max
            r = TimMaxMin3(Last3, 1);
            
            i = 1;
            if(r != NULL){
                sv3 t = r->next;
                while (t != r) {
                	ui->plainTextEditMaxScore->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
                    ui->plainTextEditMaxScore->insertPlainText(In0(t->s));
                    t = t->next;
                    i++;
                }
                ui->plainTextEditMaxScore->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
                ui->plainTextEditMaxScore->insertPlainText(In0(t->s));
            }
            //Tìm Min
            r = TimMaxMin3(Last3, 0);
            
            i = 1;
            if(r != NULL){
                sv3 t = r->next;
                while (t != r) {
                	ui->plainTextEditMinScore->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
                    ui->plainTextEditMinScore->insertPlainText(In0(t->s));
                    t = t->next;
                    i++;
                }
                ui->plainTextEditMinScore->insertPlainText(QString::fromUtf8(string(3 - to_string(i).length(), ' ')) + QString::number(i));
                ui->plainTextEditMinScore->insertPlainText(In0(t->s));
            }
            //Tính TB
            ui->lineEditTB->setText(QString::number(round(TinhTB3(Last3)*10) / 10));
            break;
        }
    }
}

void DanhsachSinhvien::on_ldClassOfStudent_textChanged(const QString &arg1)
{
    if(arg1 != ""){
        ui->labelLop->show();
        ui->ldScoresOfStudent->setEnabled(true);
        on_leFirstNameOfStudent_textChanged(ui->leFirstNameOfStudent->text() + ' ');
    }
    else{
        ui->labelLop->hide();
        ui->ldScoresOfStudent->setEnabled(false);
    }
    string x = arg1.toStdString();
    ui->ldClassOfStudent->setText(QString::fromUtf8(Upper(x)));
}


void DanhsachSinhvien::on_ldScoresOfStudent_textChanged(const QString &arg1)
{
    if(arg1 != ""){
        ui->labelDiem->show();
    }
    else
        ui->labelDiem->hide();
    string x = arg1.toStdString();
    ui->ldScoresOfStudent->setText(QString::fromUtf8(Digit(x)));
}


void DanhsachSinhvien::on_leLastNameOfStudent_textChanged(const QString &arg1)
{
    if(arg1 != ""){
        ui->labelHolot->show();
        ui->leFirstNameOfStudent->setEnabled(true);
    }
    else{
        ui->labelHolot->hide();
        ui->leFirstNameOfStudent->setEnabled(false);
    }

    if(arg1.length() == 1){
        ui->leLastNameOfStudent->setText(QString::fromUtf8(Upper(arg1.toStdString())));//Viet HOA chu dau
        // ui->leLastNameOfStudent->setText(arg1.toUpper());
    }
    if(arg1.length() > 0 && arg1[arg1.length() - 1] == ' '){
        string x = arg1.toStdString();
        ui->leLastNameOfStudent->setText(QString::fromUtf8(Proper(x)));
    }
}


void DanhsachSinhvien::on_leFirstNameOfStudent_textChanged(const QString &arg1)
{
    if(arg1 != ""){
        ui->labelTen->show();
        ui->ldClassOfStudent->setEnabled(true);
        on_leLastNameOfStudent_textChanged(ui->leLastNameOfStudent->text() + ' ');
    }
    else{
        ui->labelTen->hide();
        ui->ldClassOfStudent->setEnabled(false);
    }

    if(arg1.length() == 1){
        ui->leFirstNameOfStudent->setText(QString::fromUtf8(Upper(arg1.toStdString())));//Viet HOA chu dau
        // ui->leFirstNameOfStudent->setText(arg1.toUpper());
    }
    if(arg1.length() > 0 && arg1[arg1.length() - 1] == ' '){
        string x = arg1.toStdString();
        ui->leFirstNameOfStudent->setText(QString::fromUtf8(Proper(x)));
    }
}


void DanhsachSinhvien::on_cbbSortOption_currentIndexChanged(int index)
{
    on_ccbSort_currentIndexChanged(index);
}


void DanhsachSinhvien::on_pbExport_clicked()
{
    ui->leSearch->clear();
    QString file_name = QFileDialog::getOpenFileName(this, "Open a file", "");/*"D:/Qt/DanhsachSinhvien/dssv.csv"*/

    switch(ui->cbbSaveOption->currentIndex()){
    case 0://mang
        WriteFile0(s_v, file_name.toStdString(), n);
        break;
    case 1://don
        WriteFile(First, file_name.toStdString());
        break;
    case 2://kep
        WriteFile2(First2, file_name.toStdString());
        break;
    case 3://vong
        WriteFile3(Last3, file_name.toStdString());
        break;
    }

    QMessageBox::information(this, "SAVE FILE", "Đã lưu vào file có đường dẫn\n" + file_name);
    ui->cbbSaveOption->setEnabled(true);
}
