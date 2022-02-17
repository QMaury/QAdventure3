#include <unistd.h>

#define txtdiv printf("|=========================================|\n\n");
#define head /*system("clear");*/ printf("QAdventure3 0.1.0\nWritten by QMaury\nCopyright 2021-2022\n|=========================================|\n");  printRoomH();
#define invalid printf("???\n"); sleep(1.7);

int getAction();
void txtdvd();
void cont();
void printRoom();
void qExit();
void printRoomH();
