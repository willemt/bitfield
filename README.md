
# How does it work?

```c

/* allocate bitfield of 100 bits */
bitfield_t* bf = bitfield_new(100);

/* Mark 77th bit as on. */
bitfield_mark(bf, 77);

/* Mark 50th bit as off. */
bitfield_unmark(bf, 50);

/* Test if the 77th bit is marked */
if (bitfield_is_marked(bf, 77))
{
    printf("77th bit is marked\n");
}

```

# Building
$make

