#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;
class Polynode
{
	public:
		float coef;
		int exp;
		Polynode *next;
};
class poly_list:public Polynode
{
	Polynode *listptr,*temp;
	public:
		poly_list()
		{
			listptr=NULL;
			temp=NULL;
		}
		void create(float co, int exp1)
		{
			Polynode *newnode=new Polynode;	
			newnode->coef=co;
			newnode->exp=exp1;
			newnode->next=NULL;
			float c;
			int e;
		
			if(listptr==NULL)
			{
				listptr=temp=newnode;
			}
	

			if(exp1!=0)
			{
			
				temp->next=newnode;
				temp=temp->next;
				//cout<<temp->coef<<exp;

			}
			else if(exp1==0)
			{
				newnode->coef=co;
				newnode->exp=exp1;
				newnode->next=NULL;
				temp->next=newnode;
				temp=temp->next;
			}
		}
		void display()
		{
			Polynode *temp1;
			for(temp1=listptr;temp1!=NULL;temp1=temp1->next)
			{
				cout<<temp1->coef<<"x^"<<temp1->exp;
				if(temp1->next)
				cout<<"+";
			}
		}
		Polynode* get_node()
		{
			return listptr;
		}

		
		void add()
		{
				Polynode *newnode;
				int e;
				float c;
				poly_list p1,p2,p3;
		
				cout<<"\nEnter 1st polynomial:";
				do
				{
				cout<<"\nEnter coefficient and exponent resp:";
				cin>>c;
				cin>>e;
				p1.create(c,e);
				}while(getch() == 13);
				
				cout<<"\nEnter 2nd polynomial:";
				do
				{
				cout<<"\nEnter coefficient and exponent resp:";
				cin>>c;
				cin>>e;
				p2.create(c,e);
				}while(getch() == 13);
				
				Polynode *t1=p1.get_node();
				Polynode *t2=p2.get_node();
				Polynode *t3=p3.get_node();
				
				while(t1!=NULL && t2!=NULL)
				{
					if(t1->exp == t2->exp)
					{
						p3.create((t1->coef + t2->coef),t1->exp);
						t1=t1->next;
						t2=t2->next;
						
 					}
 					else if(t1->exp < t2->exp)
 					{
  						p3.create(t2->coef,t2->exp);
 						t2=t2->next;
 						
					 }
					 else
					 {
 						p3.create(t1->coef ,t1->exp);
 						t1=t1->next;
					 	
					 }
					 
					
				}
				while(t1!=NULL)
				{
					
 					p3.create(t1->coef,t1->exp);

 					t1=t1->next;
										 	
				}
				while(t2!=NULL)
				{
				
 					p3.create( t2->coef,t2->exp);

					t2=t2->next;
				}
				p3.display();
				
		}
		void eval(int x)
		{		
			double sum=0;
			Polynode *temp1;
			for(temp1=listptr;temp1;temp1=temp1->next)
			{	
				sum=sum+(temp1->coef)*pow(x,(temp1->exp));
			}
			cout<<"\nResult = "<<sum;
				
		}
		
		void removeDuplicates() 
		{ 
    		Polynode *ptr1, *ptr2, *dup; 
    		ptr1 = listptr; 
  
    /* Pick elements one by one */
    		while (ptr1 != NULL && ptr1->next != NULL)
			 { 
        		ptr2 = ptr1; 
  
        // Compare the picked element 
        // with rest of the elements 
	        	while (ptr2->next != NULL) 
				{ 
  
            // If powerer of two elements are same 
           			 if (ptr1->exp== ptr2->next->exp)
						 { 
  
                // Add their coefficients and put it in 1st element 
                			
                			dup = ptr2->next; 
                			ptr2->next = ptr2->next->next; 
  
                // remove the 2nd element 
                			delete (dup); 
            			} 
            		else
                	ptr2 = ptr2->next; 
        		} 
        		ptr1 = ptr1->next; 
    		} 	
} 
		void mul()
		{
			Polynode *newnode;
				int e;
				float c;
				poly_list p1,p2,p3,p4;
				
		
				cout<<"\nEnter 1st polynomial:";
				do
				{
				cout<<"\nEnter coefficient and exponent resp:";
				cin>>c;
				cin>>e;
				p1.create(c,e);
				}while(getch() == 13);
				
				cout<<"\nEnter 2nd polynomial:";
				do
				{
				cout<<"\nEnter coefficient and exponent resp:";
				cin>>c;
				cin>>e;
				p2.create(c,e);
				}while(getch() == 13);
				
				
				Polynode *t1=p1.get_node();
				Polynode *t2=p2.get_node();
				Polynode *t3=p3.get_node();
				Polynode *t4=p4.get_node();
				Polynode *t5=p3.get_node();
				
				while(t1)
				{
					t2=p2.listptr;
					//cout<<"\nLOOP1";
					while(t2)
					{	
						//cout<<"\nLOOP2";
						p3.create( (t1->coef)*(t2->coef), (t1->exp)+(t2->exp) );
						//cout<<"\nLOOP2.1";
						t2=t2->next;
					}
					t1=t1->next;
				}
			//	p3.display();
				
				int a,b=0;
				int check;
				t3=p3.listptr;
				
				while(t3)
				
				{
					
				//	cout<<"inloop1";
					t5=p3.listptr;
					a=t3->exp;
			
					while(t5 )
					{
					//	cout<<"inloop2";
						if(a == t5->exp)
						{
							//cout<<"inloop3";
							b=b+t5->coef;
						}
						
						t5=t5->next;							
					}
					
					p4.create(b,a);
					t3=t3->next;
					b=0;						
				}
				p4.removeDuplicates();
				p4.display();
			
		}
};
main()
{
	poly_list p;
	int i=1,c,exp1,x;
	float coef1;
	while(i==1)
	{
		cout<<"\n Press 1 for creating a list \n2 for Displaying \n3 for adding two polynomials \n4 for Evaluating \n5 for Multiplication ";
		cin>>c;
		switch(c)
		{
			case 1:
				
				do
				{
					cout<<"Enter coefficient and exponent resp:";
					cin>>coef1;
					cin>>exp1;
					p.create(coef1,exp1);
				}while(getch()==13);
			
				break;
			case 2:
				p.display();
				break;
			case 3:
				p.add();
				break;
			case 4:
				do
				{
					cout<<"Enter coefficient and exponent resp:";
					cin>>coef1;
					cin>>exp1;
					p.create(coef1,exp1);
					
				}while(getch()==13);
				cout<<"Enter the value of x";
				cin>>x;
				p.eval(x);
				break;	
			case 5:
			p.mul();
			break;	
			
					
		}
		cout<<"\n Press 1 to continue";
		cin>>i;
	}
}

