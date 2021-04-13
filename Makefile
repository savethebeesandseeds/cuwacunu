CC=/usr/bin/gcc

ROOT=/home/work/cuwacunu

KIJTYU=$(ROOT)/kijtyu
CONFIGURATIONS=$(ROOT)/configurations
COMMUNICATIONS=$(ROOT)/communications
WIKIMYEI=$(ROOT)/wikimyei
FANN_=$(ROOT)/fann/src/include/

NET_=$(KIJTYU)/stffn_net_kijtyu
WIKIMYEI_=$(KIJTYU)/wjc_wikimyei_kijtyu
ENTROPY_=$(KIJTYU)/shnnn_entropy_kijtyu
DATA_=$(KIJTYU)/mrkt_alliu_kijtyu

CFLAGS=-I $(NET_)/ -I $(WIKIMYEI_)/ -I $(ENTROPY_)/ -I $(DATA_)/ -I $(CONFIGURATIONS)/ -I $(COMMUNICATIONS)/
LDFLAGS=-L $(FANN_)
AUXFLAGS=-lfann -lm -Wall -O3 # FIXME

REGULAR_TARGETS=$(NET_)/cwcn_net_nebajke.c $(WIKIMYEI_)/cwcn_wikimyei_nebajke.c $(COMMUNICATIONS)/cwcn_security.c $(NET_)/cwcn_net_piaabo.c
BTC_FUT_TARGETS=$(CONFIGURATIONS)/btc_fut.config.c $(WIKIMYEI)/cwcn_btc_fut_wikimyei.c

all: _wikimyei_btc_fut
_wikimyei_btc_fut:
	$(CC) $(REGULAR_TARGETS) $(BTC_FUT_TARGETS) $(CFLAGS) $(LDFLAGS) $(AUXFLAGS) -o _wikimyei_btc_fut 
clean:
	rm -f $(ROOT)/wikimyei_*