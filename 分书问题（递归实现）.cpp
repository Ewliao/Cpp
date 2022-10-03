#include <iostream>

using namespace std;

int Num;
int take[5];

bool assigned[5]; 

int like[5][5] = {{0,0,1,1,0},{1,1,0,0,1},{0,1,1,0,1},{0,0,0,1,0},{0,1,0,0,1}};

void Try(int id){
	//递归终止条件：所有读者均已分配合理书籍
	if (id == 5)
	{
		//方案数加1
		Num++;
		
		//输出方案细节
		cout << "第" << Num << "个方案"	;
		for (int i = 0; i < 5; i++)
			cout << take[i] << ' ';
		cout << endl; 
		return;
	} 
	
	//为每一本书找到合适的读者
	for (int book = 0; book <= 4; book++)
	{
		//是否满足分书条件
		if((like[id][book] == 1) && !assigned[book])
		{
			//记录当前这本书的分配情况
			take[id] = book;
			assigned[book] = true;
			
			//为下一位读者分配合适的书籍
			Try(id + 1);
			
			//将书退还（回溯），尝试另一种方案
			assigned[book] = false; 
		 } 
	} 
	
}

int main(){
	Num = 0; //分书方案数初始值
	for (int book = 0; book < 5; book++)
		assigned[book] = false;
	 
	Try(0);
	
	return 0; 
	
}
