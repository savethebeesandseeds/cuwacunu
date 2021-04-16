CC=/usr/bin/gcc
ROOT=/home/work/cuwacunu

KIJTYU=$(ROOT)/kijtyu
CONFIGURATIONS=$(ROOT)/configurations
COMMUNICATIONS=$(ROOT)/communications
TEST_=$(ROOT)/test
FANN_=$(ROOT)/fann/src/include/

NET_=$(KIJTYU)/stffn_net_kijtyu
JIKIMYEI_=$(KIJTYU)/skwstr_jkimyei_kijtyu
AVYETA_=$(KIJTYU)/wjc_avyeta_kijtyu
IPIVYE_=$(KIJTYU)/wjc_ipivye_kijtyu
ENTROPY_=$(KIJTYU)/shnnn_entropy_kijtyu
ALLIU_=$(KIJTYU)/mrkt_alliu_kijtyu
KEMU_=$(KIJTYU)/wjc_kemu_kijtyu

CFLAGS=-I $(KEMU_)/ -I $(NET_)/ -I $(IPIVYE_)/ -I $(AVYETA_)/ -I $(ALLIU_)/ -I $(CONFIGURATIONS)/ -I $(COMMUNICATIONS)/ -I $(JIKIMYEI_)/
LDFLAGS=-L $(FANN_)
AUXFLAGS=-lfann -lm -Wall -O3 # FIXME

REGULAR_TARGETS=$(KEMU_)/*.c $(NET_)/*.c $(COMMUNICATIONS)/cwcn_security.c $(IPIVYE_)/*.c $(AVYETA_)/*.c $(JIKIMYEI_)/*.c $(ALLIU_)/*.c
BTC_FUT_TARGETS=$(CONFIGURATIONS)/btc_fut.config.c $(ROOT)/wikimyei/cwcn_btc_fut_wikimyei.c
ENTROPY_TEST_TARGETS=$(CONFIGURATIONS)/entropy_test.config.c $(ENTROPY_)/*.c $(TEST_)/testing_entropy.c
all: _wikimyei_btc_fut
_wikimyei_btc_fut:
	$(CC) $(REGULAR_TARGETS) $(BTC_FUT_TARGETS) $(CFLAGS) $(LDFLAGS) $(AUXFLAGS) -o _wikimyei_btc_fut 
_entropy_test:
	$(CC) $(ENTROPY_TEST_TARGETS) -I $(ENTROPY_)/ -I $(CONFIGURATIONS)/ $(AUXFLAGS) -o _entropy_test 
clean:
	rm -f $(ROOT)/_wikimyei_*