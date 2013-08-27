
typedef struct
{
    uint32_t *bits;
    /* size in number of bits */
    int size;
} bitfield_t;


void bitfield_init(bitfield_t * bf, const int nbits);

void bitfield_release(bitfield_t* bf);

void bitfield_mark(bitfield_t * bf, const int bit);

void bitfield_unmark(bitfield_t * bf, const int bit);

int bitfield_is_marked(bitfield_t * bf, const int bit);

int bitfield_get_length(bitfield_t * bf);

char *bitfield_str(bitfield_t * bf);
