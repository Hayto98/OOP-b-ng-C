#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int MAX = 100;
//50-studentManagement

void showMenu (void);
void addStudent (char id[][MAX],char fName[][MAX],
                 char lName[][MAX],int yob[],
                 float gpa[],int *size);
void printStudentList (char id[][MAX],char fName[][MAX],
                 char lName[][MAX],int yob[],
                 float gpa[],int size);

int findPosById (char id[][MAX],int size, char key[]);

void printStudent (char id[][MAX],char fName[][MAX],
                 char lName[][MAX],int yob[],
                 float gpa[],int pos);
void removeStudentByPos (char id[][MAX],char fName[][MAX],
                 char lName[][MAX],int yob[],
                 float gpa[],int *size,int pos);
void printHighestGPAStudent (char id[][MAX],char fName[][MAX],
                 char lName[][MAX],int yob[],
                 float gpa[],int size);
void sortStudentOrderByFName (char id[][MAX],char fName[][MAX],
                 char lName[][MAX],int yob[],
                 float gpa[],int size);
int main()
{
    // init type
    char id[MAX][10];
    char fName[MAX][30];
    char lName[MAX][30];
    int yob[MAX];
    float gpa[MAX];
    int size = 0;
    int choice;
    char buffer ;
    // process
    do{
        showMenu();
        do{ // chặn nhập láo
            printf ("\nPlz, input your choice(integer): ");
            scanf ("%d",&choice);
            scanf ("%c",&buffer);
            fflush(stdin);
            if (buffer != 10){
                printf("\nDo Ku know input integer number ???");
            }
        }while (buffer != 10);



        //xử lý choice
        switch (choice){
            case 1: {
                system("cls");
                printf ("\nAdd New Student Information");
                addStudent(id,fName,lName,yob,gpa,&size);
                break;
            }
            case 2: {
                system("cls");
                printf("\nSearch Student Information");
                char key[MAX];
                printf ("\nID: ");
                gets(key);// nhập mã sv mà bạn muốn tìm đi
                int pos = findPosById(id,size,key);
                if (pos == -1){
                    printf ("\nThis Student doesn't exist");
                }else{
                    printStudent (id,fName,lName,yob,gpa,pos);
                }
                break;
            }
            case 3: {
                system("cls");
                printf("\nDelete Student Information");
                char key[MAX];
                printf ("\nID: ");
                gets(key);// nhập mã sv mà bạn muốn tìm đi
                int pos = findPosById(id,size,key);
                if (pos == -1){
                    printf ("\nThis Student doesn't exist");
                }else{
                    printf ("\nDeleted successfully");
                    printStudent (id,fName,lName,yob,gpa,pos);
                    //thằng bị xóa nè
                    removeStudentByPos (id,fName,lName,yob,gpa,&size,pos);
                    //xóa
                }
                break;
            }
            case 4: {
                system ("cls");
                printf ("\nPrint highest gpa student");
                printHighestGPAStudent(id,fName, lName, yob,gpa,size);

                break;
            }
            case 5: {
                system("cls");
                printf ("\nPrime Student Information List");
                printStudentList(id,fName,lName,yob,gpa,size);
                break;
            }
            case 6: {
                system("cls");
                printf ("\nSort student list ordere bu fName ascending");
                sortStudentOrderByFName(id,fName,lName,yob,gpa,size);
                break;
            }
            case 7: {
                printf ("\nNice to meet you, see you again <3");
                break;
            }
            default: {
                printf ("\nThis choice is required between 1 and 7 !!!");
                break;
            }
        }

    }while (choice != 7);



    return 0;
}// trên này là main

void printHighestGPAStudent (char id[][MAX],char fName[][MAX],
                 char lName[][MAX],int yob[],
                 float gpa[],int size){
    //sort
    if (size == 0){
        printf ("\nNothing to print");
    }else{
        // tìm số điểm lớn nhất
        float gpaMax = gpa[0];
        for (int i =0; i<= size-1;i++){
            gpaMax = gpaMax < gpa[i] ? gpa[i] : gpaMax;
        }

        printf ("\n%-10s|%-15s|%-15s|%-4s|%-5s|",
                "ID","FNAME","LNAME","YOB","GPA");
        for (int i = 0;i <= size -1;i++){
            if (gpa[i] == gpaMax){
                printf ("\n%-10s|%-15s|%-15s|%4d|%5.2f|",
                    id[i],fName[i],lName[i],yob[i],gpa[i]);
            }
        }
    }

}
void sortStudentOrderByFName (char id[][MAX],char fName[][MAX],
                 char lName[][MAX],int yob[],
                 float gpa[],int size){

    for (int i = 0;i <= size- 2;i++){
        for (int j = i+ 1;j <= size -1;j++){
            if (strcmp(fName[i], fName[j])== 1){
                // swap id
                char strTmp[MAX];
                strcpy(strTmp, id[i]);
                strcpy (id[i], id[j]);
                strcpy (id[j], strTmp);
                //swap fName
                strcpy(strTmp, fName[i]);
                strcpy (fName[i], fName[j]);
                strcpy (fName[j], strTmp);
                //swap lName
                strcpy(strTmp, lName[i]);
                strcpy (lName[i], lName[j]);
                strcpy (lName[j], strTmp);
                //swap yob;
                int yobTmp = yob[i];
                yob[i] =yob[j];
                yob[j] = yobTmp;
                // swap gpa;
                float gpaTmp = gpa[i];
                gpa[i] = gpa[j];
                gpa[j] = gpaTmp;
            }
        }
    }
}


void removeStudentByPos (char id[][MAX],char fName[][MAX],
                 char lName[][MAX],int yob[],
                 float gpa[],int *size,int pos){
    for (int i = pos; i <= *size-1;i++){
        strcpy(id[i],id[i+1]);
        strcpy(fName[i],fName[i+1]);
        strcpy(lName[i],lName[i+1]);
        yob[i] = yob[i+1];
        gpa[i] = gpa[i+1];
    }
    (*size)--;
}

void printStudent (char id[][MAX],char fName[][MAX],
                 char lName[][MAX],int yob[],
                 float gpa[],int pos){
    printf ("\n%-10s|%-15s|%-15s|%-4s|%-5s|",
            "ID","FNAME","LNAME","YOB","GPA");


    printf ("\n%-10s|%-15s|%-15s|%4d|%5.2f|",
            id[pos],fName[pos],lName[pos],yob[pos],gpa[pos]);

}


int findPosById (char id[][MAX],int size, char key[]){
    for (int i = 0; i <= size-1;i++){
        if (strcmp(id[i],key)== 0) return i;
    }
    return -1;
}

void printStudentList (char id[][MAX],char fName[][MAX],
                       char lName[][MAX],int yob[],
                       float gpa[],int size){
    if (size == 0){
        printf ("\nNothing to print");
    }else{
        printf ("\n%-10s|%-15s|%-15s|%-4s|%-5s|",
                "ID","FNAME","LNAME","YOB","GPA");
        for (int i = 0;i <= size -1;i++){

            printf ("\n%-10s|%-15s|%-15s|%4d|%5.2f|",
                    id[i],fName[i],lName[i],yob[i],gpa[i]);
        }
    }
}

void addStudent (char id[][MAX],char fName[][MAX],
                 char lName[][MAX],int yob[],
                 float gpa[],int *size){
    int isFind;
    do{
        char key[MAX];
        printf("\nId: ");
        gets(key); // mời bạn nhập id mà bạn muốn dùng
        fflush(stdin);
        isFind = findPosById(id,*size,key); // tìm
        if (isFind != -1){
            printf ("\nThis id has been used");
        }else{
            strcpy(id[*size], key);
        }
    }while (isFind != -1);

    printf ("\nfName: ");
    gets(fName[*size]);
    fflush(stdin);

    printf ("\nlName: ");
    gets(lName[*size]);
    fflush(stdin);

    printf ("\nYob: ");
    scanf ("%d", &yob[*size]);
    fflush(stdin);

    printf ("\nGpa: ");
    scanf ("%f", &gpa[*size]);
    fflush(stdin);
    (*size)++;
    printf ("\nAdding successfully");
}


void showMenu (void){
    printf ("\n---Student management application---");
    printf ("\n1.Add new student information");
    printf ("\n2.Search student information");
    printf ("\n3.Delete student information");
    printf ("\n4.Print highest gpa student information list");
    printf ("\n5.Print student list");
    printf ("\n6.Sort student List order by FirstName Ascending");
    printf ("\n7.Quit");
}



//CMS
//43-studentManagement
//viết 1 chương trình menu
//nhiệm vụ quản lý sinh viên
//1 sinh viên được mô tả bằng các thuộc tính
//id, firstName, lastName, yob, gpa
//Menu gồm các chức năng sau
//1.thêm sinh viên vào danh sách
//2.tìm kiếm sinh viên dựa trên id
//3.xóa sinh viên khỏi danh sách theo id
//4.xuất ra danh sách sinh viên đạt điểm cao nhất
//5.in ra danh sách sinh viên
//6.sort theo firstName asc
//7.quit
//mô tả chương trình:
//người dùng nhập số để chương trình phục vụ các chức năng
//nếu người dùng nhập sai số => chửi
//người dùng nhập đúng số, làm chức năng
//quay lại menu ép nhập tiếp
//nhập sai số nguyên => chửi
//nhập số 7 thì thoát
//nhập sinh viên mới mà id trùng với sinh viên có trong danh sách
//thì => chửi
