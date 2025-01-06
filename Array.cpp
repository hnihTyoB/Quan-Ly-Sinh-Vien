#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stack>
using namespace std;

struct Student {
    string maSV, Ho, Ten, Lop;
    float Diem;

    Student() {
        maSV = Ho = Ten = Lop = "N/A";
        Diem = 0.0;
    }
    Student(string m, string hl, string t, string l, float d) {
        maSV = m;
        Ho = hl;
        Ten = t;
        Lop = l;
        Diem = d;
    }
};

void Insert_first0(Student *s_v, int& n, Student x){
    n++;
    for(int i = n-1; i > 0; i--){
        s_v[i] = s_v[i-1];
    }
    s_v[0] = x;
}

void Insert_after0(Student *s_v, int& n, int p, Student x){//Them vao sau vi tri p
    if(p < 0 || p > n-1)
        cout<<"vi tri p khong hop le\n";
    else
    {
        n++;
        for(int i = n-1; i > p+1; i--){
            s_v[i] = s_v[i-1];
        }
        s_v[p+1] = x;
    }
}

//void Add(Student *s_v, int& n) {
//	cout << "Nhap so sinh vien: ";
//	int num;cin >> num;
//	for (int i = 1; i <= num; i++) {
//		cout << "Nhap thong tin sinh vien " << i << ":\n";
//		cout << "Nhap ma :";
//		cin.ignore();
//		getline(cin, s_v[n].maSV);
//		cout << "Nhap ho :";
//		getline(cin, sv[n].Ho);
//		cout << "Nhap tem :";
//		getline(cin, sv[n].Ten);
//		cout << "Nhap lop :";
//		getline(cin, sv[n].Lop);
//		cout << "Nhap diem :";
//		cin >> sv[n].Diem;
//		n++;
//	}
//}
void Add0(Student *s_v, int& n, string m, string hl, string t, string l, float d) {
    Student x(m, hl, t, l, d);
    s_v[n] = x;
    n++;
}

void duyetDSSV0(Student *s_v, int n) {
    cout << left << setw(20) << "Ma sinh vien" << setw(30) << "Ho va ten" << setw(15) << "Ten" << setw(20) << "Lop" << "Diem" << endl;
    int i = 0;
    while (i < n) {
        cout << left << setw(20) << s_v[i].maSV << setw(30) << s_v[i].Ho << setw(15) << s_v[i].Ten << setw(20) << s_v[i].Lop << s_v[i].Diem << endl;
        i++;
    }
    cout << endl;
}

bool compareChar(string y, string x) {
    for (unsigned long long i = 0; i < x.length(); i++) {
        if (tolower(y[i]) != tolower(x[i]))
            return false;
    }
    return true;
}

int compareName(string x, string y){
    int m = min(x.length(), y.length());
    for(int i = 0; i < m; i++){
        if(x[i] > y[i])
            return 1;
        if(x[i] < y[i])
            return -1;
    }
    if(x.length() > y.length())
        return 1;
    else if(x.length() < y.length())
        return -1;
    else
        return 0;
}

string Daochuoi(string x) {
    stack <char> s;
    for (unsigned long long i = 0; i < x.length(); i++) {
        s.push(x[i]);
    }
    string kq;
    while (!s.empty()) {
        kq += s.top();
        s.pop();
    }
    return kq;
}

int Search_info0(Student *s_v, Student *a, string x, int n, int choose){

    // char c;
    // do {
    //     cout << "\n Dao chuoi (y/n) \n";
    //     cin >> c;
    // } while (c != 'n' && c != 'y');
    string y;
    int k = 0;
    for (int i = 0; i < n; i++) {
        switch (choose)
        {
        case 0:
            y = s_v[i].maSV;
            break;
        case 1:
            y = s_v[i].Ho;
            break;
        case 2:
            y = s_v[i].Ten;
            break;
        case 3:
            y = s_v[i].Lop;
            break;
        case 4:
            y = to_string(s_v[i].Diem);
            break;
        default:
            cout << "ERROR!\n";
            // return;
        }
        // if (compareChar(y, x) && c == 'y') {
        //     cout << left << setw(20) << p->s.maSV << setw(15) << Daochuoi(p->s.Ten) << setw(30) << Daochuoi(p->s.Ho) << setw(20) << p->s.Lop << p->s.Diem << endl;
        // }
        if (compareChar(y, x)) {
            a[k++] = s_v[i];
            // cout << left << setw(20) << p->s.maSV << setw(15) << Daochuoi(p->s.Ten) << setw(30) << Daochuoi(p->s.Ho) << setw(20) << p->s.Lop << p->s.Diem << endl;
        }
    }
    return k;//tra ve so sinh vien trung khop
}

void Delete_first0(Student *s_v, int& n) {
    for(int i = 0; i < n; i++){
        s_v[i] = s_v[i+1];
    }
    n--;
}

void Delete_after0(Student *s_v, int& n, int p) {//Xoa sau vi tri p
    if (p < 0 || p > n-1 || p+1 < 0 || p+1 > n-1)
        return;
    for(int q = p+1; q < n; q++){
        s_v[q] = s_v[q+1];
    }
    n--;
}

void Delete_info0(Student *s_v, int& n, string x){//Xoa theo maSV
    if (compareChar(s_v[0].maSV, x)) {
        Delete_first0(s_v, n);
        return;
    }
    int p;
    for (p = 0; p+1 != n && !compareChar(s_v[p+1].maSV, x); p++);//;
    
    if (p+1 != n) {
        Delete_after0(s_v, n, p);
        return;
    }
    return;
}

int TimMaxMin0(Student *s_v, Student *a, int n, int choose) {

    float maxmin;
    if (choose == 1) {//Tìm Max
        maxmin = 0;
        int i = 0;
        while (i < n) {
            if (s_v[i].Diem > maxmin) {
                maxmin = s_v[i].Diem;
            }
            i++;
        }
    }
    else {//Tim Min
        maxmin = 10;
        int i = 0;
        while (i < n) {
            if (s_v[i].Diem < maxmin) {
                maxmin = s_v[i].Diem;
            }
            i++;
        }
    }
    int i = 0, k = 0;
    while (i < n) {
        if (s_v[i].Diem == maxmin) {
            // in(First->s);
            a[k++] = s_v[i];
        }
        i++;
    }
    return k;
}

float TinhTB0(Student *s_v, int n) {
    float tb = 0.0;
    int i = 0;
    while (i < n) {
        tb += s_v[i].Diem;
        i++;
    }
    return n > 0 ? tb / n : 0;
}

void Bubble_sort0(Student *s_v, int n, int choose) {
    for (int i = 1; i < n; i++) {
        for (int j = n-1; j >= i; j--) {
            switch(choose){
            case 0://ma SV
                if (s_v[j-1].maSV > s_v[j].maSV) {
                    swap(s_v[j-1], s_v[j]);
                }
                break;
            case 1://ten
                if (compareName(s_v[j-1].Ten, s_v[j].Ten) == 1) {
                    swap(s_v[j-1], s_v[j]);
                }
                else if(compareName(s_v[j-1].Ten, s_v[j].Ten) == 0 && compareName(s_v[j-1].Ho, s_v[j].Ho) == 1){
                    swap(s_v[j-1], s_v[j]);
                }
                break;
            case 2://diem
                if (s_v[j-1].Diem > s_v[j].Diem) {
                    swap(s_v[j-1], s_v[j]);
                }
                break;
            }
        }
    }
}

//void Bubble_Sort(int A[], int n)
//{ int i,j,temp;
//  for (i=1; i<n; i++)
//    for (j=n-1;j>=i; j--)
//      if (A[j-1] > A[j])
//       { 	temp = A[j-1];	A[j-1] = A[j];	A[j] = temp;
//       }
//}

void Insertion_sort0(Student *s_v, int n, int choose){
    int i, j;
    for (i=1; i < n; i++){
        Student x = s_v[i];
        switch(choose){
        case 0://ma SV
            for (j = i-1; j >= 0 && x.maSV < s_v[j].maSV; j--)
                s_v[j+1] = s_v[j];
            s_v[j+1] = x;
            break;
        case 1://ten
            for (j = i-1; j >= 0 && (compareName(x.Ten, s_v[j].Ten) == -1 || (compareName(x.Ten, s_v[j].Ten) == 0 && compareName(x.Ho, s_v[j].Ho) == -1)); j--)
                s_v[j+1] = s_v[j];
            s_v[j+1] = x;
            break;
        case 2://diem
            for (j = i-1; j >= 0 && x.Diem < s_v[j].Diem; j--)
                s_v[j+1] = s_v[j];
            s_v[j+1] = x;
            break;
        }
    }
}

void Selection_sort0(Student *s_v, int n, int choose) {
    for (int i = 0; i < n-1; i++){
        Student min = s_v[i];
        int vitrimin = i;
        for (int j = i+1; j < n; j++){
            switch(choose){
            case 0://ma s_v
                if (s_v[j].maSV < min.maSV){
                    min = s_v[j];
                    vitrimin = j;
                }
                break;
            case 1://ten
                if (compareName(s_v[j].Ten, min.Ten) == -1 || (compareName(s_v[j].Ten, min.Ten) == 0 && compareName(s_v[j].Ho, min.Ho) == -1)){
                    min = s_v[j];
                    vitrimin = j;
                }
                break;
            case 2://diem
                if (s_v[j].Diem < min.Diem){
                    min = s_v[j];
                    vitrimin = j;
                }
                break;
            }
        }
        swap(s_v[vitrimin], s_v[i]);
    }
}


int Partition0(Student *s_v, int left, int right, int choose){
    Student x = s_v[left];
    int i = left + 1;
    int j = right;
    do{
        switch(choose){
        case 0://ma SV
            while(i <= j && s_v[i].maSV <= x.maSV)
                i++;
            while(i <= j && s_v[j].maSV > x.maSV)
                j--;
            break;
        case 1://ten
            while(i <= j && (
                       (compareName(s_v[i].Ten, x.Ten) == -1
                        || (compareName(s_v[i].Ten, x.Ten) == 0 && compareName(s_v[i].Ho, x.Ho) == -1))
                       ||
                       (compareName(s_v[i].Ten, x.Ten) == 0 && compareName(s_v[i].Ho, x.Ho) == 0)
                       )
                   )
                i++;
            while(i <= j && (compareName(s_v[j].Ten, x.Ten) == 1
                              || (compareName(s_v[j].Ten, x.Ten) == 0 && compareName(s_v[j].Ho, x.Ho) == 1)))
                j--;
            break;
        case 2://diem
            while(i <= j && s_v[i].Diem <= x.Diem)
                i++;
            while(i <= j && s_v[j].Diem > x.Diem)
                j--;
            break;
        }

        if(i < j){
            swap(s_v[i], s_v[j]);
            i++;j--;
        }
    }while(i <= j);
    swap(s_v[left], s_v[j]);
    return j;
}
void Quick_sort0(Student *s_v, int left, int right, int choose){
    int k;
    if(left < right){
        k = Partition0(s_v, left, right, choose);
        Quick_sort0(s_v, left, k-1, choose);
        Quick_sort0(s_v, k+1, right, choose);
    }
}

void Heapify0(Student *s_v, int n, int i, int choose) {
    int largest = i;//Dat nut lon nhat la goc
    int l = 2 * i + 1;//vi tri nut con ben trai
    int r = 2 * i + 2;//vi tri nut con ben phai

    switch(choose){
    case 0://ma SV
        if (l < n && s_v[l].maSV > s_v[largest].maSV) {//Nut ben trai lon hon nut goc
            largest = l;
        }
        if (r < n && s_v[r].maSV > s_v[largest].maSV) {//Nut ben phai lon hon nut goc
            largest = r;
        }
        break;
    case 1://ten
        if (l < n && (compareName(s_v[l].Ten, s_v[largest].Ten) == 1 ||
                      (compareName(s_v[l].Ten, s_v[largest].Ten) == 0 && compareName(s_v[l].Ho, s_v[largest].Ho) == 1))) {//Nut ben trai lon hon nut goc
            largest = l;
        }
        if (r < n && (compareName(s_v[r].Ten, s_v[largest].Ten) == 1 ||
                      (compareName(s_v[r].Ten, s_v[largest].Ten) == 0 && compareName(s_v[r].Ho, s_v[largest].Ho) == 1))) {//Nut ben phai lon hon nut goc
            largest = r;
        }
        break;
    case 2://diem
        if (l < n && s_v[l].Diem > s_v[largest].Diem) {//Nut ben trai lon hon nut goc
            largest = l;
        }
        if (r < n && s_v[r].Diem > s_v[largest].Diem) {//Nut ben phai lon hon nut goc
            largest = r;
        }
        break;
    }

    if (largest != i) {//largest khong phai goc
        swap(s_v[i], s_v[largest]);//Hoan vi nut goc va nut lon nhat
        Heapify0(s_v, n, largest, choose);//Goi lai de quy cho cac nut con cua nut lon nhat
    }
}
void Heap_sort0(Student *s_v, int n, int choose) {
    for (int i = n / 2 - 1; i >= 0; i--) {//Vun dong tu duoi len (Hieu chinh thanh Heap)
        Heapify0(s_v, n, i, choose);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(s_v[0], s_v[i]);//Dua nut lon nhat ve cuoi, de loai bo nut lon nhat(n--)
        Heapify0(s_v, i, 0, choose);//Hieu chinh phan con lai truoc nut lon nhat thanh Heap
    }
}

void merge0(Student *s_v, int left, int mid, int right, int choose){
    int i = left;
    int j = mid + 1;
    int k = 0;
    int n = right - left + 1;
    Student *b = new Student[n];
    while(i < mid+1 && j < right+1){
        switch(choose){
        case 0://ma SV
            if(s_v[i].maSV < s_v[j].maSV){
                b[k] = s_v[i];
                k++;i++;
            }
            else{
                b[k] = s_v[j];
                k++;j++;
            }
            break;
        case 1://ten
            if(compareName(s_v[i].Ten, s_v[j].Ten) == -1){
                b[k] = s_v[i];
                k++;i++;
            }
            else if(compareName(s_v[i].Ten, s_v[j].Ten) == 0 && compareName(s_v[i].Ho, s_v[j].Ho) == -1){
                b[k] = s_v[i];
                k++;i++;
            }
            else{
                b[k] = s_v[j];
                k++;j++;
            }
            break;
        case 2://diem
            if(s_v[i].Diem < s_v[j].Diem){
                b[k] = s_v[i];
                k++;i++;
            }
            else{
                b[k] = s_v[j];
                k++;j++;
            }
            break;
        }
    }
    while(i < mid+1){//con phan tu ben trai
        b[k] = s_v[i];
        k++;i++;
    }
    while(j < right+1){//con phan tu ben phai
        b[k] = s_v[j];
        k++;j++;
    }
    i = left;
    for(k = 0; k<n; k++){//copy du lieu lai mang chinh
        s_v[i] = b[k];
        i++;
    }
    delete []b;
}
void Merge_sort0(Student *s_v, int left, int right, int choose){
    if(left < right){
        int mid = (left+right)/2;
        Merge_sort0(s_v, left, mid, choose);
        Merge_sort0(s_v, mid+1, right, choose);
        merge0(s_v, left, mid, right, choose);
    }
}

bool DocFile0(Student *s_v, string myFilePath, int &n) {
    ifstream allStudents;
    allStudents.open(myFilePath);

    if (!allStudents) {
        cout << myFilePath + ": Open fail!\n";
        return false;
        // exit(1);
    }
    string stt;
    while (getline(allStudents, stt, ',')) {
        getline(allStudents, s_v[n].maSV, ',');
        getline(allStudents, s_v[n].Ho, ',');
        getline(allStudents, s_v[n].Ten, ',');
        getline(allStudents, s_v[n].Lop, ',');
        allStudents >> s_v[n].Diem;
        n++;
    }
    allStudents.close();
    return true;
}

void WriteFile0(Student *s_v, string myNewFile, int n) {
    ofstream fout(myNewFile, ofstream::binary);
    if (!fout) {
        cout << "Khong the mo file " + myNewFile << endl;
        return;
    }
    int i = 1;
    //	fout << "STT" << ',' << "Ma sinh vien" << ',' << "Ho va ten" << ',' << "Ten" << ',' << "Lop" << ',' << "Diem" << endl;
    int k = 1;
    while (i <= n) {
        fout << k++ << ',' << s_v[i].maSV << ',' << s_v[i].Ho << ',' << s_v[i].Ten << ',' << s_v[i].Lop << ',' << s_v[i].Diem;
        if(k+1 != n)
            fout << endl;
        i++;
    }
    fout.close();
}
