typedef struct node{
	int count;
	char data[81];
	char means[10][20];
	struct node *link;
};

struct node *ht[26];
void init_hashtable();
void display();
void addtomeanlist(char str[],int key,int cnt);
void search_hash_table(char key[]);
int getHashVal(char str[]);

void addtomeanlist(char str[],int key,int cnt)
{
		struct node *t;
		t=ht[key];
		while(t->link!=NULL)
				t=t->link;
		strcpy(t->means[cnt],str);
		t->count=cnt;
}

void search_hash_table(char key[])
{
		struct node *t;
		int val;
		int i;
		val=getHashVal(key);
		int found=0;
		int position=1;
		for(t=ht[val];t!=NULL;t=t->link)
		{
				if(strcmp(t->data,key)==0)
				{       
					 found=1;
						position++;
						break;
				}
		}
		
		if(!found)
				printf("Keyword not found in the hashtable \n");
		else
		{
				printf("Found in the hash location %d, at position %d",val,position);
				for(i=0;i<t->count;i++)
						printf("%s",t->means[i]);
		}
 }
 
 void init_hashtable()
 {
		int i;
		for(i=0;i<26;i++)
				 ht[i]=NULL;
 }
 
 int getHashVal(char str[])
 {
		char ch;
		int key;
		struct node *newN;
		ch=tolower(str[0]);
		key=ch-97;
		return key;
 }
 
 void insert_htable(char str[],int hval)
 {
		int key=hval;
		struct node *t;
		struct node *newN=(struct node *)malloc(sizeof (struct node));
		strcpy(newN->data,str);
		newN->link=NULL;
		if(ht[key]==NULL)
				ht[key]=newN;
		else
		{
				t=ht[key];
				while(t->link!=NULL)
						t=t->link;
				t->link=newN;
				t=newN;
		 }
 }
 
 void display()
 {
		struct node *temp;
		int i;
		for(i=0;i<26;i++)
				{
				printf("ht[%d]",i);
				for(temp=ht[i];temp!=NULL;temp=temp->link)
						printf("->%s",temp->data);
				printf("\n");
				}
 }
 
 void display_meanings_hashtable()
 {
		struct node *newN;
		int i,k;
		for(i=0;i<26;i++)
		{
				printf("ht[%d]",i);
				for(newN=ht[i];newN!=NULL;newN=newN->link)
						{
						printf("->%s",newN->data);
						for(k=0;k<newN->count;k++)
								printf("%s",newN->means[k]);
						}
				printf("\n");        
		 }
 }   