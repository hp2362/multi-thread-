count_mutex = mutex_init();
write_mutex = mutex_init();
read_count = 0;

void read_lock{
	lock(count_mutex);
read_count++;
if (read_count == 1) {
	lock(write_mutex);
}
unlock(count_mutex);
}

void read_unlock{
	lock(count_mutex);
read_count--;
if (read_count == 0) {
	unlock(write_mutex);
}
unlock(count_mutex);
}

void write_lock{
	lock(write_mutex);
}

void write_unlock{
	unlock(write_mutex);
}