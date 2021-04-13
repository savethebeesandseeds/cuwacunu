#include "fann.h"
#include "cwcn_net_nibajke.h"
#include "cwcn_net_piaabo.h"
#include "wikimyei.config.h"
#include "cwcn_wikimyei_nibajke.h"

void wikimyei_jkimyei_neural(){
    struct fann *ann = cwcn_net_ipivye(
        NUM_LAYERS, 
		NUM_UJCAMEI, 
		NUM_NEURONS_HIDDEN, 
		NUM_CAJTUCU
    );
    cwcn_display_network(ann);
}
