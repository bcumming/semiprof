# TODO

## tasks

* merge changes from Arbor

## features

### high priority

The library maintains a list of regions and their accumulated statistics for each thread.
On initialization it allocates enough space to record for 256 threads.
When a call to the profiler is made from a thread for the first time, that thread is assigned
one of the pre-allocated slots.
The integer index of the thread is stored in a `thread_local` variable for subsequent calls.
This solution works well for OpenMP, TBB, C++11 threads, but might not work for all libraries,
and certainly won't work if we have more than 256 threads.

* user supplied callbacks for thread id and thread count
* built in support for threading back ends (OpenMP, TBB, HPX, etc)

Other nice to have things:
* user-facing tree representation of profiler output
    - currently only flattened output is presented
* docs
* examples
* cmake

### nice to have

* PAPI support
* CUDA support
* tracing
