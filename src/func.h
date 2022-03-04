#include <unistd.h>

#define txtdiv printf("|=========================================|\n\n");
#define head printf("QAdventure3 0.1.1\nWritten by QMaury\nCopyright 2021-2022\n|=========================================|\n");  printRoomH();
#define invalid printf("???\n"); sleep(1.7);
#define clear system("clear");

extern int have;
extern char playername[51];

int getAction();
void txtdvd();
void cont();
void printRoom();
void qExit();
void printRoomH();
