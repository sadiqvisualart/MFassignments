#include<stdio.h>
#include<math.h>
#include <stdlib.h>

float finalAns[45];
float finalAnsSort[45];
float xyz[25][3];
float xyzFPS[25][3];
float xyzRBS[25][3];
float xyzBTS[20][3];
float xyzC[20][3];
float xyz45[45][3];
float xyz45Sort[45][3];
float fps1[45];
float fps2[45];
float rbs1[45];
float rbs2[45];
float rbsSort[45];

void append()
{
	int i,j;
	
	for (i=0; i<25; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz45[i][j]=xyz[i][j];
		}
	}
	for (i=0; i<20; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz45[i+25][j]=xyzC[i][j];
		}
	}
	
	printf("\ntotal 45 values ready for equation\n");
	for(i=0; i<45; i++) {
		printf("%d.. ", i);
      for(j=0;j<3;j++) {
         printf("%f ", xyz45[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }
	
}

float float_rand( float min, float max )
{
    float scale = rand() / (float) RAND_MAX; 
    return min + scale * ( max - min );    
}

void solve(int count)
{
	int i;
	
	if (count==45)
	{
		for(i=0; i<count; i++)
	{
		float x=xyz45[i][0];
	//	printf("x=%f\n", x);
		float y=xyz45[i][1];
	//	printf("y=%f\n", y);
		float z=xyz45[i][2];
	//	printf("z=%f\n", z);
		finalAns[i] = pow(x,2) - 2*x*y*pow(z,2) + 2*pow(y,2)*z - 5.7*x*y*z + pow(z,2);
	}
	}
	
	else
	{
		for(i=0; i<count; i++)
	{
		float x=xyz[i][0];
	//	printf("x=%f\n", x);
		float y=xyz[i][1];
	//	printf("y=%f\n", y);
		float z=xyz[i][2];
	//	printf("z=%f\n", z);
		finalAns[i] = pow(x,2) - 2*x*y*pow(z,2) + 2*pow(y,2)*z - 5.7*x*y*z + pow(z,2);
	}	
	}
	
	for(i=0; i<45; i++)
	{
		finalAnsSort[i]=finalAns[i];
	}
	
	int c,d;
	float t;
for (c = 0 ; c < 45 - 1; c++)
  {
    for (d = 0 ; d < 45 - c - 1; d++)
    {
      if (finalAnsSort[d] < finalAnsSort[d+1])
      {
        /* Swapping */
 
        t         = finalAnsSort[d];
        finalAnsSort[d]   = finalAnsSort[d+1];
        finalAnsSort[d+1] = t;
      }
    }
  }
  printf("final ans\n");
	for(i = 0; i < 45; i++)
      printf("%d.. %f,\n ",i, finalAns[i]);
      int j;
	
	printf("final ans sort\n");
	for(i = 0; i < 45; i++)
      printf("%f\n", finalAnsSort[i]);
      
      printf("before\n");
      
      for(i=0; i<45; i++) {
      for(j=0;j<3;j++) {
      	printf("%d.. ", i);
         printf("%f ", xyz45[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }
      printf("\nafter===============================================================================\n");
      float temp;
    for(i = 0; i < 45; i++)
    {//	printf("\ni%d\n", i);
    	for(j = 0; j < 45; j++)
    	{//	printf("\nj%d\n", j);
    		if(finalAnsSort[i]==finalAns[j])
    		{
    			//printf("\na%d, b%d\n", i,j);
    			xyz45Sort[i][0]=xyz45[j][0];
    			xyz45Sort[i][1]=xyz45[j][1];
    			xyz45Sort[i][2]=xyz45[j][2];

        

			}
			else
			{
				int s;	
			}
			
		}
	}
	
//	for(i=0; i<45; i++) {
//      for(j=0;j<3;j++) {
//      	printf("%d.. ", i);
//         printf("%f ", xyz45Sort[i][j]);
//         if(j==2){
//            printf("\n");
//         }
//      }
//   }
   
   for (i=0; i<45; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz45[i][j]=xyz45Sort[i][j];
		}
	}
	
	for(i=0; i<45; i++) {
      for(j=0;j<3;j++) {
      	printf("%d.. ", i);
         printf("%f ", xyz45[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }
}

void initPop()
{
	int count = 25; 
	int i; 
	float num;
	for (i = 0; i < count; i++) { 
		num = float_rand(-2,2);
		xyz[i][0]=num;
	} 
	
	for (i = 0; i < count; i++) { 
		num = float_rand(-1,3);
		xyz[i][1]=num;
	} 
	
	for (i = 0; i < count; i++) { 
		num = float_rand(0,3);
		xyz[i][2]=num;
	} 
	
	int j;
	
	printf("\nInitial Population:\n");
	for(i=0; i<25; i++) {
		printf("%d.. ", i);
      for(j=0;j<3;j++) {
         printf("%f ", xyz[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }
}

void crossOver(){
		//	rand() % (max_number + 1 - minimum_number) + minimum_number
	int history1[10]={0,0,0,0,0,0,0,0,0,0};
	int history2[10]={0,0,0,0,0,0,0,0,0,0};
	int i;
	int j;
	int chk=0;
		srand(time(0));
	for(i=0; i<10; i++)
	{	
	int p1 = rand() % (24 + 1 - 0) + 0;
	printf("\np1-%d ", p1);
	int p2 = rand() % (24 + 1 - 0) + 0;
	printf("p2-%d\n", p2);
	if(p1==p2)
	{
		i--;
		continue;
	}
	for(j=0; j<10; j++)
	{
		if(history1[j]==p1 && history2[j]==p2 || history1[j]==p2 && history2[j]==p1)
		{

			chk =1;
			break;
		}
	
	}
	if(chk ==1)
	{
		i--;
		continue;
	}
	else
	{
		chk=0;
		history1[i]=p1;
		history2[i]=p2;
		xyzC[i][0]=xyz[p1][0];
		xyzC[i][1]=xyz[p2][1];
		xyzC[i][2]=xyz[p1][2];
		
		xyzC[i+10][0]=xyz[p2][0];
		xyzC[i+10][1]=xyz[p1][1];
		xyzC[i+10][2]=xyz[p2][2];	
	}
	
	
	}
	
	printf("\n\n");
	
	printf("\nCrossover\n");
	for(i=0; i<20; i++) {
		printf("%d.. ", i);
      for(j=0;j<3;j++) {
         printf("%f ", xyzC[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }
	
	
}

void mutation(){
	
	int ms;
	int q;
	for(q=0; q<20; q++)
	{
		ms=rand() % (2 + 1 - 0) + 0;
	if (ms==0)
	{
		xyzC[q][0] = float_rand(-2,2);
	}
	
	else if (ms==1)
	{
		xyzC[q][1] = float_rand(-1,3);
	}
	else
	{
		xyzC[q][2] = float_rand(0,3);
	}	
	}
	
		printf("\nMutation\n");
		int i,j;
	for(i=0; i<20; i++) {
		printf("%d.. ", i);
      for(j=0;j<3;j++) {
         printf("%f ", xyzC[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }
	
	append();
	
}

void fps()
{
	float popSum=0;
	int i,j;
	//solve(25);
	for(i=0; i<25; i++)
	{
		popSum=popSum+finalAns[i];	
	}
	for(i=0; i<25; i++)
	{
		fps1[i]=(float)finalAns[i]/(float)popSum;	
	}
	fps2[0]=fps1[0];
	for(i=1; i<25; i++)
	{
		fps2[i]=fps2[i-1]+fps1[i];	
	}
	float p;
	for(i=0; i<25; i++)
	{
		p=float_rand(0,1);
		for(j=0; j<25; j++)
	{
		if(fps2[j]>p)
		{
				xyzFPS[i][0]=xyz[j][0];
    			xyzFPS[i][1]=xyz[j][1];
    			xyzFPS[i][2]=xyz[j][2];
    			break;
		}
	}	
	}
	
	for (i=0; i<25; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz[i][j]=xyzFPS[i][j];
		}
	}
	
	
	
	for(i=0; i<25; i++) {
		printf("%d.. ", i);
      for(j=0;j<3;j++) {
         printf("%f ", xyz[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }
}

void rbs()
{
	int i,j, rt,c,d;
	float t;
	solve(25);
    rt=0;
 for(i=0; i<25; i++)
	{
		rt=rt+(i+1);
	}

//	for (c = 25 - 1, d = 0; c >= 0; c--, d++)
//      rbsSort[d] = finalAnsSort[c];
 	for(i=0; i<25; i++)
	{
		rbsSort[i]=finalAnsSort[24-i];
	}     

	for(i=0; i<25; i++)
	{
		rbs1[i]=(float)rbsSort[i]/(float)rt;	
	}
	fps2[0]=fps1[0];
	for(i=1; i<25; i++)
	{
		rbs2[i]=rbs2[i-1]+rbs1[i];	
	}
	printf("\nrbs\n");
	float p;
	
	for(i=0; i<25; i++)
	{printf("\nrbsi\n");
		p=float_rand(0,1);
		for(j=0; j<25; j++)
	{printf("\nrbsj\n");
		if(rbs2[j]>p)
		{
				for(c=0; c<25; c++)
				{printf("\nrbsc\n");
					printf("%f\n", finalAns[c]);
					printf("%f\n", rbsSort[j]);
					if(finalAns[j]==rbsSort[c])
    				{printf("in if\n");
	    			xyzFPS[i][0]=xyz[j][0];
	    			xyzFPS[i][1]=xyz[j][1];
	    			xyzFPS[i][2]=xyz[j][2];

					}
					printf("out if\n");
				}
				break;

    			
		}
		//break;
	}	
	}
	
	for (i=0; i<25; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz[i][j]=xyzFPS[i][j];
		}
	}
	
	for(i=0; i<25; i++) {
		printf("%d.. ", i);
      for(j=0;j<3;j++) {
         printf("%f ", xyz[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }

}

void bts()
{
	int i, history[25];
	for(i=0; i<25; i++)
	{
		int p1 = rand() % (24 + 1 - 0) + 0;
	printf("\np1-%d ", p1);
	int p2 = rand() % (24 + 1 - 0) + 0;
	printf("p2-%d\n", p2);
	if (finalAns[p1]>finalAns[p2])
	{
		printf("\n%d..p1-%d ",i, p1);
		history[i]=p1;
	}
	else
	{
		printf("%d..p2-%d\n",i, p2);
		history[i]=p2;
	}
	}
	printf("hhhhhh\n");
	for(i=0; i<25; i++)
	{
		
		printf("%d..%d, ",i, history[i]);
	}
	printf("\n");
	int j;
	for(i=0; i<25; i++)
	{
		j=history[i];
		xyz[i][0]=xyz[j][0];
    	xyz[i][1]=xyz[j][1];
    	xyz[i][2]=xyz[j][2];
	}
	
	printf("btssssssssssssssssbtssssssss");
	
	for(i=0; i<25; i++) {
		printf("%d.. ", i);
      for(j=0;j<3;j++) {
         printf("%f ", xyz[i][j]);
         if(j==2){
            printf("\n");
         }
      }
   }

	
}

 
int main()
{
	
	initPop();
	solve(25);
	fps();
	crossOver();
	mutation();
	solve(45);
	
	
	initPop();
	solve(25);
	rbs();
	crossOver();
	mutation();
	solve(45);
	
	
	initPop();
	solve(25);
	bts();
	crossOver();
	mutation();
	solve(45);
 
}




 
