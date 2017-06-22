KL46 freedom board
ARM
RTOS
static tương tự private trong C++
không treuy xuát sang file khác
volatile
register
typedef
void

#error
#warning
pragma
ìndef
endif

trong hàm void vãn sử dung
return; đẻ kết thúc hàm 

int
phụ thuôc bus địa chỉ
hệ điều hành

type.h đinh nghĩa lại
uint8_t
uint32_t

int 

lưu ý con trỏ:

mảng gồm 
 1 2 3 4 5 6 7 8 9

 char *p1 trỏ đến 2
 int *p2 trỏ đến 2

thì *(p1 + 1) = 3
	*(p2 + 2) = (6789) mã 32 bit = 0x06070809 ??? 
Nguyễn đình mạnh linh
 huong nguyentiue

Variable thf là 
g_value

static
s_value

unt32_t a
unt32_t b

chú ý dung /**/


hard code numbers

macro
cmt sau macro
phía cuối


ss 2:

&ptr: địa chỉ lưu trữ con trỏ
ptr: địa chỉ con trỏ trỏ tới
*ptr = giá trị con trỏ or value

nội dung con trỏ chỉ tới 1 bộ nhớ khác

ví dụ:

void test(int8_t *ptr)
{
	

}


Kiểu con trỏ:
là biến trỏ đến địa chỉ
uint8_t, uint16_t,: format data con con trỏ trỏ tới

mail:  haind1@fsoft
skype: haind2611
hằng con trỏ(uint8_t * const abc) và con trỏ hằng(const uint8_t *abc)
con trỏ hằng: là vị trí ko thay đỏi đc
hằng con trỏ: nội dung không thay đổi đ

c
khi khai báo

uint8_t *ptr; -> mỗi lần reset sẽ trỏ đến 1 ô nhớ bất kì ko kiểm soát

=> Nên viết uint 8_t *ptr = NULL;
Sau đấy có thể dung malloc. calloc,...

ptr=(int)malloc(4* sizeof(int))

free(ptr)

đia chỉ là entry point: là 1 hàm nào đấy ???

uint8_t ~~ unsigned char 

định nghĩa kiểu dữ liệu: typedef unsigned short uint16_t;

hàm con trỏ:

hàm: uint8_t test(int x, int y)
=> typedef uint8_t *f_ptr(uint8_t, uint16_t)

sau đáy có theert gọi

f_ptr = test;

value = f_ptr(1,3542)

tách só 32bit thang 8bit
tìm hiểu trước

structs

struct newData
{
	int ele1;
	int* ele2;
	char ele3;
	void *myData
}

typedef struc newData newData_t; // tiền tố _t cho typedef


newData_t myStruct;
int myInt = 0;

int main()
{
	myStruct.ele1 = 1;
	myStruct.ele2 = &myInt;
	myStruc.ele3 = 3
	myStruct.myData = (void*)(&myStruct);
}

nên dùng
void fun2 (int p[], int length)(nếu cho thành p[100] thì số 100 là vô nghĩa)
chứ không dùng
void fun1 (int* p)


ex2
struct student
{
	int mark;
	char name[64];
	struct* student student_t; 
}

typedef struc newData newData_t; // tiền tố _t cho typedef

student_t *pHead = NULL;
student_t myStudentList[100];

int myInt = 0;

int main()
{
	myStruct.ele1 = 1;
	myStruct.ele2 = &myInt;
	myStruc.ele3 = 3
	myStruct.myData = (void*)(&myStruct);
}

makefile.txt


check nếu là con trỏ là 1 biến trong hàm thì phải check xem nó có NULL hay không, nếu NULL thì trả về.

file handing.

text tream: chuỗi dòng lí tự kết thục bởi dấu xuống dòng
			các kí tự in hoa có thể bị biến đổi phụ thuộc vào môi trường.

có một số basic function xử lí.

chú ý file pointer ví dụ file *pointer.

file *fTest = NULL;
fTest =fopen("/../test.txt", r);

phân biêt text file và binary file.

chú ý fread và ffile.

rewind(fp ); reset file position file(vị trí trỏ đến trong file);

fseek(file *fp, long int offset, int origin)
cho sự chọn có thế setting curent position.


ví dụ fseek

fprintf, fscanf, in và lấy kí tự từ file

đếm số lượng kí tự 1 dòng trong 1 file

uint_t count(int *fp)
{

}

uint8_t buff(512)

thì phải chú ý sao lại cho buff giá tri phù hợp.

Debugging

IAR embedded workbench

con trỏ chỉ là trỏ địa chỉ
còn hàm malloc là tìm địa chỉ còn trông để gán cho con trỏ, Tuy nhiên ta có thể gán trực tiếp nếu biết vùng nhớ chưa sử dụng. 
malloc có uuw đimẻ sẽ pign vè bộ nhớ rằng ô nhớ đã đc xử dụng, con trỏ khác ko đc chêm vào

ví dụ : a = (uint8_t *) (0x1FFFF0000); nnhuwng có điểm yếu là sẽ là bugg khi con trỏ khác vãn trỏ đến địa chỉ của con trỏ này, điểm yếu so với malloc
=> gán thành con trỏ.

	ptr = &array[Max];
sau khi không sử dụng:
	ptr = NULL;

code ex:

#include <...>

uint8_t *a = NULL
uint8_t arr[5]= {0, 1, 2, 3, 4};

void test(uint8_t **p)
{
	*p = (uint8_t *)(&arr[0]);
	**p = 10;
	*(*p + 1) = 11;
}

int main()
{
	stop= 1;
	test((uint8_t **)&a);


	return 0;
}

con trỏ trỏ đến vùng nhớ, do chỉ vào địa chỉ là 4 byte nên phải ép kiểu uint32_t

dùng con trỏ **ptr để thay đổi địa chỉ trỏ tới.


**p tuong duong voi &ptr


&ptr: địa chỉ con trỏ
ptr: địa chỉ con trỏ trỏ tới
*(&ptr) giá trị con trỏ
*ptr giá trị con trỏ trỏ tới

con trỏ để ở giữa chương trình