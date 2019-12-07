#include<ctype.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define max(x,y) (((x) > (y)) ? (x) : (y))

//void lcs2(int m,int n,char sqs[u][], char sq2[],char *ltsptr);
//void create_ts(int sl, char sq2[],int *count,char *ts[]);


/*void create_ts(int lenths[i], char sqs[u][],int *count,char *ts[]){
    //int lenths[i] = 7;
    //char sqs[u][] = "123125";
	//printf("in lts");
    printf("lenths[i] is:%d\n",lenths[i]);
	char l_half[lenths[i]];
	char r_half[lenths[i]];
	char lts[lenths[i]];
	int max_len = 0;
	char max_lts[lenths[i]];
	int length;
	char * ltsptr = lts;
    int nolts = 0; 
    for(int i =1;i<lenths[i];i++){
		if (strlen(sqs[u]) < 2){
			//char dummy[2] = "\0";
			lts[0] = '\0';
		}
		else{
			for(int j = 0;j<i;j++){
				l_half[j] = sqs[u][j];
				l_half[j+1] = '\0';
			}
			//printf("l_half is:%s\n",l_half);
			int a =0;
			for(int j = i;j<lenths[i];j++){
				r_half[a] = sqs[u][j];
				r_half[a + 1] = '\0';
				a++;
			}
			//printf("r_half is:%s\n",r_half);
			int llen = strlen(l_half);
			int rlen = strlen(r_half);
			//lcs2(llen,rlen,l_half,r_half,ltsptr);






            int **fill_list;
	        fill_list = (int**)malloc(sizeof(int*)*(llen+1));
	        for(int z=0;z<llen+1;z++){
		        fill_list[z] = (int*)malloc(sizeof(int)*(rlen+1));
	        }
            int i,j;
	
	        for (i=0; i<=llen; i++){
     	        for (j=0; j<=rlen; j++){
       		        if (i == 0 || j == 0){//set first row and colunm all zeros
         		        fill_list[i][j] = 0;
			        }
       		        else if (l_half[i-1] == r_half[j-1]){//plus one when finding a common character
         		        fill_list[i][j] = fill_list[i-1][j-1] + 1;
			        }
       		        else{
         		        if(fill_list[i-1][j] > fill_list[i][j-1]){
				            fill_list[i][j] = fill_list[i-1][j];
			            }
			            else{
				            fill_list[i][j] = fill_list[i][j-1];

			            }
                    }	
                }
	        }       

	        int pos = fill_list[llen][rlen];//start from the right_bottom index, which is the last index of fill_list
	        //largest value is set as the length of lcs
	        char lts[pos+1];
	        lts[pos] = '\0';

	        // start from the bottom pick up the common characters from the path
	        while(llen && rlen){
                if(l_half[llen-1] == r_half[rlen-1]){
                    lts[pos-1]= l_half[llen-1];
                    llen--;
			        rlen--;
			        pos--;
                }
                else if(fill_list[llen-1][rlen] >fill_list[llen][rlen-1] ){
			        llen--;
		        }
		        else{
			        rlen--;
		        }
            }
	        int lts_len = strlen(lts);
	        //printf("# an LCS (length = %d) is:%s\n",lts_len,lts);
            for(int i=0;i<llen+1;i++){
		        int* cptr = fill_list[i];
		        free(cptr); 
	        }

            

            //printf("lts is:%s\n",lts);
			length = strlen(lts);
            char result[length*2];
            strcpy(result,lts);
            strcat(result,lts);
            //printf("result is:%s\n",result);
            //printf("nolts is:%d\n",nolts);

            ts[nolts] = result;
            printf("ts%d %s\n",nolts,ts[nolts]);
            nolts++;
            (*count)++;
            
            
			//printf("%s\n",*lcs(llen,rlen,l_half,r_half));
			if(length > max_len){
				max_len = length;
				strcpy(max_lts,lts);
			}


		}
        
	}
    ts[nolts] = "\0";
    printf("%d \n",nolts);
    printf("# an LTS (length = %d) for the first sequence is:\n%s%s\n",max_len * 2,max_lts,max_lts);
	//return lts_list;
}*/
int main(){
    int m = 6;
    int n = 7;
    char sq1[] = "124126";
    char sq2[] = "127128";
//void lcts(int m,int n,char sqs[u][],char sq2[]){
    char sqs[2][max(m,n)];
	for(int i=0;i<m;i++){
		sqs[0][i] = sq1[i];
	}
	for(int j=0;j<n;j++){
		sqs[1][j] = sq2[j];
	}
	int lenths[2] = {m,n};
    int count[2] = {0,0};
    char lcts[] = "";
    char *ts[2][10001];
    //char *ts2[10001];
    //char max_lts[max(m,n)];
    //int max_len = 0;
    int max_cts = 0;
	for(int u=0;u<2;u++){
		//printf("lenths[u] is:%d\n",lenths[u]);
		char l_half[lenths[u]];
		char r_half[lenths[u]];
		char lts[lenths[u]];
		int max_len = 0;
		char max_lts[lenths[u]];
		int length;
		char * ltsptr = lts;
		int nolts = 0; 
		for(int i =1;i<lenths[u];i++){
			if (strlen(sqs[u]) < 2){
				//char dummy[2] = "\0";
				lts[0] = '\0';
			}
			else{
                //printf("last one is:%d %s\n",nolts-1,ts[u][nolts-1]);
				for(int j = 0;j<i;j++){
					l_half[j] = sqs[u][j];
					l_half[j+1] = '\0';
				}
				//printf("l_half is:%s\n",l_half);
				int a =0;
				for(int j = i;j<lenths[u];j++){
					r_half[a] = sqs[u][j];
					r_half[a + 1] = '\0';
					a++;
				}
				//printf("r_half is:%s\n",r_half);
				int llen = strlen(l_half);
				int rlen = strlen(r_half);
				//lcs2(llen,rlen,l_half,r_half,ltsptr);

				int **fill_list;
				fill_list = (int**)malloc(sizeof(int*)*(llen+1));
				for(int z=0;z<llen+1;z++){
					fill_list[z] = (int*)malloc(sizeof(int)*(rlen+1));
				}
				//int i,j;
		
				for (int i=0; i<=llen; i++){
					for (int j=0; j<=rlen; j++){
						if (i == 0 || j == 0){//set first row and colunm all zeros
							fill_list[i][j] = 0;
						}
						else if (l_half[i-1] == r_half[j-1]){//plus one when finding a common character
							fill_list[i][j] = fill_list[i-1][j-1] + 1;
						}
						else{
							if(fill_list[i-1][j] > fill_list[i][j-1]){
								fill_list[i][j] = fill_list[i-1][j];
							}
							else{
								fill_list[i][j] = fill_list[i][j-1];

							}
						}	
					}
				}       

				int pos = fill_list[llen][rlen];//start from the right_bottom index, which is the last index of fill_list
				//largest value is set as the length of lcs
				char lts[pos+1];
				lts[pos] = '\0';

				// start from the bottom pick up the common characters from the path
				while(llen && rlen){
					if(l_half[llen-1] == r_half[rlen-1]){
						lts[pos-1]= l_half[llen-1];
						llen--;
						rlen--;
						pos--;
					}
					else if(fill_list[llen-1][rlen] >fill_list[llen][rlen-1] ){
						llen--;
					}
					else{
						rlen--;
					}
				}
				int lts_len = strlen(lts);
				//printf("# an LCS (length = %d) is:%s\n",lts_len,lts);
				for(int i=0;i<llen+1;i++){
					int* cptr = fill_list[i];
					free(cptr); 
				}

				

				//printf("lts is:%s\n",lts);
				length = strlen(lts);
                if(length > max_len){
				    max_len = length;
				    strcpy(max_lts,lts);
			    }
                printf("# an LCTS (length = %d) is:\n%s",max_len*2,max_lts);
                //printf("last one:%s\n",ts[u][nolts-1]);
                if(length != 0){
                    char result[(length*2)+1];
                    strcpy(result,lts);
                    strcat(result,lts);
                    result[length*2] = '\0';
                    //printf("result is:%s\n",result);
                    //printf("nolts is:%d\n",nolts);

                    ts[u][nolts] = result;
                    printf("ts%d %s\n",nolts,ts[u][nolts]);
                    nolts++;
                    count[u]++;
                }
                printf("ts%d %s\n",nolts-1,ts[u][nolts-1]);
    
			}
            //printf("ts%d %s\n",nolts-1,ts[u][nolts-1]);
			
		}
        

	}
    //printf("%s %s\n",ts[0][0],ts[1][0]);
    //create_ts(m,sqs[u], &count1,ts[0]);
    //create_ts(n,sq2, &count2,ts[1]);
    for(int i=0;i<count[0];i++){
        for(int j=0;j<count[1];j++){
            printf("%s  %d %s  %d\n",ts[0][i],count[0],ts[1][j],count[1]);
            if(strcmp(ts[0][i],ts[1][j]) == 0){
                //printf("%s %s\n",ts1[i],ts2[j]);
                if(strlen(ts[0][i]) > max_cts){
                    strcpy(lcts,ts[0][i]);
                    max_cts = strlen(ts[0][i]);
                }
            }
        }
    }
    printf("# an LCTS (length = %d) is:\n%s",max_len*2,max_lts);
    return 0;
}