#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct keys
{
	char keys[20];
};


int validate()
{
	//validates integer input
	int conv; //convert
	char num; 
	printf("\nHow many number of keywords to scan?\n");
	do{
		fflush(stdin);
		printf("Please enter INTEGERS only: ");
		num=getchar();
		conv=atoi(&num);
	}while(conv==0);

return conv;
}

int validate_op(char *op)
{
	//validates the options
	while(*op!='1'&& *op!='2')
	{
		fflush(stdin);
		printf("\nPlease enter INTEGERS 1 or 2 only: ");
		scanf("%c", op);
	}
	return 0;
}

void initial(int *argc, char *argv[])
{
	//this function handles test cases when command line arguments are passed
	if(*argc==1) 
	{
		printf("Insufficient arguments passed. Please try again.\n");
		exit(0);
	}
	for(int check=1; check<*argc; check++)
	{
		//checks arguments for correct file name or file existence
		if(strstr(argv[check],".txt")==NULL)
		{
			printf("\nThe argument(s) passed have missing '.txt' extension. Please enter with .txt extensions only.\n");
			exit(0);
		}
		if(fopen(argv[check],"r")==NULL)
		{
			printf("\nFile '%s' could not be opened.",argv[check]);
			printf("\nPlease enter files that exist in this directory or check whether file can be opened in read mode.\n");
			exit(0);
			
		}
	}

	if(*argc>1)
	{
		//program is allowed to continue since arguments are appropriately passed
		printf("\t\t\t RESUME SCANNING SOFTWARE"
				"\nThis program will shortlist the files that contain the keywords given according to the conditions\n\n\n");
		printf("Please select the type of scanning.\n1. Single keyword- all files will be searched for one keyword only.\n"
			    "2. Multiple keywords- will further ask to choose and/or conditions on keywords. \n"); 
			
	}
}

struct keys * allocate (int n)
{
	//for storing multiple keywords
	struct keys *k= (struct keys *)malloc(sizeof(struct keys)*n);
	return k;
}

void read_keys(struct keys *k, int n)
{
	printf("\nStart entering keywords one by one\n");
	for(int read=0; read<n; read++)
	{
		fflush(stdin);
		scanf("%[^\n]",(k+read)->keys);
	}
}

void lower_case(char *array) 
{
	//this function removed case sensitivity while scanning since it converts the string that is applied to lower case
	int size;
	size= strlen(array);
	for(int ch=0;ch<size;ch++)
	{
		if(array[ch]>=65 && array[ch]<=90)
		{
			array[ch]+= 32;
		}
		
	}
}

int scan(char* strp, char *key_w)
{
	//function opens the file passed using string pointer *strp, 
	//uses strstr() function to check for keyword in each line and returns 1 if found.
	FILE *fp;

	char content[200];//for storing contents of each line
	fp= fopen(strp,"r");
	int indicator=0;
	while(fgets(content,200,fp)!=NULL)
	{
		lower_case(content);
		lower_case(key_w);

		if(strstr(content,key_w)!=NULL)//indicates found
		{
			indicator+=1;
			break; //break because just the first occurence is sufficient 
		}
	}
	return indicator;

}

int scan1_loop(int *argc, char *argv[], char *key_w, int *file_count)
{
	//scan1_loop is a function for the single-keyword type pf scanning.
	//this function takes argv[] array and applies scan function on each file for the keyword entered. loops for argc number of times.
	// *file_count variable is returned that helps to check if the keyword is not found for ANY of the files.
	int res_1; //result
	for(int check=1; check<*argc; ++check) //check starts with 1 since first argument in command line is ./scan
		{
			res_1= scan(argv[check], key_w); //calling scan function that returns the indicator (int) to check if the file passed by argv[i] has the keyword
			if(res_1==1)
				{
					file_count++;
					printf("\t %s \n",argv[check]);
				}
		}
	return *file_count;
}

int multi_scan(char *strp, struct keys *k, int num, char *op)
{
	//this function takes in each file name passed and iterates through the struct key 
	//to search for all keywords entered by calling scan function in loop
	 
	int ind_count=0; //indicator count
	int log_ind; //logical indicator 
	if(*op=='1')
	{
		//AND
		for(int check=0; check<num; check++)
		{
			log_ind=scan(strp, (k+check)->keys);
			ind_count+= log_ind;
		}
	}
	else 
	{
		//OR
		printf("\n\n %s: \n",strp);
		for(int check=0; check<num; check++)
		{
			log_ind=scan(strp, (k+check)->keys);
			if(log_ind)
			{
				ind_count+= log_ind;
				printf("\t found '%s' \n", (k+check)->keys); //prints the keyword found for OR condition 
											//since one or more keywords found also makes the file applicable to be included in the output
			}			
		}
	}
	return ind_count;
}