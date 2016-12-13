typedef struct Historical Historical;

struct Screensaver {
	char *file[50],
	int type
};

void readHist(Historical hist);

void writeHist(Historical hist);
