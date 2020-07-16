#include <stdio.h>
#include <stdlib.h>

struct  _retire_info{
  int months;
  double contribution;
  double rate_of_return;
};
typedef struct _retire_info retire_info;

double next_balance(double balance ,retire_info r)
{return balance + balance*r.rate_of_return + r.contribution ;
}
void year_month(int months,int *year,int *month)
{
  *year =months/12;
  *month=months%12;
}

void print_balance(int months,double balance){
  int age,month;

  year_month(months,&age,&month);
  printf("Age %3d month %2d you have $%.2f \n",age,month,balance );
}

void retirement(int startAge,double initial,retire_info working,retire_info retired)
{
 
  double balance=initial;
  int age_month = startAge;
  

  int m ;
  for (m=0;m<working.months;m++)
    {
      print_balance(age_month,balance);
     age_month++;
     balance=next_balance(balance,working);
    }
  
  for (m=0;m<retired.months;m++)
    {
      print_balance(age_month,balance);
     age_month++;
     balance=next_balance(balance,retired);
    }
}
   


  int main(void){
    retire_info working ={
      489 ,1000.0,0.045/12
    };
    retire_info retired ={
      384,-4000.0,0.01/12
    };

    int start_age=327;
    double saving = 21345.0;

    retirement(start_age,
	       saving,
	       working,
	       retired
	       );
    return EXIT_SUCCESS;
  }
  
