#ifndef TCPKALI_ENGINE_H
#define TCPKALI_ENGINE_H

long number_of_cpus();
int max_open_files();

struct engine;

struct engine_params {
    struct addresses remote_addresses;
    struct addresses listen_addresses;
    size_t requested_workers;       /* Number of threads to start */
    size_t channel_bandwidth_Bps;   /* Single channel bw, bytes per second. */
    size_t minimal_write_size;
    double connect_timeout;
    double channel_lifetime;
    double epoch;
    /* Message data */
    void *message_data;
    size_t message_size;
};

struct engine *engine_start(struct engine_params);


/*
 * Report the number of opened connections by categories.
 */
void engine_connections(struct engine *, size_t *incoming, size_t *outgoing, size_t *counter);
void engine_traffic(struct engine *, size_t *sent, size_t *received);


size_t engine_initiate_new_connections(struct engine *, size_t n);

void engine_terminate(struct engine *);

#endif  /* TCPKALI_ENGINE_H */
