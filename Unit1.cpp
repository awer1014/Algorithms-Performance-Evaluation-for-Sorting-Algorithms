//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int times = 0, n = 0, range = 0, last = 0, now = 0,	nn = 0;
int *data1, *data2;
float **T;
clock_t t1,t2;
Boolean check;
struct Stack *top = NULL;

struct Stack {
	int data;
	Stack *next;
};


void Swap(int &a ,int &b) {
	int c = a;
	a = b;
	b = c;
}

int Pow(int a, int b){
	int sum = 1;
	for(int i = 0; i < b; i++) {
		sum *= a;
	}
	return sum;
}

int Max(int a,int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}

void RandomData() {
	if (data1 != NULL) {
		delete data1;
	}
	data1 = new int[n];
	for (int i = 0; i < n; i++) {
		data1[i] = random(range)+1;
	}
}

void CopyData() {
	if (data2 != NULL) {
		delete data2;
	}
	data2 = new int[n];
	for (int i = 0; i < n; i++) {
		data2[i] = data1[i];
	}
}

void NewT(){
	if(T != NULL){
		for(int i = 0; i < last; i++)
			delete T[i];
		delete[] T;
	}
	T = new float*[times];
	for(int i = 0; i < times; i++){
		T[i] = new float[9];
		for(int j = 0; j < 9; j++)
			T[i][j] = 0;
	}
}

void Print(){
	String s = "";
	for (int i = 0; i < n; i++){
		if(i)s = s + "->";
		s = s + IntToStr(data2[i]);
	}
	Form1->Memo2->Lines->Add(s);
}

void SelectionSort() {
	t1 = clock();

	int min;
	for (int i = 0; i < n; i++) {
		min = i;
		for (int j = 0; j < n; j++) {
			if (data2[min] > data2[j]) {
				min = j;
			}
		}
		Swap(data2[i],data2[min]);
	}
	t2 = clock();
	T[now][0] = (float)((t2-t1)/CLOCKS_PER_SEC);
	Form1->Memo2->Lines->Add("SelectionSort : " + FloatToStr((float)((t2-t1)/CLOCKS_PER_SEC)) + "(sec.)");
	if(check) {
		Print();
	}
}

void InsertionSort() {

	t1 = clock();
	int target;
	int j;
	for (int i = 0; i < n; i++) {
		target = data2[i+1];
		j = i+1;
		while (j < 0 && data2[j-1] > target) {
			data2[j] = data2[j-1];
			j--;
		}
		data2[j] = target;
	}
	t2 = clock();
	T[now][1] = (float)((t2-t1)/CLOCKS_PER_SEC);
	Form1->Memo2->Lines->Add("InsertionSort : " + FloatToStr((float)((t2-t1)/CLOCKS_PER_SEC)) + "(sec.)");
	if(check) {
		Print();
	}
}

void BubbleSort() {

	t1 = clock();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (data2[i] > data2[j]) {
				Swap(data2[i],data2[j]);
			}
		}
	}

	t2 = clock();
	T[now][2] = (float)((t2-t1)/CLOCKS_PER_SEC);
	Form1->Memo2->Lines->Add("BubbleSort : " + FloatToStr((float)((t2-t1)/CLOCKS_PER_SEC)) + "(sec.)");
	if (check) {
		Print();
	}
}

void push(int a, int b) {
	Stack *old = top;
	top = new Stack;
	top->data = a;
	top ->next = old;

	old = top;
	top = new Stack;
	top->data = b;
	top ->next = old;
}

int pop() {
	if (top == NULL) {
		return NULL;
	}
	Stack *old = top;
	int a = old->data;
	top = top->next;
	delete old;
	return a;
}

void Quick(int A[], int left, int right) {
	int i, j;
	int target;
	if (left < right) {
		i = left + 1;
		j = right;
		target = A[left];
		do {
			while (A[i] < target && i <= j) {
				i++;
			}
			while (A[j] >= target && i <= j) {
				j--;
			}
			if (i < j) {
				Swap(A[i], A[j]);
			}
		} while(i < j);
		if (left < j) {
			Swap(A[left],A[j]);
		}
		Quick(A, left, j-1);
		Quick(A, j+1, right);
	}
}

void QuickSort() {

	t1 = clock();
	Quick(data2, 0, n-1);

	t2 = clock();
	T[now][3] = (float)((t2-t1)/CLOCKS_PER_SEC);
	Form1->Memo2->Lines->Add("QuickSort : " + FloatToStr((float)((t2-t1)/CLOCKS_PER_SEC)) + "(sec.)");
	if(check) {
		Print();
	}
}

void QuickSort_NonRecursive() {

	t1 = clock();
	int i, j;
	int left = 0, right = n-1;
	int target;
	push(left, right);
	while (top != NULL) {
		right = pop();
		left = pop();
		target = data2[left];
		i = left + 1;
		j = right ;
		do {
			while (data2[i] < target && i <= j) {
				i++;
			}
			while (data2[j] >= target && i <= j) {
				j--;
			}
			if (i < j) {
				Swap(data2[i], data2[j]);
			}
		} while(i < j);
		if (left < j) {
			Swap(data2[left], data2[j]);
		}
		if (left < j-1) {
			push(left, j-1);
		}
		if (j+1 < right) {
			push(j+1, right);
		}
	}

	t2 = clock();
	T[now][4] = (float)((t2-t1)/CLOCKS_PER_SEC);
	Form1->Memo2->Lines->Add("QuickSort_NonRecursive : " + FloatToStr((float)((t2-t1)/CLOCKS_PER_SEC)) + "(sec.)");
	if(check) {
		Print();
	}
}

void Merge(int C[], int k, int A[], int i, int m, int B[], int j, int n) {
	int *temp = new int [n], p;
	for (p = i; p <= m; p++) {
		temp[p] = A[p];
	}
	for (p = j; p <= n; p++) {
		temp[p] = B[p];
	}
	while (i <= m && j<= n) {
		if (temp[i] <= temp[j]) {
			C[k++] = temp[i++];
		}
		else {
			C[k++] = temp[j++];
		}
	}
	while (i <= m) {
		C[k++] =temp[i++];
	}
	while (j <= n) {
		C[k++] = temp[j++];
	}
	delete temp;
}

void MergeSort_Recursive(int A[], int left, int right) {
	int m;
	if (left <right) {
		m = (left + right)/2;
		MergeSort_Recursive(A, left, m);
		MergeSort_Recursive(A, m+1, right);
		Merge(A, left, A, left, m, A, m+1, right);
	}
}

void MergeSort() {
	t1 = clock();
	MergeSort_Recursive(data2, 0, n-1);
	t2 = clock();
	T[now][5] = (float)((t2-t1)/CLOCKS_PER_SEC);
	Form1->Memo2->Lines->Add("MergeSort : " + FloatToStr((float)((t2-t1)/CLOCKS_PER_SEC)) + "(sec.)");
	if(check) {
		Print();
	}
}

void MergeSort_NonRecursive() {
	t1 = clock();

	int i;
	int len = 1;
	while (len < n) {
		i = 0;
		while (i < n-len) {
			Merge(data2, i, data2, i, i+len-1, data2, i+len, min(i+2*len-1, n-1));
			i = i+2*len;
		}
		len *= 2;
	}
	t2 = clock();

	T[now][6] = (float)((t2-t1)/CLOCKS_PER_SEC);
	Form1->Memo2->Lines->Add("MergeSort_NonRecursive : " + FloatToStr((float)((t2-t1)/CLOCKS_PER_SEC)) + "(sec.)");
	if(check) {
		Print();
	}
}

void restore(int A[], int a, int b) {
	int i = a;
	int j, k;
	while (i <= b/2) {
		if (A[2*i] < A[2*i+1]) {
			j = 2*i;
		}
		else{
			j = 2*i+1;
		}
		if (A[i] < A[j]) {
			break;
		}
		Swap(A[i], A[j]);
		i = j;
	}
}

void HeapSort() {
	t1 = clock();

	int i;
	int count = 0;
	int *temp = new int [n+1];
	for (i = 0; i <= n; i++) {
		temp[i] = data2[i-1];
	}
	for (i = n/2; i > 0; i--) {
		restore(temp, i, n);
	}
	for (i = n; i > 0; i--){
		data2[count++] = temp[1];
		temp[1] = temp[i];
		restore(temp, 1, i-1);
	}
	delete temp;

	t2 = clock();
	T[now][7] = (float)((t2-t1)/CLOCKS_PER_SEC);
	Form1->Memo2->Lines->Add("HeapSort : " + FloatToStr((float)((t2-t1)/CLOCKS_PER_SEC)) + "(sec.)");
	if(check) {
		Print();
	}
}

void RadixSort() {
	t1 = clock();

	int *count = new int[10];
	int *temp = new int[n];
	int *index = new int [10];
	int i, j;
	int digit;
	int max = 0;
	int radix = 0;
	for (i = 0; i < n; i++) {
		if (data2[i] > max) {
			max = data2[i];
		}
	}
	while (max /= 10) {
		radix ++;
	}
	for (int i = 1; i < n; i++) {
		for (j = 0; j<10; j++) {
			count[j] = 0;
		}
		for (j = 0; j < n; j++) {
			digit = data2[j]%Pow(10,i)/Pow(10,i-1);
			count[digit]++;
		}
		index[0] = 0;
		for (j = 1; j < 10; j++) {
			index[j] = index[j-1]+count[j-1];
		}
		for (j = 0; j < n; j++) {
			digit = data2[j]%Pow(10,i)/Pow(10,i-1);
			temp[index[digit]++] = data2[j];
		}
		for (j = 0; j < n; j++) {
			data2[j] = temp[j];
		}
	}
	delete count;
	delete temp;
	delete index;

	t2 = clock();
	T[now][8] = (float)((t2-t1)/CLOCKS_PER_SEC);
	Form1->Memo2->Lines->Add("RadixSort : " + FloatToStr((float)((t2-t1)/CLOCKS_PER_SEC)) + "(sec.)");
	if(check) {
		Print();
	}
}

void SortType() {
	for(int i = 0; i < times; i++){
		now = i;
		n += i*nn;
		RandomData();
		Form1->Memo2->Lines->Add("Times " + IntToStr(i+1) + " ----------------------------------------");
		if(check){
			CopyData();
			Form1->Memo2->Lines->Add("Data : ");
			Print();
		}
		if(Form1->CheckBox1->Checked) {
			CopyData();
			SelectionSort();
		}
		if(Form1->CheckBox2->Checked) {
			CopyData();
			InsertionSort();
		}
		if(Form1->CheckBox3->Checked) {
			CopyData();
			BubbleSort();
		}
		if(Form1->CheckBox4->Checked) {
			CopyData();
			QuickSort();
		}
		if(Form1->CheckBox5->Checked) {
			CopyData();
			QuickSort_NonRecursive();
		}
		if(Form1->CheckBox6->Checked) {
			CopyData();
			MergeSort();
		}
		if(Form1->CheckBox7->Checked) {
			CopyData();
			MergeSort_NonRecursive();
		}
		if(Form1->CheckBox8->Checked) {
			CopyData();
			HeapSort();
		}
		if(Form1->CheckBox9->Checked) {
			CopyData();
			RadixSort();
		}
	}
	if(Form1->CheckBox1->Checked) {
		Form1->Memo1->Lines->Add("SelectionSort finished" );
	}
	if(Form1->CheckBox2->Checked) {
		Form1->Memo1->Lines->Add("InsertionSort finisheded" );
	}
	if(Form1->CheckBox3->Checked) {
		Form1->Memo1->Lines->Add("BubbleSort finished" );
	}
	if(Form1->CheckBox4->Checked) {
		Form1->Memo1->Lines->Add("QuickSort finished" );
	}
	if(Form1->CheckBox5->Checked) {
		Form1->Memo1->Lines->Add("QuickSort_NonRecursive finished" );
	}
	if(Form1->CheckBox6->Checked) {
		Form1->Memo1->Lines->Add("MergeSort finished" );
	}
	if(Form1->CheckBox7->Checked) {
		Form1->Memo1->Lines->Add("MergeSort_NonRecursive finished" );
	}
	if(Form1->CheckBox8->Checked) {
		Form1->Memo1->Lines->Add("HeapSort finished" );
	}
	if(Form1->CheckBox9->Checked) {
		Form1->Memo1->Lines->Add("RadixSort finished" );
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	last = times;
	times = Edit1->Text.ToInt();
	n = Edit2->Text.ToInt();
	nn = n;
	range = Edit3->Text.ToInt();
	check = CheckBox10->Checked;
	Memo2->Lines->Clear();
	NewT();
	SortType();
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------
