#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include <string>
#include "Array.h"

using namespace std;

struct Node3 {
    Student s;
    struct Node3 *next;
};
typedef struct Node3* sv3;

sv3 makeNode3(Student x);

int Size3(sv3 Last);

bool Empty3(sv3 Last);

void Insert_Last3(sv3& Last, Student x);

void Add3(sv3& Last, string m, string hl, string t, string l, float d);

// void in(Student s);

void duyetDSSV3(sv3 Last);

bool compareChar(string y, string x);

int compareName(string x, string y);

string Daochuoi(string x);

sv3 Search_info3(sv3 Last, string x, int choose);
sv3 Search_info3_D(sv3 Last, int x);

sv3 Search_position3(sv3 Last, int x);

void Delete_first3(sv3& Last);

void Delete_last3(sv3 &Last);

void Delete_after3(sv3& Last, sv3 p);

void Delete_info3(sv3& Last, string x);

sv3 TimMaxMin3(sv3 Last, int choose);

float TinhTB3(sv3 Last);

void Merge3(sv3& Last, int left, int mid, int right, int choose);
void Merge_sort3(sv3& Last, int left, int right, int choose);

void Bubble_sort3(sv3& Last, int choose);

void Insertion_sort3(sv3& Last, int choose);

void Selection_sort3(sv3& Last, int choose);

int Partition3(sv3& Last, int left, int right, int choose);
void Quick_sort3(sv3& Last, int left, int right, int choose);;

void Heapify3(sv3& Last, int n, int i, int choose);
void Heap_sort3(sv3& Last, int choose);

bool DocFile3(sv3& Last, string myFilePath);

void WriteFile3(sv3 Last, string myNewFile);

void Clearlist3(sv3 &Last);

#endif // CIRCULARLINKEDLIST_H
