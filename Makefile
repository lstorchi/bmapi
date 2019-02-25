# redo

all:
	make -C ./src
	make -C ./testsrc

clean:
	make -C ./src clean
	make -C ./testsrc clean
