#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <string>
#include "Array.h"

using namespace std;

struct Node2{
    Student s;
    Node2 *left, *right;
};

typedef struct Node2* sv2;

sv2 makeNode2(Student x);

int Size2(sv2 First);

bool Empty2(sv2 First);

void Insert_First2(sv2 &First, sv2& Last, Student x);

void Insert_right2(sv2 p, sv2& Last, Student x);

void Insert_Last2(sv2 &First, sv2 &Last, Student x);

void Add2(sv2& First, sv2& Last, string m, string hl, string t, string l, float d);

sv2 Search_position2(sv2 First, int x);

// void in(Student s);
void duyetDSSV2(sv2 First);

bool compareChar(string y, string x);

int compareName(string x, string y);

string Daochuoi(string x);

sv2 Search_info2(sv2 First, string x, int choose);

void Delete_first2(sv2 &First);

void Delete_node2(sv2 &First, sv2& Last, sv2 p);

sv2 getTail(sv2 First);

void Delete_info2(sv2& First, sv2& Last, string x);

sv2 TimMaxMin2(sv2 First, int choose);

float TinhTB2(sv2 First);

void Bubble_sort2(sv2& First, int choose);
void Bubble_sort_D(sv2& First, sv2& Last, int choose);

void Insertion_sort2(sv2& First, int choose);

void Selection_sort2(sv2& First, int choose);

void Merge2(sv2& First, int left, int mid, int right, int choose);
void Merge_sort2(sv2& First, int left, int right, int choose);

int Partition2(sv2& First, int left, int right, int choose);
void Quick_sort2(sv2& First, int left, int right, int choose);

void Heapify2(sv2& First, int n, int i, int choose);
void Heap_sort2(sv2& First, int choose);

bool DocFile2(sv2& First, sv2& Last, string myFilePath);

void WriteFile2(sv2 First, string myNewFile);

void Clearlist2(sv2 &First);

#endif // DOUBLELINKEDLIST_H
