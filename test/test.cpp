
#include <iostream>
#include <cstring>

#if !defined(__cplusplus)
#error "C++ compiler required for strcpy and strcat functions"
#endif


int main()
{
    char s1[6] = "Hello";
    char s2[6] = "World";
    char s3[12];
    // char *ptr;

    strcpy(s3, s1);
    strcat(s3, s2);

    std::cout << s3;

    char *ptr;
    if ((ptr = (char *)malloc(0)) ==  NULL)
         puts("\nGot a null pointer");
    else
        puts("\nGot a valid pointer");

    return 0;
}

/*
class aclass
{
    // int aclass()   Constructor does not have return value
    aclass()
    {
       cout<<"Constructor";
       
     }
};
int main()
{
    aclass obj;
    return 0;
}
*/