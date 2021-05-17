/*
 ============================================================================
 * lib.h
 *
 *  Created on: May 15, 2021
 *  Author: Slayer
 *
 *  TP2
 ============================================================================
 */

#ifndef LIB_H_
#define LIB_H_

typedef struct
{
	int id;
	char name[51];
	char last_name[51];
	float salary;
	int sector;
	int isEmpty;

}Employee;

typedef struct
{
	char sector[50];
	int idSector;
}Sector;

void hardcoding(Sector datos[], int *id2,int S);
void start_up (Employee list[], int size);
int void_search(Employee list[], int  size);
int data_intake(Employee list[], int size, int* id, Sector datos[], int S);
int data_print(Employee list[], int size);
int menu();
int data_print_s(Employee list);
int data_delete(Employee list[], int size);
int id_search(Employee list[], int size, int id);
int employee_mod(Employee list[], Sector datos[], int size, int S);
int mod_menu();
char desc_mod(Employee list[], int size);
int hardPrint(Sector datos[], int size);
void hardPrintS(Sector datos);
void alphabeticalSorting(Employee list[], int size);

#endif /* LIB_H_ */
