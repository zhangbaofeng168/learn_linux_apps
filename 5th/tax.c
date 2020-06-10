/*****************
*文件名：tax.c
*创建时间:2015-10-25
*创建者:baofeng
*程序说明:个人税率计算函数库
******************/

#include <stdio.h>

int tax(int salary,int insurance)
{
    int tax_salary = salary - insurance;
	
    int tmp = tax_salary - 3500;
    if(tmp < 0)
    {
    	printf("you needn't to tax!\n");
        return 0;
    }
    else if(tmp <= 1500)
        return (tmp*0.03 - 0);
    else if(tmp <= 4500)
        return (tmp*0.1 - 105);
    else if(tmp <= 9000)
        return (tmp*0.2 - 555);	
    else if(tmp <= 35000)
        return (tmp*0.25 - 1005);
    else if(tmp <= 55000)
        return (tmp*0.3 - 2755);
    else if(tmp <= 80000)
        return (tmp*0.35 - 5505);
    else 
        return (tmp*0.45 - 13505);
        	
}