#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H
#include <string>
#include "Array.h"
using namespace std;

struct Node {
    Student s;
    struct Node *next;
};
typedef struct Node* sv;

sv makeNode(Student x);

int Size(sv First);

void Insert_Last(sv& First, Student x);

void Add(sv& First, string m, string hl, string t, string l, float d);

// void in(Student s);

void duyetDSSV(sv First);

bool compareChar(string y, string x);

int compareName(string x, string y);

string Daochuoi(string x);

sv Search_info(sv First, string x, int choose);

sv Search_position(sv First, int x);

void Delete_first(sv& First);

void Delete_after(sv p);

void Delete_info(sv& First, string x);

sv TimMaxMin(sv First, int choose);

float TinhTB(sv First);

void Merge(sv& Last, int left, int mid, int right, int choose);
void Merge_sort(sv& Last, int left, int right, int choose);

void Bubble_sort(sv& First, int choose);

void Insertion_sort(sv& First, int choose);

void Selection_sort(sv& First, int choose);

int Partition(sv& Last, int left, int right, int choose);
void Quick_sort(sv& Last, int left, int right, int choose);

void Heapify(sv& First, int n, int i, int choose);
void Heap_sort(sv& First, int choose);

bool DocFile(sv& First, string myFilePath);

void WriteFile(sv First, string myNewFile);

void Clearlist(sv &First);

#endif // SINGLELINKEDLIST_H
