#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"server.h"

int main(int argc, char* argv[])
{
	
	    initial(&argc,argv); //function validates the command line arguments. 
							//only then the program is allowed to continue, else the program ends because of exit() function
		char key[30]; //keyword
		char key_op; //for the type of scanning option
		char log_op; //for the logical operator option
		int num_key; //number of keywords in multiple-scanning option
		int res; //result 
		int filec=0; //filecount to track whether none of the files have the entered keyword

		printf("\nEnter: "); 
		scanf("%c",&key_op);
		validate_op(&key_op); //validating option

		switch(key_op)
		{
			case '1':
				printf("\nEnter keyword (Note that any keyword entered will be taken singularly): \n");
				fflush(stdin);
				scanf("%[^\n]", key);
				printf("\n===========RESULT=========== \n");

				filec= scan1_loop(&argc, argv, key, &filec);
				if(filec==0) //here is the relevance of filec variable if none of the files have the given keyword(s)
					{
						printf("\nNone of the files contain given keyword\n");
					}
				break;

			case '2':
				num_key=validate(); //this function takes the input for number of keywords and validates then and there
									//since it's an integer type for allocating memory for structure
						   		   //this was important because if char is entered an error would appear saying "malloc: can't allocate region".
				struct keys *k= allocate(num_key);
				read_keys(k, num_key); //this function stores the keywords entered into the structure

				printf("\nWhich logical operator to be applied?\n 1. AND\n 2. OR\n Enter option: ");
				fflush(stdin);
				scanf("%c",&log_op);
				validate_op(&log_op); //validating option 
		
				printf("\nScanning under %s conditon.\n", log_op=='1'? "AND":"OR");
				printf("Files that have the entered keyword(s) according to the conditions will be displayed shortly.\n \n \n"
						"===========RESULT=========== \n");

					for(int check=1; check<argc; ++check)
					{					
						res= multi_scan(argv[check], k, num_key,&log_op); //this function is used for mutiple-keyword type of scanning						
						switch(log_op)
						{
							//for displaying result based on AND/OR condition
							case '1': //for AND condition
									if(res==(num_key))//indicates that all keywords have been found
									{
										filec++;
										printf("\tKeywords found in %s \n",argv[check]);
									}
									break;
							case '2': //for OR condition 
									if(res>0 && res<=(num_key))//checks if one or more keyword has been found
									{
										filec++;				
									}
									break;
						}

					}
					if(filec==0)
					{
						printf("Sorry! None of the files have all the keywords entered under %s conditon\n", log_op=='1'? "AND":"OR");
					}
				break;
		}	
	printf("\nTHANK YOU for your patience! :)\n"); 
}

