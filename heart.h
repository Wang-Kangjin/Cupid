#ifndef __HEART_INCLUDE__
#define __HEART_INCLUDE__ 1
#define MAP_ROW 60
#define MAP_LINE 30
#define DEFAULT_COLOR 1
#define RED    2
#define YELLOW 3
#define RANDOM 4
//程序循环构造的心
extern void initmap(int 	 (*arr)[MAP_ROW],int color);

//使用瑞文手画的心
extern void initmapbyhand(int (*map)[MAP_ROW],int color);

//打印心型，暂不使用
extern void printmap(int	 (*arr)[MAP_ROW]);

//把目标数组添加到全局面板中 arr[0][0]放在panel的相应位置
extern void addto(int (*arr)[MAP_ROW],int line ,int row);				

//1次函数接受一个7至15的整数，返回一个【30】【60】大小的矩阵
extern int matrix_varys(int (*arr)[MAP_ROW],int w);

//改变标准矩阵大小，把结果放到temp矩阵中
extern int matrix_by_stand(int (*temp)[MAP_ROW],int (*arr)[MAP_ROW],int w);
#endif
