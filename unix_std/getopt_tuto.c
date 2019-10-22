#include <unistd.h> //getopts() se trouve dans unistd
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int opt;
    while((opt = getopt(argc, argv, "ab:")) != -1){
        if(opt == 'b'){
            printf("%s\n", optarg);
        }
        else{
            printf("%c\n", opt);
        }
    }
}
