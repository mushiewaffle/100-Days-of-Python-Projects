#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>//booleans
#include"List.h"

#define MAX_LEN 160

List insertionSort(int array[], int size){
		List L = newList();
		append(L,array[0]);
		bool SwapPlaceFound = false;
		for( int i = 1; i <= size ; i++ ){
			Node curr = L->head;
			do{
				//int temp = curr->data;
				if(array[i]<curr->data){
					Node N = newNode(array[i-1]); //?
					insertBefore(L, N, array[i]);
					SwapPlaceFound = true; //if correct place found exits loop
				}
				//if(SwapPlaceFound==)
				curr = curr -> next;
			}while(curr != L->tail && SwapPlaceFound ==false);
			if(SwapPlaceFound==false){ //else if A[i] is in right pos append it to tail
				append(L, array[i]);
			} SwapPlaceFound = false;
		}
		return L;
}

int secondmain(int argc, char * argv[]){

   int n, count=0;
   FILE *in, *out;
   char line[MAX_LEN];
   char tokenlist[MAX_LEN];
   char copy[MAX_LEN];
   char* token;

   List L = newList();
   
   //bool NoSpaceOnFirst = true;

   // check command line for correct number of arguments
   if( argc != 3 ){
      printf("Usage: %s <input file> <output file>\n", argv[0]);
      exit(1);
   }

   // open files for reading and writing 
   in = fopen(argv[1], "r");
   out = fopen(argv[2], "w");
   if( in==NULL ){
      printf("Unable to open file %s for reading\n", argv[1]);
      exit(1);
   }
   if( out==NULL ){
      printf("Unable to open file %s for writing\n", argv[2]);
      exit(1);
   }

   /* read each line of input file, then count and print tokens */
   while( fgets(line, MAX_LEN, in) != NULL)  {
      count++;
      n = 0;
      token = strtok(line, " \n"); //gets 1st line
      tokenlist[0] = '\0';

      bool NoSpaceOnFirst = true;
      do{
         if(NoSpaceOnFirst == false){ //so a space does not print before numbers
            strcat(tokenlist, " "); 
         }
         strcat(tokenlist, token); //prints all #s of a single line
         n++;
         token = strtok(NULL, " \n"); //new line
      NoSpaceOnFirst = false;
      }while( token!=NULL );

      //fprintf(out, "%s\n", tokenlist);
      strcpy(copy,tokenlist); //creates a copy of tokenlist to use later on to avoid reset errors
      char* point;
      point = strtok(tokenlist, " "); //reads everything seperated by white spaces of a string & puts in an array

      int size=0; //finds size 1st
      while(point!=NULL){
         size ++;
         //fprintf(out, "%s ", point);
         point = strtok(NULL, " ");
      }
      char* pointr;
      pointr = strtok(copy, " "); //new pointer for copy of the original tokenlist bc trash # errors when reseting without making a copy
      int arr[size]; //with size found I can now assign an array to store the numbers
      for(int i = 0; i<size; i++){
         arr[i]=atoi(pointr); //converts number string to integer and puts in arr
         pointr = strtok(NULL, " ");
      }
      
      //temp print check
      for(int i = 0; i<size; i++){
         fprintf(out, "%d ", arr[i]);
      }fprintf(out, "\n");
      
      //call insertion sort?
      L = insertionSort(arr, size);
      //call print?
      printList(out, L);
      //freeList?
      freeList(*L);
   }

   /* close files */
   fclose(in);
   fclose(out);

   return(0);
}