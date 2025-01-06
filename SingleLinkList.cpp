#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Array.h"
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

struct Node {
    Student s;
    struct Node *next;
};
typedef struct Node* sv;

sv makeNode(Student x) {
    sv tmp = new Node();
    tmp->s = x;
    tmp->next = NULL;
    return tmp;
}

int Size(sv First) {
    int cnt = 0;
    while (First != NULL) {
        ++cnt;
        First = First->next;
    }
    return cnt;
}

//void Insert_First(sv& First, Student x){
//	sv tmp = makeNode(x);
//	tmp->next = First;
//	First = tmp;
//}

//void Insert_After(sv p, int x){
//	if(p == NULL)
//		printf("khong them phan tu vao danh sach duoc");
//	else
//	{ 
//		sv q = makeNode(x);
//		q->next = p->next;
//		p->next = q;
//	}
//}


void Insert_Last(sv& First, Student x) {
    sv tmp = makeNode(x);
    if (First == NULL) {
        First = tmp;
        return;
    }
    else {
        sv p = First;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = tmp;
    }
}

// void Add(sv& First) {
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
//         Insert_Last(First, x);
//     }
// }
void Add(sv& First, string m, string hl, string t, string l, float d) {
    Student x(m, hl, t, l, d);
    Insert_Last(First, x);
}

// void in(Student s) {
//     cout << left << setw(20) << s.maSV << setw(30) << s.Ho << setw(15) << s.Ten << setw(20) << s.Lop << s.Diem << endl;
// }

void duyetDSSV(sv First) {
    cout << left << setw(20) << "Ma sinh vien" << setw(30) << "Ho va ten" << setw(15) << "Ten" << setw(20) << "Lop" << "Diem" << endl;
    while (First != NULL) {
        cout << left << setw(20) << First->s.maSV << setw(30) << First->s.Ho << setw(15) << First->s.Ten << setw(20) << First->s.Lop << First->s.Diem << endl;
        First = First->next;
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

sv Search_info(sv First, string x, int choose){
    sv a = NULL;
    // char c;
    // do {
    //     cout << "\n Dao chuoi (y/n) \n";
    //     cin >> c;
    // } while (c != 'n' && c != 'y');
    string y;
    for (sv p = First; p != NULL; p = p->next) {
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
        // if (compareChar(y, x) && c == 'y') {
        //     cout << left << setw(20) << p->s.maSV << setw(15) << Daochuoi(p->s.Ten) << setw(30) << Daochuoi(p->s.Ho) << setw(20) << p->s.Lop << p->s.Diem << endl;
        // }

        if (compareChar(y, x)) {
            Insert_Last(a, p->s);
            // cout << left << setw(20) << p->s.maSV << setw(15) << Daochuoi(p->s.Ten) << setw(30) << Daochuoi(p->s.Ho) << setw(20) << p->s.Lop << p->s.Diem << endl;
        }
    }
    return a;
}

sv Search_position(sv First, int x) {
    int i = -1;
    sv p;
    for (p = First; p != NULL; p = p->next) {
        ++i;
        if (i == x) {
            return p;
        }
    }
    return NULL;
}

void Delete_first(sv& First) {
//    if (First == NULL)
//        return;
//    First = First->next;
    //Cach 2
	sv p;
	if(First == NULL)
		return;
	p = First;    // nut can xoa la nut dau
	First = p->next;
	delete p;  // huy node p, tra vùng nho ve lai cho memory heap
}

void Delete_after(sv p) {
    sv q;
    if ((p == NULL) || (p->next == NULL))
        return;
    q = p->next;
    p->next = q->next;
    delete q;
}

void Delete_info(sv& First, string x){//Xoa theo maSV
    sv p = First;
    if (First == NULL)	return;
    if (compareChar(First->s.maSV, x)) {
        Delete_first(First);
        return;
    }
    for (p = First; p->next != NULL && !compareChar(p->next->s.maSV, x); p = p->next);//;
    
    if (p->next != NULL) {
        Delete_after(p);
        return;
    }
    return;
}

sv TimMaxMin(sv First, int choose) {
    sv a = NULL;
    sv p = First;
    float maxmin;
    if (choose == 1) {//Tìm Max
        maxmin = 0;
        while (First != NULL) {
            if (First->s.Diem > maxmin) {
                maxmin = First->s.Diem;                
            }
            First = First->next;
        }
    }
    else {
        maxmin = 10;
        while (First != NULL) {
            if (First->s.Diem < maxmin) {
                maxmin = First->s.Diem;            
            }
            First = First->next;
        }
    }
    while (p != NULL) {
        if (p->s.Diem == maxmin) {
            // in(First->s);
            Insert_Last(a, p->s);
        }
        p = p->next;
    }
    return a;
}

float TinhTB(sv First) {
    float tb = 0.0;
    int n = Size(First);
    while (First != NULL) {
        tb += First->s.Diem;
        First = First->next;
    }
    return n > 0 ? tb / n : 0;
}

void Bubble_sort(sv& First, int choose) {
    for (sv q = First; q->next != NULL; q = q->next) {
        for (sv p = q->next; p != NULL; p = p->next) {
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

void Insertion_sort(sv& First, int choose) {
    sv p, pos;
    sv x = new Node;
    for (p = First->next; p != NULL; p = p->next)
    {
        x->s = p->s;
        pos = p;//pos mang dia chi cua node dang xet
        while (pos != First)
        {
            sv q = First;
            while (q->next != pos)//q tro vao node truoc pos
                q = q->next;

            bool chk = true;
            switch(choose){
            case 0://ma SV
                if (q->s.maSV > x->s.maSV){
                    pos->s = q->s;//thay gia tri q cho pos
                    sv r = First;
                    while (r->next != pos)
                        r = r->next;
                    pos = r;//doi pos ra truoc, de tiep tuc so sanh voi x (pos mang dia chi cua r va co gia tri cua q)

                    chk = false;
                }
                break;
            case 1://ten
                if (compareName(q->s.Ten, x->s.Ten) == 1 || (compareName(q->s.Ten, x->s.Ten) == 0 && compareName(q->s.Ho, x->s.Ho) == 1)){
                    pos->s = q->s;
                    sv r = First;
                    while (r->next != pos)
                        r = r->next;
                    pos = r;

                    chk = false;
                }
                break;
            case 2://diem
                if (q->s.Diem > x->s.Diem){
                    pos->s = q->s;
                    sv r = First;
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

void Selection_sort(sv& First, int choose) {
    for (sv p = First; p->next != NULL; p = p->next) {
        sv min = p;
        for (sv q = p->next; q != NULL; q = q->next) {
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

int Partition(sv& Last, int left, int right, int choose){
    sv x = Search_position(Last, left);
    int i = left + 1;
    int j = right;
    do{
        switch(choose){
        case 0://ma SV
            while(i <= j && Search_position(Last, i)->s.maSV <= x->s.maSV)
                i++;
            while(i <= j && Search_position(Last, j)->s.maSV > x->s.maSV)
                j--;
            break;
        case 1://ten
            while(i <= j && (
                       (compareName(Search_position(Last, i)->s.Ten, x->s.Ten) == -1
                        || (compareName(Search_position(Last, i)->s.Ten, x->s.Ten) == 0 && compareName(Search_position(Last, i)->s.Ho, x->s.Ho) == -1))
                       ||
                       (compareName(Search_position(Last, i)->s.Ten, x->s.Ten) == 0 && compareName(Search_position(Last, i)->s.Ho, x->s.Ho) == 0)
                       )
                   )
                i++;
            while(i <= j && (compareName(Search_position(Last, i)->s.Ten, x->s.Ten) == 1
                              || (compareName(Search_position(Last, i)->s.Ten, x->s.Ten) == 0 && compareName(Search_position(Last, i)->s.Ho, x->s.Ho) == 1)))
                j--;
            break;
        case 2://diem
            while(i <= j && Search_position(Last, i)->s.Diem <= x->s.Diem)
                i++;
            while(i <= j && Search_position(Last, j)->s.Diem > x->s.Diem)
                j--;
            break;
        }

        if(i < j){
            sv y = Search_position(Last, i);
            sv z = Search_position(Last, j);
            swap(y->s, z->s);
            i++;j--;
        }
    }while(i <= j);
    x = Search_position(Last, left);
    sv z = Search_position(Last, j);
    swap(x->s, z->s);
    return j;
}
void Quick_sort(sv& Last, int left, int right, int choose){
    int k;
    if(left < right){
        k = Partition(Last, left, right, choose);
        Quick_sort(Last, left, k-1, choose);
        Quick_sort(Last, k+1, right, choose);
    }
}

void Heapify(sv& First, int n, int i, int choose) {
    int largest = i;//Dat nut lon nhat la goc
    int leftIndex = 2 * i + 1;//vi tri nut con ben trai
    int rightIndex = 2 * i + 2;//vi tri nut con ben phai

    sv left = Search_position(First, leftIndex);
    sv right = Search_position(First, rightIndex);

    switch(choose){
    case 0://ma SV
        if (leftIndex < n && left->s.maSV > Search_position(First, largest)->s.maSV) {//Nut ben trai lon hon nut goc
            largest = leftIndex;
        }
        if (rightIndex < n && right->s.maSV > Search_position(First, largest)->s.maSV) {//Nut ben phai lon hon nut goc
            largest = rightIndex;
        }
        break;
    case 1://ten
        if (leftIndex < n && (compareName(left->s.Ten, Search_position(First, largest)->s.Ten) == 1 ||
                              (compareName(left->s.Ten, Search_position(First, largest)->s.Ten) == 0 && compareName(left->s.Ho, Search_position(First, largest)->s.Ho) == 1))) {//Nut ben trai lon hon nut goc
            largest = leftIndex;
        }
        if (rightIndex < n && (compareName(right->s.Ten, Search_position(First, largest)->s.Ten) == 1 ||
                               (compareName(right->s.Ten, Search_position(First, largest)->s.Ten) == 0 && compareName(right->s.Ho, Search_position(First, largest)->s.Ho) == 1))) {//Nut ben phai lon hon nut goc
            largest = rightIndex;
        }
        break;
    case 2://diem
        if (leftIndex < n && left->s.Diem > Search_position(First, largest)->s.Diem) {//Nut ben trai lon hon nut goc
            largest = leftIndex;
        }
        if (rightIndex < n && right->s.Diem > Search_position(First, largest)->s.Diem) {//Nut ben phai lon hon nut goc
            largest = rightIndex;
        }
        break;
    }

    if (largest != i) {//largest khong phai goc
        swap((Search_position(First, i))->s, (Search_position(First, largest))->s);//Hoan vi nut goc va nut lon nhat
        Heapify(First, n, largest, choose);
    }
}
void Heap_sort(sv& First, int choose) {
    int n = Size(First);
    for (int i = n / 2 - 1; i >= 0; i--) {//Vun dong tu duoi len (Hieu chinh thanh Heap)
        Heapify(First, n, i, choose);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(First->s, (Search_position(First, i))->s);//Dua node nho nhat ve cuoi, de loai bo node nho nhat(n--)
        Heapify(First, i, 0, choose);//Hieu chinh phan con lai thanh Heap
    }
}

void Merge(sv& First, int left, int mid, int right, int choose){
    int i = left;
    int j = mid + 1;
    int n = right - left + 1;
    sv b = NULL;//Tao dslk moi
    while(i < mid+1 && j < right+1){//Tim node nho hon sau do luu vao dslk moi b
        sv x = Search_position(First, i);
        sv y = Search_position(First, j);
        switch(choose){
        case 0://ma SV
            if(x->s.maSV < y->s.maSV){
                Insert_Last(b, x->s);
                i++;
            }
            else{
                Insert_Last(b, y->s);
                j++;
            }
            break;
        case 1://ten
            if(compareName(x->s.Ten, y->s.Ten) == -1){
                Insert_Last(b, x->s);
                i++;
            }
            else if(compareName(x->s.Ten, y->s.Ten) == 0 && compareName(x->s.Ho, y->s.Ho) == -1){
                Insert_Last(b, x->s);
                i++;
            }
            else{
                Insert_Last(b, y->s);
                j++;
            }
            break;
        case 2://diem
            if(x->s.Diem < y->s.Diem){
                Insert_Last(b, x->s);
                i++;
            }
            else{
                Insert_Last(b, y->s);
                j++;
            }
            break;
        }
    }
    while(i < mid+1){//Truong hop da xet het node ben phai mid, ta luu het node con lai ben trai vao dslk moi b
        sv x = Search_position(First, i);
        Insert_Last(b, x->s);
        i++;
    }
    while(j < right+1){//Truong hop da xet het node ben trai mid, ta luu het node con lai ben phai vao dslk moi b
        sv y = Search_position(First, j);
        Insert_Last(b, y->s);
        j++;
    }
    //Cap nhat gia tri cua b vao Last
    i = left;
    for(int k = 0; k < n; k++){
        sv p = Search_position(First, i);
        swap(p->s, Search_position(b, k)->s);
        i++;
    }
    delete b;
}
void Merge_sort(sv& First, int left, int right, int choose){
    if(left < right){
        int mid = (left+right)/2;
        Merge_sort(First, left, mid, choose);
        Merge_sort(First, mid+1, right, choose);
        Merge(First, left, mid, right, choose);
    }
}

bool DocFile(sv& First, string myFilePath) {
    ifstream allStudents;
    allStudents.open(myFilePath);

    if (!allStudents) {
        cout << myFilePath + ": Open fail!\n";
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
        Insert_Last(First, x);
    }
    allStudents.close();
    return true;
}

void WriteFile(sv First, string myNewFile) {
    ofstream fout(myNewFile, ofstream::binary);
    if (!fout) {
        cout << "Khong the mo file " + myNewFile << endl;
        return;
    }
    int i=1;
    //	fout << "STT" << ',' << "Ma sinh vien" << ',' << "Ho va ten" << ',' << "Ten" << ',' << "Lop" << ',' << "Diem" << endl;
    while (First != NULL) {
        fout << i++ << ',' << First->s.maSV << ',' << First->s.Ho << ',' << First->s.Ten << ',' << First->s.Lop << ',' << First->s.Diem;
        if(First->next != NULL)
            fout << endl;
        First = First->next;
    }
    fout.close();
}

void Clearlist(sv &First){
    while(First != NULL)
        Delete_first(First);
}
