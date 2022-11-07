#include <iostream>
#include <string.h>
#include <map>
#define ll long long int
using namespace std;
char *s_gets(char *st, int n, FILE *fp)//用于文件读入字符串
{
    char *ret_val;
    int i = 0;
    ret_val = fgets(st, n, fp);
    if (ret_val)
    {
        while (st[i] != '\n' && st[i] != '\0')
            i++;
        if (st[i] == '\n')
            st[i] = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}
typedef struct student
{
    char name[1000], major[1000], class_[1000], id[1000], year[1000], eng[1000];
} st;
struct node
{
    st data;
    struct node *next;
};
node *init()//链表初始化
{
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL;
    return head;
}
node *head = init();
void createnode() //新增学生
{
    node *op = head; // op指针是操作的节点
    cout << "请输入需要添加学生的人数：" << endl;
    ll n;
    cin >> n;
    while (n--)
    {
        printf("请依次输入学生学号、姓名、年龄、专业、班级和英语成绩（每一项用换行来分开）：\n");
        node *newnode = (node *)malloc(sizeof(node));
        cin >> newnode->data.id >> newnode->data.name >> newnode->data.year >> newnode->data.major >> newnode->data.class_ >> newnode->data.eng;
        newnode->next = NULL;
        while (op->next != NULL)
        {
            op = op->next;
        }
        op->next = newnode;
    }
}
void printLink() //打印学生
{
    node *op = head->next;
    ll no = 1;
    while (op != NULL)
    {
        cout << "第" << no << "位同学 "
             << "学号：" << op->data.id << " 姓名：" << op->data.name << " 年龄" << op->data.year << " 专业" << op->data.major << " 班级" << op->data.class_ << " 英语成绩" << op->data.eng << endl;
        op = op->next;
        no++;
    }
}
void deleteNode()//删除学生
{
    node *op = head->next;
    cout << "请输入需要删除学生学籍的学号：";
    char no[1000];
    cin >> no;
    ll ck = 0;
    while (op != NULL)
    {
        if (strcmp(op->data.id, no) == 0)
        {
            cout << "请核对以下需要删除学生学籍的信息：" << endl
                 << endl;
            cout << "学号：" << op->data.id << " 姓名：" << op->data.name << " 年龄" << op->data.year << " 专业" << op->data.major << " 班级" << op->data.class_ << " 英语成绩" << op->data.eng << endl
                 << endl;
            cout << "输入1确认删除，输入0取消删除：" << endl;
            ll k;
            cin >> k;
            if (k == 1)
            {
                node *OP = head;
                while (strcmp(OP->next->data.id, no) != 0)
                {
                    OP = OP->next;
                }
                node *curr = OP->next;
                OP->next = curr->next;
                ck = 1;
                op = op->next;
                free(curr);
                cout << "删除成功" << endl
                     << endl;
                continue;
            }
            else if (k == 0)
                return;
        }
        else
        {
            op = op->next;
        }
    }
    if (!ck)
        cout << "无法查找到此学生" << endl
             << endl;
}
void searchNode()//查找学生
{ 
    node *op = head->next;
    char no[1000];
    ll n = 1;
    cout << "请输入需要查找学生学籍的姓名：";
    cin >> no;
    ll ck = 1;
    while (op != NULL)
    {
        if (strcmp(op->data.name, no) == 0)
        {
            cout << "第" << n << "位同学 "
                 << "学号：" << op->data.id << " 姓名：" << op->data.name << " 年龄" << op->data.year << " 专业" << op->data.major << " 班级" << op->data.class_ << " 英语成绩" << op->data.eng << endl
                 << endl;
            ck = 0;
            n++;
            op = op->next;
        }
        else
        {
            op = op->next;
        }
    }
    if (ck)
        cout << "无法找到该学生！" << endl;
}
void coutnode()//统计学生
{
    map<string, ll> mp1, mp2;
    node *op = head->next;
    while (op != NULL)
    {
        string fi(op->data.major);
        string FI(op->data.year);
        if (mp1.find(fi) != mp1.end())
            mp1[fi]++;
        else
            mp1[fi] = 1;
        if (mp2.find(FI) != mp2.end())
            mp2[FI]++;
        else
            mp2[FI] = 1;
        op = op->next;
    }
    for (auto t : mp1)
        cout << "专业为:" << t.first << "有" << t.second << "名学生" << endl
             << endl;
    for (auto t : mp2)
        cout << "年龄为:" << t.first << "有" << t.second << "名学生" << endl
             << endl;
}
void nodesort()//按英语成绩排序
{
    node *p, *q;
    ll t;
    p = head->next;   
    while (p != NULL)
    {
        q = p->next;    
        while (q != NULL) 
        {
            ll x=0, y=0;
            for (int i = 0; p->data.eng[i] != '\0'; i++)
            {
                if (p->data.eng[i] >= '0' && p->data.eng[i] <= '9')
                    x = x * 10 + p->data.eng[i] - '0';
            }
             for (int i = 0; q->data.eng[i] != '\0'; i++)
            {
                if (q->data.eng[i] >= '0' && q->data.eng[i] <= '9')
                    y = y * 10 + q->data.eng[i] - '0';
            }
            if (x<y)
            {
                swap(p->data.class_, q->data.class_);
                swap(p->data.eng, q->data.eng);
                swap(p->data.id, q->data.id);
                swap(p->data.major, q->data.major);
                swap(p->data.name, q->data.name);
                swap(p->data.year, q->data.year);
            }
            q = q->next; 
        }
        p = p->next;
    }
    printLink();
}
void input()//从文件读入
{
    FILE *fp; //文件指针
    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("打开文件失败！请尝试将名单命名为“data.txt“\n");
        system("pause");
        return;
    }
    else
    {
        ll i = 0;
        char inputdata[1000], tmp[1000][1000];
        while ((s_gets(inputdata, 1000, fp)) != NULL)
        {
            if (strcmp(inputdata, "") == 0)
                continue;
            else
            {
                strcpy(tmp[i], inputdata);
                i++;
            }
        }
        node *op = head;
        while (op->next != NULL)
            op = op->next;
        ll j = 0;
        ll N = i / 6;
        for (int i = 0; i < N; i++)
        {
            node *newnode = (node *)malloc(sizeof(node));
            newnode->next = NULL;
            strcpy(newnode->data.id, tmp[j++]);
            strcpy(newnode->data.name, tmp[j++]);
            strcpy(newnode->data.year, tmp[j++]);
            strcpy(newnode->data.major, tmp[j++]);
            strcpy(newnode->data.class_, tmp[j++]);
            strcpy(newnode->data.eng, tmp[j++]);
            op->next = newnode;
            op = newnode;
        }
    }
    fclose(fp);
}
void output()//导出文件
{
    FILE *fp; //文件指针
    fp = fopen("data.txt", "a+");
    if (fp == NULL)
    {
        printf("打开文件失败！请尝试将名单命名为“data.txt“\n");
        system("pause");
        return;
    }
    else
    {
        node *op = head->next;
        while (op != NULL)
        {
            fputs("\n", fp);
            fputs(op->data.id, fp);
            fputs("\n", fp);
            fputs(op->data.name, fp);
            fputs("\n", fp);
            fputs(op->data.year, fp);
            fputs("\n", fp);
            fputs(op->data.major, fp);
            fputs("\n", fp);
            fputs(op->data.class_, fp);
            fputs("\n", fp);
            fputs(op->data.eng, fp);
            fputs("\n", fp);
            op = op->next;
        }
        fclose(fp);
    }
}
int main()
{
    cout << "*********************************************************************************************************************" << endl;
    cout << "                             欢迎使用本软件" << endl;
    while (1)
    {
        cout << "请输入功能：1.新增学生信息 2.删除学生信息 3.导入学生信息 4.学生信息搜索(按姓名) 5.学生信息统计 6.按英语成绩排序 7.学生信息保存 8.打印当前所有学生的信息 9.退出" << endl;
        ll opr;
        cin >> opr;
        switch (opr)
        {
        case 1:
            createnode();
            cout << "添加操作完成" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 2:
            deleteNode();
            cout << "删除操作完成" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 3:
            input();
            cout << "导入操作完成" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 4:
            searchNode();
            cout << "查找操作完成" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 5:
            coutnode();
            cout << "统计操作完成" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 6:
            nodesort();
            cout << "排序操作完成" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 7:
            output();
            cout << "导出操作完成" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 8:
            printLink();
            cout << "打印操作完成" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 9:
            return 0;
        default:
            cout << "输入格式错误！" << endl;
            cout << "*********************************************************************************************************************" << endl;
        }
    }
    return 0;
}