#include<stdio.h>
#include<math.h>
#include <stdlib.h>

float finalAns[45];
float finalAnsSort[45];
float xyz[25][3];
float xyzC[20][3];
float xyz45[45][3];
float xyz45Sort[45][3];

void append()
{
	printf("append\n");
	int i,j;
	for (i=0; i<25; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz45[i][j]=xyz[i][j];
		}
	}
	for (i=25; i<45; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz45[i][j]=xyzC[i][j];
		}
	}
	
//	for(i=0; i<45; i++) {
//      for(j=0;j<3;j++) {
//         printf("%f ", xyz45[i][j]);
//         if(j==2){
//            printf("\n");
//         }
//      }
//   }
	
}

float float_rand( float min, float max )
{
    float scale = rand() / (float) RAND_MAX; 
    return min + scale * ( max - min );    
}

void solve()
{
	int i;
	for(i=0; i<45; i++)
	{
		float x=xyz45[i][0];
	//	printf("x=%f\n", x);
		float y=xyz45[i][1];
	//	printf("y=%f\n", y);
		float z=xyz45[i][2];
	//	printf("z=%f\n", z);
		finalAns[i] = pow(x,2) - 2*x*y*pow(z,2) + 2*pow(y,2)*z - 5.7*x*y*z + pow(z,2);
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
      printf("%d.. %f, \n",i, finalAnsSort[i]);
      
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
    			printf("\na%d, b%d\n", i,j);
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
	printf("int pop\n");
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
	
//	for(i=0; i<25; i++) {
//      for(j=0;j<3;j++) {
//         printf("%f ", xyz[i][j]);
//         if(j==2){
//            printf("\n");
//         }
//      }
//   }
}

void crossOver(){
	printf("cross\n");
		//	rand() % (max_number + 1 - minimum_number) + minimum_number
	int history1[10]={0,0,0,0,0,0,0,0,0,0};
	int history2[10]={0,0,0,0,0,0,0,0,0,0};
	int i;
	int j;
	int chk=0;
		srand(time(0));
	for(i=0; i<10; i++)
	{
		printf("%d\n", i);
	
	int p1 = rand() % (24 + 1 - 0) + 0;
//	printf("p1 %d\n", p1);
	int p2 = rand() % (24 + 1 - 0) + 0;
//	printf("p2 %d\n", p2);
	if(p1==p2)
	{
		i--;
		continue;
	}
	for(j=0; j<10; j++)
	{
		if(history1[j]==p1 && history2[j]==p2 || history1[j]==p2 && history2[j]==p1)
		{
			printf("in if(history1[j]==p1 && history2[j]==p2 || history1[j]==p2 && history2[j]==p1)\n");
			
			chk =1;
			break;
		}
	
	}
	if(chk ==1)
	{
		printf("in if(chk ==1)\n");
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
//	for(i=0; i<20; i++) {
//      for(j=0;j<3;j++) {
//         printf("%f ", xyzC[i][j]);
//         if(j==2){
//            printf("\n");
//         }
//      }
//   }
	
	
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
	
	append();
	
}


 
int main()
{
	
	initPop();
	int i;
	for(i=0; i<25; i++)
	{
		crossOver();
	mutation();
	solve();	
	}
 
}




 
