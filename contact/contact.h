#include <string.h>


#define MAX 1000
#define MAX_NAME 20
#define MAX_TEL 20
#define MAX_GENDER 10
#define MAX_ADDR 40
#define MAX_QQ 15



typedef struct PeoInfo
{
	char qq[MAX_QQ];
	char name[MAX_NAME];
	char tel[MAX_TEL];
	char gender[MAX_GENDER];
	char addr[MAX_ADDR];
	int age;
}peoInfo;


typedef struct Contact
{
	peoInfo data[MAX];
	int size;
}contact;



void init(contact* con);

void addData(contact* con);
