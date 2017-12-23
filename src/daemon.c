#include "daemon.h"

int daemonized = 0;
FILE* logfile = NULL;

int rdt_daemonize() {
	pid_t process_id = 0;
	pid_t sid = 0;

	if (daemonized == 1) {
		return 0;
	}

	process_id = fork();
	if (process_id < 0) {
		daemonized = 0;
	}
	if (process_id > 0) {
		exit(0);
	}
	umask(0);
	sid = setsid();
	if (sid < 0) {
		exit(1);
	}
	chdir("/");
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	daemonized = 1;
	return 1;
}


int rdt_is_daemonized() {
	return daemonized;
}


int rdt_open_log_file(char* log_filename) {
	if (!daemonized) {
		return 0;
	}
	if (!log_filename) {
		return -1;
	}
	if (logfile) {
		return -2;
	}
	logfile = fopen(log_filename, "w+");
	return 1;
}


int rdt_close_log_file() {
	if (!daemonized) {
		return 0;
	}
	if (!logfile) {
		return -1;
	}
	fclose(logfile);
	return 1;
}


int rdt_log(char* log) {
	char prefix[200];
	if (!log) {
		return -1;
	}
	if (!logfile) {
		return 0;
	}
	prefix[200 - 1] = 0;
	strftime(prefix, 200 - 1, "[%d-%M-%Y(%T)]", NULL);
	fprintf(logfile, "%s %s\n", prefix, log);
	fflush(logfile);
	return 1;
}
