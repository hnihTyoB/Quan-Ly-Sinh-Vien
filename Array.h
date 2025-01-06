#ifndef ARRAY_H
#define ARRAY_H

#include <string>

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

void Insert_first0(Student *s_v, int& n, Student x);

void Insert_after0(Student *s_v, int& n, int p, Student x);

void Add0(Student *s_v, int& n, string m, string hl, string t, string l, float d);

void duyetDSSV0(Student *s_v, int n);

bool compareChar(string y, string x);

int compareName(string x, string y);

string Daochuoi(string x);

int Search_info0(Student *s_v, Student *a, string x, int n, int choose);

void Delete_first0(Student *s_v, int& n);

void Delete_after0(Student *s_v, int& n, int p);

void Delete_info0(Student *s_v, int& n, string x);

int TimMaxMin0(Student *s_v, Student *a, int n, int choose);

float TinhTB0(Student *s_v, int n);

void merge0(Student *s_v, int left, int mid, int right, int choose);
void Merge_sort0(Student *s_v, int left, int right, int choose);

void Bubble_sort0(Student *s_v, int n, int choose);

void Insertion_sort0(Student *s_v, int n, int choose);

void Selection_sort0(Student *s_v, int n, int choose);

int Partition0(Student *s_v, int left, int right, int choose);
void Quick_sort0(Student *s_v, int left, int right, int choose);

void Heapify0(Student *s_v, int n, int i, int choose);
void Heap_sort0(Student *s_v, int n, int choose);

bool DocFile0(Student *s_v, string myFilePath, int &n);

void WriteFile0(Student *s_v, string myNewFile, int n);

#endif // ARRAY_H
