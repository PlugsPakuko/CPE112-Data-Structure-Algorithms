//PAKKAWAT KAOLIM 66070503446
//Dictionary

#include<stdio.h>
#include<string.h> //hint

struct dict{
	char value[100];
	char key[100];
};

int editdict(struct dict *dic,char *key, char *value, int size){ //for editing the dictionary
	//write your code here
    for(int i = 0; i < size; i++){
        if(strcmp(dic[i].key, key) == 0){
            dic[i].value[0] = '\0';
            strcpy(dic[i].value, value);
            return 1;
        }
    }
    return 0;
}

void printdict(struct dict *dic, int size){ //for printing the output
	for(int i=0; i<size ; i++){
		printf("%s : %s\n",dic[i].key,dic[i].value);
	}
}

int main(){
	int size;
	scanf("%d",&size);
	struct dict dic[size]; //you can do this to declare structure in the array

	//write your code here
    for(int i = 0; i < size; i++){
        scanf("%s %s", dic[i].key, dic[i].value);
    }

    char modify_key[100], modify_value[100];
    scanf("%s %s", modify_key, modify_value);

    if(!editdict(dic, modify_key, modify_value, size))
        printf("No change\n");

    for(int i = 0; i < size; i++){
        printf("%s : %s\n", dic[i].key, dic[i].value);
    }
    return 0;
}