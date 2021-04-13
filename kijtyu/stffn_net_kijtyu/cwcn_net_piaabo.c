#include <stdio.h>
#include <stdbool.h>
#include "fann.h"
#include "cwcn_net_piaabo.h"

float clamp(float d, float min, float max) {
  const float t = d < min ? min : d;
  return t > max ? max : t;
}

void cwcn_display_network(struct fann *ann){
    printf("Showing netowk.\n");
	printf("---------fann_print_parameters---------\n");
	fann_print_parameters(ann);
	printf("---------mine--------------------------\n");
	// TYPE
	
//   /* The type of error that last occured. */
//   enum fann_errno_enum errno_f;
	printf("\t (enum) errno_f:\t%d\n", ann->errno_f);
//   /* Where to log error messages. */
//   FILE *error_log;
	printf("\t *error_log:\t\t{aka struct _IO_FILE *}\n");

//   /* A string representation of the last error. */
//   char *errstr;
	printf("\t *errstr:\t\t%s\n", ann->errstr);
//   /* the learning rate of the network */
//   float learning_rate;
    printf("\t learning_rate: \t%f\n", ann->learning_rate);

//   /* The learning momentum used for backpropagation algorithm. */
//   float learning_momentum;
    printf("\t learning_momentum: \t%f\n", ann->learning_momentum);

//   /* the connection rate of the network
//    * between 0 and 1, 1 meaning fully connected
//    */
//   float connection_rate;
	printf("\t connection_rate: \t%f\n", ann->connection_rate);
//   /* is 1 if shortcut connections are used in the ann otherwise 0
//    * Shortcut connections are connections that skip layers.
//    * A fully connected ann with shortcut connections are a ann where
//    * neurons have connections to all neurons in all later layers.
//    */
//   enum fann_nettype_enum network_type;
	// printf("\t (enum) network_type: \t%d\n", ann->network_type);
	printf("\t (enum) network_type: \t%d\n", fann_get_network_type(ann));

//   /* pointer to the first layer (input layer) in an array af all the layers,
//    * including the input and outputlayers
//    */
//   struct fann_layer *first_layer;
	printf("\t first_layer: \t\tstruct fann_layer *\n");

//   /* pointer to the layer past the last layer in an array af all the layers,
//    * including the input and outputlayers
//    */
//   struct fann_layer *last_layer;
	printf("\t last_layer: \t\tstruct fann_layer *\n");

//   /* Total number of neurons.
//    * very useful, because the actual neurons are allocated in one long array
//    */
//   unsigned int total_neurons;
	printf("\t total_neurons: \t%d\n", ann->total_neurons);

//   /* Number of input neurons (not calculating bias) */
//   unsigned int num_input;
	printf("\t num_input: \t\t%d\n", ann->num_input);

//   /* Number of output neurons (not calculating bias) */
//   unsigned int num_output;
	printf("\t num_output: \t\t%d\n", ann->num_output);

//   /* The weight array */
//   fann_type *weights;
	printf("\t weights: \t\tfann_type * {aka float *}\n");

//   /* The connection array */
//   struct fann_neuron **connections;
	printf("\t connections: \t\tstruct fann_neuron **\n");

//   /* Used to contain the errors used during training
//    * Is allocated during first training session,
//    * which means that if we do not train, it is never allocated.
//    */
//   fann_type *train_errors;
	printf("\t train_errors: \t\tfann_type * {aka float *}\n");

//   /* Training algorithm used when calling fann_train_on_..
//    */
//   enum fann_train_enum training_algorithm;
	printf("\t num_output: \t\t%d\n", ann->num_output);


//   /* Total number of connections.
//    * very useful, because the actual connections
//    * are allocated in one long array
//    */
//   unsigned int total_connections;
	printf("\t total_connections: \t%d\n", ann->total_connections);

//   /* used to store outputs in */
//   fann_type *output;
	printf("\t output: \t\t‘fann_type * {aka float *}’\n");

//   /* the number of data used to calculate the mean square error.
//    */
//   unsigned int num_MSE;
	printf("\t num_MSE: \t\t%d\n", ann->num_MSE);

//   /* the total error value.
//    * the real mean square error is MSE_value/num_MSE
//    */
//   float MSE_value;
	printf("\t MSE_value: \t\t%f\n", ann->MSE_value);

//   /* The number of outputs which would fail (only valid for classification problems)
//    */
//   unsigned int num_bit_fail;
	printf("\t num_bit_fail: \t\t%d\n", ann->num_bit_fail);

//   /* The maximum difference between the actual output and the expected output
//    * which is accepted when counting the bit fails.
//    * This difference is multiplied by two when dealing with symmetric activation functions,
//    * so that symmetric and not symmetric activation functions can use the same limit.
//    */
//   fann_type bit_fail_limit;
	printf("\t bit_fail_limit: \t%f\n", ann->bit_fail_limit);

//   /* The error function used during training. (default FANN_ERRORFUNC_TANH)
//    */
//   enum fann_errorfunc_enum train_error_function;
	printf("\t (enum) train_error_function: \t%d\n", ann->train_error_function);

//   /* The stop function used during training. (default FANN_STOPFUNC_MSE)
//    */
//   enum fann_stopfunc_enum train_stop_function;
	printf("\t (enum) train_stop_function: \t%d\n", ann->train_stop_function);

//   /* A pointer to user defined data. (default NULL)
//    */
//   void *user_data;
	printf("\t user_data: \t\t%p\n", ann->user_data);


}
