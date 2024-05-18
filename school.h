
#define CAPACITY   50
#define NULLPTR (void*)0
typedef struct{
 char name[20];
 char phone[11];
}person_t;

typedef struct{
char name[20];
char phone[11];
int id;
int grade;
person_t father;
person_t mother;
}st_d;

int string_comparenotsens(char*str1,char*str2);
int string_len(char*str);
int string_compare(char*s1,char*s2);
void scan_name(char*str,int maxsize);
void scan_phone(char*str,int maxsize);
void string_print(char arr[]);
void intduction (void);
void add_student(void);
void school_print(void);
int Edit_student(void);
void Remove_student(void);
void CallingBar(void);
void Call_father(void);
int save_Data(void);
void read_data(void);
void scan_studentName(char*name,int size);
void scan_studentPhone(char*phone,int size);
void scan_FatherName(char*name,int size);
void scan_FatherPhone(char*phone,int size);
void scan_MotherName(char*name,int size);
void scan_MotherPhone(char*phone,int size);
void scan_StudentGrade(int*pGrade);
void string_copy(char *str_original, char *str_copy, int counter);
void convert_char_TO_int(char*str,int*num,int digits);

