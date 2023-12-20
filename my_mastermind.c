#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include<getopt.h>
char * ini_code(int code_size)
{
    char* code;
    srand(time(NULL));
    code = (char*)malloc((code_size)*sizeof(char));
    
    for(int i = 0; i <4; i++)
    {
        code[i] = '0' + rand() % 9;
    }
    code[4] = '\0';

    return code;


}

void input(char u_input[], int len)
{
    int code_size;
    int a = 1;

    while(a)
    {
        code_size = read(0,u_input,len);
        if(code_size == -1)
        {
            printf("Input Error\n");
        }
        else if (code_size == 0)
        {
            printf("No input dectected\n");
            exit(0);  
        }
        else
        {
            u_input[len-1] = '\0';
            if(code_size -1 != 4)
            {
                printf("Invalid number of digits\n");
            }
            else
            {
                a -=1;
            }
        }
    }

}

int main(int argc, char** argv)
{
    int attempts = 10;
    //int output;
    char* code;

    int output;

    char u_input[4];

    int code_size = 4;

    code = ini_code(code_size);

     while((output = getopt(argc,argv,"c:t:"))!= -1)
    
    {
        switch(output)
        {
            case 'c':

                if(code!=NULL)
                    {
                        free(code);
                    }
                code = optarg;
                break;

            case 't':
                attempts = atoi(optarg);
                break;
        }
    } 
    /*
    if(argc > 1)
    {
        free(code);
        //code = strdup(argv[1]);
        code = (char *)malloc((strlen(argv[1])+1) * sizeof(char));
        strcpy(code, argv[1]);
        if(argc == 3)
            attempts = atoi(argv[2]);
    }
    
    */

   
    printf("Will you find the secret code?\n");
    printf("Please enter a valid guess\n");

    for(int i = 0; i < attempts; i++)
    {
        input(u_input,5);

        if(strncmp(code , u_input , code_size) == 0)
            {
                printf("Congratz! You did it!\n");
                break;
            }
        else
            {
                int wp = 0;
                int mp = 0;
                int exist[4];
               
               for(int j = 0; j < code_size; j++)
               {    
                   if(code[j] == u_input[j])
                   {
                       wp++;
                       exist[j] = code[j];
                   }
                   for(int k = 0; k < code_size; k++)
                   {
                       if(code[j] == u_input[k])
                       {
                           if(exist[j] != u_input[k])
                           {
                               mp++;
                           }
                       }
                   }
               }
                

               printf("Well placed pieces: %d\n",wp);
               printf("Misplaced pieces: %d\n",mp);


            }
    }
    return 0;
}
