#include <iostream>
#include <string.h>
#include <map>
#define ll long long int
using namespace std;
char *s_gets(char *st, int n, FILE *fp)//�����ļ������ַ���
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
node *init()//�����ʼ��
{
    node *head = (node *)malloc(sizeof(node));
    head->next = NULL;
    return head;
}
node *head = init();
void createnode() //����ѧ��
{
    node *op = head; // opָ���ǲ����Ľڵ�
    cout << "��������Ҫ���ѧ����������" << endl;
    ll n;
    cin >> n;
    while (n--)
    {
        printf("����������ѧ��ѧ�š����������䡢רҵ���༶��Ӣ��ɼ���ÿһ���û������ֿ�����\n");
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
void printLink() //��ӡѧ��
{
    node *op = head->next;
    ll no = 1;
    while (op != NULL)
    {
        cout << "��" << no << "λͬѧ "
             << "ѧ�ţ�" << op->data.id << " ������" << op->data.name << " ����" << op->data.year << " רҵ" << op->data.major << " �༶" << op->data.class_ << " Ӣ��ɼ�" << op->data.eng << endl;
        op = op->next;
        no++;
    }
}
void deleteNode()//ɾ��ѧ��
{
    node *op = head->next;
    cout << "��������Ҫɾ��ѧ��ѧ����ѧ�ţ�";
    char no[1000];
    cin >> no;
    ll ck = 0;
    while (op != NULL)
    {
        if (strcmp(op->data.id, no) == 0)
        {
            cout << "��˶�������Ҫɾ��ѧ��ѧ������Ϣ��" << endl
                 << endl;
            cout << "ѧ�ţ�" << op->data.id << " ������" << op->data.name << " ����" << op->data.year << " רҵ" << op->data.major << " �༶" << op->data.class_ << " Ӣ��ɼ�" << op->data.eng << endl
                 << endl;
            cout << "����1ȷ��ɾ��������0ȡ��ɾ����" << endl;
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
                cout << "ɾ���ɹ�" << endl
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
        cout << "�޷����ҵ���ѧ��" << endl
             << endl;
}
void searchNode()//����ѧ��
{ 
    node *op = head->next;
    char no[1000];
    ll n = 1;
    cout << "��������Ҫ����ѧ��ѧ����������";
    cin >> no;
    ll ck = 1;
    while (op != NULL)
    {
        if (strcmp(op->data.name, no) == 0)
        {
            cout << "��" << n << "λͬѧ "
                 << "ѧ�ţ�" << op->data.id << " ������" << op->data.name << " ����" << op->data.year << " רҵ" << op->data.major << " �༶" << op->data.class_ << " Ӣ��ɼ�" << op->data.eng << endl
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
        cout << "�޷��ҵ���ѧ����" << endl;
}
void coutnode()//ͳ��ѧ��
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
        cout << "רҵΪ:" << t.first << "��" << t.second << "��ѧ��" << endl
             << endl;
    for (auto t : mp2)
        cout << "����Ϊ:" << t.first << "��" << t.second << "��ѧ��" << endl
             << endl;
}
void nodesort()//��Ӣ��ɼ�����
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
void input()//���ļ�����
{
    FILE *fp; //�ļ�ָ��
    fp = fopen("data.txt", "r");
    if (fp == NULL)
    {
        printf("���ļ�ʧ�ܣ��볢�Խ���������Ϊ��data.txt��\n");
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
void output()//�����ļ�
{
    FILE *fp; //�ļ�ָ��
    fp = fopen("data.txt", "a+");
    if (fp == NULL)
    {
        printf("���ļ�ʧ�ܣ��볢�Խ���������Ϊ��data.txt��\n");
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
    cout << "                             ��ӭʹ�ñ����" << endl;
    while (1)
    {
        cout << "�����빦�ܣ�1.����ѧ����Ϣ 2.ɾ��ѧ����Ϣ 3.����ѧ����Ϣ 4.ѧ����Ϣ����(������) 5.ѧ����Ϣͳ�� 6.��Ӣ��ɼ����� 7.ѧ����Ϣ���� 8.��ӡ��ǰ����ѧ������Ϣ 9.�˳�" << endl;
        ll opr;
        cin >> opr;
        switch (opr)
        {
        case 1:
            createnode();
            cout << "��Ӳ������" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 2:
            deleteNode();
            cout << "ɾ���������" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 3:
            input();
            cout << "����������" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 4:
            searchNode();
            cout << "���Ҳ������" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 5:
            coutnode();
            cout << "ͳ�Ʋ������" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 6:
            nodesort();
            cout << "����������" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 7:
            output();
            cout << "�����������" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 8:
            printLink();
            cout << "��ӡ�������" << endl;
            cout << "*********************************************************************************************************************" << endl;
            break;
        case 9:
            return 0;
        default:
            cout << "�����ʽ����" << endl;
            cout << "*********************************************************************************************************************" << endl;
        }
    }
    return 0;
}