#include<iostream>//输入输出流
#define MAXSIZE 10//宏定义
typedef int ElemType;//给int起别名
using namespace std;//标准命名空间
class SqQueue//顺序队列类
{
public://公共权限
	SqQueue()//创建对象自动初始化
	{
		this->initQueue();//初始化
	}
	~SqQueue()//对象销毁自动调用
	{
		delete this->base;
	}
	bool initQueue();//初始化
	bool push(ElemType& elem);//入栈
	bool pop(ElemType& elem);//出栈
	void printQueue();//打印顺序队列
	int lengthQueue();//顺序队列的大小
private://私有权限
	ElemType* base;//用来存储队列的地址
	int rear;//尾部
	int front;//头部
};
bool SqQueue::initQueue()//队列初始化
{
	this->base = new ElemType[MAXSIZE];//申请队列大小为MAXSIZE在堆区，返回地址交给base保管
	if (this->base == NULL)//如果申请失败，则直接返回
	{
		return false;//退出失败
	}
	this->front = 0;//头部和尾部都为0
	this->rear = 0;
	return true;//返回成功
}
bool SqQueue::push(ElemType& elem)//入栈
{
	if ((this->rear + 1) % MAXSIZE == this->front)//这里最大存储MAXSIZE-1个数据，目的是方便判断是否队满，如果头指针+1=尾指针，则队满
	{                                             //为什么要 %MAXSIZE?因为要保证尾指针可以循环在0~MAXSIZE-1之间，如果尾指针当前位置在MAXSIZE-1（末端）
		return false;                             //加1再除余，就又回到了0位置
	}
	this->base[rear] = elem;//存入数据
	this->rear = (this->rear + 1) % MAXSIZE;//尾指针迭代，为了保证循环所以要除余（注:本质上不是个指针）
	return true;
}
bool SqQueue::pop(ElemType& elem)//出栈
{
	if (this->front == this->rear)//如果头指针和尾指针相等（代表空队列），则直接返回
	{
		return false;
	}
	elem = this->base[this->front];//提取数据
	this->front = (this->front + 1) % MAXSIZE;//头指针迭代，为了保证循环所以要除余
	return true;//本质上并没有删除，只是访问不到了，刚刚出栈的数据位置已经可以任意修改了
}
void SqQueue::printQueue()//遍历队列
{
	if (this->front == this->rear)//如果队列为空，直接返回
	{
		return;
	}
	int p = front;//p代替头指针访问数据
	while (p != this->rear)//当头指针不等于尾指针时
	{
		cout << this->base[p] << " ";
		p++;//迭代
	}
	cout << endl;//换行
}
int SqQueue::lengthQueue()
{
	return  (this->rear - this->front + MAXSIZE) % MAXSIZE;//因为尾指针-头指针可能为负数，先+MAXSIZE再除余，可以避免为负数，可以理解为加上绝对值
}
void showMenu()//菜单，方便用户操作
{
	cout << "  *****************" << endl;
	cout << "  *  顺 序 队 列  *" << endl;
	cout << "  *  1、初始化    *" << endl;
	cout << "  *  2、入  栈    *" << endl;
	cout << "  *  3、出  栈    *" << endl;
	cout << "  *  4、遍  历    *" << endl;
	cout << "  *  5、长  度    *" << endl;
	cout << "  *  0、退  出    *" << endl;
	cout << "  *****************" << endl;
	cout << "请输入您的选项:";
}
int main()
{
	SqQueue sq;//创建队列对象
	int select;//存储用户选择
	while (true)//死循环，正确可退出
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
		{
			if (sq.initQueue())
			{
				cout << "初始化成功！" << endl;
			}
			else
			{
				cout << "初始化失败！" << endl;
			}
			system("pause");//停顿
			system("cls");//清屏
		}
		break;
		case 2:
		{
			ElemType elem;
			cout << "你想入栈哪个数据！" << endl;
			cin >> elem;
			if (sq.push(elem))
			{
				cout << elem << "已经入栈！" << endl;
			}
			else
			{
				cout << "入栈失败！" << endl;
			}
			system("pause");
			system("cls");
		}
		break;
		case 3:
		{
			ElemType elem;
			if (sq.pop(elem))
			{
				cout << elem << "已出栈！" << endl;
			}
			else
			{
				cout << "出栈失败！" << endl;
			}
			system("pause");
			system("cls");
		}
		break;
		case 4:
		{
			sq.printQueue();
			system("pause");
			system("cls");
		}
		break;
		case 5:
		{
			cout << "顺序队列的长度是:" << sq.lengthQueue() << endl;
			system("pause");
			system("cls");
		}
		break;
		default://除1~5其他默认都是退出
		{
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
		}
		break;
		}
	}
}