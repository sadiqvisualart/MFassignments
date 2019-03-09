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
float xyzCSort[20][3];
float xyz45[45][3];
float xyz45Sort[45][3];
float fps1[45];
float fps2[45];
float rbs1[45];
float rbs2[45];
float rbsSort[45];

void append(int count)
{
	int i,j;
	
	if (count==45)
	{
		for (i=0; i<count-20; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz45[i][j]=xyz[i][j];
		}
	}
	for (i=0; i<count-25; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz45[i+25][j]=xyzC[i][j];
		}
	}
	}
	
	else if (count==20)
	{
		for (i=0; i<count-10; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz45[i][j]=xyz[i][j];
		}
	}
	for (i=0; i<count-10; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz45[i+10][j]=xyzC[i][j];
		}
	}
	}
	
	else if (count==35)
	{
		for (i=0; i<count-10; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz45[i][j]=xyz[i][j];
		}
	}
	for (i=0; i<count-25; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz45[i+10][j]=xyzC[i][j];
		}
	}
	}
	
	else
	{
		for (i=0; i<count-20; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz45[i][j]=xyz[i][j];
		}
	}
	for (i=0; i<count-10; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz45[i+20][j]=xyzC[i][j];
		}
	}
	}
	
	
	

	
}

float float_rand( float min, float max )
{
    float scale = rand() / (float) RAND_MAX; 
    return min + scale * ( max - min );    
}

void solveC(int count)
{
	int i,j;

		for(i=0; i<count; i++)
	{
		float x=xyzC[i][0];
		float y=xyzC[i][1];
		float z=xyzC[i][2];
		finalAns[i] = pow(x,2) - 2*x*y*pow(z,2) + 2*pow(y,2)*z - 5.7*x*y*z + pow(z,2);
	}	
	
	
	for(i=0; i<count; i++)
	{
		finalAnsSort[i]=finalAns[i];
	}
	
	int c,d;
	float t;
for (c = 0 ; c < count - 1; c++)
  {
    for (d = 0 ; d < count - c - 1; d++)
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

      float temp;
    for(i = 0; i < count; i++)
    {
    	for(j = 0; j < count; j++)
    	{
    		if(finalAnsSort[i]==finalAns[j])
    		{
    			xyzCSort[i][0]=xyzC[j][0];
    			xyzCSort[i][1]=xyzC[j][1];
    			xyzCSort[i][2]=xyzC[j][2];

        

			}
			else
			{
				int s;	
			}
			
		}
	}

   
   for (i=0; i<count; i++)
	{
		for(j=0; j<3; j++)
		{
			xyzC[i][j]=xyzCSort[i][j];
		}
	}
	

}

void solve(int count)
{
	int i;

		for(i=0; i<count; i++)
	{
		float x=xyz45[i][0];
		float y=xyz45[i][1];
		float z=xyz45[i][2];
		finalAns[i] = pow(x,2) - 2*x*y*pow(z,2) + 2*pow(y,2)*z - 5.7*x*y*z + pow(z,2);
	}

	if (count==25)
	{
		for(i=0; i<count; i++)
	{
		float x=xyz[i][0];
		float y=xyz[i][1];
		float z=xyz[i][2];
		finalAns[i] = pow(x,2) - 2*x*y*pow(z,2) + 2*pow(y,2)*z - 5.7*x*y*z + pow(z,2);
	}	
	}
	
	for(i=0; i<count; i++)
	{
		finalAnsSort[i]=finalAns[i];
	}
	
	int c,d;
	float t;
for (c = 0 ; c < count - 1; c++)
  {
    for (d = 0 ; d < count - c - 1; d++)
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

	
	printf("final ans sort\n");
	for(i = 0; i < count; i++)
      printf("%f\n", finalAnsSort[i]);
      


      float temp;
      int j;
    for(i = 0; i < 45; i++)
    {
    	for(j = 0; j < 45; j++)
    	{
    		if(finalAnsSort[i]==finalAns[j])
    		{

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
	

   
   for (i=0; i<45; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz45[i][j]=xyz45Sort[i][j];
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

	int p2 = rand() % (24 + 1 - 0) + 0;

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
	

	

	
}

void fps(int count)
{
	float popSum=0;
	int i,j;
	for(i=0; i<count; i++)
	{
		popSum=popSum+finalAns[i];	
	}
	for(i=0; i<count; i++)
	{
		fps1[i]=(float)finalAns[i]/(float)popSum;	
	}
	fps2[0]=fps1[0];
	for(i=1; i<count; i++)
	{
		fps2[i]=fps2[i-1]+fps1[i];	
	}
	float p;
	for(i=0; i<count; i++)
	{
		p=float_rand(0,1);
		for(j=0; j<count; j++)
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
	
	for (i=0; i<count; i++)
	{
		for(j=0; j<3; j++)
		{
			xyz[i][j]=xyzFPS[i][j];
		}
	}
	
	

}

void fpsC(int count)
{
	float popSum=0;
	int i,j;
	for(i=0; i<count; i++)
	{
		popSum=popSum+finalAns[i];	
	}
	for(i=0; i<count; i++)
	{
		fps1[i]=(float)finalAns[i]/(float)popSum;	
	}
	fps2[0]=fps1[0];
	for(i=1; i<count; i++)
	{
		fps2[i]=fps2[i-1]+fps1[i];	
	}
	float p;
	for(i=0; i<count; i++)
	{
		p=float_rand(0,1);
		for(j=0; j<count; j++)
	{
		if(fps2[j]>p)
		{
				xyzFPS[i][0]=xyzC[j][0];
    			xyzFPS[i][1]=xyzC[j][1];
    			xyzFPS[i][2]=xyzC[j][2];
    			break;
		}
	}	
	}
	
	for (i=0; i<count; i++)
	{
		for(j=0; j<3; j++)
		{
			xyzC[i][j]=xyzFPS[i][j];
		}
	}
	

}

void rbs()
{
	int i,j, rt,c,d;
	float t;
    rt=0;
 for(i=0; i<25; i++)
	{
		rt=rt+(i+1);
	}

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

	float p;
	
	for(i=0; i<25; i++)
	{
		p=float_rand(0,1);
		for(j=0; j<25; j++)
	{
		if(rbs2[j]>p)
		{
				for(c=0; c<25; c++)
				{

					if(finalAns[j]==rbsSort[c])
    				{
	    			xyzFPS[i][0]=xyz[j][0];
	    			xyzFPS[i][1]=xyz[j][1];
	    			xyzFPS[i][2]=xyz[j][2];

					}

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
	


}

void rbsC()
{
	int i,j, rt,c,d;
	float t;
    rt=0;
 for(i=0; i<20; i++)
	{
		rt=rt+(i+1);
	}

 	for(i=0; i<20; i++)
	{
		rbsSort[i]=finalAnsSort[19-i];
	}     

	for(i=0; i<20; i++)
	{
		rbs1[i]=(float)rbsSort[i]/(float)rt;	
	}
	fps2[0]=fps1[0];
	for(i=1; i<20; i++)
	{
		rbs2[i]=rbs2[i-1]+rbs1[i];	
	}

	float p;
	
	for(i=0; i<20; i++)
	{
		p=float_rand(0,1);
		for(j=0; j<20; j++)
	{
		if(rbs2[j]>p)
		{
				for(c=0; c<20; c++)
				{

					if(finalAns[j]==rbsSort[c])
    				{
	    			xyzFPS[i][0]=xyzC[j][0];
	    			xyzFPS[i][1]=xyzC[j][1];
	    			xyzFPS[i][2]=xyzC[j][2];

					}

				}
				break;

    			
		}
		//break;
	}	
	}
	
	for (i=0; i<20; i++)
	{
		for(j=0; j<3; j++)
		{
			xyzC[i][j]=xyzFPS[i][j];
		}
	}
	


}

void bts()
{

	int i,j,chk=0, history[10];
	for(i=0; i<10; i++)
	{
		int p1 = rand() % (24 + 1 - 0) + 0;
		
	int p2 = rand() % (24 + 1 - 0) + 0;
	
		
		for(j=0; j<10; j++)
		{
			if (p1==history[j])
			{
			
				chk=1;
				i--;
				break;
			}
			else if(p2==history[j])
			{
			
				i--;
				chk=1;
				break;	
			}
		}
		
		if(chk==1)
		{
			chk=0;
			continue;
		}

	if (finalAns[p1]>finalAns[p2])
	{
		
				history[i]=p1;
			

	}
	else
	{
			
				history[i]=p2;
			

	}
	}


	for(i=0; i<10; i++)
	{
		j=history[i];
		xyz[i][0]=xyz[j][0];
    	xyz[i][1]=xyz[j][1];
    	xyz[i][2]=xyz[j][2];
	}
	
}

void btsC()
{

	int i,j,chk=0, history[10];
	for(i=0; i<10; i++)
	{
		int p1 = rand() % (24 + 1 - 0) + 0;
		
	int p2 = rand() % (24 + 1 - 0) + 0;
	
		
		for(j=0; j<10; j++)
		{
			if (p1==history[j])
			{
			
				chk=1;
				i--;
				break;
			}
			else if(p2==history[j])
			{
			
				i--;
				chk=1;
				break;	
			}
		}
		
		if(chk==1)
		{
			chk=0;
			continue;
		}

	if (finalAns[p1]>finalAns[p2])
	{
		
				history[i]=p1;
			

	}
	else
	{
			
				history[i]=p2;
			

	}
	}


	for(i=0; i<10; i++)
	{
		j=history[i];
		xyzC[i][0]=xyzC[j][0];
    	xyzC[i][1]=xyzC[j][1];
    	xyzC[i][2]=xyzC[j][2];
	}
	
}

 
int main()
{
	int i;
	
//	initPop();
//	solve(25);
//	fps(25);
//	crossOver();
//	solveC(20);
//	fpsC(20);
//	mutation();
//	append(45);
//	solve(45);

//	initPop();
//	solve(25);
//	fps(25);
//	crossOver();
//	solveC(20);
//	rbsC(20);
//	mutation();
//	append(45);
//	solve(45);

//	initPop();
//	solve(25);
//	fps(25);
//	crossOver();
//	solveC(20);
//	btsC(20);
//	mutation();
//	append(35);
//	solve(35);



	
//	initPop();
//	solve(25);
//	rbs();
//	crossOver();
//	solveC(20);
//	rbsC(20);
//	mutation();
//	append(45);
//	solve(45);

//	initPop();
//	solve(25);
//	rbs();
//	crossOver();
//	solveC(20);
//	fpsC(20);
//	mutation();
//	append(45);
//	solve(45);

//	initPop();
//	solve(25);
//	rbs();
//	crossOver();
//	solveC(20);
//	btsC(20);
//	mutation();
//	append(35);
//	solve(35);
	
	
//	initPop();
//	solve(25);
//	bts();
//	crossOver();
//	solveC(20);
//	btsC();
//	mutation();
//	append(20);
//	solve(20);

	
//	initPop();
//	solve(25);
//	bts();
//	crossOver();
//	solveC(20);
//	fpsC(20);
//	mutation();
//	append(30);
//	solve(30);
	
	
//	initPop();
//	solve(25);
//	bts();
//	crossOver();
//	solveC(20);
//	rbsC(20);
//	mutation();
//	append(30);
//	solve(30);
// 
}




 
