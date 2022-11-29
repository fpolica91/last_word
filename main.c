#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DICT_LEN 256


int *create_delim_dict(char *delim)
{
    int *d = (int*)malloc(sizeof(int)*DICT_LEN);
    memset((void*)d, 0, sizeof(int)*DICT_LEN);

    int i;
    for(i=0; i< strlen(delim); i++) {
        d[delim[i]] = 1;
    }
    return d;
}

char *helper(char *str){
    char *del = " ,.-";
    
    if(*str == '\0')
        return NULL;
    
    int *deli_dict = create_delim_dict(del);
    while(deli_dict[*str] && *str != '\0'){
        str++;
    }
    while(*str != '\0' && !deli_dict[*str]){
        str++;
    }
    
    while(deli_dict[*str])
        str++;
    if(strlen(str) == 0)
        return NULL;
    return str;
}

char *last_word(char *str){
    char *ans;
    char *token = helper(str);
    while(token){
        if(token != NULL)
            ans = token;
        token = helper(token);

    }
    return ans;
}


int main()
{
    char *str = "this        ...       is sparta";
    char *str2 = "FOR PONIES";
    char *str3 = "  lorem,ipsum  ";
    char *tk1 = last_word(str);
    char *tk2 = last_word(str2);
    char *tk3 = last_word(str3);
    printf("%s\n", tk1);
    printf("%s\n", tk2);
    printf("%s\n", tk3);
    return 0;
}