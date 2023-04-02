#include<iostream>//���������
#define MAXSIZE 10//�궨��
typedef int ElemType;//��int�����
using namespace std;//��׼�����ռ�
class SqQueue//˳�������
{
public://����Ȩ��
	SqQueue()//���������Զ���ʼ��
	{
		this->initQueue();//��ʼ��
	}
	~SqQueue()//���������Զ�����
	{
		delete this->base;
	}
	bool initQueue();//��ʼ��
	bool push(ElemType& elem);//��ջ
	bool pop(ElemType& elem);//��ջ
	void printQueue();//��ӡ˳�����
	int lengthQueue();//˳����еĴ�С
private://˽��Ȩ��
	ElemType* base;//�����洢���еĵ�ַ
	int rear;//β��
	int front;//ͷ��
};
bool SqQueue::initQueue()//���г�ʼ��
{
	this->base = new ElemType[MAXSIZE];//������д�СΪMAXSIZE�ڶ��������ص�ַ����base����
	if (this->base == NULL)//�������ʧ�ܣ���ֱ�ӷ���
	{
		return false;//�˳�ʧ��
	}
	this->front = 0;//ͷ����β����Ϊ0
	this->rear = 0;
	return true;//���سɹ�
}
bool SqQueue::push(ElemType& elem)//��ջ
{
	if ((this->rear + 1) % MAXSIZE == this->front)//�������洢MAXSIZE-1�����ݣ�Ŀ���Ƿ����ж��Ƿ���������ͷָ��+1=βָ�룬�����
	{                                             //ΪʲôҪ %MAXSIZE?��ΪҪ��֤βָ�����ѭ����0~MAXSIZE-1֮�䣬���βָ�뵱ǰλ����MAXSIZE-1��ĩ�ˣ�
		return false;                             //��1�ٳ��࣬���ֻص���0λ��
	}
	this->base[rear] = elem;//��������
	this->rear = (this->rear + 1) % MAXSIZE;//βָ�������Ϊ�˱�֤ѭ������Ҫ���ࣨע:�����ϲ��Ǹ�ָ�룩
	return true;
}
bool SqQueue::pop(ElemType& elem)//��ջ
{
	if (this->front == this->rear)//���ͷָ���βָ����ȣ�����ն��У�����ֱ�ӷ���
	{
		return false;
	}
	elem = this->base[this->front];//��ȡ����
	this->front = (this->front + 1) % MAXSIZE;//ͷָ�������Ϊ�˱�֤ѭ������Ҫ����
	return true;//�����ϲ�û��ɾ����ֻ�Ƿ��ʲ����ˣ��ոճ�ջ������λ���Ѿ����������޸���
}
void SqQueue::printQueue()//��������
{
	if (this->front == this->rear)//�������Ϊ�գ�ֱ�ӷ���
	{
		return;
	}
	int p = front;//p����ͷָ���������
	while (p != this->rear)//��ͷָ�벻����βָ��ʱ
	{
		cout << this->base[p] << " ";
		p++;//����
	}
	cout << endl;//����
}
int SqQueue::lengthQueue()
{
	return  (this->rear - this->front + MAXSIZE) % MAXSIZE;//��Ϊβָ��-ͷָ�����Ϊ��������+MAXSIZE�ٳ��࣬���Ա���Ϊ�������������Ϊ���Ͼ���ֵ
}
void showMenu()//�˵��������û�����
{
	cout << "  *****************" << endl;
	cout << "  *  ˳ �� �� ��  *" << endl;
	cout << "  *  1����ʼ��    *" << endl;
	cout << "  *  2����  ջ    *" << endl;
	cout << "  *  3����  ջ    *" << endl;
	cout << "  *  4����  ��    *" << endl;
	cout << "  *  5����  ��    *" << endl;
	cout << "  *  0����  ��    *" << endl;
	cout << "  *****************" << endl;
	cout << "����������ѡ��:";
}
int main()
{
	SqQueue sq;//�������ж���
	int select;//�洢�û�ѡ��
	while (true)//��ѭ������ȷ���˳�
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:
		{
			if (sq.initQueue())
			{
				cout << "��ʼ���ɹ���" << endl;
			}
			else
			{
				cout << "��ʼ��ʧ�ܣ�" << endl;
			}
			system("pause");//ͣ��
			system("cls");//����
		}
		break;
		case 2:
		{
			ElemType elem;
			cout << "������ջ�ĸ����ݣ�" << endl;
			cin >> elem;
			if (sq.push(elem))
			{
				cout << elem << "�Ѿ���ջ��" << endl;
			}
			else
			{
				cout << "��ջʧ�ܣ�" << endl;
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
				cout << elem << "�ѳ�ջ��" << endl;
			}
			else
			{
				cout << "��ջʧ�ܣ�" << endl;
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
			cout << "˳����еĳ�����:" << sq.lengthQueue() << endl;
			system("pause");
			system("cls");
		}
		break;
		default://��1~5����Ĭ�϶����˳�
		{
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
		}
		break;
		}
	}
}