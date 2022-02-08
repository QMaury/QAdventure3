/* 2021-12-20   23:49
 * written by QMS
 * */

#include <stdio.h>
#include <stdlib.h>


#include "vars.h"
#include "func.h"

#define txtdiv printf("|=========================================|\n\n");

int contRes;

void qExit() {
        txtdiv;
        printf("Exit?\n\n1) Yes\n2) No\n> ");
        action = getAction();
        switch(action) {
                case 1:
                    printf("\nGoodbye!");
                    cont();
                    exit(0);
                    break;
                case 2:
                    break;
                default:
                    invalid();
        }
}

void printRoom() {
        printf("You are in room %i, %i\n", x, y);
}

int getAction() {
	char actionString[80];

	fgets(actionString, sizeof(actionString), stdin);
	return atoi(actionString);;
}

void invalid() {
    printf("????\n");
}

void cont() {
	printf("\n1) Continue\n> ");
	contRes = getAction();
	switch(contRes) {
		case 1:
			break;
	}
        printf("\n");
}
