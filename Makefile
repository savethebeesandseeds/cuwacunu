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
TSINUU_=$(KIJTYU)/wjc_tsinuu_kijtyu

CFLAGS=-I $(KEMU_)/ -I $(NET_)/ -I $(IPIVYE_)/ -I $(AVYETA_)/ -I $(ALLIU_)/ -I $(CONFIGURATIONS)/ -I $(COMMUNICATIONS)/ -I $(JIKIMYEI_)/
LDFLAGS=-L $(FANN_)
AUXFLAGS=-lfann -lm -Wall -O3 # FIXME

REGULAR_TARGETS=$(KEMU_)/*.c $(NET_)/*.c $(COMMUNICATIONS)/cwcn_security.c $(IPIVYE_)/*.c $(AVYETA_)/*.c $(JIKIMYEI_)/*.c $(ALLIU_)/*.c
BTC_FUT_TARGETS=$(CONFIGURATIONS)/btc_fut.config.c $(ROOT)/wikimyei/cwcn_btc_fut_wikimyei.c
ENTROPY_TEST_TARGETS=$(ENTROPY_)/*.c $(TEST_)/testing_entropy.c
TSINUU_TEST_TARGETS=$(TSINUU_)/cwcn_tsinuu_piaabo.c $(TSINUU_)/cwcn_tsinuu_nebajke.c $(TEST_)/testing_tsinuu.c
_all_wikimyei: _wikimyei_btc_fut
_wikimyei_btc_fut:
	$(CC) $(REGULAR_TARGETS) $(BTC_FUT_TARGETS) $(CFLAGS) $(LDFLAGS) $(AUXFLAGS) -o _wikimyei_btc_fut 
_entropy_test:
	$(CC) $(ENTROPY_TEST_TARGETS) -I $(ENTROPY_)/ -I $(CONFIGURATIONS)/ -lm -Wall -o $(ROOT)/_entropy_test
	$(ROOT)/_entropy_test 
_tsinuu_test:
	$(CC) $(TSINUU_TEST_TARGETS) -I $(TSINUU_)/ -lm -o $(ROOT)/_tsinuu_test
	$(ROOT)/_tsinuu_test
clean:
	rm -f $(ROOT)/_wikimyei_btc_fut $(ROOT)/_entropy_test $(ROOT)/_tsinuu_test