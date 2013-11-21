#include <stdio.h>
#include <stdlib.h>
#include "panel.h"
#include "heart.h"
#include "arrows.h"
#include "logo.h"

//朝右的箭头
int Arrow_horizional[7][88]={
{0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
{0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0},
{0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},
{0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0},
{0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0}
};
 int main(){
	int map1[MAP_LINE][MAP_ROW];
	int map2[MAP_LINE][MAP_ROW];
	int heart1[MAP_LINE][MAP_ROW];
	int heart2[MAP_LINE][MAP_ROW];
	clearpanel();
	initmapbyhand(map1,RED);
	initmapbyhand(map2,YELLOW);
	int size = 15; 

	int x=1,y=0;			//x标识心型最左上角的列，y标识箭头左上角对应的列
	int arr_r_start=ARR_ROW-1;	//从箭的第arr_r_start列及以后复制
	int heart_end_pos_x=35;		//心停止的列
	int heart_end_pos_y=6;		//心停止的行
	int arr_end_pos_x=18;		//箭停止的行
	int arr_end_pos_y=30;		//箭停止的列
	int down=20;			//最后闪多少下
	while(down){
		clearpanel();		//清屏
		
		matrix_by_stand(heart1,map1,size);	//根据初始化时心的大小来确定新的心的大小
		matrix_by_stand(heart2,map2,size);
		size=size>12?size-1:15;
		
		addto(heart1,heart_end_pos_y,x);
		addto(heart2,heart_end_pos_y,PANEL_ROW-x-MAP_ROW);
		if(x>=heart_end_pos_x)			//说明心形移动完成
			if (y<=arr_end_pos_y){
				add_arrow_to(Arrow_horizional,y,arr_end_pos_x,0,arr_r_start);
				if(arr_r_start == 0)
					y=y+3;			//箭出来以后的步长
				else
					arr_r_start-=3;		//箭在尚未完全出来的时候的步长
			}
		if(y >arr_end_pos_y)
			add_arrow_to(Arrow_horizional,y,arr_end_pos_x,0,0);
		printpanel();
		usleep(70000);
		if(x < heart_end_pos_x)
			x+=4;					//心走的步长
		if(x >=heart_end_pos_x && y >arr_end_pos_y)		//心和箭头都移动完成
			down--;
		
	}
	//down=50;
	clearpanel();
	int logo[LOGO_LINE][LOGO_ROW];
	initlogo(logo);
	//while(down){
		printlogo(logo);
	//	usleep(70000);
	//	down--;
	//}
  return 0;
  }
