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

void display(Screensaver scrnsave);

void movePic(Dynamic dyn);
