// get elements
int * getElements(int n1, int *p){
	
	int i;
	
	p = (int *)calloc(n1, sizeof(int));
	
	// validation for pointer
	if(p == NULL){
		printf("Unable to allocate the space\nExiting the program");
		exit(1);
	}
	
	for(i=0;i<n1;i++){
		printf("Enter the element p[%d]: ",i);
		scanf("%d",p+i);
	}
	line();
	return p;
}


//menu
int menu(){
	int opt1;
	printf("\n\n");
	line();
	printf(" Choose one of the following options\n");
	line();
	printf("1. Search\n");
	printf("2. Insert\n");
	printf("3. Delete\n");
	line();
	printf("Selected option: ");
	scanf("%d",&opt1);
	line();
	printf("\n");
	return opt1;
}

// search
void search(int x,int n1, int *p){
	
	int i, flag=0, count=0, *spos, n2=2;
	
	// iterete through each element
	for(i=0;i<n1;i++){
		// if the searched element is found
		if(p[i] == x){
			// set the flag 
			flag=1;
			
			// for the first element position
			if(count==0){
				// allocate the space
				spos = (int *)calloc(1, sizeof(int));
				// validation for pointer
				if(spos == NULL){
					line();
					printf("Unable to allocate the space\nExiting the program");
					exit(1);
					line();
				}
				// assign the value
				*(spos+count) = i;
				// increase the value of count
				count++;
			}
			
			else{
				// reallocate the space
				spos = (int *)realloc(spos,  n2*sizeof(int));
				// validation for pointer
				if(spos == NULL){
					line();
					printf("Unable to reallocate the space\nExiting the program");
					exit(1);
					line();
				}
				
				n2++;
				*(spos+count) = i;
				count++;
			}
		}
	}
	
	// if any element found
	if(flag){
		line();
		printf("Element found!\n");
		printf("Total occurances: %d",count);
		printf("\nPositon no.(s): ");
		for(i=0; i<count; i++)
		{
			printf("%d ",*(spos+i));
		}
		printf("\n");
		line();
	}
	
	else{
		line();
		printf("No element found!");
		exit(1);
		line();
	}
	
	free(spos);
}

// insert
void insert(int num, int n1, int *p){
	int opt2, x, i, j;
	
	line();
	printf("Choose the position: \n");
	printf("1. After 2.Before 3. Any\n");
	line();
	printf("Selected position: ");
	scanf("%d",&opt2);
	line();
	
	// for inserting element after or before	
	if(opt2==1 || opt2==2){
		line();
		printf("Enter the element  to be searched: ");
		scanf("%d",&x);
		line();
		// iterate through each element
		for(i=0;i<n1;i++){
			// if element found
			if(p[i] == x){
				// swap the elements forward upto the position just next to the searched element
 				for(j=n1+1;j>i+1;j--){
					p[j] = p[j-1]; 
				}
				
				// for inserting element after the searched element
				if(opt2==1)
					p[i+1] = num; // insert the given element
					
				// for inserting element before the searched element
				else if(opt2==2){
					// swap the searched element forward also 
					p[i+1] = p[i];
					// insert the given element
					p[i] = num;
					break;
				}
			}
		}
	}
	
	// for inserting element at any given position
	else if(opt2==3)
	{
		line();
		printf("Enter the position: ");
		scanf("%d",&x);
		line();
		
		if(x<=0 || x>=n1){
			line();
			printf("Wrong input!!");
			exit(1);
			line();
		}
		
		// iterate through each element
		for(i=0;i<n1;i++){
			// if the given element found
			if(i == x){
				// swap all the elements forward
				for(j=n1+1;j>x;j--){
					p[j] = p[j-1]; 
				}
				
				// insert the given element
				p[x] = num;
				break;
			}
		}
	}
	
	else{
		line();
		printf("Wrong input!!");
		exit(1);
		line();
	}
	
	printAll(n1+1, p);
}

// delete
void del(int x, int n1, int *p){
	
	int i, j;
	// iterate through each element 
	for(i=0;i<n1;i++){
		// if element found
		if(p[i] == x){
			// swap all the elements backward
			for(j=i;j<n1-1;j++){
				p[j] = p[j+1]; 
			}
			break;
		}
	}
	
	printAll(n1-1, p);
}

// line
void line(){
	int i;
	for(i=0;i<100;i++){
		printf("=");
	}
	printf("\n");
}

// to print all elements
void printAll(int n, int *p){
	int i;
	line();
	// print all the elements		
	for(i=0;i<n;i++){
		printf("%d ",p[i]);
	}
	printf("\n");
	line();
}
