typedef struct Screensaver Screensaver;

typedef struct Static Static;

typedef struct Dynamic Dynamic;

typedef struct Interactive Interactive;

struct Screensaver {
	Static *stat;
	Dynamic *dyn;
	Interactive *inter;
};

struct Static {
	char file[50];
};

struct Dynamic {
	int sleep;
	char size[5];
	char *file[50];
};

struct Interactive {
	char *file[50];
};

int randomnb(int MIN, int MAX);
int widthPBM(FILE* fichier);
int heightPBM(FILE* fichier);
void centerX(int width, const char* str);
void centerY(int height);
void displayPBM(FILE* fichier, int size, int width, int height, char *tableau);
void initialisationHeure();
