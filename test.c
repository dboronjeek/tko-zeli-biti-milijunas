
	struct employee temp;
	FILE *fp;
	int i=0,size,j;
	char ch; 
 
	fp=fopen("emp.txt","r");
	if(fp==NULL)
	{ 
	printf("\n Cannot open the file \n");
	exit(0);
	}
	while(ch!=EOF)
	{
	fscanf(fp,"%s%d%d",emp[i].name,&emp[i].age,&emp[i].sal);  
	ch=fgetc(fp); 
	i++;  
	} 
	size=i-1;
	for(i=1;i<size;++i)
	for(j=0;j<size-i;j++)
	if(emp[j+1].age<emp[j].age)
	{
	temp=emp[j];
	emp[j]=emp[j+1];
	emp[j+1]=temp;
	}
	fp=fopen("empsorted.txt","w");
	for(i=0;i<size;i++)
	fprintf(fp,"%s %d %d \n",emp[i].name,emp[i].age,emp[i].sal);
	printf("\n The file is sorted successfully and saved as empsorted.txt. \n \n");
