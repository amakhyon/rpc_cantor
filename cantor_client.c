/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "cantor.h"


void
cantor_1(char *host)
{
	CLIENT *clnt;
	results  *resultForeward;
	pairs  pairForeward;
	pairs  *pairBackward;
	results  resultBackward;

#ifndef	DEBUG
	clnt = clnt_create (host, Cantor, Cantor_Vers, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
    int choice;
    printf("please choose an option:\n 1)cantor foreward\n2)cantor backward \n choice: ");
    scanf("%d",&choice);
    if(choice ==1){
        printf("\n enter number of pairs: ");
        scanf("%d",&pairForeward.pairs_len);
        pairForeward.pairs_val = (pairs *) malloc(sizeof(pair) * pairForeward.pairs_len );
        int i; static pair tempair;
        tempair.x = tempair.y = 0;
        for(i=0; i < pairForeward.pairs_len; i++){
            printf("\n enter pair %d: ",i+1);
            scanf("%d %d",&tempair.x,&tempair.y);
            pairForeward.pairs_val[i] = tempair;
        }
        
	    resultForeward = cantorforeward_1(&pairForeward, clnt);
	    if (resultForeward == (results *) NULL) {
		    clnt_perror (clnt, "call failed");
	    }
        printf("\n results are\n");
        for(i=0;i<resultForeward->results_len; i++){
            
            printf(" %d ", resultForeward->results_val[i]);
        }
        printf("\n");

    }
    else if(choice == 2) {
        int i; int z;
        printf("\n enter number of Z values: ");
        scanf("%d",&resultBackward.results_len);
        resultBackward.results_val = (int *) malloc(sizeof(int) * resultBackward.results_len);
        for(i=0; i < resultBackward.results_len; i++){
            printf("\n enter Z value %d: ",i+1);
            scanf("%d",&z);
            resultBackward.results_val[i] = z;
        }
    
        printf("\n results are \n");
	    pairBackward = cantorbackward_1(&resultBackward, clnt);
        for(i=0; i < pairBackward->pairs_len; i++){
            printf("\n pair %d are %d %d",i+1,pairBackward->pairs_val[i].x,pairBackward->pairs_val[i].y);
        }
	    if (pairBackward == (pairs *) NULL) {
		    clnt_perror (clnt, "call failed");
	    }
    }
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	cantor_1 (host);
exit (0);
}