#include <stdio.h>


struct stu
{
	int id_no;
    int burst_time;
    int com_time ;
	int food_taken_time;

};


void TotalProcessTime(stu a[])
{
    for (int i=0;i<3;i++)
	{
            if(a[i].food_taken_time!=0)
            {
                a[i].com_time +=1;
            }
    }

}

bool remaining_time(stu a[])
{
    for (int i=0;i<3;i++)
	{
        if(a[i].food_taken_time!=0)
		{
            return true;
        }
    }
    return false;
}


void descending_sorting(stu a[])
{
    for(int i=1;i<3;i++)
	{
        for(int j=0;j<3-i;j++)
		{
            if(a[j].food_taken_time < a[j+1].food_taken_time)
			{
                stu temp = a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            else if(a[j].food_taken_time == a[j+1].food_taken_time)
			{
                if(a[j].id_no > a[j+1].id_no)
				{
                    stu temp = a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
    }

}



int main()
{
	stu a[3];

	
	for(int i=0;i<3;i++)
	{
        printf("Enter the id number of Student %d :",i+1);
        scanf("%d",&a[i].id_no);
        
        printf("Enter food taken Time by Student %d :",i+1);
        scanf("%d",&a[i].food_taken_time);
        
		a[i].burst_time = a[i].food_taken_time;

	}
	
	descending_sorting(a);

	/*
    printf("Students Entered Queue in following \n");
    while(remaining_time(a))
	{
        printf("%d \t ",a[0].id_no);
        TotalProcessTime(a);
        a[0].food_taken_time--;
        descending_sorting(a);
    }
    */
    
	int sum = 0;
    int sum1 = 0;
    printf("STUDENT ID | TURN AROUND TIME | WAITING TIME\n");
    
    for(int i=0;i<3;i++)
	{
        printf("%d :\t\t %d \t\t",a[i].id_no,a[i].com_time);
        printf("%d \n",a[i].com_time - a[i].burst_time);
        sum += a[i].com_time;
        sum1 += a[i].burst_time;
    }
    
	printf("\n THE FINAL AVERAGE TURN AROUND TIME IS : %d",sum/3);
    printf("\n THE FINAL AVERAGE WAITING TIME IS     : %d",sum1/3);

}

