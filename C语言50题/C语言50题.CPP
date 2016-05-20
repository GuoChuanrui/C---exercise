/*
//50.编写函数unsigned int reverse_bit(unsigned int value);这个函数的返回值是value的二进制位模式从左到右翻转后的值
#include<stdio.h>
unsigned int reverse_bit(unsigned int value)
{
	int i=sizeof(unsigned int)*8;
	unsigned int result=0;
	unsigned int left=0x80000000;  //最高位为1 其他为0
	unsigned int right=0x00000001;  //最低位为1 其他为0
	while(i--) 
	{ 
		if(value&left)   //和向右移动的left按位与
		{
			result|=right;   //与的结果为1则把翻转位置的值置1，为0则跳过
		}
		left=left>>1;   
		right=right<<1;	
	}
	return result;
}
void main()
{
	unsigned int result=0;
	result=reverse_bit(25);
	printf("%u\n",result);
}
*/


/*
//49.有一个字符串是“student a am i”，编写代码将字符串转换为“i am a student”，空间复杂度为O(1)
#include <stdio.h>
#include <string.h>
void convert(char* src,char* dest)
{
    int i,j,k=0;
    for(i=strlen(src)-1;i>=0;i--)
    {
        if(src[i]==' ')
        {
            for(j=i+1;src[j]&&src[j]!=' ';j++)
                dest[k++] = src[j];
            dest[k++] = ' ';
        }
    }
    for(i=0;src[i]!=' ';i++)
        dest[k++] = src[i];
    dest[k] = '\0';
}
void main()
{
    char a1[20]="student a am i";
	char a2[20];
    convert(a1,a2);
    printf("%s\n",a2);
}
*/


/*
//48.编程实现：一个函数可以求任意多个整数的平均值（使用可变参数列表）
#include <stdio.h>
#include<stdarg.h>
int Avg(int n,...)
{
	va_list arg;
	va_start(arg,n);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=va_arg(arg,int);
	}
	va_end(arg);
	return sum/n;
}
void main()
{
	int avg;
	avg=Avg(3,1,2,3);
	printf("%d\n",avg);
}
*/


/*
//47.求解：1元钱一瓶汽水，喝完后两个空瓶换一瓶汽水，问：你有20元钱，最多可以喝到几瓶汽水？
#include <stdio.h>
void main()
{
	int money=10;     //钱数
	int total=money;   //总共喝的瓶数
	int bottle=total;  //空瓶数
	while(bottle>=2)
	{
		total+=bottle/2;
		bottle=bottle/2+bottle%2;
	}
	printf("最多可以喝到%d瓶\n",total);
}
*/



//46.编写一个函数：将一个数字字符串转换为对应的数字，不考虑溢出。（比如“12.34”转换为数字：12.34）功能类似于库函数atof,考虑异常输入。
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
double my_atof( const char *string )
{
	assert(string!=NULL);
	double val=0.0,power=0.0;
	int sign=0;
	while(*string==' ')
	{
		string++;
	}
	sign=(*string=='-')? -1:1;
	if(*string=='+'||*string=='-')
	{
		string++;	
	}
	while((*string>='0')&&(*string<='9'))
	{
		val=val*10.0+(*string-'0');
		string++;
	}
	if(*string=='.')
	{
		string++;
	}
	power=1.0;
	while((*string>='0')&&(*string<='9'))
	{
		val=val*10.0+(*string-'0');
		power=power*10;
		string++;
	}
	return sign*val/power;
}
void main()
{
	char *p="12.34";
	double result=my_atof(p);
	printf("%.2f\n",result);
}



/*
//45.编写一个函数，实现内存的设置，功能类似于memset,可以以字节为单位设置内存的值，不能使用任何库函数
#include <stdio.h>
#include <assert.h>
void *my_memset(void *dest,int c,size_t count)
{
	assert(dest!=NULL);
	char* pdest=(char *)dest;
	while(count-->0)
	{
		*pdest++=c;
	}
	return dest;
}
void main()
{
	char ar[10];
	char *p;
	p=(char *)my_memset(ar,0,sizeof(char)*10);
	printf("%s\n",p);
}
*/


/*
//44.编写一个函数，实现内存的拷贝，功能类似于memmove,实现内存重叠拷贝，不能使用任何库函数
#include <stdio.h>
#include <string.h>
#include <assert.h>
void *my_memmove(void *dest,const void *src,size_t count)
{
	assert(dest!=NULL&&src!=NULL);
	char *pdest=(char *)dest;
	char *psrc=(char *)src;
	if(psrc>=pdest||pdest>=psrc+count)
	{
		while(count-->0)
		{
			*pdest++=*psrc++;
		}
	}
	else
	{
		while(count-->0)
		{
			*(pdest+count)=*(psrc+count);
		}
	}
	return dest;
}
void main()
{
	char a1[10]="abcd";
	char a2[10]="xyz";
	printf("%s\n",my_memmove(a1,a2,3));
}
*/


/*
//43.编写一个函数，实现内存的拷贝，功能类似于memcpy,可以不实现内存重叠拷贝，不能使用任何库函数
#include<stdio.h>
#include <assert.h>
void *my_memcpy(void *dest,const void *src,size_t count)
{
	assert(dest!=NULL&&src!=NULL);
	char *pdest=(char*)dest;
	const char *psrc=(const char *)src;
	for(int i=0;i<count;i++)
	{
		*pdest++=*psrc++;
	}
	*pdest='\0';
	return dest;
}
void main()
{
	char a1[50]="abc";
	char a2[10]="xyz";
	char *p=(char *)my_memcpy(a1,a2,3);
	printf("%s\n",p);
}
*/


/*
//42.实现字符串的比较，功能类似strcmp,不使用任何库函数
#include <stdio.h>
#include <assert.h>
int my_strcmp(const char *dest, const char *src)
{
	assert(dest!=NULL && src!=NULL);
	if(*dest=='\0' && *src=='\0')
		return 0;
	const char *pdest=dest;
	const char *psrc=src;
	int result=0;
	while(*pdest!='\0'||*psrc!='\0')
	{
		if((result=*pdest-*psrc) != 0)
			break;
		pdest++;
		psrc++;
	}
	if(result>0)
		result=1;
	else if(result<0)
		result=-1;
	return result;
}
void main()
{
	char a[10]="abc";
	char b[10]="xyz";
	printf("%d\n",my_strcmp(a,b));
}
*/


/*
//41.实现字符串的链接，功能类似strcat,不使用任何库函数
#include <stdio.h>
#include <assert.h>
char *my_strcat(char dest[],char src[])
{
	assert(dest!=NULL&&src!=NULL);
    char *pdest=dest;
	char *psrc=src;
	while(*pdest!='\0')
	{
		pdest++;
	}
	while(*psrc!='\0')
	{
		*pdest++=*psrc++;
	}
	*pdest='\0';
	return dest;
}
void main()
{
	char a1[10]="abc";        
	char a2[10]="123";
	char *p=my_strcat(a1,a2);
	printf("%s\n",p);
}
*/


/*
//40.实现字符串的拷贝，功能类似strcpy,不使用任何库函数
#include <stdio.h>
#include <assert.h>
char *my_strcpy(char dest[],const char src[])
{
	assert(dest!=NULL&&src!=NULL);
	char *pdest=dest;
	const char *psrc=src;
	while(*psrc!='\0')
	{
		*pdest++=*psrc++;
	}
//	*pdest='\0';
	return dest;
}
void main()
{
	char a1[10]="123";
	char a2[10]="abc";
	char *p=my_strcpy(a1,a2);
	printf("%s\n",p);
}
*/


/*
//39.当输入小写字母a,输出大写字母Z，输入b，输出Y，以此类推，当输入z，输出A。要求时间复杂度为O(1)
#include <stdio.h>
#include <string.h>
void output(char str[])
{
	for(int i=0;i<10;i++)
	{
		if(str[i]>='a'&&str[i]<='z')
			str[i]=str[i]-(7+2*(str[i]-'a'));     
	}
	printf("%s\n",str);
}
void main()
{
	char ar[100];
	printf("请输入字符串:");
	scanf("%s",ar);
	output(ar);	
}
*/


/*
//38.从标准输入读取字符，并把他们写到标准输出。除了大写字母转换成小写字母外，其他的原样输出
#include <stdio.h>
#include <string.h>
void output(char str[])
{
	int len=strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[i]>='A'&&str[i]<='Z')
			str[i]=str[i]+32;
	}
	printf("%s\n",str);
}
void main()
{
	char ar[100];
	printf("请输入字符:");
	scanf("%s",ar);
	output(ar);
}
*/


/*
//37.编写一个函数，从一个字符串中提取出一个字符串
#include <stdio.h>
#include<string.h>
#include <assert.h>
int substr(char dst[],char src[],int start,int len)   //从src起始位置偏移start个字符的位置开始，最多复制len个非空字符，dst以NULL结尾，返回值是dst中字符串的个数 
{
	assert(src!=NULL);
	int count=0;
	char *pSrc=src;
	char *pDst=dst;
	pSrc+=start;
	while(len-->0)
	{
		if(*pSrc!='\0')
		{	*pDst++=*pSrc++;
			count++;
		}
		else 
			break;
	}
	*pDst=NULL;
	return count;
}
void main()
{
	char dst[20]={0};
	char src[]="hello-world";
	int len=substr(dst,src,9,4);
	printf("%s  长度为 %d \n",dst,len);
}
*/


/*
//36.将一个字符串内容逆序
#include <stdio.h>
#include <string.h>
char *invert(char *pStr)
{
	int len=strlen(pStr);
	static char p[20];          
	for(int i=0;i<len;i++)
	{
		p[i]=pStr[len-1-i];
	}
	p[len]='\0';
	return p;
}
void main()
{
	char ar[]="bit-tech";
	char *p=invert(ar);
	printf("%s\n",p);
}
*/


/*
//35.在字符串中查找一个指定的字符第一次出现的位置，并返回字符所在的位置，如果不存在则返回NULL
#include <stdio.h>
#include<assert.h>
#include<string.h>
int search(const char *pStr,char s)
{
	assert(pStr!=NULL);
	const char *p=pStr;
	int count=1;
	while(*p!='\0')
	{
		if(*p++!=s)
			count++;
		else 
			break;
	}
	if(count>=strlen(pStr)+1)
		return 0;
	else
		return count;
}
void main()
{
	char *p="qwertyuiop";
	int pos=search(p,'o');
	if(pos==0)
		printf("NULL\n");
	else
		printf("%d\n",pos);
}
*/


/*
//34.程序接受一个整数输入，输出该整数的每一位
#include <stdio.h>
void main()
{
	int a,i=0;
	int ar[10]={0};
	printf("请输入一个数字:");
	scanf("%d",&a);
	while(a>=1)
	{
		ar[i]=a%10;
		a=a/10;
		i++;
	}

	for(i=i-1;i>=0;i--)
	{
		printf("%d ",ar[i]);
	}
	printf("\n"); 
}
*/


/*
//33.求1-100这100个整数中9出现的次数
#include <stdio.h>
void main()
{
	int count=0;
	for(int i=1;i<=100;i++)
	{
		if(i%10==9||(i>=90&&i<99))
			count++;
	}
	printf("9出现%d次\n",count);
}
*/


/*
//32.不允许创建第三方变量交换两个数的值
#include <stdio.h>
void swap(int *a,int *b)
{
	*a=*a+*b;
	*b=*a-*b;
	*a=*a-*b;
}
void main()
{
	int a,b;
	printf("请输入两个数:");
	scanf("%d %d",&a,&b);
	//swap(&a,&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("交换后: a=%d , b=%d\n",a,b);
}
*/


/*
//31.编写程序判断你的电脑存储方式时大端存储还是小端存储
#include <stdio.h>
void main()
{
	union temp
	{
		unsigned short int a;
		unsigned char b;
	}temp;
	temp.a=0X0001;
	if(temp.b==0x00)
		printf("大端\n");
	else
		printf("小端\n");
}
*/


/*
//30.求一个数的二进制序列中1的个数
#include <stdio.h>
void main()
{
	int n,count=0;
	printf("请输入一个数:>");
	scanf("%d",&n);
	while(n)
	{
		if((n&(0x0001))==1)
			count++;
		n=n>>1;
	}
	printf("%d\n",count);
}
*/


/*
//29.对任意一个整型数组排序（用选择排序法）
#include <stdio.h>
void main()
{
	int a[]={1,2,34,225,65,45,76,8};
	int temp,len=sizeof(a)/sizeof(int);
	for(int i=0;i<len-1;i++)      
	{
		for(int j=i+1;j<len;j++)
		{
			if(a[i]>a[j])
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	for(i=0;i<len;i++)
	{
		printf("%d\n",a[i]);
	}
	
}
*/


/*
//28.不允许创建临时变量求一个字符串的长度
#include <stdio.h>
#include <string.h>
void main()
{
	char *p="hello";
	printf("%s的字符长度为:%d\n",p,strlen(p));
}
*/


/*
//27.编写一个函数可以求字符串的长度（不使用任何库函数）
#include <stdio.h>
#include <assert.h>
int my_strlen(const char *p)
{
	assert(p!=NULL);
	int count=0;
	while(*p++!='\0')
	{
		count++;
	}
	return count;

}
void main()
{
	char *p="hello";
	int len=my_strlen(p);
	printf("%s字符的长度为：%d\n",p,len);
}
*/


/*
//26.用非递归的方式求斐波那契数列的第n个数
#include <stdio.h>
void main()
{
	int n;
	printf("请输入个数n:>");
	scanf("%d",&n);
	int fb1=1,fb2=1,result=0;
	if(n==1||n==2)
		result=1;
	for(int i=2;i<n;i++)
	{
		result=fb1+fb2;
		fb1=fb2;
		fb2=result;
	}
	printf("第%d个数为%d\n",n,result);
}
*/


/*
//25.用递归的方式求斐波那契数列的第n个数
#include <stdio.h>
int fb(int n)
{	
	int result=0;
	if(n==1)
		result=1;
	else if(n==2)
		result=1;
	else
		result=fb(n-2)+fb(n-1);
	return result;

}
void main()
{
	int n;
	printf("请输入个数n:>");
	scanf("%d",&n);
	int result=fb(n);
	printf("%d\n",result);
}
*/


/*
//24.将多个字符串排序输出
#include <stdio.h>
#include <string.h>
 //交换
void swap(char *p1,char *p2)
{
	char p[20];
	strcpy(p,p1);
	strcpy(p1,p2);
	strcpy(p2,p);
}
void main()
{
	char str1[20]="hello";
	char str2[20]="bit-tech";
	char str3[20]="world";
	if(strcmp(str1,str2)>0)
		swap(str1,str2);
	if(strcmp(str1,str3)>0)
		swap(str1,str3);
	if(strcmp(str2,str3)>0)
		swap(str2,str3);
	printf("%s  %s  %s\n",str1,str2,str3);
}
*/


/*
//23.对任意一个整型数组排序（用冒泡排序法）
#include <stdio.h>
void main()
{
	int a[10]={1,5,32,14,54,26,7,82,91,10};
	int temp=0;
	for(int i=0;i<sizeof(a)/sizeof(int)-1;i++)
	{
		for(int j=0;j<sizeof(a)/sizeof(int)-1-i;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(i=0;i<sizeof(a)/sizeof(int);i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
*/


/*
//22.将一个整型数组逆序
#include <stdio.h>
void main()
{
	int a[5]={1,2,3,4,5};
	int temp,k=sizeof(a)/sizeof(int);
	for(int i=0;i<k/2;i++)
	{
		temp=a[i];
		a[i]=a[k-i-1];	
		a[k-i-1]=temp;
	}
	for(i=0;i<k;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
*/

/*
//21.求一个3*3矩阵对角线元素之和
#include <stdio.h>
int main()
{
	int a[3][3]={1,2,3,4,5,6,7,8,9};
	int sum=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if((i==j)||(i+j==2))
			{
				sum+=a[i][j];
			}
		}
	}
	printf("3*3矩阵对角线和：%d\n",sum);
	return 0;
}
*/


/*
//20.判断一个字符串是否为回文字符串
#include<stdio.h>
#include<string.h>
#include <malloc.h>
void main()
{
	char *p=(char*)malloc(sizeof(char)*100);
	char a[100];
	printf("请输入一个字符串：");
	scanf("%s",p);
	char *s=p;
	int i=strlen(p);
	a[i]='\0';
	i=i-1;
	while(i>=0)
	{
		a[i]=*s++;
		i--;
	}
	if(strcmp(p,a)==0)
	{
		printf("%s是回文字符串\n",p);
	}
	else
	{
		printf("%s不是回文字符串\n",p);
	}
	free(p);
	free(s);
}
*/


/*
//19.判断一个数是否为回文数
#include<stdio.h>
void main()
{
	int num,new_num=0,temp;
	scanf("%d",&num);
	temp=num;
	while(num)
	{
		new_num=new_num*10+num%10;
		num/=10;
	}
	if(temp==new_num)
		printf("是回文\n");
	else
		printf("不是回文\n");
}
*/


/*
//18.求解 1+2!+3!+…+20!的和
#include<stdio.h>
void main()
{
	int i,j,jc,sum=0;
	for(i=1;i<=20;i++)
	{
		jc=1;
		for(j=1;j<=i;j++)
		{
			jc=jc*j;
		}
		sum+=jc;
	}
	printf("sum=%d\n",sum);
}
*/
  
  
/*
//17.求解1-1/2+1/3-1/4+1/5…+1/99-1/100的值
#include<stdio.h>
void main()
{
	float deno=1,sign=1,sum=0;
	for(int i=0;i<100;i++)
	{
		sum+=sign/deno;
		deno++;
		sign=sign*(-1);
	}
	printf("sum=%f\n",sum);
}
*/


/*
//16.猴子吃桃问题。每天吃一半加1个，第10天只剩一个桃子。求第一天共摘了多少。
#include<stdio.h>
void main()
{
	int sum=1;
	for(int i=0;i<10;i++)
	{
		sum=(sum+1)*2;
	}
	printf("第一天共摘了%d个\n",sum);
}
*/


/*
//15.一球从100米高度落下，每次落地后反跳到原高度的一半；再落下，求它在第10次落地时，共经过多少米？第10次反弹多高？
#include<stdio.h>
void main()
{
	float height=100,sum=height;
	for(int i=0;i<10;i++)
	{
		height=height/2;
		sum+=height;
	}
	printf("共经过%f米，第10次反弹%f米\n",sum,height);
}
*/


/*
//14.求解s=a+aa+aaa+aaaa+aa…a，其中a是一个数字。
#include<stdio.h>
#include<math.h>
void main()
{
	int a,n,temp,s;
	printf("请输入a,n:");
	scanf("%d %d",&a,&n);
	temp=a;
	s=a;
	for(int i=1;i<n;i++)
	{
		temp+=a*pow(10,i);
		s+=temp;
	}
	printf("%d\n",s);
}
*/


/*
//13.有一分数数列：2/1,3/2,5/3,8/5,13/8,21/13…，求出这个数列的前20项之和。
#include<stdio.h>
void main()
{
	float nume=2,deno=1,temp,sum=0;    //nume分子，deno分母
	for(int i=0;i<20;i++)
	{
		sum+=nume/deno;
		temp=nume;
		nume=deno+nume;
		deno=temp;
	}
	printf("sum=%f\n",sum);	
}
*/
  
  
/*
//12.在屏幕上输出2000年之前的所有润年和润年个数
#include<stdio.h>
void main()
{
	int year=1,count=0;
	for(year=1;year<=2000;year++)
	{
		if((year%4==0&&year%100!=0)||year%400==0)
		{
			printf("%d  ",year);
			count++;
			if(count%10==0)
				printf("\n");
		}
		
	}
	printf("\n一共%d个润年。\n",count);
}
*/


/*
//11.有1、2、3、4四个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
#include<stdio.h>
void main()
{
	int i,j,k,count=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			for(k=0;k<4;k++)
			{
				if(i!=j&&i!=k&&k!=j)
				{
					printf("  %d%d%d   ",i+1,j+1,k+1);
					count++;
				}
			}
		}
	}
	printf("\n一共%d个。\n",count);
}
*/


/*
//10.写一个函数，函数的功能是：交换两个整数的值
#include<stdio.h>
void change(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void main()
{
	int x,y;
	printf("请输入x,y:");
	scanf("%d %d",&x,&y);
	change(&x,&y);
	printf("x=%d  y=%d\n",x,y);
}
*/


/*
//9.交换两整数的值
#include<stdio.h>
void main()
{
	int a,b,temp;
	printf("请输入a，b：");
	scanf("%d %d",&a,&b);
	temp=a;
	a=b;
	b=temp;
	printf("a=%d,b=%d\n",a,b);
}
*/
  

/*
//8.求两个整数的最小公倍数
#include<stdio.h>
void main()
{
	int m,n,t,r,p;
	printf("请输入两个整数：");
	scanf("%d %d",&m,&n);
	if(m<n)
	{
		t=m;
		m=n;
		n=t;
	}
	p=m*n;
	while(n!=0)
	{
		r=m%n;
		m=n;
		n=r;
	}
	printf("最小公倍数为：%d\n",p/m);	
}
*/
  
  
/*
//7.求两个整数的最大公约数
#include<stdio.h>
void main()
{
	int m,n,t,r;
	printf("请输入两个整数：");
	scanf("%d %d",&m,&n);
	if(m<n)
	{
		t=m;
		m=n;
		n=t;
	}
	while(n!=0)
	{
		r=m%n;
		m=n;
		n=r;
	}
	printf("最大公约数为 %d\n",m);
}
*/


/*
//6.求1-100之间的素数
#include<stdio.h>
#include<math.h>
void main()
{
	int n,k,i;     //n从1-100，K是根号n
	for(n=2;n<100;n++)
	{
		k=sqrt(n);
		for(i=2;i<=k;i++)
		{
			if(n%i==0) break;
		}
		if(i>=k+1)
		{
			printf("%d ",n);
		}
	}
	printf("\n");
}

*/


/*
//5.求10个整数中的最大值
#include<stdio.h>
void main()
{
	int ar[10]={1,2,3,45,56,6,8,10,98,9};
	int i,max=a[0];
	for(i=0;i<10;i++)
	{
		if(max<ar[i])
			max=ar[i];
	}
	printf("最大值是%d\n",max);
}
*/


/*
//4.求两个整数的较大值
#include<stdio.h>
void main()
{
	int a,b;
	scanf("%d,%d",&a,&b);
	if(a>b)
		printf("较大值为：%d\n",a);
	else
		printf("较大值为：%d\n",b);
}

*/


/*
//3.在屏幕上打印9*9乘法口诀表
#include<stdio.h>
void main()
{
	int i,j;
	for(i=1;i<10;i++)
	{
		for(j=1;j<i+1;j++)
		{
			printf("%d*%d=%d  ",j,i,i*j);
		}
		printf("\n");
	}
}
*/


/*
//2.计算1,2,3,4，…,100这100个整数的和
#include<stdio.h>
void main()
{
	int i,sum=0;
	for(i=1;i<101;i++)
	{
		sum+=i;
	}
	printf("1+2+…+100 = %d\n",sum);
}
*/


/*
//1.在屏幕上输出“Hello World”
#include<stdio.h>
void main()
{
	printf("Hello World\n");
}
*/