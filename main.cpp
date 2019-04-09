#include<iostream>
#include<stdlib.h>
using namespace std;

class node
	{
	public:
		int no;
		char b;
		char name[20];
		node *next,*prev;
	};

class list
	{
		node *head[6],*p,*t;
		public:
			void create();
			void display();
			void book();
			void verify();
			void cancel();
	};


void list::create()
		{
			int i,j=0;
			for(i=0;i<6;i++)
			{
				head[i] = new node;
				head[i]->b = 'v';
				head[i]->no = 10*(i+1);
				head[i]->prev = NULL;
				head[i]->next = NULL;
				p = head[i];
					for(j=0;j<8;j++)
					{
						t = p;
						p-> next = new node;
						p = p->next;
						p->b = 'v';
						p->no = 10*(i+1)+(j+1);
						p->prev = t;
						p->next = NULL;
					}
				t = p;
				p-> next = new node;
				p = p->next;
				p->b = 'v';
				p->no = 10*(i+1)+(j+1);
				p->prev = t;
				head[i]->prev = p;
				p->next = head[i];
			}
		}

void list::display()
		{
			cout<<"\n seats available are as follows (The zero indicates it as vacant)";
			for(int i=0;i<6;i++)
			{
				if(i==2)
					cout<<"\n\n\n";
				p = head[i];
				cout<<"\n\n";
				do{
					cout<<"  "<<p->no<<" "<<p->b;
					p = p->next;
				}while(p != head[i]);
			}
			cout<<"\n\t\t======================================================";
			cout<<"\n\t\t======================================================\n";
		}


void list::book()
	{
		int i,j,m;
		do{
			cout<<"\n Enter the seat no. you want to book ";
			cin>>m;
			if(m<10||m>71)
				cout<<"\n Please enter valid seat no. \n";
			else
			{
				for(i=0;i<6;i++)
				{
					p = head[i];
					do{
						if(m == p->no)
						{
								if(p->b == 'b')
									cout<<"\n Seat no. "<<p->no<<" is not available ";
								else
								{
									p->b = 'b';
									cout<<"\n Enter your name ";
									cin>>p->name;
									break;
								}
						}
						p = p->next;
					}while(p != head[i]);
				}
			}
		cout<<"\n Enter one to book one more ticket";
		cin>>j;
		}while(j==1);
	}


void list::cancel()
	{
		int i,j,m;
		do{
			cout<<"\n Enter the seat no. you want to cancel ";
			cin>>m;
			for(i=0;i<6;i++)
			{
				p = head[i];
				do{
					if(m == p->no)
					{
					p->b = 'v';
					}
					p = p->next;
				}while(p != head[i]);
			}
		cout<<"\n Enter one to cancel one more ticket";
		cin>>j;
		}while(j==1);
	}

void list::verify()
	{
		int i,j,m;
		do{
			cout<<"\n Enter the seat no. you want to verify ";
			cin>>m;
			for(i=0;i<6;i++)
			{
				p = head[i];
				do{
					if(m == p->no)
					{
						if(p->b == 'v')
							cout<<"\n seat is vacant ";
						else
							cout<<"\n Name of the customer is :\t"<<p->name;
							cout<<"\n Seat no. :\t"<<p->no;
					}
					p = p->next;
				}while(p != head[i]);
			}
		cout<<"\n Enter one to verify another customer ";
		cin>>j;
		}while(j==1);
	}


int main()
{
	list s;
	int i,m;
	s.create();
	while(1)
	{
			cout<<"\n Enter your choice\
					\n\t1) The list of available seats\
					\n\t2) To book the seats\
					\n\t3) To cancel the booking\
					\n\t4) To check the record of seat\
					\n\t5) Exit";
			cin>>i;
			switch(i)
			{
				case 1:
					s.display();
				break;
				case 2:
					s.book();
				break;
				case 3:
					s.cancel();
				break;
				case 4:
					s.verify();
				break;
				case 5:
					exit(0);
				break;
				default:
					cout<<"\n Invalid input";
			}
	}
	return 0;
}

