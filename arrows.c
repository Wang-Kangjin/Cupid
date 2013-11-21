
#include "panel.h"
#include "arrows.h"
#include "heart.h"

extern void add_arrow_to(int (*arr)[ARR_ROW],int row ,int line,int i,int arr_r_start){
			//把箭的（第i行，arr_r_start列）右下的部分放到panel的第line行，第row列
	int j;
	int m=line,n=row;
	for(i=0;i<ARR_LINE;i++,m++)
		for(j=arr_r_start,n=row;j<ARR_ROW;j++,n++){
			if(panel[m][n] == 0)
			panel[m][n] = arr[i][j];
			else if (panel[m][n]>=100 || panel[m][n]==YELLOW ||panel[m][n]==RANDOM)		//如果在重叠部分或者在黄色（第二个）区域
				panel[m][n]=panel[m][n];        //原本颜色不变
				else if(arr[i][j])
					panel[m][n] = arr[i][j];	//换成箭头颜色(不显示空格)
		}


}

