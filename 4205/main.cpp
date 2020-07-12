#include <iostream>
#include<cstring>
using namespace std;

class turing
{
    struct node
    {
        int year;
        char name[30];
        node*next;
        node(char n[30],int y=0,node*N=NULL)
        {
            year=y;
            next=N;
            strcpy(name,n);
        }
        node():next(NULL) {}
        ~node() {}
    };
private:
    node *head;
    int length;
public:
    node* move(int i) const
    {
        node*p=head;
        while(i-->=0)
            p=p->next;
        return p;
    }
    turing()
    {
        head=new node;
        length=0;
    }
    void insert(int y,char n[30])
    {
        node *p=head;
        while(p!=NULL)
        {
            if(p->next==NULL||p->next->year==y&&(strcmp(p->next->name,n)>0))
            {
                p->next=new node(n,y,p->next);
                break;
            }
            if(p->next==NULL||p->year==y&&(strcmp(p->next->name,n)>0))
            {
                p->next=new node(n,y,p->next);
                break;
            }
            if(p->next==NULL||p->year==y&&(strcmp(p->next->name,n)==0))
            {
                p->next=new node(n,y,p->next);
                break;
            }
            if(p->next==NULL||p->next->year>y)
            {
                p->next=new node(n,y,p->next);
                break;
            }
            p=p->next;
        }
    }
    void Delete(int i)
    {
        node *pos,*delp;

        pos=move(i-1);
        delp=pos->next;
        pos->next=delp->next;
        delete delp;
        --length;
    }
    void list(int i)
    {
        node *p;
        p=move(i-1);
        cout<<p->year<<" "<<p->name<<endl;
    }
    void read(int n)
    {
        int y,j=0,k;
        char nam[30];
        char caozuo[50];
        for(int i=0; i<n; i++)
        {
            if(i==0)
                cin.get();
            cin.getline(caozuo,50);
            if(caozuo[0]=='i')
            {
                y=(caozuo[7]-'0')*1000+(caozuo[8]-'0')*100+(caozuo[9]-'0')*10+(caozuo[10]-'0');
                j=0;
                while(caozuo[j]!='\0')
                {
                    nam[j]=caozuo [j+12];
                    j++;
                }
                insert(y,nam);
            }
            if(caozuo[0]=='d')
            {
                k=0;
                int i=7,q;
                while(caozuo[i]!='\0')
                {
                    q=caozuo[i]-'0';
                    k=k*10+q;
                    i++;
                }
                Delete(k-1);

            }
            if(caozuo[0]=='l')
            {
                k=0;
                int i=5,q;
                while(caozuo[i]!='\0')
                {
                    q=caozuo[i]-'0';
                    k=k*10+q;
                    i++;
                }
                list(k);
            }
        }
    }

};
int main()
{
    int n;
    turing turing1;
    cin>>n;
    turing1.read(n);
    return 0;
}
