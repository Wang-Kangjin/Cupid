#ifndef LOGOINCLUDE
#define LOGOINCLUDE
#define LOGO_LINE 23
#define LOGO_ROW  86

extern void initlogo(int (*logo)[LOGO_ROW]);
extern void addlogo(int (*logo)[LOGO_ROW],int,int);
extern void printlogo(int (*logo)[LOGO_ROW]);
#endif 
