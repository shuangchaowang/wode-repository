#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<sys/time.h>
#include"main.h"
#include"lts.h"
#include"lps.h"
#include"lcs.h"
#include"lcps.h"

long getTime(){
    struct timeval t;
    gettimeofday(&t,NULL);
    return t.tv_sec * 1000 + t.tv_usec /1000;
}


int main(int argc, char *argv[]){

    long start_time = getTime();
    
    int sq1_len,sq2_len;
    char sq1[10001];
    char sq2[10001];
    int true_num = 0;
    bool param[] = {false,false,false,false,false,false,false,false};
    char *input = NULL;
    char *output = NULL;
    char *str[] = {"-cp","-ct","-c","-p","-t","-g","-i","-o"};
    const char *content = "-g:\tto generate an instance consisting of two sequences over the digit alphabet\n" \
        "-c:\tto compute an LCS for the two input sequences\n" \
        "-t:\tto compute an LTS for the input sequence\n" \
        "-p:\tto compute an LPS for the input sequence\n" \
        "-ct:\tto compute an LCTS for the two input sequences\n"\
        "-cp:\tto compute an LCPS for the two input sequences\n"\
        "-i inputfilename:\tto read in sequence(s) from file 'inputfilename'\n"\
        "-o outputfilename:\tto write all the results into the file 'outputfilename'\n";
    for (int i=1;i<argc;i++){
        int j = 0;
        int isbreak = 0;
        for(j=0;j<6;j++){
            if(strcmp(argv[i],str[j]) == 0){
                param[j] = true;
                true_num++;
                isbreak = 1;
                break;
            }
        }
        if(isbreak == 1){
            continue;
        }
        if(strcmp(argv[i],str[j]) == 0){
            param[j] = true;
            true_num++;
            if(argc<=i+1){
                printf("1\n%s", content);
                return 1;
            }
            else{
                input = argv[i+1];
                continue;
            }
        }
        j++;
        if(strcmp(argv[i],str[j]) == 0){
            param[j] = true;
            true_num++;
            if(argc<=i+1){
                printf("2\n%c",content);
                return 1;
            }
            else{
                output = argv[i+1];
                continue;
            }
        }
    }
    if(true_num == 0){
        printf("3\n%s",content);
        return 1;
    }
    else{
        if(param[5]){
            if(param[1]||param[2]||param[3]||param[4]||param[0]||param[6]){
                //printf("%s %s %s %s %s %s",str[0],str[1],str[2],str[3],str[4],str[6]);
                printf("4\n%s",content);
                return 1;
            }
            else{
                printf("Enter the lengths of the two sequences: ");
                scanf("%d %d",&sq1_len,&sq2_len);
                srand(time(0));
                for(int i=0;i<sq1_len;i++){
                    sq1[i] = rand()%10 + 48;
                    sq1[i+1] = '\0';
                }
                for(int i=0;i<sq2_len;i++){
                    sq2[i] = rand()%10 + 48;
                    sq2[i+1] = '\0';
                }
                if(param[7]){
                    FILE *fp = fopen(output,"w");
                    fprintf(fp,"%s\n",sq1);
                    fprintf(fp,"%s\n",sq2);
                    fclose(fp);
                }
                else{
                    printf("%s\n",sq1);
                    printf("%s\n",sq2);
                }

                //printf("sucess\n");
            }
        }
        else{
            if(param[0]||param[1]||param[2]){
                if(param[2]){
                    if(param[6]){
                        FILE *fp;
                        if((fp = fopen(input,"r")) == NULL){
                            printf("ERROR, FILE IS EMPTY");
                            return 1;
                        }
                        fscanf(fp,"%[^\n]s",sq1);
                        fscanf(fp,"%[^\n]s",sq2);
                        sq1_len = strlen(sq1);
                        sq2_len = strlen(sq2);
                        lcs(sq1_len,sq2_len,sq1,sq2,param[7],output);
                    }
                    else{
                        printf("Enter the first sequence: ");
                        scanf("%s",sq1);
                        printf("Enter the second sequence: ");
                        scanf("%s",sq2);
                        sq1_len = strlen(sq1);
                        sq2_len = strlen(sq2);
                        lcs(sq1_len,sq2_len,sq1,sq2,param[7],output);

                    }
                }
                if(param[0]){
                    if(param[6]){
                        FILE *fp;
                        if((fp = fopen(input,"r")) == NULL){
                            printf("ERROR, FILE IS EMPTY");
                            return 1;
                        }
                        fscanf(fp,"%[^\n]s",sq1);
                        fscanf(fp,"%[^\n]s",sq2);
                        sq1_len = strlen(sq1);
                        sq2_len = strlen(sq2);
                        char sq3[sq1_len];
                        for(int i = sq1_len;i>=0;i--){
                            sq3[sq1_len-i-1] = sq1[i];
                        }
                        char sq4[sq2_len];
                        for(int i = sq2_len;i>=0;i--){
                            sq4[sq2_len-i-1] = sq2[i];
                        }
                        lcps(sq1_len,sq2_len,sq1_len,sq2_len,sq1,sq2,sq3,sq4,param[7],output);
                    }
                    else{
                        printf("Enter the first sequence: ");
                        scanf("%s",sq1);
                        printf("Enter the second sequence: ");
                        scanf("%s",sq2);
                        sq1_len = strlen(sq1);
                        sq2_len = strlen(sq2);
                        char sq3[sq1_len];
                        for(int i = sq1_len;i>=0;i--){
                            sq3[sq1_len-i-1] = sq1[i];
                        }
                        char sq4[sq2_len];
                        for(int i = sq2_len;i>=0;i--){
                            sq4[sq2_len-i-1] = sq2[i];
                        }
                        lcps(sq1_len,sq2_len,sq1_len,sq2_len,sq1,sq2,sq3,sq4,param[7],output);
                    }
                }

                //printf("sucess\n");
            }
            else{
                if(param[4]){ // run -t which is lts
                    char sq[10001];
                    int len_sq;
                    if(param[6]){ // if run -i read sq from inputfile
                        
                        FILE *fp;
                        if((fp = fopen(input,"r")) == NULL){
                            printf("ERROR, FILE IS EMPTY");
                            return 1;
                        }
                        fscanf(fp,"%[^\n]s",sq);
                        len_sq = strlen(sq);
                        lts(len_sq,sq,param[7],output);

                    }
                    else{
                        printf("Enter the sequence: ");
                        scanf("%s",sq);
                        len_sq = strlen(sq);
                        lts(len_sq,sq,param[7],output);

                    }
                }
                if(param[3]){ //run -p which is lps
                    char sq[10001];
                    int len_sq;
                    if(param[6]){ // if run -i read sq and inputfile
                        FILE *fp;
                        if((fp = fopen(input,"r")) == NULL){
                            printf("ERROR, FILE IS EMPTY");
                            return 1;
                        }
                        fscanf(fp,"%[^\n]s",sq);
                        len_sq = strlen(sq);
                        lps(len_sq,sq,param[7],output);
                    }
                    else{
                        printf("Enter the sequence: ");
                        scanf("%s",sq);
                        len_sq = strlen(sq);
                        lps(len_sq,sq,param[7],output);

                    }
                }

                
            }        

                
        }
    }
        
    
    printf("time used: %ld\n", getTime() - start_time);

    return 0;
}