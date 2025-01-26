#ifndef mainH
#define mainH
enum eCMD
{
    CMD_EXIT = -1, CMD_NONE, CMD_READ, CMD_SHOW, CMD_EDIT, CMD_ADD, CMD_DELETE,
    CMD_SORT, CMD_FIND, CMD_SAVE, CMD_SAVE_NEW, CMD_CALC, CMD_CREATE, CMD_ERROR};
struct Specific {
    char BrandName[24];
    char ModelName[24];
    char BodyMat[24];
    int Price;
};
extern bool change;
extern int count;
extern char filenamein[50];
#endif
