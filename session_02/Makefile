
# Compiler and flags
CC = gcc
CFLAGS = -Wall -O2

# Targets
all: write_file_conflict \
     write_file_conflict_fcntl \
     write_file_conflict_flock \
     write_file_conflict_flock_LOCK_NB \
     test_file

write_file_conflict: write_file_conflict.c
	$(CC) $(CFLAGS) -o write_file_conflict write_file_conflict.c

write_file_conflict_fcntl: write_file_conflict_fcntl.c
	$(CC) $(CFLAGS) -o write_file_conflict_fcntl write_file_conflict_fcntl.c

write_file_conflict_flock: write_file_conflict_flock.c
	$(CC) $(CFLAGS) -o write_file_conflict_flock write_file_conflict_flock.c

write_file_conflict_flock_LOCK_NB: write_file_conflict_flock_LOCK_NB.c
	$(CC) $(CFLAGS) -o write_file_conflict_flock_LOCK_NB write_file_conflict_flock_LOCK_NB.c

test_file: test_file.c
	$(CC) $(CFLAGS) -o test_file test_file.c

clean:
	rm -f write_file_conflict \
	      write_file_conflict_fcntl \
	      write_file_conflict_flock \
	      write_file_conflict_flock_LOCK_NB \
	      test_file
