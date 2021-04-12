GCC=/usr/bin/gcc
CFLAGS=-I /home/work/cuwacunu/fann/src/include/
LDFLAGS=-L /home/work/cuwacunu/fann/src/include/
TARGETS=cwcn_net_trainer.c cwcn_net_utils.c cwcn_net_data_mech.c 
NAME=net
all:
	$(GCC) $(CFLAGS) $(LDFLAGS) -Wall -O3 $(TARGETS) -o $(NAME) -lfann -lm
net: $(TARGETS)
	$(GCC) $(CFLAGS) $(LDFLAGS) -Wall -O3 $< -o $@ -lfann -lm
clean:
	rm -f $(NAME)