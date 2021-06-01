CC=/usr/bin/gcc
ROOT=/home/work/cuwacunu

KIJTYU=$(ROOT)/kijtyu
CONFIGURATIONS=$(ROOT)/configurations
COMMUNICATIONS=$(ROOT)/communications
TEST_=$(ROOT)/test

UJCAMEI_=$(KIJTYU)/mrkt_ujcamei_kijtyu
CAJTUCU_=$(KIJTYU)/mrkt_cajtucu_kijtyu
ENTROPY_=$(KIJTYU)/shnnn_entropy_kijtyu
JIKIMYEI_=$(KIJTYU)/skwstr_jkimyei_kijtyu
DUURUVA_=$(KIJTYU)/wjc_duuruva_kijtyu
KEMU_=$(KIJTYU)/wjc_kemu_kijtyu
MUNAAJPI_=$(KIJTYU)/wjc_munaajpi_kijtyu
UWAABO_=$(KIJTYU)/wjc_uwaabo_kijtyu
TSINUU_=$(KIJTYU)/wjc_tsinuu_kijtyu
WIKIMYEI_=$(KIJTYU)/wjc_wikimyei_kijtyu
KALAMAR_=$(KIJTYU)/wjc_kalamar_kijtyu


# CFLAGS=-I $(KEMU_)/ -I $(UWAABO_)/ -I $(MUNAAJPI_)/ -I $(ALLIU_)/ -I $(CONFIGURATIONS)/ -I $(COMMUNICATIONS)/ -I $(JIKIMYEI_)/

# AUXFLAGS=-lfann -lm -Wall -O3 # FIXME
KALAMAR_TARGETS=$(KALAMAR_)/cwcn_kalamar_piaabo.c
KALAMAR_HEADERS=$(KALAMAR_)/
WIKIMYEI_TARGETS=$(WIKIMYEI_)/cwcn_wikimyei_nebajke.c $(WIKIMYEI_)/cwcn_wikimyei_piaabo.c
WIKIMYEI_HEADERS=$(WIKIMYEI_)/
CAJTUCU_TARGETS=$(CAJTUCU_)/cwcn_cajtucu_piaabo.c
CAJTUCU_HEADERS=$(CAJTUCU_)/
UJCAMEI_TARGETS=$(UJCAMEI_)/cwcn_ujcamei_piaabo.c
UJCAMEI_HEADERS=$(UJCAMEI_)/
ENTROPY_TARGETS=$(ENTROPY_)/cwcn_entropy_nebajke.c
ENTROPY_HEADERS=$(ENTROPY_)/
JIKIMYEI_TARGETS=$(JIKIMYEI_)/cwcn_jkimyei_nebajke.c
JIKIMYEI_HEADERS=$(JIKIMYEI_)/
DUURUVA_TARGETS=$(DUURUVA_)/cwcn_duuruva_nebajke.c
DUURUVA_HEADERS=$(DUURUVA_)/
KEMU_TARGETS=$(KEMU_)/cwcn_kemu_piaabo.c
KEMU_HEADERS=$(KEMU_)/
MUNAAJPI_TARGETS=$(MUNAAJPI_)/cwcn_munaajpi_piaabo.c
MUNAAJPI_HEADERS=$(MUNAAJPI_)/
UWAABO_TARGETS=$(UWAABO_)/cwcn_uwaabo_piaabo.c
UWAABO_HEADERS=$(UWAABO_)/
TSINUU_TARGETS=$(TSINUU_)/cwcn_tsinuu_nebajke.c $(TSINUU_)/cwcn_tsinuu_piaabo.c
TSINUU_HEADERS=$(TSINUU_)/
CONFIGURATIONS_TARGETS=$(CONFIGURATIONS)/wikimyei.config.c
CONFIGURATIONS_HEADERS=$(CONFIGURATIONS)/

REGULAR_TARGETS=\
$(TSINUU_TARGETS) \
$(CAJTUCU_TARGETS) \
$(UJCAMEI_TARGETS) \
$(ENTROPY_TARGETS) \
$(DUURUVA_TARGETS) \
$(KEMU_TARGETS) \
$(MUNAAJPI_TARGETS) \
$(UWAABO_TARGETS) \
$(CONFIGURATIONS_TARGETS) \
$(JIKIMYEI_TARGETS) \
$(WIKIMYEI_TARGETS)

REGULAR_HEADERS=\
-I $(TSINUU_HEADERS) \
-I $(CAJTUCU_HEADERS) \
-I $(UJCAMEI_HEADERS) \
-I $(ENTROPY_HEADERS) \
-I $(JIKIMYEI_HEADERS) \
-I $(DUURUVA_HEADERS) \
-I $(KEMU_HEADERS) \
-I $(MUNAAJPI_HEADERS) \
-I $(UWAABO_HEADERS) \
-I $(CONFIGURATIONS_HEADERS) \
-I $(WIKIMYEI_HEADERS)

# BTC_FUT_TARGETS=$(CONFIGURATIONS)/btc_fut.config.c $(WIKIMYEI_)/cwcn_btc_fut_wikimyei.c
KALAMAR_TEST_TARGETS=$(KALAMAR_TARGETS)
KALAMAR_TEST_HEADERS=-I $(KALAMAR_HEADERS)

WIKIMYEI_TEST_TARGETS=$(REGULAR_TARGETS)
WIKIMYEI_TEST_HEADERS=$(REGULAR_HEADERS)

ENTROPY_TEST_TARGETS=$(ENTROPY_)/*.c $(TEST_)/testing_entropy.c
TSINUU_TEST_TARGETS=$(TSINUU_)/cwcn_tsinuu_piaabo.c $(TSINUU_)/cwcn_tsinuu_nebajke.c $(TEST_)/testing_tsinuu.c
DUURUVA_TEST_TARGETS=$(DUURUVA_)/cwcn_duuruva_nebajke.c $(TEST_)/testing_duuruva.c
_all_wikimyei: _wikimyei_btc_fut
_kalamar_test:
	$(CC) $(KALAMAR_TEST_TARGETS) $(TEST_)/testing_kalamar.c $(KALAMAR_TEST_HEADERS) -lncurses -lm -Wall -o $(ROOT)/_kalamar_test
	$(ROOT)/_kalamar_test
_wikimyei_test:
	$(CC) $(WIKIMYEI_TEST_TARGETS) $(TEST_)/testing_wikimyei.c $(WIKIMYEI_TEST_HEADERS) -lm -Wall -o $(ROOT)/_wikimyei_test
	$(ROOT)/_wikimyei_test
_entropy_test:
	$(CC) $(ENTROPY_TEST_TARGETS) -I $(ENTROPY_)/ -I $(CONFIGURATIONS)/ -lm -Wall -o $(ROOT)/_entropy_test
	$(ROOT)/_entropy_test 
_tsinuu_test:
	$(CC) $(TSINUU_TEST_TARGETS) -I $(TSINUU_)/ -lm -Wall -o $(ROOT)/_tsinuu_test
	$(ROOT)/_tsinuu_test 
_duuruva_test:
	$(CC) $(DUURUVA_TEST_TARGETS) -I $(DUURUVA_)/ -I -lm -Wall -o $(ROOT)/_duuruva_test
	$(ROOT)/_duuruva_test
clean:
	rm -f $(ROOT)/_kalamar_test $(ROOT)/_wikimyei_test $(ROOT)/_entropy_test $(ROOT)/_tsinuu_test $(ROOT)/_duuruva_test