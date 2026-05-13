#include<stdio.h>
#include<stdlib.h>


//////////////////////////////////////////////////////////////////////////
void add(int *array,int *list_length,int array_length) {
	if (*list_length>=array_length){
		printf("addition of elements not possible!");
		return;
	}
   int element;

   printf("enter element-");
   scanf("%d",&element);
	array[*list_length] = element;
   printf("added element\n");
	*list_length+=1;

   }
/////////////////////////////////////////////////////////////////////////
void delete_element(int *array,int *list_length) {
	int *start=array;
	int element;
	int element_index=-1;
	printf("enter element to delete-");
	scanf("%d",&element);
	for(int i=0;i<*list_length;i++){
		if (*array==element){
			element_index=i;
			break;
		}
		array++;
	}
	for (int i=element_index;i<*list_length;i++){
		array[i]=array[i+1];
	}
	*list_length-=1;
if (element_index==-1) {
	printf("element not found!");
	return;
}
}
////////////////////////////////////////////////////////////////////////
void find(int *array,int *list_length,int array_length){
	int *start=array;
	int element;
   int element_index=-1;
   printf("enter element to find-");
   scanf("%d",&element);

   for(int i=0;i<*list_length;i++){
   	if (*array==element){
   		element_index=i;
   		break;
	   }
	   array++;
   }
   array=start;
   if (element_index == -1)
        printf("Element not found\n");
    else
        printf("index is %d\n",element_index);
   printf("\nposition  is %d\n",element_index+1);
}
////////////////////////////////////////////////////////////////////////
void find_kth(int *array,int *list_length,int array_length){
   int *start=array;
   int element=array[0];
   int element_index;
   printf("enter the index to check-");
   scanf("%d",&element_index);
   if (element_index < 0 || element_index >= *list_length) {
    printf("Invalid index\n");
    return;
	}
   array=array+element_index;
   printf("the element is %d",*array);
   array=start;
}
/////////////////////////////////////////////////////////////////////////
void insert(int *array,int *list_length,int array_length){
	int insertplace;
	int element;
	printf("enter the place where u need to insert the number-");
	scanf("%d",&insertplace);
	printf("enter the element to add-");
	scanf("%d",&element);
	int index=insertplace-1;
	*list_length+=1;

	for(int i=*list_length;i>index;i--){
		array[i]=array[i-1];

	}
	array[index]=element;
}
//////////////////////////////////////////////////////////////////////////
void create(int *array,int *list_length){
	int *start=array;
	int n;
	printf("enter the number of elements in list->");
	scanf("%d",&n);
	*list_length=n;
	for (int i=0;i<n;i++){
		printf("enter element %d - ",i+1);
		scanf("%d",&array[i]);
	}
	printf("list initialised..");
}
///////////////////////////////////////////////////////////////////////////
void display(int *array,int *list_length,int array_length){
	printf("\n\nDISPLAYING LIST\n");
	for (int i=0;i<*list_length;i++){
		if(i==0){
			printf("|%d",array[i]);
		}
		else if(i==*list_length-1){
			printf("|%d|",array[i]);
		}
		else{
			printf("|%d",array[i]);
		}
	}
}
///////////////////////////////////////////////////////////////////////////
int main() {

   int array[5];
   int array_length;
   array_length = sizeof(array)/sizeof(array[0]);
   int list_length=0;
   int choice;
   while (1){
   printf("\n---OPERATIONS---\n");
   printf("1.add\n2.delete\n3.insert\n4.find\n5.find kth\n6.create\n7.display\n8.exit\n");
   printf("enter the choice-->");
   scanf("%d",&choice);
    switch (choice)
	{
	case 1:add(array,&list_length,array_length);break;
	case 2:delete_element(array,&list_length);break;
	case 3:insert(array,&list_length,array_length);break;
	case 4:find(array,&list_length,array_length);break;
	case 5:find_kth(array,&list_length,array_length);break;
	case 6:create(array,&list_length);break;
	case 7:display(array,&list_length,array_length);break;
	case 8:return 0;
	default:printf("enter the valid choice!!!\n\n");break;
   }
}
}




