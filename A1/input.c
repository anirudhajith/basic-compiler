
int *var=6;
struct mystruct *ms=&var;
int auto, static, inline;
int a,b;
extern void *k;
int p;
int p;
int p;
int *hh(char *p);

int main(int b)
{
	int auto=2,b=3,c;
	c=auto+b;
	printf("%d",c);
	
	struct player
	{
	int a;
	double c;
	};
	int *jj=&auto;
	system.out.print("java here");
	char echo[3]="bash here";
	myprintf("CS3300 here");
	printf(echo);
	/*
	mixing things here a bit
	*/
	if(a==9)
	{
	//NO-OP
	}
	if(a==1)
	hh(++jj);
	else if(a==2)
	hh(jj++);
	else if(a==3)
	hh(*jj++);
	else
	{
	//NO-OP
	}
	struct player *p;
	p=(struct player *)malloc(sizeof(struct player));
	p->a=1;
	p->b=2.4;
	//#pragma omp parallel for
for(a=1;a<=5;a++) static(a);
int *p;
float *j;
p=&auto;
j=0x1234;
printf("*j=%p",(char *)j);
void *static=&c;
int a=5,b=8,c;
c=a<=>b;
hh(p);
return(0);
}

int *hh(char *p)
{
int n=7;
scanf("%d",&n);
if(n==0)
printf("%d\n",n+1);
else if(n==1)
printf("%d\n",n+2);
return(NULL);
}

int main(){
switch(grade) {
      case 'A' :
         printf("Excellent!\n" );
         break;
      case 'B' :
      case 'C' :
         printf("Well done\n" );
         break;
      case 'D' :
         printf("You passed\n" );
         break;
      case 'F' :
         printf("Better try again\n" );
         break;
      default :
         printf("Invalid grade\n" );
   }
   
   printf("Your grade is  %c\n", grade );

	struct Books {
   		char  title[50];
   		char  author[50];
   		char  ****subject[100];
   		struct Books{
	   		int a;
			int b;
   		}booog[0];
   	int   book_id;
	}book[234234];
 	
	struct Books Book1;        /* Declare Book1 of type Book */
   	struct Books Book2;        /* Declare Book2 of type Book */
 
   /* book 1 specification */
   Book1.book_id = (6495407);

   /* book 2 specification */
   strcpy(Book2.title);
   strcpy( Book2.author.name->abfha, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 0x6495700;
   
   a++++;
   --b++++;
   v(--a.b->h++++, a);
   
   a.b;
   a.b->c->d;
   for (a.b; g<3; --b++--);
   for(;;) {print("hi");}
   ;
   
   
   struct book ***ptr = &sfhb;
   struct book **ptr;

   	**ptr = ((5));
	*(ptr) = 5;
	a.b++;
	int a = -5 * &(6&7) * *p;
	char* hello = "hello" "5 6";
	//int a = 5 6;

	{
		int thisis = "a new scope";
		{
			int thisis = "an even" "smaller score";
		}
	}

}

int main()
{
	/*----valid-----*/

	6=8++;
	6=h++;
	d()++=6;
	*((10+1)*u)=(3+7);
	2=2;
	++2=2--;
	(a+a)=2*a; //notice the paranthesis, without which this is invalid (see below)
	-a=7;
	--a=7;
	-fun((10+1)=x); //notice the paranthesis, without which this is invalid (see below)
	-8=7;
	y(x)=f(x)+g(x);
	func((y(x)+c)=f(x)+g(x)); //notice the paranthesis, without which this is invalid (see below)
	
	//a+a=2*a; (this is invalid for this assignment)
	//fun(a+a=2*a); (this is invalid for this assignment)
	//fun(10+1=x); (this is invalid for this assignment)
	//func(y(x)+c=f(x)+g(x)); (this is invalid for this assignment)

}

/*

***parsing successful***
#global_declarations = 1
#function_definitions = 1
#integer_constants = 19
#pointers_declarations = 0
#ifs_without_else = 0
if-else max-depth = 0

*/

struct Vertex {
   char label;
   int visited;
};

//stack variables

int stack[MAX]; 
int top = -1; 

//graph variables

//array of vertices
struct Vertex* lstVertices[MAX];

//adjacency matrix
int a[MAX][MAX];

//vertex count
int vertexCount = 0;

//stack functions

void push(int item) { 
   stack[++top] = item; 
} 

int pop() { 
   return stack[top--]; 
} 

int peek() {
   return stack[top];
}
int isStackEmpty() {
   return top == -1;
}

//graph functions

//add vertex to the vertex list
void addVertex(char label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->label = label;  
   vertex->visited = false;     
   lstVertices[vertexCount++] = vertex;
}

//add edge to edge arraydewdwedewdewd
void addEdge(int start,int end) {
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}

//display the vertex
void displayVertex(int vertexIndex) {
   printf("%c ",lstVertices[vertexIndex]->label);
}       

//get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
   int i;

   for(i = 0; i < vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
         return i;
      }
   }

   return -1;
}

void depthFirstSearch() {
   int i;

   //mark first node as visited
   lstVertices[0]->visited = true;

   //display the vertex
   displayVertex(0);   

   //push vertex index in stack
   push(0);

   while(!isStackEmpty()) {
      //get the unvisited vertex of vertex which is at top of the stack
      int unvisitedVertex = getAdjUnvisitedVertex(peek());

      //no adjacent vertex found
      if(unvisitedVertex == -1) {
         pop();
      } else {
         lstVertices[unvisitedVertex]->visited = true;
         displayVertex(unvisitedVertex);
         push(unvisitedVertex);
      }
   }

   //stack is empty, search is complete, reset the visited flag        
   for(i = 0;i < vertexCount;i++) {
      lstVertices[i]->visited = false;
   }        
}

int main() {
   int i, j;

   for(i = 0; i < MAX; i++)    // set adjacency
 {
      for(j = 0; j < MAX; j++) // matrix to 0
         adjMatrix[i][j] = 0;
   }
   addVertex('S');   // 0
   addVertex('A');   // 1
   addVertex('B');   // 2
   addVertex('C');   // 3
   addVertex('D');   // 4

   addEdge(0, 1);    // S - A
   addEdge(0, 2);    // S - B
   addEdge(0, 3);    // S - C
   addEdge(1, 4);    // A - D
   addEdge(2, 4);    // B - D
   addEdge(3, 4);    // C - D

   printf("Depth First Search: ");
   depthFirstSearch(); 

   return 0;   
}
