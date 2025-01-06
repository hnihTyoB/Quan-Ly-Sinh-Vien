#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Array.h"
#include <QDebug>
using namespace std;

// struct Student {
//     string maSV, Ho, Ten, Lop;
//     float Diem;
//     Student() {
//         maSV = Ho = Ten = Lop = "N/A";
//         Diem = 0.0;
//     }
//     Student(string m, string hl, string t, string l, float d) {
//         maSV = m;
//         Ho = hl;
//         Ten = t;
//         Lop = l;
//         Diem = d;
//     }
// };

struct Node3 {
    Student s;
    struct Node3 *next;
};
typedef struct Node3* sv3;

sv3 makeNode3(Student x) {
    sv3 tmp = new Node3();
    tmp->s = x;
    tmp->next = NULL;
    return tmp;
}

bool Empty3(sv3 Last){
    return(Last == NULL);
}

int Size3(sv3 Last) {
    if(Empty3(Last))
        return 0;
    sv3 p = Last->next;
    int cnt = 1;
    while (p != Last){
        ++cnt;
        p = p->next;
    }
    return cnt;
}

//void Insert_First3(sv3 &Last, int x){
//	sv3 p = makeNode3(x);
//	if (Empty(Last))
//		Last = p;
//	else
//		p->next = Last->next;
//	Last->next = p;
//}

void Insert_Last3(sv3& Last, Student x) {
    sv3 p = makeNode3(x);
    if(Empty3(Last)) {
        p->next = p;
    }
    else{
        p->next = Last->next;
        Last->next = p;
    }
    Last = p;
}

//void Insert_After3(sv3 Last, sv3 p, int x){
//	if(p == NULL)
//		cout<<"Nut hien tai khong co, nen khong the them";
//	else
//	{  
//		if (p==Last)
//			Insert_Last3(Last, x);
//		else
//		{  
//			sv3 q = makeNode3(x);
//			q->next = p->next;
//			p->next = q;
//		}   
//	} 
//}

// void Add(sv3& Last) {
//     cout << "Nhap so sinh vien: ";
//     int n;cin >> n;
//     for (int i = 1; i <= n; i++) {
//         cout << "Nhap thong tin sinh vien " << i << ":\n";
//         string m, hl, t, l;
//         float d;
//         cout << "Nhap ma :";
//         cin.ignore();
//         getline(cin, m);
//         cout << "Nhap ho :";
//         getline(cin, hl);
//         cout << "Nhap tem :";
//         getline(cin, t);
//         cout << "Nhap lop :";
//         getline(cin, l);
//         cout << "Nhap diem :";
//         cin >> d;
//         Student x(m, hl, t, l, d);
//         Insert_Last(Last, x);
//     }
// }
void Add3(sv3& Last, string m, string hl, string t, string l, float d) {
    Student x(m, hl, t, l, d);
    Insert_Last3(Last, x);
}

// void in(Student s) {
//     cout << left << setw(20) << s.maSV << setw(30) << s.Ho << setw(15) << s.Ten << setw(20) << s.Lop << s.Diem << endl;
// }

void duyetDSSV3(sv3 Last) {
    sv3 p;
    if (Last == NULL)
        cout<<"\n   Danh sach rong ";
    else{
        p = Last->next;  // p chi toi phan tu dau trong dslk vong
        cout << left << setw(20) << "Ma sinh vien" << setw(30) << "Ho va ten" << setw(15) << "Ten" << setw(20) << "Lop" << "Diem" << endl;
        while(p != Last){
            cout << left << setw(20) << p->s.maSV << setw(30) << p->s.Ho << setw(15) << p->s.Ten << setw(20) << p->s.Lop << p->s.Diem << endl;
            p = p->next;
        }
        //Vong lap dung khi gap Last nen thieu phan tu cuoi chua in ra
        cout << left << setw(20) << p->s.maSV << setw(30) << p->s.Ho << setw(15) << p->s.Ten << setw(20) << p->s.Lop << p->s.Diem << endl;
    }
    cout << endl;
}

// bool compareChar(string y, string x) {
//     for (unsigned long long i = 0; i < x.length();i++) {
//         if (tolower(y[i]) != tolower(x[i]))
//             return false;
//     }
//     return true;
// }

// int compareName(string x, string y){
//     int m = min(x.length(), y.length());
//     for(int i = 0; i < m; i++){
//         if(x[i] > y[i])
//             return 1;
//         if(x[i] < y[i])
//             return -1;
//     }
//     if(x.length() > y.length())
//         return 1;
//     else if(x.length() < y.length())
//         return -1;
//     else
//         return 0;
// }

// string Daochuoi(string x) {
//     stack <char> s;
//     for (unsigned long long i = 0; i < x.length();i++) {
//         s.push(x[i]);
//     }
//     string kq;
//     while (!s.empty()) {
//         kq += s.top();
//         s.pop();
//     }
//     return kq;
// }

sv3 Search_info3(sv3 Last, string x, int choose){
    sv3 a = NULL;
    if(Empty3(Last))
        return a;
    // char c;
    // do {
    //     cout << "\n Dao chuoi (y/n) \n";
    //     cin >> c;
    // } while (c != 'n' && c != 'y');
    string y;
    sv3 p = Last->next;
    while(p != Last){
        switch (choose)
        {
        case 0:
            y = p->s.maSV;
            break;
        case 1:
            y = p->s.Ho;
            break;
        case 2:
            y = p->s.Ten;
            break;
        case 3:
            y = p->s.Lop;
            break;
        case 4:
            y = to_string(p->s.Diem);
            break;
        default:
            cout << "ERROR!\n";
            // return;
        }
        if (compareChar(y, x)) {
            Insert_Last3(a, p->s);
        }
        p = p->next;
    }
    //Vong lap dung khi gap Last nen thieu phan tu cuoi chua in ra
    switch (choose)
    {
    case 0:
        y = p->s.maSV;
        break;
    case 1:
        y = p->s.Ho;
        break;
    case 2:
        y = p->s.Ten;
        break;
    case 3:
        y = p->s.Lop;
        break;
    case 4:
        y = to_string(p->s.Diem);
        break;
    default:
        cout << "ERROR!\n";
        // return;
    }
    if (compareChar(y, x)) {
        Insert_Last3(a, p->s);
    }
    return a;
}
sv3 Search_info3_D(sv3 Last, int x){   // tìm phan tu có noi dung là x
    sv3 p;
    if (Empty3(Last))
        return (NULL);
    else{
        p = Last->next;  // p chi toi phan tu dau cua dslk vong
        if (p->s.Diem==x)
            return (p);
        else{
            p=p->next;
            while(p != Last->next && p->s.Diem != x )
                p = p->next;
            return (p->s.Diem==x ? p : NULL);
        }
    }
}

sv3 Search_position3(sv3 Last, int x){
    int i = -1;
    if(x == Size3(Last) - 1)
        return Last;
    for(sv3 p = Last->next; p != Last; p = p->next) {
        ++i;
        if (i == x) {
            return p;
        }
    }
    return NULL;
}

void Delete_first3(sv3& Last){
    sv3 p;
    if(Empty3(Last))
        cout<<"Khong co nut trong danh sach lien ket vong, nen khong the xoa";
    else{
        p = Last->next;    // nut can xoa la nut dau
        if (p == Last)  	// danh sach chi co 1 nut
            Last = NULL;
        else
            Last->next = p->next;
        delete p;
    }
}

void Delete_last3(sv3 &Last){
    sv3 p, q;
    if(Empty3(Last))
        cout<<"Khong co nut trong danh sach lien ket vong, nen khong the xoa";
    else{
        p = Last;    // nut can xoa la nut cuoi
        if (Last->next == Last)  	// danh sach chi co 1 nut
            Last = NULL;
        else{
            for (q=Last->next; q->next != Last; q=q->next);	// q dung ngay truoc Last
            
            q->next = Last->next;
            Last = q;
        }
        delete p;
    }
}

void Delete_after3(sv3& Last, sv3 p){
    sv3 q;
    if(Empty3(Last))
        cout<<"Khong co nut trong danh sach lien ket vong, nen khong the xoa";
    else{ // neu p la NULL hoac danh sach chi co 1 nut
        if((p == NULL) || (Last->next == Last))
            cout<<"khong the xoa trong danh sach lien ket vong duoc";
        else{
            q = p->next;//q la phan tu sau p
            if (p->next == Last){//Phan tu can xoa la phan tu cuoi
                p->next = Last->next;
                Last = p;
            }
            else{
                p->next = q->next;
            }
            delete q;
        }
    }
}

void Delete_info3(sv3& Last, string x){//Xoa theo maSV
    sv3 p = Last;
    if(Last == NULL)	return;
    if(Last->s.maSV == x){
        Delete_last3(Last);
        return;
    }
    for(p = Last->next; p->next != Last && !compareChar(p->next->s.maSV, x); p = p->next){
        if (p->next != Last){
            Delete_after3(Last, p);
            return;
        }
    }
}

sv3 TimMaxMin3(sv3 Last, int choose) {
    sv3 a = NULL;
    sv3 p = Last;
    if(Empty3(Last))
        return a;
    float maxmin;
    if (choose == 1) {//Tim Max
        maxmin = 0;
        do{
            if (p->s.Diem > maxmin) {
                maxmin = p->s.Diem;
            }
            p = p->next;
        }while (p != Last);
    }
    else {//Tim Min
        maxmin = 10;
        do{
            if (p->s.Diem < maxmin) {
                maxmin = p->s.Diem;
            }
            p = p->next;
        }while (p != Last);
    }

    p = Last;
    do{
        if (p->s.Diem == maxmin) {
            // in(First->s);
            Insert_Last3(a, p->s);
        }
        p = p->next;
    }while (p != Last);

    return a;
}

float TinhTB3(sv3 Last){
    float tb = 0.0;
    int n = Size3(Last); 
    if(Empty3(Last))
        return 0;
    sv3 p = Last;
    do{
        tb += p->s.Diem;
        p = p->next;
    }while (p != Last);
    return tb / n;
}

void Bubble_sort3(sv3& Last, int choose) {
    for (sv3 q = Last->next; q->next != Last->next; q = q->next) {
        for (sv3 p = q->next; p != Last->next; p = p->next) {
            switch(choose){
            case 0://ma SV
                if (q->s.maSV > p->s.maSV) {
                    swap(q->s, p->s);
                }
                break;
            case 1://ten
                if (compareName(q->s.Ten, p->s.Ten) == 1) {
                    swap(q->s, p->s);
                }
                else if(compareName(q->s.Ten, p->s.Ten) == 0 && compareName(q->s.Ho, p->s.Ho) == 1){
                    swap(q->s, p->s);
                }
                break;
            case 2://diem
                if (q->s.Diem > p->s.Diem) {
                    swap(q->s, p->s);
                }
                break;
            }
        }
    }
}

void Insertion_sort3(sv3& Last, int choose) {
    sv3 p = Last->next, pos;
    sv3 x = new Node3;
    for (p = p->next; p != Last->next; p = p->next){
        x->s = p->s;
        pos = p;//pos mang dia chi cua node dang xet
        while (pos != Last->next)
        {
            sv3 q = Last->next;
            while (q->next != pos)//q tro vao node truoc pos
                q = q->next;

            bool chk = true;
            switch(choose){
            case 0://ma SV
                if (q->s.maSV > x->s.maSV){
                    pos->s = q->s;//thay gia tri q cho pos
                    sv3 r = Last->next;
                    while (r->next != pos)//r tro vao node truoc pos
                        r = r->next;
                    pos = r;//doi pos ra truoc, de tiep tuc so sanh voi x (pos mang dia chi cua r va co gia tri cua q)

                    chk = false;
                }
                break;
            case 1://ten
                if (compareName(q->s.Ten, x->s.Ten) == 1 || (compareName(q->s.Ten, x->s.Ten) == 0 && compareName(q->s.Ho, x->s.Ho) == 1)){
                    pos->s = q->s;
                    sv3 r = Last->next;
                    while (r->next != pos)
                        r = r->next;
                    pos = r;

                    chk = false;
                }
                break;
            case 2://diem
                if (q->s.Diem > x->s.Diem){
                    pos->s = q->s;
                    sv3 r = Last->next;
                    while (r->next != pos)
                        r = r->next;
                    pos = r;

                    chk = false;
                }
                break;
            }
            if (chk)//vi tri cua pos hop le, dung vong lap
                break;
        }
        pos->s = x->s;//khi doi pos den vi tri thich hop thi thay gia tri x cho pos
    }
}

void Selection_sort3(sv3& Last, int choose){
    for (sv3 p = Last->next; p->next != Last->next; p = p->next) {
        sv3 min = p;
        for (sv3 q = p->next; q != Last->next; q = q->next) {
            switch(choose){
            case 0://ma SV
                if (q->s.maSV < min->s.maSV)
                    min = q;
                break;
            case 1://ten
                if (compareName(q->s.Ten, min->s.Ten) == -1) {
                    min = q;
                }
                else if(compareName(q->s.Ten, p->s.Ten) == 0 && compareName(q->s.Ho, p->s.Ho) == -1){
                    min = q;
                }
                break;
            case 2://diem
                if (q->s.Diem < min->s.Diem)
                    min = q;
                break;
            }
        }
        if (min != p)
            swap(min->s, p->s);
    }
}

int Partition3(sv3& Last, int left, int right, int choose){
    sv3 x = Search_position3(Last, left);
    int i = left + 1;
    int j = right;
    do{
        switch(choose){
        case 0://ma sv3
            while(i <= j && Search_position3(Last, i)->s.maSV <= x->s.maSV)
                i++;
            while(i <= j && Search_position3(Last, j)->s.maSV > x->s.maSV)
                j--;
            break;
        case 1://ten
            while(i <= j && (
                       (compareName(Search_position3(Last, i)->s.Ten, x->s.Ten) == -1
                        || (compareName(Search_position3(Last, i)->s.Ten, x->s.Ten) == 0 && compareName(Search_position3(Last, i)->s.Ho, x->s.Ho) == -1))
                       ||
                       (compareName(Search_position3(Last, i)->s.Ten, x->s.Ten) == 0 && compareName(Search_position3(Last, i)->s.Ho, x->s.Ho) == 0)
                       )
                   )
                i++;
            while(i <= j && (compareName(Search_position3(Last, j)->s.Ten, x->s.Ten) == 1
                              || (compareName(Search_position3(Last, j)->s.Ten, x->s.Ten) == 0 && compareName(Search_position3(Last, j)->s.Ho, x->s.Ho) == 1)))
                j--;
            break;
        case 2://diem
            while(i <= j && Search_position3(Last, i)->s.Diem <= x->s.Diem)
                i++;
            while(i <= j && Search_position3(Last, j)->s.Diem > x->s.Diem)
                j--;
            break;
        }
        if(i < j){
            sv3 y = Search_position3(Last, i);
            sv3 z = Search_position3(Last, j);
            swap(y->s, z->s);
            i++;j--;
        }
    }while(i <= j);
    x = Search_position3(Last, left);
    sv3 z = Search_position3(Last, j);
    swap(x->s, z->s);
    return j;
}
void Quick_sort3(sv3& Last, int left, int right, int choose){
    int k;
    if(left < right){
        k = Partition3(Last, left, right, choose);
        Quick_sort3(Last, left, k-1, choose);
        Quick_sort3(Last, k+1, right, choose);
    }
}

void Heapify3(sv3& Last, int n, int i, int choose) {
    int largest = i;//Dat nut lon nhat la goc
    int leftIndex = 2 * i + 1;//vi tri nut con ben trai
    int rightIndex = 2 * i + 2;//vi tri nut con ben phai

    sv3 left = Search_position3(Last, leftIndex);
    sv3 right = Search_position3(Last, rightIndex);
    sv3 current = Search_position3(Last, i);//Dat nut goc

    switch(choose){
    case 0://ma SV
        if (leftIndex < n && left->s.maSV > Search_position3(Last, largest)->s.maSV) {//Nut ben trai lon hon nut goc
            largest = leftIndex;
        }
        if (rightIndex < n && right->s.maSV > Search_position3(Last, largest)->s.maSV) {//Nut ben phai lon hon nut goc
            largest = rightIndex;
        }
        break;
    case 1://ten
        if (leftIndex < n && (compareName(left->s.Ten, Search_position3(Last, largest)->s.Ten) == 1 ||
                              (compareName(left->s.Ten, Search_position3(Last, largest)->s.Ten) == 0 && compareName(left->s.Ho, Search_position3(Last, largest)->s.Ho) == 1))) {//Nut ben trai lon hon nut goc
            largest = leftIndex;
        }
        if (rightIndex < n && (compareName(right->s.Ten, Search_position3(Last, largest)->s.Ten) == 1 ||
                               (compareName(right->s.Ten, Search_position3(Last, largest)->s.Ten) == 0 && compareName(right->s.Ho, Search_position3(Last, largest)->s.Ho) == 1))) {//Nut ben phai lon hon nut goc
            largest = rightIndex;
        }
        break;
    case 2://diem
        if (leftIndex < n && left->s.Diem > Search_position3(Last, largest)->s.Diem) {//Nut ben trai lon hon nut goc
            largest = leftIndex;
        }
        if (rightIndex < n && right->s.Diem > Search_position3(Last, largest)->s.Diem) {//Nut ben phai lon hon nut goc
            largest = rightIndex;
        }
        break;
    }

    if (largest != i) {//largest khong phai goc
        swap(current->s, Search_position3(Last, largest)->s);//Hoan vi nut goc va nut lon nhat
        Heapify3(Last, n, largest, choose);
    }
}
void Heap_sort3(sv3& Last, int choose) {
    int n = Size3(Last);
    for (int i = n / 2 - 1; i >= 0; i--) {//Vun dong tu duoi len (Hieu chinh thanh Heap)
        Heapify3(Last, n, i, choose);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(Last->next->s, (Search_position3(Last, i))->s);//Dua node nho nhat ve cuoi, de loai bo node nho nhat(n--)
        Heapify3(Last, i, 0, choose);//Hieu chinh phan con lai thanh Heap
    }
}

void Merge3(sv3& Last, int left, int mid, int right, int choose){
    int i = left;
    int j = mid + 1;
    int n = right - left + 1;
    sv3 b = NULL;//Tao dslk moi
    while(i < mid+1 && j < right+1){//Tim node nho hon sau do luu vao dslk moi b
        sv3 x = Search_position3(Last, i);
        sv3 y = Search_position3(Last, j);
        switch(choose){
        case 0://ma SV
            if(x->s.maSV < y->s.maSV){
                Insert_Last3(b, x->s);
                i++;
            }
            else{
                Insert_Last3(b, y->s);
                j++;
            }
            break;
        case 1://ten
            if(compareName(x->s.Ten, y->s.Ten) == -1){
                Insert_Last3(b, x->s);
                i++;
            }
            else if(compareName(x->s.Ten, y->s.Ten) == 0 && compareName(x->s.Ho, y->s.Ho) == -1){
                Insert_Last3(b, x->s);
                i++;
            }
            else{
                Insert_Last3(b, y->s);
                j++;
            }
            break;
        case 2://diem
            if(x->s.Diem < y->s.Diem){
                Insert_Last3(b, x->s);
                i++;
            }
            else{
                Insert_Last3(b, y->s);
                j++;
            }
            break;
        }
    }
    while(i < mid+1){//Truong hop da xet het node ben phai mid, ta luu het node con lai ben trai vao dslk moi b
        sv3 x = Search_position3(Last, i);
        Insert_Last3(b, x->s);
        i++;
    }
    while(j < right+1){//Truong hop da xet het node ben trai mid, ta luu het node con lai ben phai vao dslk moi b
        sv3 y = Search_position3(Last, j);
        Insert_Last3(b, y->s);
        j++;
    }
    //Cap nhat gia tri cua b vao Last
    i = left;
    for(int k = 0; k < n; k++){
        sv3 p = Search_position3(Last, i);
        swap(p->s, Search_position3(b, k)->s);
        i++;
    }
    delete b;
}
void Merge_sort3(sv3& Last, int left, int right, int choose){
    if(left < right){
        int mid = (left+right)/2;
        Merge_sort3(Last, left, mid, choose);
        Merge_sort3(Last, mid+1, right, choose);
        Merge3(Last, left, mid, right, choose);
    }
}

bool DocFile3(sv3& Last, string myFilePath) {
    ifstream allStudents;
    allStudents.open(myFilePath);

    if (!allStudents) {
        cout << myFilePath << ": Open fail!\n";
        return false;
        // exit(1);
    }
    string stt;
    while (getline(allStudents, stt, ',')) {
        string m, hl, t, l;
        float d;
        getline(allStudents, m, ',');
        getline(allStudents, hl, ',');
        getline(allStudents, t, ',');
        getline(allStudents, l, ',');
        allStudents >> d;
        Student x(m, hl, t, l, d);
        Insert_Last3(Last, x);
    }
    allStudents.close();
    return true;
}

void WriteFile3(sv3 Last, string myNewFile) {
    ofstream fout(myNewFile, ofstream::binary);
    if (!fout) {
        cout << "Khong the mo file " << myNewFile << endl;
        return;
    }
    int i=1;
    //	fout << "STT" << ',' << "Ma sinh vien" << ',' << "Ho va ten" << ',' << "Ten" << ',' << "Lop" << ',' << "Diem" << endl;
    sv3 p = Last->next;
    while (p != Last){
        fout << i++ << ',' << p->s.maSV << ',' << p->s.Ho << ',' << p->s.Ten << ',' << p->s.Lop << ',' << p->s.Diem << endl;
        p = p->next;
    }
    //Vong lap dung khi gap Last nen thieu phan tu cuoi chua in ra
    fout << i++ << ',' << p->s.maSV << ',' << p->s.Ho << ',' << p->s.Ten << ',' << p->s.Lop << ',' << p->s.Diem;
    fout.close();
}

void Clearlist3(sv3 &Last){
    while(Last != NULL)
        Delete_first3(Last);
}
