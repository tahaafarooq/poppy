poppy: poppy.c
	gcc -shared poppy.c -o poppy -Wl,-e,entry -fPIC

su: su.c
	gcc -shared su.c -o suuser -Wl,-e,entry -fPIC