#include "panel.h"
#include "heart.h"
#include <stdio.h>
extern void clearpanel(){
	int i,j;
	for(i=0;i<PANEL_LINE;i++)
		for(j=0;j<PANEL_ROW;j++)
			panel[i][j]=0;
}
extern void printpanel(){
	int i,j;
	system("clear");
	for(i=0;i<PANEL_LINE;i++){
		for(j=0;j<PANEL_ROW;j++)
			if(panel[i][j]==0)
				printf(" ");
			else{
				//printf("*");     以前的，不带颜色
				int color;
				if(panel[i][j]>=100){
					color=panel[i][j]/100;		//除100，解析重叠颜色
					if(color%2!=0)
						color=color-1;
					}
				else 
					color = panel[i][j];
				switch(color)
				  {
					case DEFAULT_COLOR:	printf("*");break;				//默认颜色
					case RED:		printf("\033[49;31m#\033[39;49m");break;	//红色
					case YELLOW:		printf("\033[49;33m#\033[39;49m");break;
					case RANDOM:		printf("\033[49;%dm#\033[39;49m",rand()%7+30);break;
				  }
			}
		printf("\n");
		}
}
