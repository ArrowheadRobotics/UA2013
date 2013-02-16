#include "stderr.h"

ErrorContext::ErrorContext(char *filename) {
	openContext(filename);
}

void ErrorContext::openContext(char *filename) {
	fp = fopen(filename, "wb");
}

void ErrorContext::write(char *buf, bool writetoconsole) {
	fwrite(buf, strlen(buf), 1, fp);
	if(writetoconsole) printf(buf);
}

ErrorContext::~ErrorContext() {
	fclose(fp);
}
