#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 35

typedef struct PERSON {
	int tag;
	char date[100];
	char fee[100];
	char name[25];
	int age;
	char univ[35];
	char job[15];
	struct PERSON* next;
}PERSON;

//set up / author: ±Ë¿Ø«ˆ
int read_data_arr(struct PERSON head[], const char* myFile) {
	FILE* myinFile;
	int i = 0;

	myinFile = fopen(myFile, "r");
	if (myinFile == NULL) {
		printf("File could not be opened\n");
	}

	char line[256];

	while ((fgets(line, 256, myinFile)) != NULL) {

		char* tok;

		tok = strtok(line, "/");
		head[i].tag = atoi(tok);

		tok = strtok(NULL, "/");
		strcpy(head[i].date, tok);

		tok = strtok(NULL, "/");
		strcpy(head[i].fee, tok);

		tok = strtok(NULL, "/");
		strcpy(head[i].name, tok);

		tok = strtok(NULL, "/");
		head[i].age = atoi(tok);

		tok = strtok(NULL, "/");
		strcpy(head[i].univ, tok);

		tok = strtok(NULL, "/\n");
		strcpy(head[i].job, tok);

		i++;
	}
	fclose(myinFile);

	return i;
}
struct PERSON* add_list(struct PERSON* head, struct PERSON* ptr) {
	struct PERSON* p;

	if (head == NULL) {
		head = ptr;
		return head;
	}
	p = head;
	while (p->next) {
		p = p->next;
	}
	p->next = ptr;

	return head;
}
struct PERSON* read_data_list(struct PERSON* head, char* myFile) {
	FILE* myinFile;

	myinFile = fopen(myFile, "r");
	if (myinFile == NULL) {
		printf("File could not be opened\n");
	}

	char line[256];

	while ((fgets(line, 256, myinFile)) != NULL) {


		struct PERSON* ptr = (struct PERSON*)malloc(sizeof(struct PERSON));
		ptr->next = NULL;

		char* tok;

		tok = strtok(line, "/");
		ptr->tag = atoi(tok);

		tok = strtok(NULL, "/");
		strcpy(ptr->date, tok);

		tok = strtok(NULL, "/");
		strcpy(ptr->fee, tok);

		tok = strtok(NULL, "/");
		strcpy(ptr->name, tok);

		tok = strtok(NULL, "/");
		ptr->age = atoi(tok);

		tok = strtok(NULL, "/");
		strcpy(ptr->univ, tok);

		tok = strtok(NULL, "/\n");
		strcpy(ptr->job, tok);

		head = add_list(head, ptr);

	}
	fclose(myinFile);

	return head;
}

//p1 and p2 and other print data part/ author: ±Ë¿Ø«ˆ
void print_arr(struct PERSON head[], int n, int* p) {
	int i;

	for (i = 0; i < n; i++) {

		if (*p == 1) {
			if (strstr(head[i].name, "Choi") != 0)
			{
				printf("%d/%s/%s/%s/%d/%s/%s \n", head[i].tag, head[i].date, head[i].fee, head[i].name, head[i].age, head[i].univ, head[i].job);
			}
		}
		else if (*p == 2) {
			if (strcmp(head[i].univ, "Gachon University") == 0)
			{
				printf("%d/%s/%s/%s/%d/%s/%s \n", head[i].tag, head[i].date, head[i].fee, head[i].name, head[i].age, head[i].univ, head[i].job);
			}
		}
		else if (*p == 3 || *p == 6 || *p == 7) {
			printf("%d/%s/%s/%s/%d/%s/%s \n", head[i].tag, head[i].date, head[i].fee, head[i].name, head[i].age, head[i].univ, head[i].job);
		}
	}

}
void print_list(struct PERSON* head, int* p) {
	struct PERSON* person = head;

	while (person) {
		if (*p == 1) {
			if (strstr(person->name, "Choi") != 0)
			{
				printf("%d/%s/%s/%s/%d/%s/%s \n", person->tag, person->date, person->fee, person->name, person->age, person->univ, person->job);
			}
		}
		else if (*p == 2) {
			if (strcmp(person->univ, "Gachon University") == 0)
			{
				printf("%d/%s/%s/%s/%d/%s/%s \n", person->tag, person->date, person->fee, person->name, person->age, person->univ, person->job);
			}
		}
		else if (*p == 4 || *p == 6 || *p == 7) {
			printf("%d/%s/%s/%s/%d/%s/%s \n", person->tag, person->date, person->fee, person->name, person->age, person->univ, person->job);
		}
		person = person->next;
	}
}

//p3 / author: √÷¡§ø¯
void tag_sort(struct PERSON data[]) {

	struct PERSON temp[30];
	for (int i = 0; i < 29; i++)
	{
		for (int j = 0; j < 29 - i; j++)
		{
			if (data[j].tag > data[j + 1].tag)
			{
				temp[i] = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp[i];
			}
		}
	}
}

//p4 / author: ¡§¿∫º∑, √÷¡§ø¯
struct PERSON* p4(struct PERSON* head2, struct PERSON* arr, int n) {
	for (int i = 0; i < n; i++) {
		struct PERSON* a = (struct PERSON*)malloc(sizeof(struct PERSON));
		a->tag = arr[i].tag;
		strcpy(a->date, arr[i].date);
		strcpy(a->fee, arr[i].fee);
		strcpy(a->name, arr[i].name);
		a->age = arr[i].age;
		strcpy(a->univ, arr[i].univ);
		strcpy(a->job, arr[i].job);
		a->next = NULL;

		head2 = add_list(head2, a);
	}
	return head2;
}

// Written by "±Ë»Ò¡ÿ", Used for P5-1, P8-1, P8-2
void Copy_Element(const PERSON* src, PERSON* dest)
{
	dest->tag = src->tag;
	strcpy(dest->date, src->date);
	strcpy(dest->fee, src->fee);
	strcpy(dest->name, src->name);
	dest->age = src->age;
	strcpy(dest->univ, src->univ);
	strcpy(dest->job, src->job);
	dest->next = src->next;
}

// Written by "±Ë»Ò¡ÿ", Used for P5-1
void selection_sort(const PERSON data[], const int num_persons, PERSON sort_age[])
{
	int least, temp;

	for (int i = 0; i < num_persons; i++) {
		Copy_Element(&data[i], &sort_age[i]);
	}

	for (int index = 0; index < num_persons - 1; index++) {
		least = index;

		for (int t = index + 1; t < num_persons; t++) {
			if (sort_age[t].age < sort_age[least].age) {
				least = t;
			}
		}

		if (index != least) {
			temp = sort_age[index].age;
			sort_age[index].age = sort_age[least].age;
			sort_age[least].age = temp;
		}
	}
}

// Written by "±Ë»Ò¡ÿ", Used for P5-1, P8-1, P8-2
bool Write_File(const char* fname, PERSON* person, int num_persons)
{
	FILE* pFile;
	pFile = fopen(fname, "w");

	if (pFile == NULL) {
		printf("ERROR: Cannot read the file !!\n");
		return false;
	}

	for (int index = 0; index < num_persons; index++) {
		fprintf(pFile, "%d/%s/%s/%s/%d/%s/%s\n", person[index].tag, person[index].date, person[index].fee, person[index].name, person[index].age, person[index].univ, person[index].job);
	}

	fclose(pFile);
	return true;
}

//p6-1 / author: ¡§¿∫º∑
void swap(struct PERSON* a, struct PERSON* b) {
	struct PERSON tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void del(struct PERSON* d, int* idx, int count, int c) {
	for (int i = 0; i < count; i++) {
		d[idx[i]] = { NULL };
	}
	for (int i = count - 1; i >= 0; i--) {
		for (int j = idx[i] + 1; j < c; j++) {
			swap(&d[j - 1], &d[j]);
		}
	}
}
int find(struct PERSON* d, const char* name, int c) {
	int text_length = 0, sub_length = 0, count = 0;
	int idx[30] = { NULL };
	int k;
	for (k = 0; k < c; k++) {
		text_length = strlen(d[k].name);
		sub_length = strlen(name);
		for (int i = 0; i < text_length; i++) {
			if (d[k].name[i] == name[0]) {
				int tmp = 0;
				for (int j = 0; j < sub_length; j++) {
					if (d[k].name[i + j] != name[j]) break;
					else tmp++;
					if (tmp == sub_length) {
						idx[count] = k;
						count++;
						i += sub_length;
						break;
					}
				}
			}
		}
	}
	del(d, idx, count, c);
	return count;
}

//p6-2 / author: ¡§¿∫º∑
int cmp(struct PERSON* d, const char* name) {
	int text_length = 0, sub_length = 0, count = 0;

	text_length = strlen(d->name);
	sub_length = strlen(name);
	for (int i = 0; i < text_length; i++) {
		if (d->name[i] == name[0]) {
			int tmp = 0;
			for (int j = 0; j < sub_length; j++) {
				if (d->name[i + j] != name[j])
					break;
				else tmp++;
				if (tmp == sub_length) {
					count++;
					i += sub_length;
					break;
				}
			}
		}
	}
	return count;
}
void deleteNode(struct PERSON* head, const char* name) {
	struct PERSON* cNode = head;
	struct PERSON* pNode = NULL;
	while (cNode != NULL) {
		if (cmp(cNode, name) == 1) break;
		pNode = cNode;
		cNode = cNode->next;
	}
	pNode->next = cNode->next;
}

//p7 / author:¡§¿∫º∑, √÷¡§ø¯
int find_tag_arr(struct PERSON* head, int* num) {
	int i, j;
	for (i = 30; i > 0; i--) {
		for (j = 0; j < *num; j++) {
			if (i == head[j].tag) break;
		}
		if (j == *num) return i;
	}
}
int find_tag_list(struct PERSON* head) {
	int i, j;
	struct PERSON* a;

	for (i = 30; i > 0; i--) {
		a = head;
		while (a != NULL) {
			if (a->tag == i) {
				break;
			}
			a = a->next;
		}
		if (a == NULL) return i;
	}

}
void p7_1(struct PERSON* ptr, int* num) {
	ptr[*num].tag = find_tag_arr(ptr, num);
	strcpy(ptr[*num].date, "2022-11-30");
	strcpy(ptr[*num].fee, "yes");
	strcpy(ptr[*num].name, "Gildong Paik");
	ptr[*num].age = 35;
	strcpy(ptr[*num].univ, "Gachon University");
	strcpy(ptr[*num].job, "Student");

	*num += 1;
}
void p7_2(struct PERSON* head) {
	struct PERSON* ptr = (struct PERSON*)malloc(sizeof(struct PERSON));
	ptr->tag = find_tag_list(head);
	strcpy(ptr->date, "2022-11-03");
	strcpy(ptr->fee, "yes");
	strcpy(ptr->name, "Gildong Paik");
	ptr->age = 35;
	strcpy(ptr->univ, "Gachon University");
	strcpy(ptr->job, "Student");
	ptr->next = NULL;
	head = add_list(head, ptr);
}

// Written by "±Ë»Ò¡ÿ", Used for P8-1, P8-2
int CheckSum(const PERSON input[])
{
	int XOR = 0;

	PERSON temp;
	for (int i = 0; i < 10; i++) {
		Copy_Element(&input[i], &temp);

		int k = 0;
		while (temp.name[k] != '\0') {
			XOR ^= temp.name[k];
			k += 1;
		}
	}

	return XOR;
}

// Written by "±Ë»Ò¡ÿ", Used for P8-1, P8-2
bool Read_File(const char* fname, PERSON* person, int* num_persons)
{
	FILE* pFile;
	pFile = fopen(fname, "r");

	if (pFile == NULL)
	{
		printf("ERROR: Cannot read the file !!\n");
		*num_persons = 0;
		return false;
	}

	PERSON read_data;
	while (fscanf(pFile, "%d/%[^/]/%[^/]/%[^/]/%d/%[^/]/%s", &read_data.tag, &read_data.date, &read_data.fee, &read_data.name, &read_data.age, &read_data.univ, &read_data.job) == 7)
	{
		Copy_Element(&read_data, &person[(*num_persons)++]);
	}

	fclose(pFile);
	return true;
}

// Written by "±Ë»Ò¡ÿ", Used for P8-1, P8-2
void p8(const PERSON* original, const int numberOfPerson)
{
	PERSON mostRecent[10];
	int startIdx = numberOfPerson - 10;

	int mostRecentNum = 0;
	for (int idx = startIdx; idx < numberOfPerson; idx++)
	{
		Copy_Element(&original[idx], &mostRecent[idx - startIdx]);
		mostRecentNum += 1;
	}

	int org_checkSum = CheckSum(mostRecent);
	Write_File("P8-1.txt", mostRecent, mostRecentNum);

	PERSON afterWrite[10];
	int afterPersons = 0;
	Read_File("P8-1.txt", afterWrite, &afterPersons);
	Write_File("P8-2.txt", afterWrite, afterPersons);

	PERSON copiedData[10];
	int copiedPersons = 0;
	Read_File("P8-2.txt", copiedData, &copiedPersons);
	int cpy_checkSum = CheckSum(copiedData);

	if (org_checkSum == cpy_checkSum)
	{
		printf("-----Copy recent data and Exclusive OR Checksum-----\n");
		printf("[Org_Checksum]: %d\n", org_checkSum);
		printf("[Cpy_Checksum]: %d\n", cpy_checkSum);
		printf("\nCopy Complete !!\n");
	}
	else
	{
		printf("-----Copy recent data and Exclusive OR Checksum-----\n");
		printf("[Org_Checksum]: %d\n", org_checkSum);
		printf("[Cpy_Checksum]: %d\n", cpy_checkSum);
		printf("\nCopy Fail...\n");
	}
}

int main() {
	char fileName[] = "registraion_data.txt";
	struct PERSON* head = NULL;
	struct PERSON arr_head[MAX];
	int count = 0;
	int p = 1;

	count = read_data_arr(arr_head, fileName);
	head = read_data_list(head, fileName);


	printf("\n[ P1-1 ]\n");
	print_arr(arr_head, count, &p);
	printf("\n[ P1-2 ]\n");
	print_list(head, &p);

	printf("-------------------------------\n");
	p++;

	printf("[ P2-1 ]\n");
	print_arr(arr_head, count, &p);
	printf("\n[ P2-2 ]\n");
	print_list(head, &p);

	printf("-------------------------------\n");
	p++;

	tag_sort(arr_head);
	printf("[ P3 ]\n");
	print_arr(arr_head, count, &p);

	printf("-------------------------------\n");
	p++;

	printf("[ P4 ]\n");
	struct PERSON* head2 = NULL;
	head2 = p4(head2, arr_head, count);
	print_list(head2, &p);

	printf("-------------------------------\n");
	p++;

	// Written by "±Ë»Ò¡ÿ", P5-1 code
	printf("[ P5 ]\n");
	printf("Output to P5-1.txt\n");

	PERSON sort_age[MAX];

	selection_sort(arr_head, count, sort_age);

	if (!Write_File("P5-1.txt", sort_age, count)) {
		return -1;
	}


	printf("-------------------------------\n");
	p++;


	int del_cnt = find(arr_head, "Choi", count);
	count -= del_cnt;
	printf("[ p6-1 ]\n");
	print_arr(arr_head, count, &p);

	printf("[ p6-2 ]\n");
	for (int j = 0; j < del_cnt; j++)
		deleteNode(head, "Choi");
	print_list(head, &p);

	printf("-------------------------------\n");
	p++;

	printf("[ p7-1 ]\n");
	p7_1(arr_head, &count);
	print_arr(arr_head, count, &p);

	printf("[ p7-2 ]\n");
	p7_2(head);
	print_list(head, &p);

	printf("-------------------------------\n");

	// Written by "±Ë»Ò¡ÿ", P8-1, P8-2 code
	printf("[ p8-1 && p8-2 ]\n\n");
	p8(arr_head, count);

	return 0;
}