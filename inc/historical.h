typedef struct Historical Historical;

struct Historical {
	char *file[50];
	int type;
};

void writeHist(Historical hist);