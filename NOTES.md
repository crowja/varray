# Dev notes for varray

*   `varray` maintains an opaque `struct varray` and will free whatever memory
    it allocates. However it's the responsibility of the caller to free any
    memory it allocated.
