#ifndef BLOOM_H
#define BLOOM_H

struct commit;
struct repository;
<<<<<<< HEAD
struct commit_graph;

struct bloom_filter_settings {
	uint32_t hash_version;
	uint32_t num_hashes;
=======

struct bloom_filter_settings {
	/*
	 * The version of the hashing technique being used.
	 * We currently only support version = 1 which is
	 * the seeded murmur3 hashing technique implemented
	 * in bloom.c.
	 */
	uint32_t hash_version;

	/*
	 * The number of times a path is hashed, i.e. the
	 * number of bit positions tht cumulatively
	 * determine whether a path is present in the
	 * Bloom filter.
	 */
	uint32_t num_hashes;

	/*
	 * The minimum number of bits per entry in the Bloom
	 * filter. If the filter contains 'n' entries, then
	 * filter size is the minimum number of 8-bit words
	 * that contain n*b bits.
	 */
>>>>>>> upstream/maint
	uint32_t bits_per_entry;

	/*
	 * The maximum number of changed paths per commit
	 * before declaring a Bloom filter to be too-large.
	 *
	 * Written to the 'BFXL' chunk (instead of 'BDAT').
	 */
	uint32_t max_changed_paths;
};

#define DEFAULT_BLOOM_MAX_CHANGES 512
#define DEFAULT_BLOOM_FILTER_SETTINGS { 1, 7, 10, DEFAULT_BLOOM_MAX_CHANGES }
#define BITS_PER_WORD 8
<<<<<<< HEAD
#define BLOOMDATA_CHUNK_HEADER_SIZE 3*sizeof(uint32_t)
=======
#define BLOOMDATA_CHUNK_HEADER_SIZE 3 * sizeof(uint32_t)
>>>>>>> upstream/maint

/*
 * A bloom_filter struct represents a data segment to
 * use when testing hash values. The 'len' member
<<<<<<< HEAD
 * dictates how many uint64_t entries are stored in
=======
 * dictates how many entries are stored in
>>>>>>> upstream/maint
 * 'data'.
 */
struct bloom_filter {
	unsigned char *data;
<<<<<<< HEAD
	int len;
=======
	size_t len;
>>>>>>> upstream/maint
};

/*
 * A bloom_key represents the k hash values for a
<<<<<<< HEAD
 * given hash input. These can be precomputed and
 * stored in a bloom_key for re-use when testing
 * against a bloom_filter.
=======
 * given string. These can be precomputed and
 * stored in a bloom_key for re-use when testing
 * against a bloom_filter. The number of hashes is
 * given by the Bloom filter settings and is the same
 * for all Bloom filters and keys interacting with
 * the loaded version of the commit graph file and
 * the Bloom data chunks.
>>>>>>> upstream/maint
 */
struct bloom_key {
	uint32_t *hashes;
};

<<<<<<< HEAD
void load_bloom_filters(void);

void fill_bloom_key(const char *data,
		    int len,
		    struct bloom_key *key,
		    struct bloom_filter_settings *settings);

void add_key_to_filter(struct bloom_key *key,
					   struct bloom_filter *filter,
					   struct bloom_filter_settings *settings);
=======
/*
 * Calculate the murmur3 32-bit hash value for the given data
 * using the given seed.
 * Produces a uniformly distributed hash value.
 * Not considered to be cryptographically secure.
 * Implemented as described in https://en.wikipedia.org/wiki/MurmurHash#Algorithm
 */
uint32_t murmur3_seeded(uint32_t seed, const char *data, size_t len);

void fill_bloom_key(const char *data,
		    size_t len,
		    struct bloom_key *key,
		    const struct bloom_filter_settings *settings);
void clear_bloom_key(struct bloom_key *key);

void add_key_to_filter(const struct bloom_key *key,
		       struct bloom_filter *filter,
		       const struct bloom_filter_settings *settings);

void init_bloom_filters(void);
>>>>>>> upstream/maint

struct bloom_filter *get_or_compute_bloom_filter(struct repository *r,
						 struct commit *c,
						 int compute_if_not_present,
						 const struct bloom_filter_settings *settings,
						 int *computed);

#define get_bloom_filter(r, c) get_or_compute_bloom_filter( \
	(r), (c), 0, NULL, NULL)

<<<<<<< HEAD
int bloom_filter_contains(struct bloom_filter *filter,
			  struct bloom_key *key,
			  struct bloom_filter_settings *settings);
=======
int bloom_filter_contains(const struct bloom_filter *filter,
			  const struct bloom_key *key,
			  const struct bloom_filter_settings *settings);
>>>>>>> upstream/maint

#endif
