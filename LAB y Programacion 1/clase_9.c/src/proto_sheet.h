/*
 * proto_sheet.h
 *
 *  Created on: May 6, 2021
 *      Author: Slayer
 */

#ifndef PROTO_SHEET_H_
#define PROTO_SHEET_H_

typedef struct
{
	int Product;
	char description[6969];
	int origin;
	int type;
	int p_price;
	int isEmpty;

}Register;

void start_up (Register lista[], int size);
int void_search(Register lista[], int  size);
int data_intake(Register product[], int size, int* id);
int data_print(Register product[], int size);
int menu();
int data_print_s(Register product);
int data_delete(Register product[], int size);
int id_search(Register product[], int size, int id);
int product_mod(Register product[], int size);
int mod_menu();
char desc_mod(Register product[], int size);



#endif /* PROTO_SHEET_H_ */
