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

struct Node2{
    Student s;
    Node2 *left, *right;
};

typedef struct Node2* sv2;

sv2 makeNode2(Student x) {
    sv2 tmp = new Node2();
    tmp->s = x;
    tmp->right = NULL;
    tmp->left = NULL;
    return tmp;
}

int Size2(sv2 First) {
    int cnt = 0;
    while (First != NULL) {
        ++cnt;
        First = First->right;
    }
    return cnt;
}

bool Empty2(sv2 First){
    return First == NULL;
}

void Insert_First2(sv2 &First, sv2& Last, Student x){
    sv2 p = makeNode2(x);
    if(First == NULL)      // truong hop danh sach rong
        Last = p;
    else{
        p->right = First;
        First->left = p;	// tao lien ket giua p va First
    }
    First = p;
}

void Insert_right2(sv2 p, sv2& Last, Student x){//q la nut can them vao, p la nut truoc q, r la nut sau q
    sv2 q, r;
    if(p == NULL)
        printf("Nut p khong hien huu, khong them nut duoc\n");
    else{
        q = makeNode2(x);//Node can them vao
        r = p->right;
        // tao hai lien ket giua r va q
        if(p == Last)
            Last = q;
        else
            r->left = q;
        q->right = r;
        // tao hai lien ket giua p va q
        q->left = p;
        p->right = q;
    }
}

void Insert_Last2(sv2 &First, sv2 &Last, Student x){
    sv2 tmp = makeNode2(x);
    if(First == NULL){
        First = tmp;
        Last = First;
    }
    else{
        tmp->left = Last;
        Last->right = tmp;
        Last = tmp;
    }
}

//void Add(sv2& First, sv2& Last) {
//	cout << "Nhap so sinh vien: ";
//	int n; cin >> n;
//	for (int i = 1; i <= n; i++) {
//		cout << "Nhap thong tin sinh vien " << i << ":\n";
//		string m, hl, t, l;
//		float d;
//		cout << "Nhap ma :";
//		cin.ignore();
//		getline(cin, m);
//		cout << "Nhap ho :";
//		getline(cin, hl);
//		cout << "Nhap tem :";
//		getline(cin, t);
//		cout << "Nhap lop :";
//		getline(cin, l);
//		cout << "Nhap diem :";
//		cin >> d;
//		Student x(m, hl, t, l, d);
//		Insert_First(First, Last, x);
//	}
//}
void Add2(sv2& First, sv2& Last, string m, string hl, string t, string l, float d) {
    Student x(m, hl, t, l, d);
    Insert_Last2(First, Last, x);
}

sv2 Search_position2(sv2 First, int x) {
    int i = -1;
    sv2 p;
    for (p = First; p != NULL; p = p->right) {
        ++i;
        if (i == x) {
            return p;
        }
    }
    return NULL;
}

// void in(Student s) {
//     cout << left << setw(20) << s.maSV << setw(30) << s.Ho << setw(15) << s.Ten << setw(20) << s.Lop << s.Diem << endl;
// }

void duyetDSSV2(sv2 First) {
    cout << left << setw(20) << "Ma sinh vien" << setw(30) << "Ho va ten" << setw(15) << "Ten" << setw(20) << "Lop" << "Diem" << endl;
    while(First != NULL) {
        cout << left << setw(20) << First->s.maSV << setw(30) << First->s.Ho << setw(15) << First->s.Ten << setw(20) << First->s.Lop << First->s.Diem << endl;
        First = First->right;
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

sv2 Search_info2(sv2 First, string x, int choose){
    sv2 af = NULL;
    sv2 al = NULL;
    cout<<"Xong";
    // char c;
    // do {
    //     cout << "\n Dao chuoi (y/n) \n";
    //     cin >> c;
    // } while (c != 'n' && c != 'y');
    string y;
    for (sv2 p = First; p != NULL; p = p->right) {
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
            Insert_Last2(af, al, p->s);
            // cout << left << setw(20) << p->s.maSV << setw(15) << Daochuoi(p->s.Ten) << setw(30) << Daochuoi(p->s.Ho) << setw(20) << p->s.Lop << p->s.Diem << endl;
        }
    }
    cout<<"Xong";
    return af;
}

void Delete_first2(sv2 &First){
    sv2 p;
    if(Empty2(First))  // truong hop danh sach rong
        printf("Danh sach rong!");
    else{
        p = First;  // p la nut can xoa
        if(First->right == NULL)  // truong hop danh sach co mot nut
            First = NULL;
        else{
            First = p->right;
            First->left = NULL;
        }
        delete p;
    }
}

void Delete_node2(sv2 &First, sv2& Last, sv2 p){
    sv2 q, r;
    if(p == NULL)
        printf("Nut p khong hien huu, khong xoa nut duoc\n");
    else{
        if(First == NULL)  // truong hop danh sach rong
            printf("Danh sach rong!");
        else{
            if(p == First)  // truong hop xoa nut dau
                Delete_first2(First);
            else{
                q = p->left;   // q la nut truoc
                r = p->right;  // r la nut sau
                // tao hai lien ket giua q va r
                if (p == Last){
                    Last = q;
                }
                else{
                    r->left = q;
                }
                q->right = r;
                delete p;
            }
        }
    }
}

sv2 getTail(sv2 First) {//Tra ve node cuoi cung cua dslk
    while (First != NULL && First->right != NULL) {
        First = First->right;
    }
    return First;
}

void Delete_info2(sv2& First, sv2& Last, string x){//Xoa theo masv2
    sv2 p = First;
    if (First == NULL)	return;
    if (First->s.maSV == x) {
        Delete_first2(First);
        return;
    }
    for (p = First; p != NULL && !compareChar(p->s.maSV, x); p = p->right) {
        if (p != NULL) {
            Delete_node2(First, Last, p);
            return;
        }
    }
}

sv2 TimMaxMin2(sv2 First, int choose) {
    sv2 af = NULL;
    sv2 al = NULL;
    sv2 p = First;
    float maxmin;
    if (choose == 1) {//Tìm Max
        maxmin = 0;
        while (First != NULL) {
            if (First->s.Diem > maxmin) {
                maxmin = First->s.Diem;
            }
            First = First->right;
        }
    }
    else {
        maxmin = 10;
        while (First != NULL) {
            if (First->s.Diem < maxmin) {
                maxmin = First->s.Diem;
            }
            First = First->right;
        }
    }
    while (p != NULL) {
        if (p->s.Diem == maxmin) {
            // in(First->s);
            Insert_Last2(af, al, p->s);
        }
        p = p->right;
    }
    return af;
}

float TinhTB2(sv2 First) {
    float tb = 0.0;
    int n = Size2(First);
    while (First != NULL) {
        tb += First->s.Diem;
        First = First->right;
    }
    return n > 0 ? tb / n : 0;
}

void Bubble_sort2(sv2& First, int choose) {
    for (sv2 q = First; q->right != NULL; q = q->right) {
        for (sv2 p = q->right; p != NULL; p = p->right) {
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
void Bubble_sort_D(sv2& First, sv2& Last, int choose){
    for(sv2 p = First; p->right != NULL; p = p->right){
        for(sv2 q=Last ; q != p; q = q->left){
            switch(choose){
            case 0://ma SV
                if (q->s.maSV > q->left->s.maSV) {
                    swap(q->s, q->left->s);
                }
                break;
            case 1://ten
                if (compareName(q->s.Ten, q->left->s.Ten) == 1) {
                    swap(q->s, q->left->s);
                }
                else if(compareName(q->s.Ten, q->left->s.Ten) == 0 && compareName(q->s.Ho, q->left->s.Ho) == 1){
                    swap(q->s, q->left->s);
                }
                break;
            case 2://diem
                if (q->s.Diem > q->left->s.Diem) {
                    swap(q->s, q->left->s);
                }
                break;
            }
        }
    }
}

void Insertion_sort2(sv2& First, int choose) {
    sv2 p, pos;
    sv2 x = new Node2;
    for (p = First->right; p != NULL; p = p->right)
    {
        x->s = p->s;
        pos = p;//pos mang dia chi cua node dang xet
        while (pos != First)
        {
            sv2 q = First;
            while (q->right != pos)//q tro vao node truoc pos
                q = q->right;

            bool chk = true;
            switch(choose){
            case 0://ma SV
                if (q->s.maSV > x->s.maSV){
                    pos->s = q->s;//thay gia tri q cho pos
                    sv2 r = First;
                    while (r->right != pos)//r tro vao node truoc pos
                        r = r->right;
                    pos = r;//doi pos ra truoc, de tiep tuc so sanh voi x (pos mang dia chi cua r va co gia tri cua q)

                    chk = false;
                }
                break;
            case 1://ten
                if (compareName(q->s.Ten, x->s.Ten) == 1 || (compareName(q->s.Ten, x->s.Ten) == 0 && compareName(q->s.Ho, x->s.Ho) == 1)){
                    pos->s = q->s;
                    sv2 r = First;
                    while (r->right != pos)
                        r = r->right;
                    pos = r;

                    chk = false;
                }
                break;
            case 2://diem
                if (q->s.Diem > x->s.Diem){
                    pos->s = q->s;
                    sv2 r = First;
                    while (r->right != pos)
                        r = r->right;
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
//void Insertion_sort2(sv2& First, sv2& Last){
//	sv2 i = First;
//  	for(i = i->right; i != NULL; i = i->right){
//  		Student x = i->s;
//  		Delete_node(First, Last, i);
//     	for(sv2 j = i->left; j != NULL; j = j->left){
//     		if(x.Diem > j->s.Diem){//x nam trong khoang giua
//     			Insert_right(j, Last, x);
//     			break;
//			}
//			else if(j->left == NULL && x.Diem < j->s.Diem)//x la node nho nhat
//				Insert_First(First, Last, x);
//		}
//  	}
//}

void Selection_sort2(sv2& First, int choose) {
    for (sv2 p = First; p->right != NULL; p = p->right) {
        sv2 min = p;
        for (sv2 q = p->right; q != NULL; q = q->right) {
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

int Partition2(sv2& First, int left, int right, int choose){
    sv2 x = Search_position2(First, left);
    int i = left + 1;
    int j = right;
    do{
        switch(choose){
        case 0://ma SV
            while(i <= j && Search_position2(First, i)->s.maSV <= x->s.maSV)
                i++;
            while(i <= j && Search_position2(First, j)->s.maSV > x->s.maSV)
                j--;
            break;
        case 1://ten
            while(i <= j && (
                       (compareName(Search_position2(First, i)->s.Ten, x->s.Ten) == -1
                        || (compareName(Search_position2(First, i)->s.Ten, x->s.Ten) == 0 && compareName(Search_position2(First, i)->s.Ho, x->s.Ho) == -1))
                       ||
                       (compareName(Search_position2(First, i)->s.Ten, x->s.Ten) == 0 && compareName(Search_position2(First, i)->s.Ho, x->s.Ho) == 0)
                       )
                   )
                i++;
            while(i <= j && (compareName(Search_position2(First, j)->s.Ten, x->s.Ten) == 1
                              || (compareName(Search_position2(First, j)->s.Ten, x->s.Ten) == 0 && compareName(Search_position2(First, j)->s.Ho, x->s.Ho) == 1)))
                j--;
            break;
        case 2://diem
            while(i <= j && Search_position2(First, i)->s.Diem <= x->s.Diem)
                i++;
            while(i <= j && Search_position2(First, j)->s.Diem > x->s.Diem)
                j--;
            break;
        }

        if(i < j){
            sv2 y = Search_position2(First, i);
            sv2 z = Search_position2(First, j);
            swap(y->s, z->s);
            i++;j--;
        }
    }while(i <= j);
    x = Search_position2(First, left);
    sv2 z = Search_position2(First, j);
    swap(x->s, z->s);
    return j;
}
void Quick_sort2(sv2& First, int left, int right, int choose){
    int k;
    if(left < right){
        k = Partition2(First, left, right, choose);
        Quick_sort2(First, left, k-1, choose);
        Quick_sort2(First, k+1, right, choose);
    }
}

void Heapify2(sv2& First, int n, int i, int choose) {
    int largest = i;//Dat nut lon nhat la goc
    int leftIndex = 2 * i + 1;//vi tri nut con ben trai
    int rightIndex = 2 * i + 2;//vi tri nut con ben pbai

    sv2 left = Search_position2(First, leftIndex);
    sv2 right = Search_position2(First, rightIndex);

    switch(choose){
    case 0://ma SV
        if (leftIndex < n && left->s.maSV > Search_position2(First, largest)->s.maSV) {//Nut ben trai lon hon nut goc
            largest = leftIndex;
        }
        if (rightIndex < n && right->s.maSV > Search_position2(First, largest)->s.maSV) {//Nut ben phai lon hon nut goc
            largest = rightIndex;
        }
        break;
    case 1://ten
        if (leftIndex < n && (compareName(left->s.Ten, Search_position2(First, largest)->s.Ten) == 1 ||
                              (compareName(left->s.Ten, Search_position2(First, largest)->s.Ten) == 0 && compareName(left->s.Ho, Search_position2(First, largest)->s.Ho) == 1))) {//Nut ben trai lon hon nut goc
            largest = leftIndex;
        }
        if (rightIndex < n && (compareName(right->s.Ten, Search_position2(First, largest)->s.Ten) == 1 ||
                               (compareName(right->s.Ten, Search_position2(First, largest)->s.Ten) == 0 && compareName(right->s.Ho, Search_position2(First, largest)->s.Ho) == 1))) {//Nut ben phai lon hon nut goc
            largest = rightIndex;
        }
        break;
    case 2://diem
        if (leftIndex < n && left->s.Diem > Search_position2(First, largest)->s.Diem) {//Nut ben trai lon hon nut goc
            largest = leftIndex;
        }
        if (rightIndex < n && right->s.Diem > Search_position2(First, largest)->s.Diem) {//Nut ben phai lon hon nut goc
            largest = rightIndex;
        }
        break;
    }

    if (largest != i) {//largest khong phai goc
        swap((Search_position2(First, i))->s, (Search_position2(First, largest))->s);//Hoan vi nut goc va nut lon nhat
        Heapify2(First, n, largest, choose);
    }
}
void Heap_sort2(sv2& First, int choose) {
    int n = Size2(First);
    for (int i = n / 2 - 1; i >= 0; i--) {//Vun dong tu duoi len (Hieu chinh thanh Heap)
        Heapify2(First, n, i, choose);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(First->s, (Search_position2(First, i))->s);//Dua node nho nhat ve cuoi, de loai bo node nho nhat(n--)
        Heapify2(First, i, 0, choose);//Hieu chinh phan con lai thanh Heap
    }
}

void Merge2(sv2& First, int left, int mid, int right, int choose){
    int i = left;
    int j = mid + 1;
    int n = right - left + 1;
    sv2 bf = NULL;//Tao dslk moi
    sv2 bl = NULL;
    while(i < mid+1 && j < right+1){//Tim node nho hon sau do luu vao dslk moi b
        sv2 x = Search_position2(First, i);
        sv2 y = Search_position2(First, j);
        switch(choose){
        case 0://ma sv2
            if(x->s.maSV < y->s.maSV){
                Insert_Last2(bf, bl, x->s);
                i++;
            }
            else{
                Insert_Last2(bf, bl, y->s);
                j++;
            }
            break;
        case 1://ten
            if(compareName(x->s.Ten, y->s.Ten) == -1){
                Insert_Last2(bf, bl, x->s);
                i++;
            }
            else if(compareName(x->s.Ten, y->s.Ten) == 0 && compareName(x->s.Ho, y->s.Ho) == -1){
                Insert_Last2(bf, bl, x->s);
                i++;
            }
            else{
                Insert_Last2(bf, bl, y->s);
                j++;
            }
            break;
        case 2://diem
            if(x->s.Diem < y->s.Diem){
                Insert_Last2(bf, bl, x->s);
                i++;
            }
            else{
                Insert_Last2(bf, bl, y->s);
                j++;
            }
            break;
        }
    }
    while(i < mid+1){//Truong hop da xet het node ben phai mid, ta luu het node con lai ben trai vao dslk moi b
        sv2 x = Search_position2(First, i);
        Insert_Last2(bf, bl, x->s);
        i++;
    }
    while(j < right+1){//Truong hop da xet het node ben trai mid, ta luu het node con lai ben phai vao dslk moi b
        sv2 y = Search_position2(First, j);
        Insert_Last2(bf, bl, y->s);
        j++;
    }
    //Cap nhat gia tri cua b vao Last
    i = left;
    for(int k = 0; k < n; k++){
        sv2 p = Search_position2(First, i);
        swap(p->s, Search_position2(bf, k)->s);
        i++;
    }
    delete bf;
    delete bl;
}
void Merge_sort2(sv2& First, int left, int right, int choose){
    if(left < right){
        int mid = (left+right)/2;
        Merge_sort2(First, left, mid, choose);
        Merge_sort2(First, mid+1, right, choose);
        Merge2(First, left, mid, right, choose);
    }
}

bool DocFile2(sv2& First, sv2& Last, string myFilePath) {
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
        Insert_Last2(First, Last, x);
    }
    allStudents.close();
    return true;
}

void WriteFile2(sv2 First, string myNewFile) {
    ofstream fout(myNewFile, ofstream::binary);
    if (!fout) {
        cout << "Khong the mo file " + myNewFile << endl;
        return;
    }
    int i=1;
    //	fout << "STT" << ',' << "Ma sinh vien" << ',' << "Ho va ten" << ',' << "Ten" << ',' << "Lop" << ',' << "Diem" << endl;
    while (First != NULL) {
        fout << i++ << ',' << First->s.maSV << ',' << First->s.Ho << ',' << First->s.Ten << ',' << First->s.Lop << ',' << First->s.Diem;
        if(First->right != NULL)
            fout << endl;
        First = First->right;
    }
    fout.close();
}

void Clearlist2(sv2 &First){
    while(First != NULL)
        Delete_first2(First);
}
