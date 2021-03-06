/**
0: 空白
1: 人物
2: 砖
3: 箱子
4: 终点
5: 终点+箱子
6: 终点+人
**/

const char  map[][8][8] =
{
	    /*第1关*/
	2,2,2,2,2,2,2,2,
	2,0,0,0,0,4,0,2,
	2,0,0,0,0,0,0,2,
	2,0,2,0,3,0,0,2,
	2,0,0,0,0,2,0,2,
	2,0,0,0,0,0,0,2,
	2,0,1,0,0,0,0,2,
	2,2,2,2,2,2,2,2,
	 
		/*第2关*/
	2,2,2,2,2,2,2,2,
	2,0,0,0,0,4,0,2,
	2,0,0,0,2,0,0,2,
	2,0,2,0,3,0,0,2,
	2,0,0,0,0,2,0,2,
	2,0,0,0,0,0,0,2,
	2,0,1,0,0,0,0,2,
	2,2,2,2,2,2,2,2, 

	   /*第3关*/
	2,2,2,2,2,2,2,2,
	2,0,0,0,0,4,0,2,
	2,0,0,0,2,0,0,2,
	2,0,2,0,3,0,0,2,
	2,0,0,0,0,2,0,2,
	2,0,0,2,0,0,0,2,
	2,0,1,0,0,0,0,2,
	2,2,2,2,2,2,2,2, 

		/*第4关*/
	0,2,2,2,2,2,0,0,
	0,2,1,0,0,2,2,2,
	2,2,0,2,0,0,0,2,
	2,0,0,0,0,2,0,2,
	2,0,2,0,0,4,0,2,
	2,0,3,0,2,0,2,2,
	2,2,2,0,0,0,2,0,
	0,0,2,2,2,2,2,0, 

		/*第5关*/
    2,2,2,2,2,2,2,2,
	2,0,0,0,0,0,1,2,
	2,0,0,0,5,0,0,2,
	2,0,0,2,2,2,2,2,
	2,2,0,0,2,0,0,0,
	2,0,3,0,2,0,0,0,
	2,0,0,4,2,0,0,0,
	2,2,2,2,2,0,0,0, 

		/*第6关*/
    0,0,2,2,2,2,0,0,
	0,0,2,4,4,2,0,0,
	0,2,2,0,4,2,2,2,
	0,2,0,0,3,4,0,2,
	2,2,0,3,0,0,0,2,
	2,0,0,2,3,3,0,2,
	2,0,0,1,0,0,0,2,
	2,2,2,2,2,2,2,2, 

		/*第7关*/
    0,0,0,2,2,2,2,2,
	0,2,2,2,0,1,0,2,
	0,2,0,0,3,0,0,2,
	2,2,0,2,0,2,2,2,
	2,0,0,2,0,2,4,2,
	2,0,2,0,0,3,4,2,
	2,0,0,0,0,0,0,2,
	2,2,2,2,2,2,2,2,

		/*第8关*/
    0,0,0,2,2,2,2,0,
	0,2,2,2,0,1,2,0,
	0,2,0,0,3,0,2,0,
	2,2,0,2,0,2,2,2,
	2,0,0,2,0,2,4,2,
	2,0,2,0,0,0,0,2,
	2,0,0,0,0,0,0,2,
	2,2,2,2,2,2,2,2, 

		/*第9关*/
    0,0,0,2,2,2,2,0,
	0,2,2,2,0,1,2,0,
	0,2,0,0,3,0,2,0,
	2,2,0,2,0,2,2,2,
	2,0,0,2,0,2,4,2,
	2,0,2,0,0,3,4,2,
	2,0,3,0,0,0,4,2,
	2,2,2,2,2,2,2,2, 

		/*第10关*/
    0,0,2,2,2,2,2,0,
	2,2,2,0,0,0,2,0,
	2,0,3,0,2,0,2,2,
	2,0,2,0,0,4,0,2,
	2,0,0,0,0,2,0,2,
	2,2,3,2,4,0,0,2,
	0,2,1,0,0,2,2,2,
	0,2,2,2,2,2,0,0, 

		/*第11关*/
	0,2,2,2,2,2,2,0,
	2,2,0,0,0,0,2,0,
	2,1,3,0,0,0,2,0,
	2,2,3,0,0,0,2,2,
	2,2,0,3,0,0,0,2,
	2,4,3,0,0,0,0,2,
	2,4,4,5,4,0,0,2,
	2,2,2,2,2,2,2,2,

		/*第12关*/
	0,0,0,2,2,2,2,2,
	0,2,2,2,0,0,0,2,
	2,2,0,1,3,0,0,2,
	2,0,4,3,0,0,0,2,
	2,0,4,5,0,0,2,2,
	2,0,4,3,0,0,2,0,
	2,2,0,0,0,2,2,0,
	0,2,2,2,2,2,0,0,

		/*第13关*/
	2,2,2,2,2,2,2,2,
	2,0,0,0,2,0,1,2,
	2,0,0,0,5,0,0,2,
	2,2,0,2,0,2,2,2,
	2,0,0,2,0,0,0,2,
	2,0,3,0,0,2,0,2,
	2,0,0,4,2,0,0,2,
	2,2,2,2,2,2,2,2,

		/*第14关*/
	0,0,2,2,2,2,2,0,
	2,2,2,0,0,0,2,0,
	2,0,3,0,2,0,2,2,
	2,0,2,0,0,4,0,2,
	2,0,0,0,0,2,0,2,
	2,2,0,2,0,0,0,2,
	0,2,1,0,0,2,2,2,
	0,2,2,2,2,2,0,0,

		/*第15关*/
	0,0,2,2,2,2,2,0,
	2,2,2,0,0,0,2,0,
	2,0,3,0,2,0,2,2,
	2,0,2,0,0,4,0,2,
	2,0,0,0,0,2,0,2,
	2,2,3,2,4,0,0,2,
	0,2,1,0,0,2,2,2,
	0,2,2,2,2,2,0,0,

		/*第16关*/
	0,0,0,2,2,2,2,0,
	0,2,2,2,0,1,2,2,
	0,2,0,0,3,0,0,2,
	2,2,4,2,0,2,0,2,
	2,0,0,2,0,2,0,2,
	2,0,0,0,0,0,0,2,
	2,2,0,0,0,2,2,2,
	0,2,2,2,2,2,0,0,

		/*第17关*/
	0,0,0,2,2,2,2,2,
	0,2,2,2,0,1,0,2,
	0,2,0,0,3,0,0,2,
	2,2,0,2,0,2,0,2,
	2,0,0,2,0,2,4,2,
	2,0,2,0,0,3,4,2,
	2,0,0,0,2,0,0,2,
	2,2,2,2,2,2,2,2,

		/*第18关*/
	0,0,0,2,2,2,2,0,
	0,2,2,2,0,1,2,0,
	0,2,0,0,3,0,2,0,
	2,2,0,2,0,2,2,2,
	2,0,0,2,0,2,4,2,
	2,0,2,0,0,3,4,2,
	2,0,3,0,0,0,4,2,
	2,2,2,2,2,2,2,2,

		/*第19关*/
	0,2,2,2,2,0,0,0,
	2,2,0,0,2,2,0,0,
	2,1,3,0,0,2,0,0,
	2,2,3,0,0,2,2,0,
	2,2,0,3,0,0,2,0,
	2,4,3,0,0,0,2,0,
	2,4,4,5,4,2,2,0,
	2,2,2,2,2,2,0,0,

		/*第20关*/
	0,0,0,2,2,2,2,0,
	0,2,2,2,0,0,2,2,
	2,2,0,1,3,0,0,2,
	2,0,4,3,0,0,0,2,
	2,0,4,5,0,2,2,2,
	2,0,4,3,0,2,0,0,
	2,2,0,0,2,2,0,0,
	0,2,2,2,2,0,0,0,

		/*第21关*/
	0,0,2,2,2,2,0,0,
	0,0,2,4,4,2,0,0,
	0,2,2,0,4,2,2,0,
	0,2,0,0,3,4,2,0,
	2,2,0,3,0,0,2,2,
	2,0,0,2,3,3,0,2,
	2,0,0,1,0,0,0,2,
	2,2,2,2,2,2,2,2,
};
